#ifndef LIST_H
#define LIST_H

#include <iostream>

namespace myl
{
	template <typename T>
	class list
	{
	private:
		template <typename U>
		struct Node
		{
			Node() = default;
			Node(const T& el, Node* n = nullptr, Node* p = nullptr) : val(el), next(n), prev(p) {}
			
			T val;
			Node* next{};
			Node* prev{};
		};
		
		Node<T>* head{};
		Node<T>* tail{};
	public:
		class iterator: public std::iterator<std::bidirectional_iterator_tag,T>
        {
        public:
            iterator(Node<T> * node = nullptr);
            iterator(const iterator&);
            iterator& operator=(const iterator&);
            iterator(iterator&&) noexcept;
            iterator& operator=(iterator&&) noexcept;
        public:
            iterator& operator++();
			iterator operator++(int);
			iterator& operator--();
            iterator operator--(int);
            bool operator!=(const iterator& other) const;
            const T& operator*() const;
            T& operator*();
			T* operator->();
			friend iterator list<T>::insert(iterator,const T&);
			friend void list<T>::erase(iterator);
        private:
            Node<T>* it;
        };
	public:
		list() = default;
		list(const list&);
		list& operator=(const list&);
		list(list&&) noexcept;
		list& operator=(list&&) noexcept;
		~list();
	public:
		iterator push_back(const T&);
		iterator push_front(const T&);

		void pop_back();
		void pop_front();
		void clear();
		size_t size() const;

		iterator begin();
		iterator end();
		iterator insert(iterator,const T&);
		void erase(iterator);

	};
}
#include "list.hpp"

#endif
