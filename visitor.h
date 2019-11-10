#ifndef VISITOR_H
#define VISITOR_H

#include "composite.h"
#include <iostream>
using namespace std;

class Base;
class Op;

class Visitor {
	
	public: 
	Visitor() { };
	
	virtual void rootNode() = 0;
	virtual void sqrNode() = 0;
	virtual void multNode() = 0;
	virtual void subNode() = 0;
	virtual void addNode() = 0;
	virtual void opNode(Op* op) = 0;
	
	virtual void execute() = 0;
	
};

class PrintVisitor : public Visitor {
	private:
		string output;

	public:
		PrintVisitor();

		void rootNode(); //For visiting a root node (do nothing)
		void sqrNode(); //For visiting a square node
		void multNode(); //For visiting a multiple node
		void subNode(); //For visiting a subtraction node
		void addNode(); //For visiting an add node
		void opNode(Op* op); //For visiting a leaf node
		
		void visitAssignment(Base* b);

		void execute(); //Prints all visited nodes
		string getOutput();
		
};
#endif