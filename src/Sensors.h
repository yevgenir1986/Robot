//
// Created by jeka on 2/18/20.
//

#ifndef ROBOT_SENSORS_H
#define ROBOT_SENSORS_H

#include "common.h"
#include "House.h"

class WallSensor {
    bool isWall(Direction d) const;
};

class DirtSensor {
    bool isDirty() const;
};

class BatterySensor {
    int stepsLeft() const;
};


class SimWallSensor: public WallSensor
{
public:
   SimWallSensor(const House& h): _house(h) {};
   bool isWall(Direction d) const {
        return _house.isWall();
   }
private:
    House _house;
};

class SimDirtSensor: public DirtSensor
{
public:
    SimDirtSensor(const House& h): _house(h) {};
    bool isDirty() const {
        return _house.isDirty();
    }
private:
    House _house;
};

class SimBatterySensor: public BatterySensor
{
public:
    SimBatterySensor(int maxSteps): _batteryCapacity(BATTERY_CAPACITY),
                        _batteryConsumptionRate(BATTERY_CONSUMPTION_RATE),
                        _batteryRechargeRate(BATTERY_RECHARGE_RATE),
                        _maxSteps(maxSteps)

    {
        _stepsLeft = _batteryCapacity / _batteryConsumptionRate;
        if (_stepsLeft > _maxSteps)
            _stepsLeft = _maxSteps;
    };
    int stepsLeft() const {
        return _stepsLeft;
    }
    void step(){
        _stepsLeft -= _batteryConsumptionRate;
    }
    void charge(){
        _stepsLeft += _batteryRechargeRate;
    }
private:
    int _stepsLeft;
    int _batteryCapacity;
    int _batteryConsumptionRate;
    int _batteryRechargeRate;
    int _maxSteps;
};

#endif //ROBOT_SENSORS_H
