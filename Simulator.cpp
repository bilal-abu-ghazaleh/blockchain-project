// ----------------------------------------------------------------------------
//  Simulator class:  
//  Implementation file for all Simulator programs.               Simulator.cpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 24th, 2018
// ---------------------------------------------------------------------------- 
#include "Simulator.hpp"

//  ---------------------------------------------------------------------------
//	Runs the simulator by setting vars appropriately and sending messages until
//  Consensus is reached. Does not have a return value.
void Simulator::
run() {
	int simPopSize = simPop->size();
	double deciderProb;
	int sender, receiver;
	while(simNumRounds < simMaxRounds){
		deciderProb  = simPop->dRandom(); 	//Use same dRand as Pop
		bool updateInventory = true;
		Blockchain added;
		Blockchain subtracted;

		//Extend
		if (simPopSize == 0) fatal("Cannot send message to same person");
		if(deciderProb < simProbExtend){
			receiver = uRandom(simPopSize);

			subtracted = simPop->choice(receiver);
			simPop->extend(receiver);

			added = simPop->choice(receiver);
			updateInventory = true;
		}
		//Send message
		else{
			sender = uRandom(simPopSize);
			receiver = uRandom(simPopSize - 1);
			if (receiver >= sender) receiver++;

			subtracted = simPop->choice(receiver);
			simPop->sendMessage(sender, receiver);

			added = simPop->choice(receiver);
			if (subtracted == added)
				updateInventory = false;
		}
		simNumRounds++;
		//After each simulation step, if the agent’s new and old choices differ
		//the new one should be added and the old one subtracted from the inventory.
		if(updateInventory){
			simPop->inventoryAdd(added);
			simPop->inventorySub(subtracted);
			simPop->printInventory();
		}
	}
}

//  ---------------------------------------------------------------------------
//	Given in the Spec - Credit to M. Fischer - Yale University October 2018
//	Generate a random num, given seed between 0 and n - 1
int Simulator::
uRandom( int n ) { 
	long int usefulMax = RAND_MAX-((RAND_MAX-n)+1)%n; // avoids int overflow
	long int r;
	do { r = random(); }
	while ( r > usefulMax );
	return r % n;
}

