#pragma once
#include "iterator.h"
namespace myList
{
	template <typename T>
	Iterator_list<T>::Iterator_list() : myList::base_iterator<T>() {};

	template <typename T>
	Iterator_list<T>::Iterator_list(const Iterator_list<T> &it) : myList::base_iterator<T>(it) {};

	template <typename T>
	Iterator_list<T>::Iterator_list(std::shared_ptr<Node<T>> ptr) : myList::base_iterator<T>(ptr) {};


	// Получение значения текущего узла
	template <typename T>
	const T& Iterator_list<T>::operator*() const
	{
		if (!this->m_node.lock())
			throw AccessException();
		return this->m_node.lock()->get_data();
	}

	template <typename T>
	const T* Iterator_list<T>::operator->() const
	{
		if (!this->m_node.lock())
			throw AccessException();
		return m_node.lock()->get_data();
	}

	template <typename T>
	T& Iterator_list<T>::operator*()
	{
		if (!this->m_node.lock())
			throw AccessException();
		return this->m_node.lock()->get_data();
	}

	template <typename T>
	T* Iterator_list<T>::operator->()
	{
		if (!this->m_node.lock())
			throw AccessException();
		return m_node.lock()->get_data();
	}


	template <typename T>
	const_Iterator_list<T>::const_Iterator_list() : myList::base_iterator<T>() {};

	template <typename T>
	const_Iterator_list<T>::const_Iterator_list(const const_Iterator_list<T> &it) : myList::base_iterator<T>(it) {};

	template <typename T>
	const_Iterator_list<T>::const_Iterator_list(std::shared_ptr<Node<T>> ptr) : myList::base_iterator<T>(ptr) {};


	// Получение значения текущего узла
	template <typename T>
	const T& const_Iterator_list<T>::operator*() const
	{
		if (!this->m_node.lock())
			throw AccessException();
		return this->m_node.lock()->get_data();
	}

	template <typename T>
	const T* const_Iterator_list<T>::operator->() const
	{
		if (!this->m_node.lock())
			throw AccessException();
		return m_node.lock()->get_data();
	}
}