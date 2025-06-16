#include "FlightClient.h"
#include <iostream>
#include <chrono>

/*
 * Constructor
 */
FlightModelClient::FlightModelClient(std::shared_ptr<Channel> channel)
    : stub_(FlightModel::NewStub(channel)) {}

/*
 * Call Simulation Server
 */
FlightModelOutput FlightModelClient::StepSimulation(const PrimaryControlOutput& controls) {
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

/*
 * Create gRPC control message
 */
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
