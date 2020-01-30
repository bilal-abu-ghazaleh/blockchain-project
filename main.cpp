//  ---------------------------------------------------------------------------
//  Main program for consensus.                             main.cpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 24, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"
#include "Simulator.hpp"

void run ( int argc, char** argv );
unsigned int verifyCMDS ( int argc, char** argv );

// ----------------------------------------------------------------------------
// Consensus main program with banner and bye included
int main ( int argc, char** argv ) {
	banner();
	run(argc, argv);
	bye();
	return 0;
}

//  ---------------------------------------------------------------------------
//	Instantiate Simulator and calls Simulator::run and print appropriate output
void
run ( int argc, char** argv) {
	unsigned int seed = verifyCMDS(argc, argv);

	int numAgents = stoi(argv[1]);
	int maxRounds = stoi(argv[2]);
	double probNack = stod(argv[3]);
	double probFickle = stod(argv[4]);
	double probExtend = stod(argv[5]);

	Population pop(numAgents, probFickle, probNack,
	 probExtend, maxRounds, seed);

	Simulator sim(pop, probExtend, maxRounds);

	//	Print output as per format
	cout << "Welcome to Consensus Simulator!\n" 
		<< "Using seed: " << seed
	  	<< "\n" << right << setw(13) << "numAgents:" << setw(7) << numAgents
	  	<< "\n" << right << setw(13) << "maxRounds:" << setw(7) << maxRounds
	  	<< "\n" << setw(13) << "probNak:" << setw(7)  << probNack
	 	<< "\n" << setw(13) << "probFickle:" << setw(7)  << probFickle 
	 	<< "\n" <<  setw(13) << "probExtend:" << setw(7) << probExtend
		<< "\n\nPopulation statistics:\n" << endl;
		pop.printStats();

		sim.run();
		cout << pop << endl;
} 

//  ---------------------------------------------------------------------------
//	Verify correct number of CMD line arguemtns. And checks whether Seed given.
//	Returns seed if Seed given, time(0) otherwise and Calls fatal on error.
// 	Assumes that if CMDs are given, they are correct format (they are int)
unsigned int
verifyCMDS ( int argc, char** argv ) {
	if(argc == 6)
		return time(0);
	else if(argc == 7)
		return stoi(argv[6]);
	else
		fatal("Usage: numAgents maxRounds probNak probFickle probExtend[seed]\n");
	return 0;
}

