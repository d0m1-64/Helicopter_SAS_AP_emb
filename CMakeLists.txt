cmake_minimum_required(VERSION 3.31)
project(Helicopter_SAS_AP_emb)

set(CMAKE_CXX_STANDARD 20)

add_executable(Helicopter_SAS_AP_emb SIM_Main.cpp
        Saving_Routine.cpp
        Datatypes.h
        FlightModelClient.cpp
        FlightModelClient.h
)
