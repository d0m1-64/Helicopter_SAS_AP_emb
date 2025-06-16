#include <H5Cpp.h>
#include <iostream>
#include <vector>
#include <string>

using namespace H5;

const std::string FILE_NAME = "/mnt/data/Dataset_20250615_1824.h5";

// Structs
struct SimulationParameters {
    double dt;
    double simTime;
    double NofSteps[2];  // 1x2 array
    std::vector<double> t;
};

struct ControllerParameters {
    double SAS_Enabled;
    double AutoPilot_Enabled;
    double Abs_values_flag;
    double beauford;
};

struct AutoPilotInputs {
    std::vector<double> GS_x, GS_y, VS, psi;
};

struct PilotControls {
    std::vector<double> delta_coll, delta_lat, delta_long, delta_ped;
};

// Init and return dataset group
H5::Group init_dataset(H5::H5File& file, const std::string& path) {
    std::string token;
    H5::Group group = file.openGroup("/");
    size_t pos = 0, next;
    while ((next = path.find('/', pos)) != std::string::npos) {
        token = path.substr(pos, next - pos);
        pos = next + 1;
        if (token.empty()) continue;
        try { group = group.openGroup(token); }
        catch (...) { group = group.createGroup(token); }
    }
    token = path.substr(pos);
    try { return group.openGroup(token); }
    catch (...) { return group.createGroup(token); }
}

// Save simulation and controller attributes
void save_config(const SimulationParameters& sim, const ControllerParameters& ctrl) {
    H5File file(FILE_NAME, H5F_ACC_RDWR);

    // Simulation
    Group sim_group = init_dataset(file, "/Simulation_Parameters");
    sim_group.createAttribute("dt", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &sim.dt);
    sim_group.createAttribute("simTime", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &sim.simTime);
    hsize_t dims2[1] = {2};
    DataSpace ds2(1, dims2);
    sim_group.createAttribute("NofSteps", PredType::NATIVE_DOUBLE, ds2).write(PredType::NATIVE_DOUBLE, sim.NofSteps);

    // Dataset 't'
    hsize_t t_dims[2] = {1, sim.t.size()};
    DataSpace t_space(2, t_dims);
    sim_group.createDataSet("t", PredType::NATIVE_DOUBLE, t_space).write(sim.t.data(), PredType::NATIVE_DOUBLE);

    // Controller
    Group ctrl_group = init_dataset(file, "/Controller_Parameters");
    ctrl_group.createAttribute("SAS_Enabled", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl.SAS_Enabled);
    ctrl_group.createAttribute("AutoPilot_Enabled", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl.AutoPilot_Enabled);
    ctrl_group.createAttribute("Abs_values_flag", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl.Abs_values_flag);
    ctrl_group.createAttribute("beauford", PredType::NATIVE_DOUBLE, DataSpace(H5S_SCALAR)).write(PredType::NATIVE_DOUBLE, &ctrl.beauford);
}

// Save AutoPilot and PilotControl inputs
void save_inputs(const AutoPilotInputs& ap, const PilotControls& pc) {
    H5File file(FILE_NAME, H5F_ACC_RDWR);
    hsize_t dims[2] = {601, 1};
    DataSpace space(2, dims);

    auto ap_group = init_dataset(file, "/Inputs/Auto_Pilot");
    ap_group.createDataSet("GS_x", PredType::NATIVE_DOUBLE, space).write(ap.GS_x.data(), PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("GS_y", PredType::NATIVE_DOUBLE, space).write(ap.GS_y.data(), PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("VS",   PredType::NATIVE_DOUBLE, space).write(ap.VS.data(), PredType::NATIVE_DOUBLE);
    ap_group.createDataSet("psi",  PredType::NATIVE_DOUBLE, space).write(ap.psi.data(), PredType::NATIVE_DOUBLE);

    auto pc_group = init_dataset(file, "/Inputs/Pilot_Controls");
    pc_group.createDataSet("delta_coll", PredType::NATIVE_DOUBLE, space).write(pc.delta_coll.data(), PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_lat",  PredType::NATIVE_DOUBLE, space).write(pc.delta_lat.data(), PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_long", PredType::NATIVE_DOUBLE, space).write(pc.delta_long.data(), PredType::NATIVE_DOUBLE);
    pc_group.createDataSet("delta_ped",  PredType::NATIVE_DOUBLE, space).write(pc.delta_ped.data(), PredType::NATIVE_DOUBLE);
}

// Append helper
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

// Save timestep to '/Responses'
void save_timestep(double lat, double lon, double alt,
                   double roll, double pitch, double yaw,
                   double u, double v, double w) {
    H5File file(FILE_NAME, H5F_ACC_RDWR);
    auto pos = init_dataset(file, "/Responses/WSG84Position");
    auto att = init_dataset(file, "/Responses/Attitudes");
    auto vel = init_dataset(file, "/Responses/Velocities");

    appendToDataset(pos, "latitude", lat);
    appendToDataset(pos, "longitude", lon);
    appendToDataset(pos, "altitude", alt);

    appendToDataset(att, "roll", roll);
    appendToDataset(att, "pitch", pitch);
    appendToDataset(att, "yaw", yaw);

    appendToDataset(vel, "u", u);
    appendToDataset(vel, "v", v);
    appendToDataset(vel, "w", w);
}
