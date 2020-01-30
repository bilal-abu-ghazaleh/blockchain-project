// ----------------------------------------------------------------------------
//  Inventory class:  
//  Implementation file for all Inventory programs.              Inventory.cpp
//  Created by Bilal Abu-Ghazaleh on Thursday December 4th, 2018
// ---------------------------------------------------------------------------- 
#include "Inventory.hpp"

//  ---------------------------------------------------------------------------
//	Add to the inventory
void Inventory::
add(Blockchain bc) {
	std::map<Blockchain,int>::iterator bcFound;
	bcFound = inventoryMap.find(bc);
	if (bcFound != inventoryMap.end()){
		int bcCount = inventoryMap.find(bc)->second;
		// cout << bcCount << "HERE\n";
		inventoryMap[bc] = ++bcCount;
	}
	else{	
		inventoryMap[bc] = 1; //Map is empty here
		// cout << "adding: " << bc << "\n";
	}
}

//  ---------------------------------------------------------------------------
//	Subtract from the inventory
void Inventory::
sub(Blockchain bc) { 
	std::map<Blockchain,int>::iterator bcFound;
	bcFound = inventoryMap.find(bc);	
	if (bcFound == inventoryMap.end()){
		fatal("Something is wrong, cannot sub from empty");
	}
	int bcCount = inventoryMap.find(bc)->second;
	if (bcCount == 1){
		inventoryMap.erase(bc);
	}
	else{ //There are many
		inventoryMap[bc] = --bcCount;
	}
}

