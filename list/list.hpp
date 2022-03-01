template <typename T>
myl::list<T>::list(const list<T>& other)
{
	const Node<T>* curr = other.head;
	if (curr)
	{
		head = tail = new Node<T>(curr->val);
		curr = curr->next;
	}
	
	Node<T>* tmp = tail;
	while (curr)
	{
		tail = new Node<T>(curr->val, nullptr, tmp);
		tmp->next = tail;
		tmp = tail;
		curr = curr->next;
	}
}

template <typename T>
myl::list<T>& myl::list<T>::operator=(const list& other)
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

	const Node<T>* curr = other.head;
	if (curr)
	{
		head = tail = new Node<T>(curr->val);
		curr = curr->next;
	}
	
	Node<T>* tmp = tail;
	while (curr)
	{
		tail = new Node<T>(curr->val, nullptr, tmp);
		tmp->next = tail;
		tmp = tail;
		curr = curr->next;
	}

	return *this;
}

template <typename T>
myl::list<T>::list(list<T>&& rv) noexcept
{
	head = rv.head;
	tail = rv.tail;
	rv.head = nullptr;
	rv.tail = nullptr;
}

template <typename T>
myl::list<T>& myl::list<T>::operator=(list&& rv) noexcept
{
	if (this == &rv)
		return *this;

	tail = head;
	while (tail)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	head = rv.head;
	tail = rv.tail;
	rv.head = nullptr;
	rv.tail = nullptr;
	return *this;
}

template <typename T>
myl::list<T>::~list()
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

template <typename T>
typename myl::list<T>::iterator myl::list<T>::push_back(const T& elem)
{
	if (! tail)
	{
		head = tail = new Node<T>(elem);
		tail->next = new Node<T> (T(),nullptr,tail);
		return head;
	}
	else
	{
		Node<T>* new_node = new Node<T>(elem, tail->next , tail);
		tail->next = new_node;
		new_node->next->prev = new_node;
		tail = new_node;
		return new_node;
	}
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::push_front(const T& elem)
{
	if (! head)
	{
		Node<T>* new_node = new Node<T>(elem);
		head = tail = new_node;
		tail->next = new Node<T> (T(),nullptr,tail);
		return head;
	}
	else
	{
		Node<T>* new_node = new Node<T>(elem, head, nullptr);
		head->prev = new_node;
		head = new_node;
		return new_node;
	}
}

template <typename T>
void myl::list<T>::pop_back()
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
			Node<T>* tmp = tail->prev;
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}
	}
}

template <typename T>
void myl::list<T>::pop_front()
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
			Node<T>* tmp = head->next;
			delete head;
			head = tmp;
			head->prev = nullptr;
		}
	}
}

template <typename T>
void myl::list<T>::clear()
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


template <typename T>
myl::list<T>::iterator::iterator(myl::list<T>::Node<T> * node)
{
    it = node;
}

template <typename T>
myl::list<T>::iterator::iterator(const iterator& other)
{
    it = other.it;
}

template <typename T>
myl::list<T>::iterator::iterator(iterator&& other) noexcept
{
    it = other.it;
    other.it = nullptr;
}

template <typename T>
typename myl::list<T>::iterator& myl::list<T>::iterator::operator=(const iterator& other)
{
    it = other.it;
    return *this;
}

template <typename T>
typename myl::list<T>::iterator& myl::list<T>::iterator::operator=(iterator&& other) noexcept
{
    it = other.it;
    other.it = nullptr;
    return *this;
}

template <typename T>
typename myl::list<T>::iterator& myl::list<T>::iterator::operator++()
{
    it = it->next;
    return *this;
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::iterator::operator++(int)
{
    iterator tmp = it;
    it = it->next;
    return tmp;
}

template <typename T>
typename myl::list<T>::iterator& myl::list<T>::iterator::operator--()
{
    it = it->prev;
    return *this;
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::iterator::operator--(int)
{
    iterator tmp = it;
    it = it->prev;
    return tmp;
}

template <typename T>
bool myl::list<T>::iterator::operator!=(const iterator& rv) const
{
    return this->it != rv.it;
}

template <typename T>
const T& myl::list<T>::iterator::operator*() const
{
    return it->val;
}

template <typename T>
T& myl::list<T>::iterator::operator*()
{
    return it->val;
}

template <typename T>
T* myl::list<T>::iterator::operator->()
{
    return &it->val;
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::begin()
{
    return iterator(head);
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::end()
{
    return iterator(tail->next);
}

template <typename T>
typename myl::list<T>::iterator myl::list<T>::insert(iterator it,const T& elem)
{
	if(it.it == nullptr)
	{

		return push_front(elem);
	}
	else if(it.it->prev != nullptr && it.it->next != nullptr)
	{

		Node<T> * new_node = new Node<T>(elem, it.it, it.it->prev);
		it.it->prev->next = new_node;
		return new_node;
	} 
	else if(it.it->prev == nullptr && it.it->next != nullptr)
	{
		return push_front(elem);
	}
	else
	{
		return push_back(elem);
	}
}

template <typename T>
void myl::list<T>::erase(iterator it)
{
    if(it.it->prev != nullptr && it.it->next->next != nullptr)
	{
		Node<T>* tmp = it.it;
		it.it->prev->next = it.it->next;
		it.it->next->prev = it.it->prev;
		delete tmp;
	} 
	else if(it.it->prev == nullptr && it.it->next != nullptr)
	{
		pop_front();
	}
	else
	{
		pop_back();
	}
}

template <typename T>
size_t myl::list<T>::size() const
{
	if(head == nullptr) return 0;
	size_t size_count{};
	Node<T> * cur = head;
	while(cur->next != nullptr)
	{
		++size_count;
		cur = cur->next;
	}
	return size_count;
}