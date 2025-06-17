#include <H5Cpp.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Datatypes.h"

using namespace H5;
using json = nlohmann::json;

static std::string h5file_name;
std::string config_file_name = "Sim_Config.json";



// Generate unique filename based on date and time for current Simulation
std::string generate_filename() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    char buf[64];
    strftime(buf, sizeof(buf), "./Datasets/Dataset_%Y%m%d_%H%M.h5", ltm);
    return std::string(buf);
}

/*
 * Initialization of the h5 Dataset at beginning of Simulation
 */
void init_dataset() {

    file_name = generate_filename();
    H5File file(h5file_name, H5F_ACC_TRUNC);

    const std::vector<std::string> paths = {
        "/Simulation_Parameters",
        "/Controller_Parameters",
        "/Inputs",
        "/Inputs/Auto_Pilot",
        "/Inputs/Pilot_Controls",
        "/Responses",
        "/Responses/Attitudes",
        "/Responses/Velocities_B",
        "/Responses/AngularRates",
        "/Responses/Control_Efforts"
    };

    for (const auto& path : paths) {
        try {
            init_dataset(file, path); // Reuse existing function to create/make sure the group exists
        } catch (const H5::Exception& e) {
            std::cerr << "Failed to initialize group: " << path << "\n";
        }
    }
}

/*
 * Save the Simulation Configuration to the h5 Dataset
 */
void save_config() {
    std::ifstream config_file(config_file_name);
    if (!config_file.is_open()) {
        std::cerr << "Failed to open Sim_Config.json\n";
        return;
    }

    json config;
    config_file >> config;

    auto sim = config["simulation"];
    auto ctrl = config["controller_parameters"];

    std::vector<double> t(sim["NofSteps"]);
    for (int i = 0; i < sim["NofSteps"]; ++i) {
        t[i] = i * sim["dt"];
    }

    H5File file(h5file_name, H5F_ACC_RDWR);

    Group sim_group = init_dataset(file, "/Simulation_Parameters");
    sim_group.createAttribute("dt", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &sim["dt"]);
    sim_group.createAttribute("simTime", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &sim["simTime"]);
    sim_group.createAttribute("NofSteps", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &sim["NofSteps"]);
    sim_group.createDataSet("t", PredType::NATIVE_DOUBLE, space).write(t.data(), PredType::NATIVE_DOUBLE);


    Group ctrl_group = init_dataset(file, "/Controller_Parameters");
    ctrl_group.createAttribute("SAS_Enabled", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl["SAS_Enabled"]);
    ctrl_group.createAttribute("AutoPilot_Enabled", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl["AutoPilot_Enabled"]);
    ctrl_group.createAttribute("Abs_values_flag", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl["Abs_values_flag"]);

}



/*
 * Save the used Inputs (AutoPilot and Pilot) to the h5 dataset
 */
