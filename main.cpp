#include <iostream>
#include <string>
//#include "base.h"
#include "composite.h"
#include "iterator.h"
#include "visitor.h"


using namespace std;

int main() {
    Op* one = new Op(1);
    Op* two = new Op(2);
    Add* a1 = new Add(one, two);
    
    Root* treeRoot = new Root(a1);
    
    PreorderIterator* iter = new PreorderIterator(treeRoot);
    PrintVisitor* v = new PrintVisitor();
    
    
    iter->first();
    while (!iter->is_done()) {
        
        if (iter->current() != NULL) {
        v->visitAssignment(iter->current());
        }
        
        iter->next();
    }
    
    v->execute();
    
    
    
    return 0;
}