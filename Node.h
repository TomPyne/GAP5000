#pragma once
class Node
{
public:
	static unsigned int serialNumber;
	Node();
	Node::Node(int d, Node *np);
	~Node();
	int get_data();
	Node *get_nextptr();
	void set_data(int d);
	void set_nextptr(Node *np);
	void display();
	unsigned int get_id_number();
private: 
	int data;
	unsigned int idNumber;
	Node *nextptr;
};

