#ifndef __BASE_H__
#define __BASE_H__
#include "iterator.h"

class Iterator;

class Base {
    public:
        Base(){};

        //virtual
        virtual void print() = 0;
        virtual double evaluate() = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
        
        virtual void accept(Visitor*) = 0;
        
};

#endif