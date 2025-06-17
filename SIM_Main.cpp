#include <iostream>
#include <chrono>
#include <fstream>

#include <nlohmann/json.hpp>
#include <grpcpp/grpcpp.h>
#include "flightmodel.grpc.pb.h"

#include "Full_Controller/Full_Controller.h"
#include "FlightModelClient.h"
#include "Saving_Routine.cpp"
#include "Testing_Procedures.cpp"
#include "Converters.cpp"
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
    int NofSteps = sim_time / dt;
    bool AutoPilot_Enabled = sim_config["controller_parameters"]["AutoPilot_Enabled"];
    bool SAS_Enabled = sim_config["controller_parameters"]["SAS_Enabled"];

    init_dataset();
    save_config();


    // 1. gRPC client
    FlightModelClient client(grpc::CreateChannel(hel_sim_address, grpc::InsecureChannelCredentials()));


    // 2. Controller instance
    Full_Controller controller;


    // 3. Form inputs
    auto [Pilot_Cntrls, AP_Cntrls] = testing_procedures();
    save_inputs(AP_Cntrls, Pilot_Cntrls);


    // 4. Initial States
    Windspeed wind = {0.0, 0.0, 0.0}; // could be f(t) in future
    State_vector x = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Pilot_Controls curr_cntrl_eff = { 0.0, 0.0, 0.0, 0.0};


    // 5. Run the Simulation Loop
    for (int step = 0; step < NofSteps; step++) {


        // 5.1. Step the controller
        controller.step(&Pilot_Cntrls[step].delta_long, &Pilot_Cntrls[step].delta_lat, &Pilot_Cntrls[step].delta_coll, &Pilot_Cntrls[step].delta_ped,
                        &AP_Cntrls[step].GS_x, &AP_Cntrls[step].GS_y, &AP_Cntrls[step].VS, &AP_Cntrls[step].Heading,
                        &wind.Wind_x_B, &wind.Wind_y_B, &wind.Wind_z_B,
                        &AutoPilot_Enabled, &SAS_Enabled,
                        &x.u, &x.w, &x.q, &x.theta,
                        &x.v, &x.p, &x.phi, &x.r,
                        &curr_cntrl_eff.delta_long, &curr_cntrl_eff.delta_lat, &curr_cntrl_eff.delta_coll, &curr_cntrl_eff.delta_ped);


        // 5.2. Create gRPC message from controller outputs
        auto control_msg = CreateControlMessage(curr_cntrl_eff.delta_long, curr_cntrl_eff.delta_lat, curr_cntrl_eff.delta_coll, curr_cntrl_eff.delta_ped);


        // 5.3. Step the Helicopter Model
        FlightModelOutput result = client.StepSimulation(control_msg);


        // 5.4. Update local Helicopter State
        AngularRates angularRates; Attitudes attitudes; Velocities_B velocities_B;
        convertOwnshipPositionExtended(result().ownshipPosition(), angularRates, attitudes, velocities_B, x);


        // 5.5. Save Outputs
        save_timestep(step, angularRates, attitudes, velocities_B, curr_cntrl_eff);


        // 5.6. Log Simulation Progress
        printf("Step %d of %d complete\n", step, NofSteps);
    }

    return 0;
}
