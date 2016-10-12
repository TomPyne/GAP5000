#pragma once



class Source
{
private:

public:
	Source();
	~Source();
	void setUp();
	int main();
	bool isMenuInputValid(char input);
	void menuLoop();
};

#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Stack.h"
#include "Queue.h"


class MainProg
{
private:
	std::fstream stackFile, queueFile;

	Stack *stack;
	Queue *queue;
public:
	

	void handle_setUp();                      

	void handle_clearStack();
	void handle_pushStack(std::string data);
	void handle_popStack();
	void handle_displayReverseStack();
	void handle_displayStack();
	void handle_reverseStack();

	void handle_clearQueue();
	void handle_pushQueue(std::string data);
	void handle_popQueue();
	void handle_displayReverseQueue();
	void handle_displayQueue();
	void handle_reverseQueue();

	void handle_writeStack();
	void handle_readStack();
	void handle_writeQueue();
	void handle_readQueue();

	void printMenu();
	bool isMenuInputValid(char input); // Check for bad input
	void menuLoop();                   // Handle the looping of the menu until
	                                   // quit
	




	MainProg();
	~MainProg();
};

#pragma once
#include "LinkedList.h"
#include <string>

class Queue
{
private:
	LinkedList* m_linkedList;
public:
	Queue();
	~Queue();

	void push(std::string data);
	std::string pop();
	bool checkEmpty();
	void display();
	void displayReverse();
	void clear();
	void reverseList();

	void writeToQueue(std::string fileName);
	void readFromFile(std::string fileName);
};

#pragma once

#include <string>

class Node
{
public:

	Node();
	Node::Node(std::string d, Node *np);
	~Node();
	std::string get_data();
	Node *get_nextptr();
	void set_data(std::string d);
	void set_nextptr(Node *np);
	void display();
private:
	std::string data;

	Node *nextptr;
};

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insert_front(std::string d);
	void append(std::string d);
	void display();
	void display_nth(unsigned int nth);
	void delete_nth(unsigned int nth);
	void insert_before_nth(unsigned int nth, std::string d);
	void display_id(unsigned int id);
	bool is_Empty();
	int remove_front();
	void remove_back();
	std::string get_front();
	void get_back();
	void displayReverse();

	void writeFile(std::string fileName);
	void readFile(std::string fileName);
private:
	Node *head;
	std::fstream file;
};

#pragma once

#include <string>
#include <fstream>
#include "LinkedList.h"

class Stack
{
private:
	LinkedList *m_linkedList;
public:
	Stack();
	~Stack();

	void push(std::string data);
	std::string pop();
	bool checkEmpty();
	void display();
	void displayReverse();
	void clear();
	void reverseList();

	void writeToFile(std::string fileName);
	void readFromFile(std::string fileName);
};

#include "Stack.h"



Stack::Stack()
{
	m_linkedList = new LinkedList;
}


Stack::~Stack()
{
	delete m_linkedList;
	m_linkedList = NULL;
}

void Stack::push(std::string data)
{
	m_linkedList->insert_front(data);
}

std::string Stack::pop()
{
	if (m_linkedList->is_Empty() == false)
	{
		std::string data;
		data = m_linkedList->get_front();
		m_linkedList->remove_front();

		return data;
	}
}
bool Stack::checkEmpty()
{
	return m_linkedList->is_Empty();
}

void Stack::display()
{
	m_linkedList->display();
}

void Stack::displayReverse()
{
	m_linkedList->displayReverse();
}

void Stack::clear()
{
	while (!m_linkedList->is_Empty())
	{
		m_linkedList->remove_front();
	}
}

void Stack::reverseList()
{
	// Temporary list that will be fed the values in reverse order
	LinkedList *temp;
	temp = new LinkedList;

	// Feed values backwards into temp list
	while (m_linkedList->is_Empty() == false)
	{ 

		temp->insert_front(pop());
	}

	// Feed values from temp back into the main list, taking care to add to back to
	// to ensure new order is preserved
	while (temp->is_Empty() == false)
	{

		m_linkedList->append(temp->get_front());
		temp->remove_front();
	}

	// Delete temporary list
	delete temp;
}

