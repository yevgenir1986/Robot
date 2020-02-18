//
// Created by jeka on 2/18/20.
//

#ifndef ROBOT_ROBOTALGORITHM_H
#define ROBOT_ROBOTALGORITHM_H

#include <stdint.h>
#include <map>
#include "common.h"

const std::string name = "Our Robot";
const std::string description = "This is the greatest robot ever";


class RobotAlgorithm {
public:
    template<typename RobotRep>
    void init(RobotRep &robot, std::map<std::string, int> config) {
        if (config.find("MAX_STEPS") != config.end())
            _max_steps = config["MAX_STEPS"];
    }
    Direction nextStep(Direction lastMove, bool& finish);
    const std::string& getName() const { return name;}
    const std::string& getDescription() const { return description; }

private:
    int _max_steps;
};

#endif //ROBOT_ROBOTALGORITHM_H
