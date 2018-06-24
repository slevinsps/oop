#pragma once
#include "clist.h"
#include <ostream> 
#include "exceptions.h"

#include <iostream>
#include <initializer_list>
#include "node.h"
#include <memory>

namespace myList
{
	template <typename T>
	Clist<T>::Clist() : myList::Base_list(0)
	{
		head = nullptr;
		tail = nullptr;
	}

	template <typename T>
	Clist<T>::Clist(std::initializer_list<T> list) : myList::Base_list(list.size())
	{
		head = nullptr;
		tail = nullptr;
		std::shared_ptr<Node<T>> my_node;
		for (auto elem : list)
		{
			try
			{
				my_node = std::shared_ptr<Node<T>>(new Node<T>);
			}
			catch (std::bad_alloc)
			{
				clear();
				throw MemoryException();
			}

			my_node->set_next(nullptr);
			my_node->set_data(elem);

			if (!head)
			{
				head = my_node;
				tail = my_node;
				head->set_next(tail);
			}
			tail->set_next(my_node);
			tail = my_node;
		}
	}

	template <typename T>
	Clist<T>::Clist(size_t len, const T* array) : myList::Base_list(len)
	{
		std::shared_ptr<Node<T>> my_node;
		head = nullptr;
		tail = nullptr;
		for (int i = 0; i < len; i++)
		{
			try
			{
				my_node = std::shared_ptr<Node<T>>(new Node<T>);
			}
			catch(std::bad_alloc)
			{
				clear();
				throw MemoryException();
			}
			my_node->set_next(nullptr);
			my_node->set_data(array[i]);
			if (!head)
			{
				head = my_node;
				tail = my_node;
				head->set_next(tail);
			}
			tail->set_next(my_node);
			tail = my_node;
		}
	}
	template <typename T>
	Clist<T>::Clist(const Clist<T>& obj) : myList::Base_list(obj.size())
	{
		std::shared_ptr<Node<T>> my_node;
		head = nullptr;
		tail = nullptr;

		const_Iterator_list<T> it;
		for (it = obj.begin(); !it.check_null(); ++it)
		{
			try
			{
				my_node = std::shared_ptr<Node<T>>(new Node<T>);
			}
			catch(std::bad_alloc)
			{
				clear();
				throw MemoryException();
			}
			my_node->set_next(nullptr);
			my_node->set_data(*it);

			if (!head)
			{
				head = my_node;
				tail = my_node;
				head->set_next(tail);
			}
			tail->set_next(my_node);
			tail = my_node;
		}
	}

	template <typename T>
	Clist<T>::Clist(Clist<T>&& obj) : myList::Base_list(obj.size())
	{
		std::shared_ptr<Node<T>>
		head = nullptr;
		tail = nullptr;

		Iterator_list<T> it;
		for (it = obj.begin(); it != nullptr; ++it)
		{
			try
			{
				my_node = std::shared_ptr<Node<T>>(new Node<T>);
			}
			catch (std::bad_alloc)
			{
				clear();
				throw MemoryException();
			}
			my_node->set_next(nullptr);
			my_node->set_data(*it);

			if (!head)
			{
				head = my_node;
				tail = my_node;
				head->set_next(tail);
			}
			tail->set_next(my_node);
			tail = my_node;
		}
		obj.clear();
	}


	template <typename T>
	Clist<T>::~Clist()
	{
		std::shared_ptr<Node<T>> tmp;
		while (head)
		{
			tmp = head->get_next();
			head.reset();
			head = tmp;
			tmp.reset();
		}
	}

	template <typename T>
	void Clist<T>::clear(void)
	{
		std::shared_ptr<Node<T>> tmp;
		while (head)
		{
			tmp = head->get_next();
			head.reset();
			head = tmp;
			tmp.reset();
		}
		head = nullptr;
		tail = nullptr;
	}

	template <typename T>
	T& Clist<T>::get_head() 
	{
		return head->get_data();
	}

	template <typename T>
	const T& Clist<T>::get_head(void) const
	{
		return head->get_data();
	}

	template <typename T>
	const T Clist<T>::get_tail(void) const
	{
		return tail->get_data();
	}

	template <typename T>
	T Clist<T>::get_tail(void)
	{
		return tail->get_data();
	}


	template <typename T>
	void Clist<T>::push_back(const T& element)
	{
		try
		{
			std::shared_ptr<Node<T>> my_node = std::shared_ptr<Node<T>>(new Node<T>);
			my_node->set_next(nullptr);
			my_node->set_data(element);
			tail->set_next(my_node);
			tail = my_node;
			this->length++;
		}
		catch(std::bad_alloc)
		{
			throw MemoryException();
		}
	}

	template <typename T>
	void Clist<T>::push_begin(T element)
	{
		try
		{
			std::shared_ptr<Node<T>> my_node = std::shared_ptr<Node<T>>(new Node<T>);
			my_node->set_next(head);
			my_node->set_data(element);
			head = my_node;
			length++;
		}
		catch(std::bad_alloc)
		{
			throw MemoryException();
		}
	}

