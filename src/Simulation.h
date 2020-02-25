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
    void run_single_simulation(RobotAlgorithm alg, House& h);
};




#endif //ROBOT_SIMULATION_H
