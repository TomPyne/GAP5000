#pragma once

#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insert_front(int d);
	void append(int d);
	void display();
	void display_nth(unsigned int nth);
	void delete_nth(unsigned int nth);
	void insert_before_nth(unsigned int nth, int d);
	void display_id(unsigned int id);
	bool is_Empty();
	int remove_front();
	void remove_back();
	void get_front();
	void get_back();
private:
	Node *head;
};

