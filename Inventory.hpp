//  ---------------------------------------------------------------------------
//  Header file for all Inventory programs.                     Inventory.hpp
//  Created by Bilal Abu-Ghazaleh on Thursday December 4th, 2018
// ----------------------------------------------------------------------------
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "tools.hpp" // includes all the other headers you need.
#include "Agent.hpp"
#include <map>

class Inventory {
private:
	// ------------------------------------------------------------------------
	std::map<Blockchain, int> inventoryMap;

public:
	// ------------------------------------------------------------------------
	Inventory() = default;
	~Inventory() =default;
	// ------------------------------------------------------------------------
	void add(Blockchain bc);
	void sub(Blockchain bc);

	//	Print with appropriate format
	ostream& print ( ostream& out) const {
		out << "Inventory: " << inventoryMap.size() 
			<< " active blockchain(s):\n";
		for (auto const& item : inventoryMap) {
		    out << item.second // string's value 
		        << " copies of " 
		        << item.first  // string (key)
				<< endl ;
		}
		return out << endl;
	}
};

inline ostream& operator<< ( ostream& out, const Inventory& i ) {
	return i.print ( out );
}

#endif	// INVENTORY_HPP


