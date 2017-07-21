//
//  DoubleLinkedList.cpp
//  assignment3.1
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#include "DoubleLinkedList.hpp"

#include <iostream>
using namespace std;

DoubleLinkedList :: DoubleLinkedList():head(NULL), size(0), tail(NULL){}

DoubleLinkedList :: DoubleLinkedList(int data){
    node* current = new node;
    current->data = data;
    head = current;
    tail = current;
    size = 1;
    current->next = NULL;
    current->prev = NULL;
}

void DoubleLinkedList :: append(int data){
    node* current = new node;
    current->data = data;
    current->next = NULL;
    if (head == NULL && tail == NULL){
        head = current;
        tail = current;
        size = 1;
        current->prev = NULL;
        return;
    }
    else{
        node* temp = tail;
        temp->next = current;
        current->prev = temp;
        tail = current;
        size++;
    }
}
void DoubleLinkedList:: printList(){
    if(head == NULL){
        return;
    }
    node* current = head;
    while(current->next != NULL){
        cout<<current->data<<"=>";
        current = current->next;
    }
    
    cout<<current->data<<endl;
    
}


void DoubleLinkedList:: insertFront(int data){
    node* current = new node;
    current->data = data;
    if(head == NULL && tail == NULL){
        head = current;
        tail = current;
        size = 1;
        current->prev = NULL;
        current->next = NULL;
        return;
    }
    else{
        current->next = head;
        head->prev = current;
        head = current;
        current->prev = NULL;
        size++;
    }
}

void DoubleLinkedList:: deleteList(){
    if(head == NULL){
        return;
    }
    node* current = head;
    while(current->next != NULL){
        node* temp = current;
        current = current->next;
        delete temp;
        current->prev = NULL;
    }
    delete current;
    head = NULL;
    tail = NULL;
    size = 0;
    
}
void DoubleLinkedList:: deleteFront(){
    if (head == NULL && tail == NULL){
        return;
    }
    else if(size == 1){
        deleteList();
    }
    else{
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        head -> prev = NULL;
        size--;
    }
}
int DoubleLinkedList:: listSize(){
    return size;
}
void DoubleLinkedList:: deleteBack(){
    if (head == NULL && tail == NULL){
        return;
    }
    else if(size == 1){
        deleteList();
        size = 0;
    }
    else{
        node* temp;
        temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        size--;
    }
}
void DoubleLinkedList:: deleteDuplicates(int value){
    
    if(head==NULL && tail == NULL){
        return;
    }
    
    node* current = head;
    
    while(current->data == value && current == head){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        head -> prev = NULL;
        size--;
        current = head;
    }
    current = current->next;
    
    while (current->next != NULL){
        if (current->data == value){
            node* temp = current;
            node* prev;
            current = current->next;
            prev = temp ->prev;
            prev->next = current;
            current->prev = prev;
            temp->next = NULL;
            temp ->prev = NULL;
            delete temp;
            size--;
        }
        else{
            current = current->next;
        }
    }
    
    if (size == 1 && current->data == value){
        deleteList();
        size = 0;
    }
    
    else if(current->data == value && current == tail){
        node* temp;
        temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        size--;
    }
}

int DoubleLinkedList:: MtoLastElement(int M){
    
    if ((M - size) *-1 > size){
        cout<<"You inputted an integer outside of the range, the function will return 0"<<endl;
        return 0;
    }
    node* current = head;
    int count = 1;
    M = M - size;
    M = M * -1;
    while(count != M ){
        current = current->next;
        count ++;
    }
    return current->data;
}
void DoubleLinkedList:: listReverse(){
    if (head == tail){
        return;
    }
    if (head == NULL && tail == NULL){
        return;
    }
    
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    node* findTail = head;
    
    while(tail->prev != NULL){
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    
    head = tail;
    tail = findTail;
}

ostream& operator<<(ostream& stream, DoubleLinkedList* link){
    
    if(link->head == NULL){
        return stream;
    }
    
    DoubleLinkedList :: node* current = link->head;
    while(current->next != NULL){
        stream<<current->data<<"=>";
        current = current->next;
    }
    
    
    stream<<current->data<<endl;
    
    
    
    return stream;
}

DoubleLinkedList :: ~DoubleLinkedList(){
    deleteList();
    cout<<"Destructor called"<<endl;
}


DoubleLinkedList& DoubleLinkedList :: operator=(const DoubleLinkedList& rhs){
    
    if(rhs.head == NULL && tail == NULL){
        this->deleteList();
        cout<<"Overloaded = function was called"<<endl;
        return *this;
    }
    this->deleteList();
    this->head = new node;
    node* rhsHead = rhs.head;
    node* link = this->head;
    link->data = rhsHead->data;
    rhsHead = rhsHead->next;
    while(rhsHead != NULL){
        node* secondNode = new node;
        secondNode->data = rhsHead->data;
        link->next = secondNode;
        link = link->next;
        rhsHead = rhsHead->next;
    }
    this -> tail = link;
    this -> size = rhs.size;
    link->next = NULL;
    cout<<"Overloaded = function was called"<<endl;
    return *this;
}


DoubleLinkedList :: DoubleLinkedList(const DoubleLinkedList& rhs){
    
    if(rhs.head == NULL && tail == NULL){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    else{
        this->head = new node;
        node* rhsHead = rhs.head;
        node* link = this->head;
        link->data = rhsHead->data;
        rhsHead = rhsHead->next;
        
        while(rhsHead != NULL){
            node* secondNode = new node;
            secondNode->data = rhsHead->data;
            link->next = secondNode;
            link = link->next;
            rhsHead = rhsHead->next;
        }
        link->next = NULL;
        tail = link;
        size = rhs.size;
    }
    cout<<"copy constructor was called"<<endl;
}
