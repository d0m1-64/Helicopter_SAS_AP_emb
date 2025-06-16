
#ifndef DATATYPES_H
#define DATATYPES_H

#include <vector>

struct Attitudes {
    double phi;
    double theta;
    double psi;
};

struct AngularRates {
    double p;
    double q;
    double r;
};

struct WSG84Position {
    double latitude;
    double longitude;
    double altitude;
};

struct Velocities_B {
    double u;
    double v;
    double w;
};

struct Velocities_abs {
    double GroundSpeed;
    double TrueAirspeed;
    double indicatedAirspeed;
};

struct Accelerations {
    double a_x;
    double a_y;
    double a_z;
};

#endif //DATATYPES_H
