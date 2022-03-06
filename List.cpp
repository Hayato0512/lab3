/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: A data collection List ADT class.
 *
 * Creation Date:
 * Author:
 */

#include "List.h"
#include <string>
#include <iostream>

using namespace std; // Needed for cout, cin to be recognized

// Constructors and Destructors


// Description: Default constructor
List::List(){
	elementCount = 0;
	head = NULL;
}


// Description: Copy constructor to copy an existing List object.
List::List(const List& lst){
	head = new Node;

	//deepCopy(head, lst);
	Node* recDeep  = deepCopyR(head, lst.head);
	this->elementCount = lst.elementCount;
}

// Description: Destruct a List object, releasing heap-allocated memory.
List::~List(){
	// You need to write this!

}

Node* List::deepCopyR(Node* newCurrent, Node* oldCurrent){
	if(oldCurrent==NULL)
		return NULL;
	if(newCurrent!=NULL){
		newCurrent->data = oldCurrent->data;
	}
	else{
		newCurrent = new Node;
		newCurrent->data = oldCurrent->data;

	}
	newCurrent->next = deepCopyR(newCurrent->next,oldCurrent->next);
	return newCurrent;
}


void List::deepCopy(Node* newHead,const List& oldList){
	Node* newCurrent = newHead;
	Node* oldCurrent = oldList.head;
	newCurrent->data = oldCurrent->data;
	Node* prev = newCurrent;
	newCurrent = newCurrent->next;
	oldCurrent = oldCurrent->next;
	while(oldCurrent!=NULL){
		newCurrent = new Node;
		newCurrent->data = oldCurrent->data;
		prev->next = newCurrent;
		prev = newCurrent;
		newCurrent = newCurrent->next;
		oldCurrent = oldCurrent->next;
	}
}
/**************************************************************************/
// List Operations
//
// Description: Add an element (newElement) to the list.
// Postcondition: newElement is inserted at the end of the list.
void List::add(int newElement){
	Node *newNode = new Node(newElement); //new Node with x

	// Check to see if list is empty
	if (head == NULL){
		// Make new Node the new head
		head = newNode;
	}else{
		// Move to the end of the list
		Node* current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	elementCount++;
}


/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
 // Description: Prints the contents of the list from the first to the last element.
void List::printList(){
	Node *current = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != NULL){
		cout << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be wanted
}
// end of implementation file of List class
