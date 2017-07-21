//
//  DoubleLinkedList.hpp
//  assignment3.1
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#endif /* DoubleLinkedList_hpp */


#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cmath>

using namespace std;


class DoubleLinkedList{
    
private:
    struct node{
        node* next;
        node* prev;
        int data;
    };
    
public:
    node* head;
    node* tail;
    int size;
    
    DoubleLinkedList();
    DoubleLinkedList(int data);
    void append(int data);
    void printList();
    void insertFront(int data);
    void deleteList();
    void deleteFront();
    int listSize();
    void deleteBack();
    void deleteDuplicates(int value);
    int MtoLastElement(int M);
    void listReverse();
    friend ostream& operator<<(ostream& stream, DoubleLinkedList* link);
    ~DoubleLinkedList(); //destructor
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs);
    DoubleLinkedList(const DoubleLinkedList& rhs);
    
    
};


