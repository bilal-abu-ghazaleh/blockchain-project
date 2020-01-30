// ----------------------------------------------------------------------------
//  Population class:  
//  Implementation file for all Population programs.           Population.cpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 24th, 2018
// ---------------------------------------------------------------------------- 
#include "Population.hpp"

// ----------------------------------------------------------------------------
// Population constructor, sets values accordingly and initiates rand seed Gen
Population::
Population(int numAgents, double probFickle, double probNak, double probExtend,
 int maxRounds ,unsigned int seed):
 	popNumAgents(numAgents), popProbFickle(probFickle), popProbNak(probNak),
 	popProbExtend(probExtend), popMaxRounds(maxRounds) {

 	// CMD range verification
 	if (popNumAgents < 1 || popProbFickle < 0 || popProbFickle > 1 ||
 	popProbNak < 0 || popProbNak > 1 || (popProbNak + popProbFickle) > 1
 	|| popProbExtend < 0 || popProbExtend > 1){
 		fatal("Please verify CMDs in range.\n");
 	}

 	srand(seed);
 	popAgents = new Agent*[popNumAgents];
 	numFickle = 0;
 	numNak = 0;

	double randType;
	//Genisis Blcok here
	SPtr temp;
	Block* genesis = new Block();
	SPtr gen(genesis);

	for (int j = 0; j < popNumAgents; j++) {
		randType = dRandom();
		Blockchain bcGen = Blockchain(gen);
		inventoryAdd(bcGen);
		if (randType < popProbNak) {	//Choose Nak
			popAgents[j] = new Nakamoto(bcGen);
			numNak++;
		}
		else if(randType < popProbFickle){
			popAgents[j] = new Fickle(bcGen);
			numFickle++;
		}
		else
			popAgents[j] = new Crowd(bcGen);
	}
}

//  ---------------------------------------------------------------------------
// Destructor, population retains custody of all agents so destructor
// must take care to delete them all
Population::
~Population(){
	for (int j = 0; j < popNumAgents; j++) {
		delete popAgents[j];
	}
	delete[] popAgents;
}

//  ---------------------------------------------------------------------------
// 	Simulates a single communication step from sender to receiver.
//	Commented out intermediate print as per spec
void Population::
sendMessage ( int sender, int receiver ) {
	Blockchain senderMessage = popAgents[sender]->choice();
	popAgents[receiver]->update(senderMessage);
	// cout << "Send Message: (" << sender << ", " << receiver << ")\n";
}

//  ---------------------------------------------------------------------------
// 	Simulates a single extention of receiver.
//	Commented out intermediate print as per spec
void Population::
extend(int receiver){
	// cout << " extend(" << receiver << ")\n";
	popAgents[receiver]->extend();
	// cout << "New Blockchain " << *popAgents[receiver] << "\n";
}

//  ---------------------------------------------------------------------------
//	Given in the Spec - Credit to M. Fischer - Yale University October 2018
//	Generate a random num, given seed between 0 and n - 1
double Population::
 dRandom() {
   return random()/(RAND_MAX+1.0); // result is double in [0,1)
 }

//  ---------------------------------------------------------------------------
// 	Print Stats
void Population::
printStats ()  {
	int numCrowd = popNumAgents - numFickle - numNak;
	cout << setw(13) << "numNak:" << setw(7) << numNak << "\n"
	<< setw(13) << "numFickle:" << setw(7) << numFickle << "\n" 
	<< setw(13) << "numCrowd:" << setw(7) << numCrowd << "\n"
	<< setw(13) << "numOnes:" << setw(7) << ZERO << "\n"
	<< setw(13) << "probExtend:" << setw(7) << popProbExtend << "\n" << endl
	<< popInventory
	<< "Starting simulation with probExtend = " << popProbExtend 
	<< "\n" << endl;
}

//  ---------------------------------------------------------------------------
// 	Print the population
ostream& Population::
print ( ostream& out) const {
	out << "\nCurrent blockchain choices after " << popMaxRounds 
		<< " rounds:" << endl;
	for (int j = 0; j < popNumAgents; j++){
		out << setw(0) << "Agent " << j << " choice: " <<  *popAgents[j] << "\n";
	}
	return out << endl;
}