void Stack::writeToFile(std::string fileName)
{
	m_linkedList->writeFile(fileName);
}

void Stack::readFromFile(std::string fileName)
{
	// Clear the current Stack before reading in new data
	clear();
	m_linkedList->readFile(fileName);
}

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList() {
	Node *tempPtr = head;
	Node *tempPtr2;

	while (tempPtr != nullptr) {
		tempPtr2 = tempPtr->get_nextptr();
		delete tempPtr;
		tempPtr = tempPtr2;
	}
}


void LinkedList::insert_front(std::string d) {
	Node *newNode = new Node(d, head);
	head = newNode;
}

void LinkedList::append(std::string d) {
	if (head == nullptr) {
		insert_front(d);
	}
	else {
		Node *tempPtr = head;
		while (tempPtr->get_nextptr() != nullptr) {
			tempPtr = tempPtr->get_nextptr();
		}
		Node *newNode = new Node(d, nullptr);
		tempPtr->set_nextptr(newNode);
	}
}

void LinkedList::display() {
	Node *tempPtr = head;
	while (tempPtr != nullptr) {
		tempPtr->Node::display();
		tempPtr = tempPtr->get_nextptr();
	}
}

void LinkedList::display_nth(unsigned int nth) {
	unsigned int count = nth;
	Node *tempPtr = head;
	while (tempPtr != nullptr) {
		if (count == 0) {
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
	if (nth == 0) {
		if (currentNode != nullptr) {
			head = currentNode->get_nextptr();
			delete currentNode;
		}
		return;
	}

	while (currentNode != nullptr) {
		if (count == 0) {
			prevNode->set_nextptr(currentNode->get_nextptr());
			delete currentNode;
			return;
		}
		count--;
		prevNode = currentNode;
		currentNode = currentNode->get_nextptr();
	}
}


void LinkedList::insert_before_nth(unsigned int nth, std::string d) {
	if (nth == 0) {
		insert_front(d);
		return;
	}

	Node *prevNode = nullptr;
	Node *currentNode = head;
	unsigned int count = nth;

	while (currentNode != nullptr) {
		if (count == 0) {
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
		return 1;
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

std::string LinkedList::get_front()
{
	return head->get_data();
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

void LinkedList::displayReverse()
{
	Node *lastPtr;
	Node *tempPtr = head;
	
	// Set and print lastPtr
	while (tempPtr->get_nextptr() != nullptr)
	{
		tempPtr = tempPtr->get_nextptr();
	}
	lastPtr = tempPtr;
	lastPtr->Node::display();
	tempPtr = head;
	
	// Iterate through, printing last node every time
	while (lastPtr != head)
	{
		while (tempPtr->get_nextptr() != lastPtr)
		{
			tempPtr = tempPtr->get_nextptr();
		}
		tempPtr->Node::display();
		lastPtr = tempPtr;
		tempPtr = head;
	}

}

void LinkedList::writeFile(std::string fileName)
{
	// Open file with read permission and ensure it is empty
	file.open(fileName, std::ios::out);
	file.clear();

	// Loop through list writing every element to a new line
	Node *tempPtr = head;
	while (tempPtr != nullptr)
	{
		file << tempPtr->get_data() << std::endl;
		tempPtr = tempPtr->get_nextptr();
	}

	file.close();

}

void LinkedList::readFile(std::string fileName)
{
	// Open file with write permission
	file.open(fileName, std::ios::in);

	std::string data;

	while (!file.eof())
	{
		file >> data;
		insert_front(data);
	}

	file.close();
}

#include "Node.h"
#include <iostream>

Node::Node()
{
	data = " ";
	nextptr = nullptr;
}

Node::Node(std::string d, Node *np) {
	data = d;
	nextptr = np;
}

Node::~Node() {

}

std::string Node::get_data() {
	return data;
}

Node *Node::get_nextptr() {
	return nextptr;
}

void Node::set_data(std::string d) {
	data = d;
}

void Node::set_nextptr(Node *np) {
	nextptr = np;
}

void Node::display() {
	std::cout << get_data() << std::endl;
}

#include "Queue.h"


Queue::Queue()
{
	m_linkedList = new LinkedList();
}


Queue::~Queue()
{
	delete m_linkedList;
	m_linkedList = NULL;
}

void Queue::push(std::string data)
{
	m_linkedList->append(data);
}

std::string Queue::pop()
{
	std::string data;
	data = m_linkedList->get_front();
	m_linkedList->remove_front();

	return data;
}

bool Queue::checkEmpty()
{
	return m_linkedList->is_Empty();
}

void Queue::display()
{
	m_linkedList->display();
}

void Queue::displayReverse()
{
	m_linkedList->displayReverse();
}

void Queue::clear()
{
	while (!m_linkedList->is_Empty())
	{
		m_linkedList->remove_back();
	}
}

void Queue::reverseList()
{
	// Temporary list that will be fed the values in reverse order
	LinkedList *temp;
	temp = new LinkedList;

	// Feed values backwards into temp list
	while (m_linkedList->is_Empty() == false)
	{

		temp->insert_front(pop());
	}

	// Feed values from temp back into the main list, taking care to add to back to
	// to ensure new order is preserved
	while (temp->is_Empty() == false)
	{

		m_linkedList->append(temp->get_front());
		temp->remove_front();
	}

	// Delete temporary list
	delete temp;
}

void Queue::writeToQueue(std::string fileName)
{
	m_linkedList->writeFile(fileName);
}

void Queue::readFromFile(std::string fileName)
{
	// Clear the current Queue before reading in new data
	clear();
	m_linkedList->readFile(fileName);
}

#include "MainProg.h"


MainProg::MainProg()
{
}


MainProg::~MainProg()
{
	delete stack;
	delete queue;
}

void MainProg::handle_setUp()
{
	std::cout << "============================================================\n\n";

	std::cout << "Creating and populating Stack..\n\n";

	// Push data to the stack	
	std::cout << "Stack Push-> Alpha" << std::endl;
	stack->push("Alpha");

	std::cout << "Push-> Beta" << std::endl;
	stack->push("Beta");

	std::cout << "Push-> Gamma" << std::endl;
	stack->push("Gamma");

	std::cout << "Push-> Delta" << std::endl;
	stack->push("Delta");

	std::cout << "Push-> Epsilon" << std::endl;
	stack->push("Epsilon");

	std::cout << "Push-> Zeta" << std::endl;
	stack->push("Zeta");

	std::cout << "Push-> Eta" << std::endl;
	stack->push("Eta");

	std::cout << "Done. \n\n";

	
	std::cout << "Creating and populating Queue..\n\n";

	// Push data to the queue
	std::cout << "Push-> Phantom" << std::endl;
	queue->push("Phantom");

	std::cout << "Push-> Tomcat" << std::endl;
	queue->push("Tomcat");

	std::cout << "Push-> Eagle" << std::endl;
	queue->push("Eagle");

	std::cout << "Push-> Falcon" << std::endl;
	queue->push("Falcon");

	std::cout << "Push-> Hornet" << std::endl;
	queue->push("Hornet");

	std::cout << "Push-> Raptor" << std::endl;
	queue->push("Raptor");

	std::cout << "Push-> Lightning" << std::endl;
	queue->push("Lightning");

	std::cout << "Done. \n\n";
}

void MainProg::handle_clearStack()
{
	std::cout << "============================================================\n\n";

	std::cout << "Clearing Stack..\n";
	stack->clear();
	std::cout << "Stack cleared\n\n";
}

void MainProg::handle_pushStack(std::string data)
{
	std::cout << "============================================================\n\n";

	std::cout << "Pushing " << data << " to Stack..\n";
	stack->push(data);
	std::cout << "Done.\n\n";
}

void MainProg::handle_popStack()
{
	std::cout << "============================================================\n\n";

	if (stack->checkEmpty())
	{
		std::cout << "The Stack is empty\n\n";
	}
	else
	{
		std::cout << stack->pop() << " has been popped from Stack\n\n";

	}
}

void MainProg::handle_displayReverseStack()
{
	std::cout << "============================================================\n\n";

	if (stack->checkEmpty())
	{
		std::cout << "The Stack is empty\n\n";
	}
	else
	{
		std::cout << "--- Display Stack in reverse order ---\n\n";
		stack->displayReverse();
	}
}

void MainProg::handle_reverseStack()
{
	std::cout << "============================================================\n\n";

	if (stack->checkEmpty())
	{
		std::cout << "The Stack is empty\n\n";
	}
	else
	{
		std::cout << "Reversing Stack..\n";
		stack->reverseList();
		std::cout << "Done.\n\n";
	}
}

void MainProg::handle_displayStack()
{
	std::cout << "============================================================\n\n";

	if (stack->checkEmpty())
	{
		std::cout << "The Stack is empty\n";
	}
	else
	{
		std::cout << "--- Display Stack ---\n\n";
		stack->display();
		stack->writeToFile("Stack.txt");
	}	
}

void MainProg::handle_clearQueue()
{
	std::cout << "============================================================\n\n";

	std::cout << "Clearing Queue..\n";
	queue->clear();
	std::cout << "Queue cleared\n\n";
}

void MainProg::handle_pushQueue(std::string data)
{
	std::cout << "============================================================\n\n";

	std::cout << "Pushing " << data << " to Queue..\n";
	queue->push(data);
	std::cout << "Done.\n\n";
}

void MainProg::handle_popQueue()
{
	std::cout << "============================================================\n\n";

	if (queue->checkEmpty())
	{
		std::cout << "The Queue is empty\n\n";
	}
	else
	{
		std::cout << queue->pop() << " has been popped from Queue\n\n";
	}
}

void MainProg::handle_displayReverseQueue()
{
	std::cout << "============================================================\n\n";

	if (queue->checkEmpty())
	{
		std::cout << "The Queue is empty\n\n";
	}
	else
	{
		std::cout << "--- Display Queue in reverse order ---\n\n";
		queue->displayReverse();
		std::cout << "\n";
	}
}

void MainProg::handle_displayQueue()
{
	std::cout << "============================================================\n\n";

	if (queue->checkEmpty())
	{
		std::cout << "The Queue is empty\n\n";
	}
	else
	{
		std::cout << "--- Display Queue ---\n\n";
		queue->display();
		std::cout << "\n";
	}
}

void MainProg::handle_reverseQueue()
{
	std::cout << "============================================================\n\n";

	if (queue->checkEmpty())
	{
		std::cout << "The Queue is empty\n\n";
	}
	else
	{
		std::cout << "Reversing Queue..\n";
		queue->reverseList();
		std::cout << "Done.\n\n";
	}
}

void MainProg::handle_writeStack()
{
	std::cout << "============================================================\n\n";

	if (stack->checkEmpty())
	{
		std::cout << "There is nothing in the Stack to write\n\n";
	}
	else
	{
		std::cout << "Writing to Stack..\n";
		std::string fileName = "Stack.txt";
		stack->writeToFile(fileName);
		std::cout << "Done.\n\n";
	}
}

void MainProg::handle_readStack()
{
	std::cout << "============================================================\n\n";

	std::cout << "Reading Stack from file..\n";
	std::string fileName = "Stack.txt";
	stack->readFromFile(fileName);
	std::cout << "Done.\n\n";
}

void MainProg::handle_writeQueue()
{
	std::cout << "============================================================\n\n";

	if (queue->checkEmpty())
	{
		std::cout << "There is nothing in the Queue to write\n\n";
	}
	else
	{
		std::cout << "Writing to Queue..\n";
		std::string fileName = "Queue.txt";
		queue->writeToQueue(fileName);
		std::cout << "Done.\n\n";
	}
}

void MainProg::handle_readQueue()
{
	std::cout << "============================================================\n\n";

	std::cout << "Reading Queue from file..\n";
	std::string fileName = "Queue.txt";
	queue->readFromFile(fileName);
	std::cout << "Done.\n\n";
}

bool MainProg::isMenuInputValid(char input)
{
	if (input == 'a' ||
		input == 'b' ||
		input == 'c' ||
		input == 'd' ||
		input == 'e' ||
		input == 'f' ||
		input == 'g' ||
		input == 'h' ||
		input == 'i' ||
		input == 'j' ||
		input == 'k' ||
		input == 'q' ||
		input == 'm' ||
		input == 'o' ||
		input == 'p' ||
		input == 'r' ||
		input == 's' ||
		input == 't' ||
		input == 'u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MainProg::printMenu()
{
	system("cls");
	std::cout << "============================================================";
	std::cout << "\n\n---- Main Menu ----\n\n"
		<< "a - Create and populate the Stack and Queue\n"
		<< "\n"
		<< "b - Clear the Stack\n"
		<< "c <string> - Push onto the Stack\n"
		<< "d - Pop from the Stack\n"
		<< "e - Display Stack in reverse\n"
		<< "f - Display the Stack\n"
		<< "o - Reverse the Stack order\n"
		<< "r - Read from Stack.txt\n"
		<< "s - Write to Stack.txt\n"
		<< "\n"
		<< "g - Clear the Queue\n"
		<< "h <string> - Push onto the Queue\n"
		<< "i - Pop from the Queue\n"
		<< "j - Display the Queue in reverse\n"
		<< "k - Display the Queue\n"
		<< "p - Reverse the Queue order\n"
		<< "t - Read from Queue.txt\n"
		<< "u - Write to Queue.txt\n"
		<< "\n"
		<< "q - Quit program\n\n";
}

void MainProg::menuLoop()
{

	// Create Stack and Queue objects here to make sure they exist before triggering any functions
	queue = new Queue;
	stack = new Stack;

	// Clear the stack after initialisation to ensure no strange artifacts
	queue->clear();
	stack->clear();

	// Print Menu
	printMenu();

	char command = 'q';
	std::string data;

	// Menu Loop
	while (true)
	{
		// Loop until command is valid

		std::cout << "m - Redisplay the menu (Clears the screen)\n";
		std::cout << "Input command: ";
		std::cin >> command;
		isMenuInputValid(command);

		while (isMenuInputValid(command) == false)
		{
			std::cout << "Error, '" << command << "' is not a valid input. Try again: ";
			std::cin >> command;
		}


		switch(command)
		{
		case 'a':
			handle_setUp();
			break;
			
		case 'b':
			handle_clearStack();
			break;

		case 'c':
			std::cin >> data;
			handle_pushStack(data);
			break;

		case 'd':
			handle_popStack();
			break;

		case 'e':
			handle_displayReverseStack();
			break;

		case 'f':
			handle_displayStack();
			break;

		case 'g':
			handle_clearQueue();
			break;

		case 'h':
			std::cin >> data;
			handle_pushQueue(data);
			break;

		case 'i':
			handle_popQueue();
			break;

		case 'j':
			handle_displayReverseQueue();
			break;

		case 'k':
			handle_displayQueue();
			break;

		case 'm':
			printMenu();
			break;

		case 'o':
			handle_reverseStack();
			break;

		case 'p':
			handle_reverseQueue();
			break;

		case 'r':
			handle_readStack();
			break;

		case 's':
			handle_writeStack();
			break;

		case 't':
			handle_readQueue();
			break;

		case 'u':
			handle_writeQueue();
			break;

		case 'q':
			break;
		}

		// Break menu loop
		if (command == 'q')
		{
			break;
		}
	}
}

#include "MainProg.h"

int main()
{
	MainProg *mainProg;

	mainProg = new MainProg;

	mainProg->menuLoop();

	delete mainProg;
	mainProg = NULL;

	return 0;
}


