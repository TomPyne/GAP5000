#include "Node.h"
#include <iostream>

unsigned int Node::serialNumber = 1000000;

Node::Node()
{
	idNumber = serialNumber;
	serialNumber++;
	data = 0;
	nextptr = nullptr;
}

Node::Node(int d, Node *np) {
	idNumber = serialNumber;
	serialNumber++;
	data = d;
	nextptr = np;
}

Node::~Node() {

}

int Node::get_data() {
	return data;
}

Node *Node::get_nextptr() {
	return nextptr;
}

void Node::set_data(int d) {
	data = d;
}

void Node::set_nextptr(Node *np) {
	nextptr = np;
}

void Node::display() {
	std::cout << idNumber << "    ";
	std::cout << get_data() << std::endl;
}

unsigned int Node::get_id_number() {
	return idNumber;
}

