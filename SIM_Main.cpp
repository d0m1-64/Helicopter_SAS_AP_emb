#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <ctime>

#include <grpcpp/grpcpp.h>
#include "flightmodel.grpc.pb.h"
#include "Full_Controller.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using flightmodel::FlightModel;
using flightmodel::FlightModelInput;
using flightmodel::FlightModelOutput;
using flightmodel::PrimaryControlOutput;

class FlightModelClient {
public:
    FlightModelClient(std::shared_ptr<Channel> channel)
        : stub_(FlightModel::NewStub(channel)) {}

    FlightModelOutput StepSimulation(const PrimaryControlOutput& controls) {
        FlightModelInput request;
        *request.mutable_primarycontrolinput() = controls;

        FlightModelOutput reply;
        ClientContext context;

        Status status = stub_->ExecuteSingleTimeStep(&context, request, &reply);

        if (!status.ok()) {
            std::cerr << "gRPC call failed: " << status.error_message() << std::endl;
        }

        return reply;
    }

private:
    std::unique_ptr<FlightModel::Stub> stub_;
};

PrimaryControlOutput CreateControlMessage(double coll, double lat, double lon, double ped) {
    PrimaryControlOutput control_msg;
    auto* now = new google::protobuf::Timestamp();
    auto now_time = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now_time.time_since_epoch()).count();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time.time_since_epoch()).count() % 1000000000;

    now->set_seconds(seconds);
    now->set_nanos(nanos);
    control_msg.set_allocated_timestamp(now);

    control_msg.set_collective(coll);
    control_msg.set_cyclic_lat(lat);
    control_msg.set_cyclic_lon(lon);
    control_msg.set_pedals(ped);

    return control_msg;
}

int main() {
    // 1. gRPC client
    FlightModelClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    // 2. Controller instance
    Full_Controller controller;
    controller.initialize();

    // 3. Form inputs



    for (int step = 0; step < 1000; ++step) {
        // 4. Step the controller
        controller.step(&delta_long, &delta_lat, &delta_coll, &delta_ped,
                        &ref_x, &ref_y, &ref_vs, &ref_psi,
                        &wind_x, &wind_y, &wind_z,
                        &ap_enabled, &sas_enabled,
                        &u, &w, &q, &theta,
                        &v, &p, &phi, &r,
                        &output_delt, &output_de_g, &output_de_c, &output_de_e);

        // 5. Create gRPC message from controller outputs
        auto control_msg = CreateControlMessage(output_de_c, output_de_g, output_delt, output_de_e);

        // 6. Call gRPC
        FlightModelOutput result = client.StepSimulation(control_msg);

        // 7. Optionally process result for next timestep inputs
        // Example: update 'u', 'v', etc. from `result.ownshippage.velocities().u()` etc.

        std::cout << "Step " << step << " complete\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60Hz
    }

    controller.terminate();
    return 0;
}
