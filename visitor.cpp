#include "visitor.h"
#include "composite.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

PrintVisitor::PrintVisitor() {
    output == "";
    
}

void PrintVisitor::rootNode() {
    printf("%s", "Root node! Do nothing!");
    return;
}

void PrintVisitor::sqrNode() {
    cout << "Executing sqrNode" << endl;
    string tempStr = "^2";
    output += tempStr;
    output += ", ";
    return;

}

void PrintVisitor::multNode() {
    cout << "Executing multNode" << endl;
    string tempStr = "*";
    output += tempStr;
    output += ", ";
    return;
}

void PrintVisitor::subNode() {
    cout << "Executing subNode" << endl;
    string tempStr = "-";
    output += tempStr;
    output += ", ";
    return;
    return;
}

void PrintVisitor::addNode() {
    cout << "Executing addNode" << endl;
    string tempStr = "+";
    output += tempStr;
    output += ", ";
    return;
}

void PrintVisitor::opNode(Op* op) {
    cout << "Executing opNode" << endl;
    string tempStr = to_string(op->evaluate());
    output += tempStr;
    output += ", ";
    
}

void PrintVisitor::execute() {
    cout << output << endl;
}

void PrintVisitor::visitAssignment(Base* b) {
    b->accept(this);
    return;
}

string PrintVisitor::getOutput() {
    return output;
}
