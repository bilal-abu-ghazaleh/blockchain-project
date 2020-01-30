//  ---------------------------------------------------------------------------
//  Header file for all Block programs.                       Block.hpp
//  Created by Bilal Abu-Ghazaleh on Thursday October 4th, 2018
// ----------------------------------------------------------------------------
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "tools.hpp" // includes all the other headers you need.
#include "SPtr.hpp"
#include "Serial.hpp"


inline ostream& operator<< ( ostream& out, const Block& b );

class Block {
private:
	// ------------------------------------------------------------------------
	const int serialNo = Serial::newID();
	const SPtr sp;
	const int level;

public:
	// ------------------------------------------------------------------------
	Block() : level(0) {};
	Block(SPtr spIn): sp(spIn), level(spIn->blkLevel() + 1) {};
	//Copy constructor and copy assignment operator deleted
	Block(const Block&) =delete;
	Block& operator=(const Block&) =delete;
	// ------------------------------------------------------------------------
	//	Returns the block level
	int blkLevel() const { return level; }
	//	Returns ID
	int blkId() const { return serialNo; }
	//	Print with appropriate format
	ostream& print ( ostream& out) const {
		if(level > 0) out << *sp;
		return out << "[" << level << "," << serialNo << "] ";
	};
	~Block()=default;
};

inline ostream& operator<< ( ostream& out, const Block& b ) {
	return b.print ( out );
}
#endif	// BLOCK_HPP