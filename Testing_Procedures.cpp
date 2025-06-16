#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <nlohmann/json.hpp>
#include "Datatypes.h"

using json = nlohmann::json;



/*
 * Test 0: No Input
*/
std::vector<double> test_0(int N) {
    return std::vector<double>(N, 0.0);
}



/*
 * Test 1: Step Input
*/
std::vector<double> test_1(int N, double dt, double start_time, double amplitude) {
    std::vector<double> input(N, 0.0);
    int start_idx = static_cast<int>(start_time / dt);
    for (int i = start_idx; i < N; ++i) input[i] = amplitude;
    return input;
}



/*
 * Test 2: Rectangle Input
*/
std::vector<double> test_2(int N, double dt, double start_time, double duration, double amplitude) {
    std::vector<double> input(N, 0.0);
    int start_idx = static_cast<int>(start_time / dt);
    int end_idx = static_cast<int>((start_time + duration) / dt);
    for (int i = start_idx; i <= end_idx && i < N; ++i) input[i] = amplitude;
    return input;
}



/*
 * Test 3: Doublet
*/
std::vector<double> test_3(int N, double dt, double start_time, double duration, double amplitude) {
    std::vector<double> input(N, 0.0);
    int up_start = static_cast<int>(start_time / dt);
    int dur = static_cast<int>(duration / dt);
    int gap = static_cast<int>(1.0 / dt);
    int down_start = up_start + dur + gap;

    for (int i = up_start; i < up_start + dur && i < N; ++i) input[i] = amplitude;
    for (int i = down_start; i < down_start + dur && i < N; ++i) input[i] = -amplitude;
    return input;
}



/*
 * Test 4: 3211
*/
std::vector<double> test_4(int N, double dt, double start_time, double amplitude, double unit_duration) {
    std::vector<double> input(N, 0.0);
    std::vector<double> pattern = {1, -1, 1, -1};
    std::vector<double> durations = {3, 2, 1, 1};
    double current_time = start_time;

    for (size_t i = 0; i < pattern.size(); ++i) {
        int start_idx = static_cast<int>(current_time / dt);
        int end_idx = static_cast<int>((current_time + durations[i] * unit_duration) / dt);
        for (int j = start_idx; j < end_idx && j < N; ++j)
            input[j] = pattern[i] * amplitude;
        current_time += durations[i] * unit_duration;
    }
    return input;
}



/*
 * Test 5: 2311
*/
std::vector<double> test_5(int N, double dt, double start_time, double amplitude, double unit_duration) {
    std::vector<double> input(N, 0.0);
    std::vector<double> pattern = {1, -1, 1, -1};
    std::vector<double> durations = {2, 3, 1, 1};
    double current_time = start_time;

    for (size_t i = 0; i < pattern.size(); ++i) {
        int start_idx = static_cast<int>(current_time / dt);
        int end_idx = static_cast<int>((current_time + durations[i] * unit_duration) / dt);
        for (int j = start_idx; j < end_idx && j < N; ++j)
            input[j] = pattern[i] * amplitude;
        current_time += durations[i] * unit_duration;
    }
    return input;
}



/*
 * Test 6: Sine Sweep
*/
std::vector<double> test_6(int N, double dt, double start_time, double amplitude, double unit_duration) {
    std::vector<double> input(N, 0.0);

    double sweepStart = start_time;
    double sweepEnd = sweepStart + 5 * unit_duration;
    double T = sweepEnd - sweepStart;

    double C1 = 4.0;
    double C2 = 0.0187;
    double w_min = 0.3;
    double w_max = 12.0;

    int start_idx = static_cast<int>(sweepStart / dt);
    int end_idx = static_cast<int>(sweepEnd / dt);
    double theta = 0.0;

    for (int i = start_idx; i <= end_idx && i < N; ++i) {
        double t_now = (i - start_idx) * dt;
        double t_norm = t_now / T;
        double K = C2 * (std::exp(C1 * t_norm) - 1.0);
        double omega_t = w_min + K * (w_max - w_min);
        theta += omega_t * dt;
        input[i] = amplitude * std::sin(theta);
    }
    return input;
}




/*
 * Main Testing Procedures selecting function
*/
std::pair<std::vector<Pilot_Controls>, std::vector<AutoPilot_Controls>> testing_procedures() {


    /*
     * Parsing information from the Config File
     */
    std::ifstream file("Sim_Config.json");
    if (!file.is_open()) throw std::runtime_error("Cannot open Sim_Config.json");

    json cfg;
    file >> cfg;

    double simTime = cfg["simulation"]["simTime"];
    double dt = cfg["simulation"]["dt"];
    int N = static_cast<int>(simTime / dt);

    int test_Nr = cfg["input_configuration"]["test_Nr"];
    int input_idx = cfg["input_configuration"]["input_idx"];
    double unit_amplitude = cfg["input_configuration"]["unit_amplitude"];
    double unit_duration = cfg["input_configuration"]["unit_duration"];
    double start_time = cfg["input_configuration"]["start_time"];
    bool AutoPilot_Enabled = cfg["controller_parameters"]["AutoPilot_Enabled"];


    /*
    * Generating the wanted input signal
    */
    std::vector<double> signal;

    switch (test_Nr) {
        case 0: signal = test_0(N); break;
        case 1: signal = test_1(N, dt, start_time, unit_amplitude); break;
        case 2: signal = test_2(N, dt, start_time, unit_duration, unit_amplitude); break;
        case 3: signal = test_3(N, dt, start_time, unit_duration, unit_amplitude); break;
        case 4: signal = test_4(N, dt, start_time, unit_amplitude, unit_duration); break;
        case 5: signal = test_5(N, dt, start_time, unit_amplitude, unit_duration); break;
        case 6: signal = test_6(N, dt, start_time, unit_amplitude, unit_duration); break;
        default: throw std::runtime_error("Unknown test number");
    }


    /*
    * Forming the complete inputs and assigning the generated signal to the correct channel
    */
    std::vector<Pilot_Controls> pilot(N);
    std::vector<AutoPilot_Controls> autoPilot(N);

    for (int i = 0; i < N; ++i) {
        if (AutoPilot_Enabled) {
            switch (input_idx) {
                case 1: autoPilot[i].GS_x = signal[i]; break;
                case 2: autoPilot[i].GS_y = signal[i]; break;
                case 3: autoPilot[i].VS = signal[i]; break;
                case 4: autoPilot[i].Heading = signal[i]; break;
            }
        } else {
            switch (input_idx) {
                case 1: pilot[i].delta_long = signal[i]; break;
                case 2: pilot[i].delta_lat = signal[i]; break;
                case 3: pilot[i].delta_coll = signal[i]; break;
                case 4: pilot[i].delta_ped = signal[i]; break;
            }
        }
    }

    return {pilot, autoPilot};
}
