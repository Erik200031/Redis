#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "string.h"

class List
{
public:
	List() = default;
	List(const String& str);  
	List(const List& other);  
	List& operator=(const List& other);  
	~List();  

	void push_back(const String& str);
	void push_front(const String& str);
	void pop_back();
	void pop_front();
	void print_from_head() const;
	void print_from_tail() const;
	String get(int which) const;
	void clear();

private:
	struct Node
	{
		Node() = default;
		Node(String str, Node* n = nullptr, Node* p = nullptr) : val(str), next(n), prev(p) {}
		
		String val;
		Node* next{};
		Node* prev{};
	};

	Node* head{};
	Node* tail{};
};

#include "list.hpp"

#endif
