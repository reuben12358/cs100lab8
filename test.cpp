#include <iostream>
#include <string>
//#include "base.h"
#include "composite.h"
#include "iterator.h"
#include "visitor.h"

#include "gtest/gtest.h"

TEST(t, tree1) { //single
    Op* one = new Op(1);
    Root* treeRoot = new Root(one);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("1.000000, ", out);
    
}

TEST(t, tree2) { //operator
    Op* eight = new Op(8);
    Op* seven = new Op(7);
    Sub* diff1 = new Sub(eight, seven);
    Root* treeRoot = new Root(diff1);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("-, 8.000000, 7.000000, ", out);
    
}

TEST(t, tree3) { //operator two
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("+, 1.000000, 2.000000, ", out);
    
}

TEST(t, tree4) { //operator squared
    Op* one = new Op(1);
    Op* two = new Op(2);

    Add* a1 = new Add(one, two);
    Sqr* sqr1 = new Sqr(a1);
    Root* treeRoot = new Root(sqr1);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("^2, +, 1.000000, 2.000000, ", out);
    
}

TEST(t, tree5) { //operator operator sqr operator
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* three = new Op(3);

    Add* a1 = new Add(one, two);
    Add* a2 = new Add(three, a1);
    Sqr* sqr1 = new Sqr(a2);
    
    Root* treeRoot = new Root(sqr1);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("^2, +, 3.000000, +, 1.000000, 2.000000, ", out);
    
}

TEST(t, tree6) { //basic operator operator
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Op* four = new Op(4);

    Add* a1 = new Add(one, two);
    Add* a3 = new Add(three, four);
    Add* a2 = new Add(a3, a1);
    Sqr* sqr1 = new Sqr(a2);
    
    Root* treeRoot = new Root(sqr1);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("^2, +, +, 3.000000, 4.000000, +, 1.000000, 2.000000, ", out);
    
    
}


TEST(t, tree7) { 
    Op* one = new Op(24);
    Op* two = new Op(400);
    
    Mult* m1 = new Mult(one, two);
    Root* treeRoot = new Root(m1);
    
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
    
    string out = v->getOutput();

    
    EXPECT_EQ("*, 24.000000, 400.000000, ", out);
    
}
 
int main(int argc, char **argv){
        ::testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
}
