#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>

class List
{
public:
	List() = default;
	List(const std::string& str);  //param ctor
	List(const List& other);  //copy
	List& operator=(const List& other);  //assignment
	~List();  //dtor

	void push_back(const std::string& str);
	void push_front(const std::string& str);
	void pop_back();
	void pop_front();
	void print_from_head() const;
	void print_from_tail() const;
	std::string get(int which);
	void clear();

private:
	struct Node
	{
		Node() = default;
		Node(std::string str, Node* n = nullptr, Node* p = nullptr) : val(str), next(n), prev(p) {}
		
		std::string val;
		Node* next{};
		Node* prev{};
	};

	Node* head{};
	Node* tail{};
};

#include "list.hpp"

#endif
