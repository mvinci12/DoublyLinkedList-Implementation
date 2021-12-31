//
//  LinkedList.h
//  Linked_List
//
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.


#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly 
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
};

/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{   
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/
template <class T>
LinkedList<T>::LinkedList(T minval, T maxval)
{ 
    Node<T>* Node1 = new Node<T>(minval);
    Node<T>* Node2 = new Node<T>(maxval);
    
    this->head= Node1;
    Node1->next= Node2;
    Node2->prev= Node1;

}

template <class T>
LinkedList<T>:: ~LinkedList() {

	while (this->head)
	{
		Node<T> *curr = this->head;     
        this->head = this->head->next;     
        delete curr;
	}
    
}


template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data){

    Node<T> *curr = location;

    while(curr!= nullptr){                    
        if ((curr->data == data) || (curr->data < data && curr->next->data > data)){    //if the data is in the linked list OR checking if data fits in between two nodes
            return curr;                                                                //data is put inbetween where its bigger than curr and less then curr->next node
        } else{
            curr = curr->next;
        }
    }
}



template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data){

    Node<T> *curr = location;

    if (curr->data == data){
        return nullptr;            //its already in the linked list
    }
    else if((location->data < data) && (location->next->data > data)){

        Node<T>* temp = location->next;                 
        location->next = new Node<T>(data);
        Node<T>* newnode = location->next;
        newnode->prev = location;
        newnode->next = temp;
        temp->prev = newnode;

        return location;
    }
    else{
        return nullptr;
        }          //if linked list is unsorted

}



template <class T>
void LinkedList<T>::printData(){
    Node<T>* curr = this->head;
    while(curr){
        curr->printData();
        curr = curr->next;
    }
}

template <class T>
void LinkedList<T>::print(){
    Node<T>* curr = this->head;
    while(curr){                    
        curr->print();
        cout << endl;
        curr = curr->next;
    }
}



#endif /* LinkedList_h */
