#include "iterator.h"
#include <cstdio>

void PreorderIterator::first() {
                                                //printf("\n%s\n", "Executing PreorderIterator::first()");
    // Empty the stack (just in case we had something leftover from another run)
        while (!iterators.empty()) {
            iterators.pop();
        }
    
    // Create an iterator for the Base* that we built the iterator for
        Iterator* firstIter = self_ptr->create_iterator();
                                                /*printf(" %s", "firstIter initalized with... ");
                                                if (firstIter->current()) {
                                                    firstIter->current()->print();
                                                }
                                                else {
                                                    printf("%s\n", "current_ptr = NULL, therefore it is a unary or non-existent.");
                                                } */
        
    // Initialize that iterator and push it onto the stack
        if (firstIter) {
            firstIter->first();
            
                                                //printf(" %s", "firstIter initialized with... ");
                                                /*if (firstIter) {
                                                    firstIter->current()->print();
                                                    cout << endl;
                                                }*/

            iterators.push(firstIter);
                    this->checkStack();
        }
}


void PreorderIterator::next() {
                                                //printf("\n%s\n", "Executing PreorderIterator::next()");
    // Create an iterator for the item on the top of the stack
        Base* topCurrent = this->current();

        
        if (topCurrent) {
            
                                               /* printf(" %s", "Top current exists: ");
                                                topCurrent->print();
                                                cout << endl; */
                
            Iterator* nextIter = topCurrent->create_iterator();
            nextIter->first();
                //iterators.top()->next();
                
                                               /* if (nextIter->current() != NULL) {
                                                    printf(" %s", "Initialized nextIter to... ");
                                                    nextIter->current()->print();
                                                    cout << endl;
                                                }
                                                else {
                                                    printf(" %s\n", "nextIter's first is NULL. Therefore it is a NullOperator and should be popped off.");
                                                } */
                
            iterators.push(nextIter);
                                                //this->checkStack();
        }
        else {
                                                //printf(" %s\n", "Top current is a NULL. You cannot create an iterator for this. Popping.");
            iterators.pop();
                                               /* this->checkStack();
                                                printf(" %s\n", "Returning."); */
            return;
        }
    
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
        while ( iterators.size() > 0 && iterators.top()->is_done()) { //THIS WAS THE ERROR
                                                //printf(" %s\n", "Top of iterator stack is NULL.");
            if (!iterators.empty()) {
                iterators.pop();
            }
                                                /*printf("  %s\n", "Popped top of stack due to being NULL.");
                                                if (!iterators.empty()) {
                                                    printf(" %s\n", "Checking stack at start of  next() while.");
                                                    this->checkStack();
                                                } */
           /*if (!iterators.empty()) {
                        printf(" %s\n", "Advancing next top iterator of the stack.");
                iterators.top()->next();
                
                if (iterators.top()->current() == NULL) {
                        printf(" %s\n", "Found that top's current_ptr is NULL, meaning that it is finished iterating. Popping.");
                    iterators.pop();
                }*/
                
                if (!iterators.empty()) {
                                                //printf(" %s\n", "Advancing next top iterator of the stack.");
                    iterators.top()->next();
                }
                        
                                               /* if (!iterators.empty()) {
                                                    printf("  %s\n", "Stack after next --");
                                                    this->checkStack();
                                                } */
            //}
        }
    
}


bool PreorderIterator::is_done() {
                                                //printf("%s\n", "Executing PreorderIterator::is_done().");
    // Return true if there are no more elements on the stack to iterate
        if (this->iterators.size() < 1) {
                                                //printf("  %s\n", "Finished.");
            return true;
        }
        else {
                                                //printf("  %s\n", "Unfinished.");
            return false;
        }
}


Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
        if (iterators.size() > 0) {
            return iterators.top()->current();
        }
        else {
            return NULL;
        }
    
}




void PreorderIterator::checkStack() {
    stack<Iterator*> chk = iterators;
    
    printf(" %s", "Stack is: ");
    while (!chk.empty()) {
        if (chk.top()->current() != NULL) {
        chk.top()->current()->print();
        }
        else {
            printf(" %s", "NULL");
        }
        chk.pop();
        cout << " ";
    }
    cout << endl;
    
}





void OperatorIterator::first() {
    
    current_ptr = self_ptr->get_left();
    
}

void OperatorIterator::next() {
            if (current_ptr == self_ptr->get_left()) {
            current_ptr = self_ptr->get_right();
            }
            else {
                current_ptr = NULL;
            }
}

bool OperatorIterator::is_done() {
    
    
            if (current_ptr == NULL) {
                return true;
            }  
            else {
                return false;
            }
        
}


Base* OperatorIterator::current() {
    return current_ptr;
}





void UnaryIterator::first() {
    current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    current_ptr = NULL;
}

bool UnaryIterator::is_done() {
            if (current_ptr == NULL) {
                return true;
            }
            else {
                return false;
            }
}

Base* UnaryIterator::current() {
    return current_ptr;
}







void NullIterator::first() {
    current_ptr = NULL;
}

void NullIterator::next() {
    current_ptr = NULL;
}

bool NullIterator::is_done() {
    return true;
}

Base* NullIterator::current() {
    return current_ptr;
}

