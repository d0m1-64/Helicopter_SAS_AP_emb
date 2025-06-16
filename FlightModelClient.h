#pragma once

#include <memory>
#include <grpcpp/grpcpp.h>
#include "flightmodel.grpc.pb.h"
#include "google/protobuf/timestamp.pb.h"

// Use specific namespaces to avoid polluting the global namespace
using grpc::Channel;
using flightmodel::FlightModel;
using flightmodel::PrimaryControlOutput;
using flightmodel::FlightModelOutput;

/**
 * Creates a PrimaryControlOutput message with timestamp and control values.
 *
 * @param coll Collective input
 * @param lat  Lateral cyclic input
 * @param lon  Longitudinal cyclic input
 * @param ped  Pedal input
 * @return A populated PrimaryControlOutput message
 */
PrimaryControlOutput CreateControlMessage(double coll, double lat, double lon, double ped);

/**
 * A simple gRPC client for interacting with the FlightModel simulation.
 */
class FlightModelClient {
public:
    explicit FlightModelClient(std::shared_ptr<Channel> channel);

    /**
     * Sends control inputs to the simulation and receives state feedback.
     *
     * @param controls The input control message to send
     * @return The simulation output/state after applying the input
     */
    FlightModelOutput StepSimulation(const PrimaryControlOutput& controls);

private:
    std::unique_ptr<FlightModel::Stub> stub_;
};
