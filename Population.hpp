//  ---------------------------------------------------------------------------
//  Header file for all Population programs.                  Population.hpp
//  Created by Bilal Abu-Ghazaleh on Friday November 2nd, 2018
// ----------------------------------------------------------------------------
#ifndef POPULATION_HPP
#define POPULATION_HPP

#define ONE 1
#define ZERO 0

#include "tools.hpp" // includes all the other headers you need.
#include "Inventory.hpp"

class Population {
private:
	// ------------------------------------------------------------------------
	int popNumAgents;
	double popProbFickle;
	double popProbNak;
	double popProbExtend;
	int popMaxRounds;
	// unsigned int popSeed;
	Agent** popAgents;
	Inventory popInventory;

	int numFickle;
	int numNak;

public:
	// ------------------------------------------------------------------------
	Population() =default;
	Population( int numAgents, double probFickle, double probNak, 
		double probExtend, int maxRounds, unsigned int seed );
	~Population();
	// ------------------------------------------------------------------------
	int size () const { return popNumAgents; }

	void sendMessage ( int sender, int receiver );
	Blockchain choice(int receiver){ return popAgents[receiver]->choice(); }
	void inventoryAdd(Blockchain bc) { popInventory.add(bc); }
	void inventorySub(Blockchain bc) { popInventory.sub(bc); }
	void printInventory() { cout << popInventory; }

	void extend(int receiver);
	double dRandom();

	void printStats ();
	ostream& print ( ostream& out) const;
};

inline ostream& operator<< ( ostream& out, const Population& pop ) {
	return pop.print ( out );
}
#endif	// POPULATION_HPP

