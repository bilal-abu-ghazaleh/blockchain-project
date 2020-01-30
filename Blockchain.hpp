//  ---------------------------------------------------------------------------
//  Header file for all Blockchain programs.                    Blockchain.hpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 4th, 2018
// ----------------------------------------------------------------------------
#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "tools.hpp" // includes all the other headers you need.
#include "Block.hpp"

class Blockchain {
private:
	// ------------------------------------------------------------------------
	SPtr sp;

public:
	// ------------------------------------------------------------------------
	Blockchain() = default;
	Blockchain(SPtr spIn): sp(spIn) {};
	//	Return True if blocks are same -> BC is the same
	bool operator==( Blockchain& s1) const {
    	return  s1.tail()->blkId() == sp->blkId();
	}
	// ------------------------------------------------------------------------
	Blockchain extend();
	//	Print with appropriate format
	ostream& print ( ostream& out) const {
		return out << *sp;//
	}

	unsigned int length(){ return sp->blkLevel(); }
	Block* tail() const { return &*sp; }
};

inline ostream& operator<< ( ostream& out, const Blockchain& bc ) {
	return bc.print ( out );
}

inline bool operator<(const  Blockchain& s1, const Blockchain& s2) {
    return  s1.tail()->blkId() < s2.tail()->blkId();
}

#endif	// BLOCKCHAIN_HPP