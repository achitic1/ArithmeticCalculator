/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.h
 * Author: cwood
 *
 * Created on March 3, 2019, 10:22 AM
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackADT.h"

const int SIZE = 50;

template <class T>
class ArrayStack : StackADT<T> {
public:
    ArrayStack();
//    ArrayStack(const ArrayStack& orig);
//    virtual ~ArrayStack();
    
    //interface methods
    
    /*
     * Determines if the stack is empty
     * @returns 0 if stack is not empty and 1 if it is empty
     */
    bool isEmpty() const;
    
    /*
     * Pushes a new Item to the top of the stack
     * @param newItem - the item to be added to the top of the stack
     * @returns whether the item was able to be added to the stack or not
     */
    bool push(const T& newItem);
    
    /*
     * Takes the top item off the stack
     * @returns true or false depending on whether the stack is empty or not
     */
    bool pop();
    
    /* Returns the item at the top of the stack
     * @returns the item at the top of the stack
     */
    T peek() const;
    
private:
//    static const int SIZE = 50;
    T items[SIZE];
    int top;
};

#include "ArrayStack.cpp"
#endif /* ARRAYSTACK_H */

