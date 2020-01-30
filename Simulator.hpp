//  ---------------------------------------------------------------------------
//  Header file for all Simulator programs.                       Simulator.hpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 24th, 2018
// ----------------------------------------------------------------------------
#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#define ONE 1
#define ZERO 0

#include "tools.hpp" // includes all the other headers you need.
#include "Population.hpp"

class Simulator {
private:
	// ------------------------------------------------------------------------
	Population* simPop;
	int simNumRounds;
	double simProbExtend;
	int simMaxRounds;
	int uRandom( int n );

public:
	// ------------------------------------------------------------------------
	Simulator( Population& pop, double probExtend, int maxRounds ) : 
	 simPop(&pop), simNumRounds(ZERO), simProbExtend(probExtend), 
	 simMaxRounds(maxRounds)  {}
	~Simulator() =default;
	// ------------------------------------------------------------------------
	void run();
	int numRounds() const{ return simNumRounds; }
};
#endif	// SIMULATOR_HPP


