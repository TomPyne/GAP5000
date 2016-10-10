#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList() {
	Node *tempPtr = head;
	Node *tempPtr2;

	while(tempPtr != nullptr) {
		tempPtr2 = tempPtr->get_nextptr();
		delete tempPtr;
		tempPtr = tempPtr2;
	}
}


void LinkedList::insert_front(int d) {
	Node *newNode = new Node(d, head);
	head = newNode;
}

void LinkedList::append(int d) {
	if(head == nullptr){
		insert_front(d);
	} else {
		Node *tempPtr = head;
		while(tempPtr->get_nextptr() != nullptr) {
			tempPtr = tempPtr->get_nextptr();
		}
		Node *newNode = new Node(d, nullptr);
		tempPtr->set_nextptr(newNode);
	}
}

void LinkedList::display() {
	Node *tempPtr = head;
	while(tempPtr != nullptr) {
		tempPtr->display();
		tempPtr = tempPtr->get_nextptr();
	}
}

void LinkedList::display_nth(unsigned int nth) {
	unsigned int count = nth;
	Node *tempPtr = head;
	while(tempPtr != nullptr) {
		if(count == 0) {
			tempPtr->display();
			break;
		}
		count--;
		tempPtr = tempPtr->get_nextptr();
	}
}

void LinkedList::delete_nth(unsigned int nth) {
	Node *prevNode = nullptr;
	Node *currentNode = head;
	unsigned int count = nth;
	if(nth == 0) {
		if(currentNode != nullptr) {
			head = currentNode->get_nextptr();
			delete currentNode;
		}
		return;
	}

	while(currentNode != nullptr) {
		if(count == 0) {
			prevNode->set_nextptr(currentNode->get_nextptr());
			delete currentNode;
			return;
		}
		count--;
		prevNode = currentNode;
		currentNode = currentNode->get_nextptr();
	}
}


void LinkedList::insert_before_nth(unsigned int nth, int d) {
	if(nth == 0) {
		insert_front(d);
		return;
	}

	Node *prevNode = nullptr;
	Node *currentNode = head;
	unsigned int count = nth;

	while(currentNode != nullptr) {
		if(count == 0) {
			Node *newNode = new Node(d, currentNode);
			prevNode->set_nextptr(newNode);
			return;
		}
		count--;
		prevNode = currentNode;
		currentNode = currentNode->get_nextptr();
	}
}

bool LinkedList::is_Empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::remove_front()
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		Node* temp = head;
		head = head->get_nextptr();
		delete temp;
	}
}

void LinkedList::remove_back()
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		Node* currNode = head;
		Node* prevNode = nullptr;

		while (currNode->get_nextptr() != nullptr)
		{
			prevNode = currNode;
			currNode = currNode->get_nextptr();
		}
		prevNode->set_nextptr(nullptr);
		delete currNode;
	}
}

void LinkedList::get_front()
{
	head->display();
}

void LinkedList::get_back()
{
	Node* currNode = head;

	while (currNode->get_nextptr() != nullptr)
	{
		currNode = currNode->get_nextptr();
	}
	currNode->display();
}