	template <typename T>
	void Clist<T>::pop_back(void)
	{
		if (head && tail)
		{
			if (tail == head)
			{
				tail.reset();
				tail = nullptr;
				head = nullptr;
			}
			else
			{
				Iterator_list<T> it;
				std::shared_ptr<Node<T>> my_node = head;

				for (it = begin(), it++; it != end(); ++it) 
				{
					my_node = my_node->get_next();
				}
				std::cout << my_node->get_data() << "\n";
			

				tail.reset();
				my_node->set_next(nullptr);
				tail = my_node;
			}
		}
		length--;
	}

	template <typename T>
	void Clist<T>::pop_begin(void)
	{
		if (head && tail)
		{
			if (tail == head)
			{
				tail.reset();
				tail = nullptr;
				head = nullptr;
			}
			else
			{
				std::shared_ptr<Node<T>> my_node = head->get_next();
				head.reset();
				head = my_node;
			}
		}
		length--;
	}

	template <typename T>
	void Clist<T>::merge_list(const Clist<T>& merge_list)
	{

		const_Iterator_list<T> it;
		std::shared_ptr<Node<T>>  my_node;

		for (it = merge_list.begin(); !it.check_null(); ++it)
		{
			my_node = std::shared_ptr<Node<T>>(new Node<T>(*it));
			tail->set_next(my_node);
			tail = my_node;
		}
		this->length += merge_list.size();
	}

	
	template <typename T>
	Clist<T>& Clist<T>::operator=(const Clist<T>& obj)
	{
		if (this != &obj)
		{
			std::shared_ptr<Node<T>> tmp;			
			while (head)
			{
				tmp = head->get_next();
				head.reset();
				head = tmp;
				tmp.reset();
			}


			std::shared_ptr<Node<T>>  my_node;
			head = nullptr;
			tail = nullptr;

			const_Iterator_list<T> it;
			for (it = obj.begin(); !it.check_null(); ++it)
			{
				try
				{
					my_node = std::shared_ptr<Node<T>>(new Node<T>);
				}
				catch (std::bad_alloc)
				{
					clear();
					throw MemoryException();
				}

				my_node->set_next(nullptr);
				my_node->set_data(*it);

				if (!head)
				{
					head = my_node;
					tail = my_node;
					head->set_next(tail);
				}
				tail->set_next(my_node);
				tail = my_node;
			}
			this->length = obj.size();
		}
		return *this;
	}

	template <typename T>
	Clist<T>& Clist<T>::operator=(Clist<T>&& obj)
	{
		if (this != &obj)
		{
			std::shared_ptr<Node<T>> tmp;
			while (head)
			{
				tmp = head->next;
				head.reset();
				head = tmp;
				tmp.reset();
			}

			std::shared_ptr<Node<T>>  my_node;
			head = nullptr;
			tail = nullptr;

			Iterator_list<T> it;
			for (it = obj.begin(); it != nullptr; ++it)
			{
				try
				{
					my_node = std::shared_ptr<Node<T>>(new Node<T>);
				}
				catch (std::bad_alloc)
				{
					clear();
					throw MemoryException();
				}

				my_node->set_next(nullptr);
				my_node->set_data(*it);

				if (!head)
				{
					head = my_node;
					tail = my_node;
					head->set_next(tail);
				}
				tail->set_next(my_node);
				tail = my_node;
			}
			this->length = obj.size();
			obj.clear();
		}
		return *this;
	}

	template< typename T >
	Iterator_list<T> Clist< T >::begin()
	{
		return Iterator_list<T>(head);
	}

	template< typename T >
	Iterator_list<T> Clist< T >::end()
	{
		return Iterator_list<T>(tail);
	}

	template< typename T >
	const_Iterator_list<T> Clist< T >::begin() const
	{
		return const_Iterator_list<T>(head);
	}

	template< typename T >
	const_Iterator_list<T> Clist< T >::end() const
	{
		return const_Iterator_list<T>(tail);
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Clist<T>& obj)
	{
		os << "[ ";
		const_Iterator_list<T> it = obj.begin();
		for (; !it.check_null(); ++it)
		{
			os << *it << " ";
		}
		os << "]";
		return os;
	}

	template <typename T>
	std::istream& operator>>(std::istream& os, Clist<T>& obj)
	{
		T data;
		os >> data;
		obj.push_back(data);
		return os;
	}

	template <typename T>
	bool operator==(const Clist<T>& L1, const Clist<T>& L2)
	{
		bool res = true;
		if (L1.size() != L2.size())
			return false;

		const_Iterator_list<T> it1 = L1.begin();
		const_Iterator_list<T> it2 = L2.begin();

		for (; res == true && !it1.check_null(); ++it1, ++it2)
		{
			if (*it1 != *it2)
				res = false;
		}
		return res;
	}
	template <typename T>
	bool operator!=(const Clist<T>& L1, const Clist<T>& L2)
	{
		return !(L1 == L2);
	}
}