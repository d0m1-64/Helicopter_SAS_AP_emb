
#ifndef DATATYPES_H
#define DATATYPES_H


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

struct AutoPilot_Controls {
    double GS_x;
    double GS_y;
    double VS;
    double Heading;
};

struct Pilot_Controls {
    double delta_long;
    double delta_lat;
    double delta_coll;
    double delta_ped;
};

struct Windspeed {
    double Wind_x_B;
    double Wind_y_B;
    double Wind_z_B;
};

struct State_vector {
    double u;
    double w;
    double q;
    double theta;
    double v;
    double p;
    double phi;
    double r;
};

#endif //DATATYPES_H
