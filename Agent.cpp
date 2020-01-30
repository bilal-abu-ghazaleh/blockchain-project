//  ---------------------------------------------------------------------------
//  CPP file for all Agent programs.                       Agent.cpp
//  Created by Bilal Abu-Ghazaleh on Friday December 2nd, 2018
// ----------------------------------------------------------------------------
#include "Agent.hpp"

//  ---------------------------------------------------------------------------
//	Fickle update value as per algorithm provided. The spec does not say that 
//	Fickle and Crowd update must return void. The return value is used to eval
//	whetehr there was an update.
void Fickle::
update( Blockchain m ) { currentChoice = m; }

//  ---------------------------------------------------------------------------
//	Crowd algo update as per spec. Same return value as Fickle::update
//	TODO
void Crowd::
update( Blockchain m ) { 
	currentState == m ? currentChoice = m : currentState = m;
}

//  ---------------------------------------------------------------------------
//	Ignoring a new blockchain received from another agent unless the new 
//	chain is longer than the current one, in which case the longer blockchain
// 	replaces the shorter one.
void Nakamoto::
update( Blockchain m ) { 
	 if ( m.length() > currentChoice.length()) currentChoice = m;
}

//  ---------------------------------------------------------------------------
//	Causes the agent to extend its current blockchain and to make the extended 
//	blockchain its new choice.
void Fickle::
extend(){ currentChoice = currentChoice.extend(); }

//  ---------------------------------------------------------------------------
//	Causes the agent to extend its current blockchain and to make the extended 
//	blockchain its new choice.
void Crowd::
extend(){ currentChoice = currentChoice.extend(); }

//  ---------------------------------------------------------------------------
//	Causes the agent to extend its current blockchain and to make the extended 
//	blockchain its new choice.
void Nakamoto::
extend(){ currentChoice = currentChoice.extend(); }
