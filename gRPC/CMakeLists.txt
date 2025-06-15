cmake_minimum_required(VERSION 3.22)
project(SIMNEW_protos VERSION 0.1.0)

find_package(Protobuf CONFIG)
find_package(gRPC CONFIG)

if (Protobuf_FOUND AND gRPC_FOUND)
    message("FOUND protobuf and grpc.")
    set(PROTO_FILES
            flightmodel.proto
    )

    add_library(protos ${PROTO_FILES})
    target_link_libraries(protos
            PUBLIC
            protobuf::libprotobuf
            gRPC::grpc
            gRPC::grpc++_reflection
            gRPC::grpc++
    )

    target_include_directories(protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

    get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)

    protobuf_generate(TARGET protos
            LANGUAGE cpp
            IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

    protobuf_generate(TARGET protos
            LANGUAGE grpc
            GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
            PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}"
            IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
endif ()