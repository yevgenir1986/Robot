//
// Created by jeka on 2/18/20.
//

#ifndef ROBOT_SIMULATION_H
#define ROBOT_SIMULATION_H

#include <vector>
#include "RobotAlgorithm.h"
#include "Sensors.h"

class Simulation {
private:
    std::vector <RobotAlgorithm> _algos;
    std::vector <House> _houses;

public:
    void run_simulation();
    void run_single_simulation(RobotAlgorithm alg, const House& h);
};

class SimulationRobotRep
{
    SimulationRobotRep(const House& h): _ws(h), _ds(h), _bs(h.max_steps()) {};
    const WallSensor& getWallSensor() const;
    const DirtSensor& getDirtSensor() const;
    const BatterySensor& getBatterySensor() const;

private:
    SimWallSensor _ws;
    SimDirtSensor _ds;
    SimBatterySensor _bs;
};


#endif //ROBOT_SIMULATION_H
