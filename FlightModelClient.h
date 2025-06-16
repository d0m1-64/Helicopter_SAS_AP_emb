#ifndef FLIGHT_MODEL_CLIENT_H
#define FLIGHT_MODEL_CLIENT_H

#include <memory>
#include <grpcpp/grpcpp.h>
#include "flightmodel.grpc.pb.h"
#include "google/protobuf/timestamp.pb.h"

// Use specific namespaces to avoid polluting the global namespace
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using flightmodel::FlightModel;
using flightmodel::PrimaryControlOutput;
using flightmodel::FlightModelOutput;

// Creates a PrimaryControlOutput message with timestamp and control values.
PrimaryControlOutput CreateControlMessage(double coll, double lat, double lon, double ped);

/**
 * A simple gRPC client for interacting with the FlightModel simulation.
 */
class FlightModelClient {
public:
    explicit FlightModelClient(std::shared_ptr<Channel> channel);

    FlightModelOutput StepSimulation(const PrimaryControlOutput& controls);

private:
    std::unique_ptr<FlightModel::Stub> stub_;
};

#endif // FLIGHT_MODEL_CLIENT_H
