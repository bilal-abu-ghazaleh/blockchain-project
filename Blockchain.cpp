// ----------------------------------------------------------------------------
//  Blockchain class:  
//  Implementation file for all Blockchain programs.           Blockchain.cpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 24th, 2018
// ---------------------------------------------------------------------------- 
#include "Blockchain.hpp"

// ----------------------------------------------------------------------------
//	Extends the blockchain by creating new block, new SPtr and then ret
//	New Blockchain
Blockchain Blockchain:: 
extend(){
	Block* b = new Block(sp);
	SPtr newSp(b);
	Blockchain newBC(newSp);

	return newBC;
}
