//
// Created by jeka on 2/24/20.
//

#ifndef ROBOT_SIMULATIONROBOTREP_H
#define ROBOT_SIMULATIONROBOTREP_H

#include "Sensors.h"

class SimulationRobotRep
{
public:
    SimulationRobotRep(const House& h): _ws(h), _ds(h), _bs(h.max_steps()) {}
    WallSensor& getWallSensor();
    DirtSensor& getDirtSensor();
    BatterySensor& getBatterySensor();

private:
    SimWallSensor _ws;
    SimDirtSensor _ds;
    SimBatterySensor _bs;
};

#endif //ROBOT_SIMULATIONROBOTREP_H
