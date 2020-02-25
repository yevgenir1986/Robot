//
// Created by jeka on 2/18/20.
//

#ifndef ROBOT_ROBOTALGORITHM_H
#define ROBOT_ROBOTALGORITHM_H

#include <stdint.h>
#include <map>
#include "common.h"
#include <iostream>
#include "Sensors.h"

class RobotAlgorithm {
public:
    template<typename RobotRep>
    void init(RobotRep &robot, std::map<std::string, int> config)
    {
        if (config.find("MAX_STEPS") != config.end())
        {
            _max_steps = config["MAX_STEPS"];
        }
        std::cout << "init new robot with max_steps: " << _max_steps << std::endl;
        _wall_sensor = robot.getWallSensor();
        _dirt_sensor = robot.getDirtSensor();
        _battery_sensor = robot.getBatterySensor();
    }
    virtual Direction nextStep(Direction lastMove, bool& finish);
    virtual const std::string& getName() const { return name;}
    virtual const std::string& getDescription() const { return description;}

protected:
    int _max_steps = 0;
    WallSensor _wall_sensor;
    DirtSensor _dirt_sensor;
    BatterySensor _battery_sensor;
    const std::string name = "Our Robot";
    const std::string description = "This is the greatest robot ever";
};

#endif //ROBOT_ROBOTALGORITHM_H
