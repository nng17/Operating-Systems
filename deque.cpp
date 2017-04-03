// Nathan Ng
// COEN 177 Lab
// Wednesday 2:15
// Lab 3


// Taken from COEN 70 HW files

/* includes and header file */
#include <iostream>
#include <cassert>
#include "deque.h"

/* node class to create linked list */
class Node {

public: 
	int data;
    int flag;
	Node *next; 
	Node *prev; 
};

// constructor for Deque class
Deque::Deque() {

	/* intialize count at 0, allocate memory for dummy node */
	count = 0; 
	head = new Node; 
	assert(head != NULL); 	/* assert dummy node is valid */

	/* point dummy node to itself forward and backward */
	head->next = head; 
	head->prev = head; 

}

// destructor for Deque class
Deque::~Deque() {

	/* variables to traverse list */
	Node *np, *next; 

	/* start at the head and traverse the list, freeing each node */
	np = head; 
	do { 
		next = np->next; 
		delete np; 
	    np = next; 	
	} while (np != head);

}

// returns the number of elements in the list
int Deque::size() {

	return count; 

}; 

// adds node to the beginning of list
void Deque::addFirst(int x, int y) {

	/* initialize new node and dummy node */
	Node *np, *temp; 

	/* allocate memory and assert valid memory for node */
	np = new Node; 
	assert(np != NULL); 

	/* initialize data and pointers */
	np->data = x;
    np->flag = y;
	np->next = head->next; 
	np->prev = head; 

	/* change existing pointers to point to new node */
	temp = head; 
	temp->next->prev = np;
	temp->next = np; 

	/* increment counter */
	count++; 

}

// adds node to the end of the list
void Deque::addLast(int x, int y) {

	/* intiailzie new node and dummy node */
	Node *np, *temp; 

	/* allocate memory and assert valid memory for node */
	np = new Node; 
	assert(np != NULL); 

	/* initialize data and pointers */
	np->data = x;
    np->flag = y;
	np->next = head; 
	np->prev = head->prev; 

	/* change existing pointers to point to new node */
	temp = head; 
	temp->prev->next = np; 
	temp->prev = np; 

	/* increment counter */
	count++; 

}

// removes the first node in the list and returns its data
int Deque::removeFirst() {

	/* initialize dummy nodes and variable to store data */
	Node *temp, *np; 
	int x; 

	/* assert non-empty list */
	assert(count != 0); 

	/* set temp to dummy node and decrement counter */
	temp = head; 
	count--; 

	/* change pointers so first node is not referenced, store data */
	np = temp->next; 
	temp->next = np->next; 
	np->next->prev = temp; 
	x = np->data; 

	/* free memory and return data */
	delete np;
	return x; 

}

// removes the last node in the list and returns its data
int Deque::removeLast() {

	/* initialize dummy nodes and variable to store data */
	Node *temp, *np; 
	int x; 

	/* assert non-empty list */
	assert(count != 0); 

	/* set temp to dummy node and decrement counter */
	temp = head; 
	count--;

	/* change pointers so last node is not referenced, store data */
	np = temp->prev; 
	temp->prev = np->prev; 
	np->prev->next = temp; 
	x = np->data; 

	/* free memory and return data */
	delete np;
	return x; 

}

// returns data from first item in list
int Deque::getFirst() {

	/* assert non-empty list */
	assert(count != 0); 
	return head->next->data; 

}

// returns data from last item in list
int Deque::getLast() {

	/* assert non-empty list */ 
	assert(count != 0); 
	return head->prev->data; 

}

// returns index of element in linked list or error value
int Deque::findElement(int x) {
    
    Node *np = head->next;
    int index = 0;
    
    if (count == 0)
        return -1;
    
    while (index < size()) {
        if (np->data == x)
            return index;
        else {
            index++;
            np = np->next;
        }
    }
    
    return -1;
    
}

// removes element from middle of list, returns data
int Deque::removeElement(int x) {
    
    // counter
    int i = 0;
    int d;
    Node *np = head->next;
    
    // traverse list to index passed in
    while (i < x) {
        np = np->next;
        i++;
    }
    
    // save data, modify pointers of neighboring nodes
    d = np->data;
    np->prev->next = np->next;
    np->next->prev = np->prev;
    
    // free node allocation, decrement counter, return data
    delete np;
    count--;
    return d;
    
}

// increases visited count to determine frequency of use
int Deque::increase(int x) {
    
    int d;
    Node *np = head;
    
    while (np != NULL) {
        if (np->data == x) {
            np->flag++;
            return np->flag;
        }
        np = np->next;
    }
    
    return -1;
    
}

// finds element with lowest frequency, returns index
int Deque::findMin() {
    
    // assumes a list of size > 0
    int i = 0;
    int j;
    
    // start at beginning of list, set initial minimum
    Node *np = head->next;
    int min = np->flag;

    // while pointer is valid
    while (np != head) {
        // if new min found, set index, set new min
        if (np->flag <= min) {
            j = i;
            min = np->flag;
        }
        i++;
        np = np->next;
    }
    
    // return index
    return j;
}

// removes element with lowest frequency, returns data
int Deque::removeMin() {
    
    int index = findMin();
    int d = removeElement(index);
    return d;
}

// second chance FIFO removal

int Deque::removeVisited() {
    
    int d;
    int i = 0;
    Node *np = head->next;
    
    while (np != NULL) {
        if (np == head) {
            i = 0;
            np = np->next;
        }
        else if (np->flag == 0) {
            np->flag = 1;
            i++;
            np = np->next;
        }
        else {
            d = removeElement(i);
            break;
        }
    }
    
    return d;
}
