#include<vector>
#include "Datatypes.h"

/*
 * This function converts the received proto messages from the
 * Helicopter model to the usual structs
 */
void convertOwnshipPositionExtended(
    const OwnshipPosition& ownshipPos,
    AngularRates& angularRates,
    Attitudes& attitudes,
    Velocities_B& velocities_B,
    std::vector<double>& x
){

    // Convert angular rates
    auto angularRatesMsg = ownshipPos.angularRates();
    angularRates.p = angularRatesMsg.roll();
    angularRates.q = angularRatesMsg.pitch();
    angularRates.r = angularRatesMsg.yaw();

    // Convert attitudes
    Attitudes attitudesMsg = ownshipPos.attitudes();
    attitudes.phi = attitudesMsg.roll();
    attitudes.theta = attitudesMsg.pitch();
    attitudes.psi = attitudesMsg.yaw();

    // Convert velocities
    Velocities_B velocitiesMsg = ownshipPos.velocitiesAir();
    velocities_B.u = velocitiesMsg.u();
    velocities_B.v = velocitiesMsg.v();
    velocities_B.w = velocitiesMsg.w();

    // Form new State vector
    x = {
        velocities_B.u,
        velocities_B.w,
        angularRates.q,
        attitudes.theta,
        velocities_B.v,
        angularRates.p,
        attitudes.phi,
        angularRates.r
    };

}