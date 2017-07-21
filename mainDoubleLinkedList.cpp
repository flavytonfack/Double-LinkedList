//
//  main.cpp
//  assignment3.1
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#include <iostream>
#include "DoubleLinkedList.hpp"
using namespace std;

int main() {
    
    DoubleLinkedList * l1 = new DoubleLinkedList(); //default constructer
    DoubleLinkedList * l2 = new DoubleLinkedList(55); //custom constructer
    DoubleLinkedList * l3 = new DoubleLinkedList();
    
    
    l1 ->append(1);
    l1 ->append(2);
    l1 ->append(3);
    l1 ->append(4);
    l1 ->append(5);
    l1 ->append(6);
    l1 ->append(7);
    
    cout<<"FIRST LIST"<<endl;
    
    cout<<"Testing append of 1, 2 ,3 ,4 ,5 ,6, 7"<<endl;
    cout<<l1;
    cout<<"testing instert front '0'"<<endl;
    l1->insertFront(0);
    cout<<l1;
    cout<<"testing pop front "<<endl;
    l1->deleteFront();
    cout<<l1;
    cout<<"testing pop last"<<endl;
    l1->deleteBack();
    cout<<l1;
    cout<<"testing reverse list"<<endl;
    l1->listReverse();
    cout<<l1;
    cout<<"testing return size of list"<<endl;
    cout<<l1->listSize()<<endl;
    
    
    cout<<"-------------------------"<<endl;
    cout<<"NEW LIST"<<endl;
    l2->insertFront(90);
    l2 ->append(90);
    l2 ->append(91);
    l2 ->append(90);
    l2 ->append(93);
    l2 ->append(90);
    l2 ->append(95);
    l2->append(90);
    cout<<l2;
    cout<<"testing delete all copies of number from list, delete all copies of '90'"<<endl;
    l2->deleteDuplicates(90);
    cout<<l2;
    cout<<"testing return Mth term '0' which returns last term and '1' which returns second to last term"<<endl;
    cout<<"last term = "<<l2->MtoLastElement(0)<<endl;
    cout<<"second to last term = "<<l2->MtoLastElement(1)<<endl;
    
    cout<<"testing = overload, LIST 2 = LIST 1"<<endl;
    cout<<" l1 = "<<l1;
    cout<<" l2 = "<<l2;
    cout<<"l2 = l1"<<endl;
    *l2 = *l1;
    cout<<" l1 = "<<l1;
    cout<<" l2 = "<<l2;
    cout<<"test by appending 99 to l1 , l2 should not be effected"<<endl;
    l1->append(99);
    cout<<" l1 = "<<l1;
    cout<<" l2 = "<<l2;
    
    
    cout<<"-------------------------"<<endl;
    cout<<"NEW LIST"<<endl;
    
    
    l3->insertFront(10);
    l3 ->append(11);
    l3 ->append(12);
    l3 ->append(13);
    l3 ->append(14);
    l3 ->append(15);
    l3 ->append(16);
    l3->append(17);
    cout<<"testing copy constructor"<<endl;
    cout<<"l3 = "<<l3;
    cout<<"l4 = Nothing"<<endl;
    cout<<" LinkedList l4(l3) "<<endl;
    DoubleLinkedList l4(*l3);
    cout<<"l4 = "<<&l4;
    cout<<"l3 = "<<l3;
    
    cout<<"test by appending 99 to l3 , l4 should not be effected"<<endl;
    l3->append(99);
    cout<<"l4 = "<<&l4;
    cout<<"l3 = "<<l3;
    
    
    cout<<"testing destructor"<<endl;
    cout<<"delete l1, l2, l3, l4"<<endl;
    delete l2;
    delete l3;
    delete l1;
    return 0;
}
