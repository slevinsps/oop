#pragma once
#include "node.h"
#include "base_iterator.h"
namespace myList 
{
	template <typename T>
	class Iterator_list : public myList::base_iterator<T>
	{
	public:
		Iterator_list();
		Iterator_list(const Iterator_list<T>& iter);
		Iterator_list(std::shared_ptr<Node<T>> ptr);
		const T& operator*() const;
		const T* operator->() const;
		T& operator*();
		T* operator->();
	};


	template <typename T>
	class const_Iterator_list : public myList::base_iterator<T>
	{
	public:
		const_Iterator_list();
		const_Iterator_list(const const_Iterator_list<T>& iter);
		const_Iterator_list(const std::shared_ptr<Node<T>> ptr);
		const T& operator*() const;
		const T* operator->() const;
	};
}

#include "iterator_implem.h"