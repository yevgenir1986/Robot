#include <iostream>
#include "Simulation.h"

#include "NaiveAlgo.h"
#include "SimulationRobotRep.h"

int main() {
	std::cout << "Hello World!" << std::endl;
    House h("/home/jeka/Dev/Robot/h1.txt");
	std::cout << "total: " << h.total_dirt_level() << std::endl;
	h.print();


	Simulation s;
    SimulationRobotRep robot_rep(h);
    NaiveAlgo alg;
    std::map<std::string, int> config;
    config["MAX_STEPS"] = h.max_steps();
	alg.init(robot_rep, config);
	s.run_single_simulation(alg, h);
	std::cout << "bye bye" << std::endl;

	//std::cin.get();
}