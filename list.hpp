#include "list.h"

List::List(const std::string& str)
{
	head = new Node(str);
	tail = head;
}

List::List(const List& other)
{
	const Node* curr = other.head;
	if (curr)
	{
		head = tail = new Node(curr->val);
		curr = curr->next;
	}
	
	Node* tmp = tail;
	while (curr)
	{
		tail = new Node(curr->val, nullptr, tmp);
		tmp->next = tail;
		tmp = tail;
		curr = curr->next;
	}
}

List& List::operator=(const List& other)
{
	if (this == &other)
		return *this;

	tail = head;
	while (tail)
	{
		tail = head->next;
		delete head;
		head = tail;
	}

	const Node* curr = other.head;
	if (curr)
	{
		head = tail = new Node(curr->val);
		curr = curr->next;
	}
	
	Node* tmp = tail;
	while (curr)
	{
		tail = new Node(curr->val, nullptr, tmp);
		tmp->next = tail;
		tmp = tail;
		curr = curr->next;
	}

	return *this;
}

List::~List()
{
	if (head)
	{
		tail = head;
		while (tail)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
		head = tail = nullptr;
	}
}

void List::push_back(const std::string& str)
{
	if (! tail)
	{
		head = tail = new Node(str);
	}
	else
	{
		Node* tmp = new Node(str, nullptr, tail);
		tail->next = tmp;
		tail = tmp;
	}
}

void List::push_front(const std::string& str)
{
	if (! head)
	{
		head = tail = new Node(str);
	}
	else
	{
		Node* tmp = new Node(str, head, nullptr);
		head->prev = tmp;
		head = tmp;
	}
}

void List::pop_back()
{
	if (tail)
	{
		if (! tail->prev)
		{
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			Node* tmp = tail->prev;
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}
	}
}

void List::pop_front()
{
	if (head)
	{
		if (! head->next)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* tmp = head->next;
			delete head;
			head = tmp;
			head->prev = nullptr;
		}
	}
}

void List::print_from_head() const
{
	if (! head)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		Node* curr = head;
		while (curr)
		{
			std::cout << curr->val << " ";
			curr = curr->next;
		}
		std::cout << std::endl;

	}
}

void List::print_from_tail() const
{
	if (! tail)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		Node* curr = tail;
		while (curr)
		{
			std::cout << curr->val << " ";
			curr = curr->prev;
		}
		std::cout << std::endl;
	}
}

std::string List::get(int which)
{
	if (which < 1)
	{
		return "";
	}
	if (! head)
	{
		return "";
	}

	int count = 1;
	Node* curr = head;
	while (curr && count != which)
	{
		curr = curr->next;
		++count;
	}

	return curr->val;
}

void List::clear()
{
	if (head)
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
		head = tail = nullptr;
	}
}
