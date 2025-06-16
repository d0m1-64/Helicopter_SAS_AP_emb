#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "FlightClient.h"
#include <nlohmann/json.hpp>
#include <grpcpp/grpcpp.h>
#include "flightmodel.grpc.pb.h"
#include "Full_Controller.h"
#include "Datatypes.h"

using json = nlohmann::json;


/*
 * Main Simulation Function
 */
int main() {
    // 0. Read Sim_Config.json and Init h5 Dataset
    std::ifstream file("Sim_Config.json");
    json sim_config;
    file >> sim_config;

    std::string hel_sim_address = sim_config["simulation"]["Hel_Sim_Adress"];
    double sim_time = sim_config["simulation"]["simTime"];
    double dt = sim_config["simulation"]["dt"];
    NofSteps = sim_time / dt;

    init_dataset();
    save_config();

    // 1. gRPC client
    FlightModelClient client(grpc::CreateChannel(hel_sim_address, grpc::InsecureChannelCredentials()));

    // 2. Controller instance
    Full_Controller controller;
    controller.initialize();

    // 3. Form inputs
    auto [pilot_controls, autopilot_controls] = testing_procedures();
    save_inputs(autopilot_controls, pilot_controls);

    // 4. Initial States
    // ToDo: Define initial states

    // 5. Run the Simulation Loop
    for (int step = 0; step < NofSteps; step++) {

        // 5.1. Step the controller
        // ToDo: fix references
        controller.step(pilot_controls.delta_long, &delta_lat, &delta_coll, &delta_ped,
                        &ref_x, &ref_y, &ref_vs, &ref_psi,
                        &wind_x, &wind_y, &wind_z,
                        &ap_enabled, &sas_enabled,
                        &u, &w, &q, &theta,
                        &v, &p, &phi, &r,
                        &output_delt, &output_de_g, &output_de_c, &output_de_e);

        // 5.2. Create gRPC message from controller outputs
        auto control_msg = CreateControlMessage(output_de_c, output_de_g, output_delt, output_de_e);

        // 5.3. Call gRPC
        FlightModelOutput result = client.StepSimulation(control_msg);

        // 5.4. Update local Helicopter State
        // ToDo

        // 5.5. Save Outputs
        // ToDo
        save_timestep();

        // 5.6. Log Simulation Progress
        std::cout << "Step " << step << " of " << NofSteps << " complete\n";
    }

    // 6. Terminate controller and gRPC connection
    controller.terminate();

    // 7. Plot results
    //Plotting_Routine();


    return 0;
}