void save_inputs(const std::vector<AutoPilot_Controls>& ap_vec, const std::vector<Pilot_Controls>& pc_vec) {
    H5File file(h5file_name, H5F_ACC_RDWR);
    const hsize_t N = ap_vec.size();
    hsize_t dims[2] = {N, 1};
    DataSpace space(2, dims);

    // Extract field vectors for AutoPilot_Controls
    std::vector<double> GS_x(N), GS_y(N), VS(N), Heading(N);
    for (size_t i = 0; i < N; ++i) {
        GS_x[i] = ap_vec[i].GS_x;
        GS_y[i] = ap_vec[i].GS_y;
        VS[i]   = ap_vec[i].VS;
        Heading[i] = ap_vec[i].Heading;
    }

    // Save AutoPilot inputs
    auto ap_group = init_dataset(file, "/Inputs/Auto_Pilot");
    ap_group.createDataSet("GS_x",    PredType::NATIVE_DOUBLE, space).write(GS_x.data(), PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("GS_y",    PredType::NATIVE_DOUBLE, space).write(GS_y.data(), PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("VS",      PredType::NATIVE_DOUBLE, space).write(VS.data(),   PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("Heading", PredType::NATIVE_DOUBLE, space).write(Heading.data(), PredType::NATIVE_DOUBLE);

    // Extract field vectors for Pilot_Controls
    std::vector<double> delta_long(N), delta_lat(N), delta_coll(N), delta_ped(N);
    for (size_t i = 0; i < N; ++i) {
        delta_long[i] = pc_vec[i].delta_long;
        delta_lat[i]  = pc_vec[i].delta_lat;
        delta_coll[i] = pc_vec[i].delta_coll;
        delta_ped[i]  = pc_vec[i].delta_ped;
    }

    // Save Pilot inputs
    auto pc_group = init_dataset(file, "/Inputs/Pilot_Controls");
    pc_group.createDataSet("delta_long", PredType::NATIVE_DOUBLE, space).write(delta_long.data(), PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_lat",  PredType::NATIVE_DOUBLE, space).write(delta_lat.data(),  PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_coll", PredType::NATIVE_DOUBLE, space).write(delta_coll.data(), PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_ped",  PredType::NATIVE_DOUBLE, space).write(delta_ped.data(),  PredType::NATIVE_DOUBLE);
}




// Helper: Append a single value to a dataset
void appendToDataset(H5::Group& group, const std::string& name, double value) {
    H5::DataSet dataset;
    H5::DataSpace space;
    hsize_t size[1];

    try {
        dataset = group.openDataSet(name);
        space = dataset.getSpace();
        space.getSimpleExtentDims(size);
        size[0]++;
        dataset.extend(size);
    } catch (...) {
        hsize_t init_size[1] = {0}, max_size[1] = {H5S_UNLIMITED};
        hsize_t chunk[1] = {100};
        DataSpace newspace(1, init_size, max_size);
        DSetCreatPropList plist;
        plist.setChunk(1, chunk);
        dataset = group.createDataSet(name, PredType::NATIVE_DOUBLE, newspace, plist);
        size[0] = 1;
        dataset.extend(size);
    }

    H5::DataSpace filespace = dataset.getSpace();
    hsize_t offset[1] = { size[0] - 1 }, count[1] = { 1 };
    filespace.selectHyperslab(H5S_SELECT_SET, count, offset);
    DataSpace memspace(1, count);
    dataset.write(&value, PredType::NATIVE_DOUBLE, memspace, filespace);
}



/*
 * Save the Model Output of the current timestep to the h5 dataset
 */
void save_timestep(int step, const AngularRates& ang_rat, const Attitudes& att, const Velocities_B& vel, const Pilot_Controls& control_eff) {
    H5File file(h5file_name, H5F_ACC_RDWR);
    auto angular_rates = init_dataset(file, "/Responses/AngularRates");
    auto attitude = init_dataset(file, "/Responses/Attitudes");
    auto velocity = init_dataset(file, "/Responses/Velocities");
    auto control_efforts = init_dataset(file, "/Responses/Control_Efforts");

    appendToDataset(angular_rates, "p", ang_rat.p);
    appendToDataset(angular_rates, "q", ang_rat.q);
    appendToDataset(angular_rates, "r", ang_rat.r);

    appendToDataset(attitude, "roll", att.phi);
    appendToDataset(attitude, "pitch", att.theta);
    appendToDataset(attitude, "yaw", att.psi);

    appendToDataset(velocity, "u", vel.u);
    appendToDataset(velocity, "v", vel.v);
    appendToDataset(velocity, "w", vel.w);

    appendToDataset(control_efforts, "delta_long", control_eff.delta_long);
    appendToDataset(control_efforts, "delta_lat", control_eff.delta_lat);
    appendToDataset(control_efforts, "delta_coll", control_eff.delta_coll);
    appendToDataset(control_efforts, "delta_ped", control_eff.delta_ped);
}