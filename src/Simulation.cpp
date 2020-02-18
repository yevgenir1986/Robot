//
// Created by jeka on 2/18/20.
//

#include "Simulation.h"

void Simulation::run_simulation()
{
    for (auto algo: _algos)
        for (auto house: _houses)
            run_single_simulation(algo, house);
}

void Simulation::run_single_simulation(RobotAlgorithm alg, const House& h)
{
    bool finished = false;
    Direction lastMove = Direction::STAY;



    while (!finished)
    {
        lastMove = alg.nextStep(lastMove, finished);
    }

    //TODO: calculate score
}
