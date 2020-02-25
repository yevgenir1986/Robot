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
    WallSensor& getWallSensor() { return _ws; };
    DirtSensor& getDirtSensor() { return _ds; };
    BatterySensor& getBatterySensor() { return _bs; };

private:
    SimWallSensor _ws;
    SimDirtSensor _ds;
    SimBatterySensor _bs;
};

#endif //ROBOT_SIMULATIONROBOTREP_H
