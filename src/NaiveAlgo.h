//
// Created by jeka on 2/24/20.
//
#include "RobotAlgorithm.h"

#ifndef ROBOT_NAIVEROBOT_H
#define ROBOT_NAIVEROBOT_H

const std::string name = "NaiveAlgo";
const std::string description = "This is the greatest robot ever";


class NaiveAlgo: public RobotAlgorithm
{
public:
    virtual Direction nextStep(Direction lastMove, bool& finish)
    {
//        if (_dirt_sensor.isDirty())
//        {
//
//        }
        return Direction::UP;
    }
    virtual const std::string& getName() const { return name;}
    virtual const std::string& getDescription() const { return description; }

};

#endif //ROBOT_NAIVEROBOT_H
