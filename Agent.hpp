//  ---------------------------------------------------------------------------
//  Header file for all Agent programs.                       Agent.hpp
//  Created by Bilal Abu-Ghazaleh on Friday December 2nd, 2018
// ----------------------------------------------------------------------------
#ifndef AGENT_HPP
#define AGENT_HPP

#include "Blockchain.hpp"
#include "tools.hpp" // includes all the other headers you need.

//  ---------------------------------------------------------------------------
// 	Virtual Void class for Agent
class Agent {
public:
	// ------------------------------------------------------------------------
	virtual ~Agent() =default;
	// ------------------------------------------------------------------------
	virtual Blockchain choice() const = 0;
	virtual void update( Blockchain m ) = 0;
	virtual void extend() = 0;

	virtual ostream& print ( ostream& out) const = 0;

};

//  ---------------------------------------------------------------------------
//	Base Class for all Agents with non virtual values and fucntions
class AgentBase : public Agent {
private:
	// ------------------------------------------------------------------------
	Blockchain currentChoice;

public:
	// ------------------------------------------------------------------------
	~AgentBase() = default;
	// ------------------------------------------------------------------------
	Blockchain choice()  const = 0;
	void update( Blockchain m ) = 0;
	void extend() = 0;

	ostream& print ( ostream& out) const {
		return out << currentChoice;
	}

};

//  ---------------------------------------------------------------------------
//	Class for Fickle Agent
class Fickle : public AgentBase {
private:
	// ------------------------------------------------------------------------
	Blockchain currentChoice;

public:
	// ------------------------------------------------------------------------
	Fickle( Blockchain ch ) : currentChoice(ch) {}
	// ------------------------------------------------------------------------
	Blockchain choice() const { return currentChoice; }
	void update( Blockchain m );
	void extend();

	ostream& print ( ostream& out) const {
		return out << currentChoice;
	}

};

//  ---------------------------------------------------------------------------
//	Class for Crowd Agent
class Crowd : public AgentBase {
private:
	// ------------------------------------------------------------------------
	Blockchain currentChoice;
	Blockchain currentState;

public:
	// ------------------------------------------------------------------------
	Crowd( Blockchain ch ) : currentChoice(ch), currentState(ch) {}
	// ------------------------------------------------------------------------
	Blockchain choice() const { return currentChoice; }
	void update( Blockchain m );
	void extend();
	ostream& print ( ostream& out) const {
		return out << currentChoice;
	}
};

//  ---------------------------------------------------------------------------
//	Class for Nakamoto Agent
class Nakamoto : public AgentBase {
private:
	// ------------------------------------------------------------------------
	Blockchain currentChoice;

public:
	// ------------------------------------------------------------------------
	Nakamoto( Blockchain ch ) : currentChoice(ch) {}
	// ------------------------------------------------------------------------
	Blockchain choice() const { return currentChoice; }
	void update( Blockchain m );
	void extend();

	ostream& print ( ostream& out) const {
		return out << currentChoice;
	}
};

//Operators for print functions for all Agents
inline ostream& operator<< ( ostream& out, const Agent& a ) {
	return a.print ( out );
}

inline ostream& operator<< ( ostream& out, const AgentBase& ab ) {
	return ab.print ( out );
}

inline ostream& operator<< ( ostream& out, const Fickle& f ) {
	return f.print ( out );
}

inline ostream& operator<< ( ostream& out, const Crowd& c ) {
	return c.print ( out );
}

inline ostream& operator<< ( ostream& out, const Nakamoto& n ) {
	return n.print ( out );
}
#endif	// AGENT_HPP

