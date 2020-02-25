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

void Simulation::run_single_simulation(RobotAlgorithm alg, House& h)
{
    bool finished = false;
    size_t steps_left = h.max_steps();
    Direction lastMove = Direction::STAY;

    while (!finished && steps_left > 0)
    {
        --steps_left;
        lastMove = alg.nextStep(lastMove, finished);
        if (finished)
        {
            break;
        }
        h.move(lastMove);
    }

    //TODO: calculate score
    std::cout << "Total dirt left: " << h.total_dirt_level() << std::endl;
    h.print();
}
