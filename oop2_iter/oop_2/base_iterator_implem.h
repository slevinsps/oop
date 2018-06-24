#pragma once
#include "base_iterator.h"
namespace myList
{
	template <typename T>
	base_iterator<T>::base_iterator() {}
	
	template <typename T>
	base_iterator<T>::base_iterator(const base_iterator<T> &it)
	{
		this->m_node = it.m_node;
	}

	template<typename T>
	base_iterator<T>::base_iterator(std::shared_ptr<Node<T>> ptr) {
		this->m_node = ptr;
	}

	template <typename T>
	base_iterator<T>::~base_iterator()
	{
		m_node.reset();
	}

	template <typename T>
	bool base_iterator<T>::operator==(const base_iterator& other) const
	{
		if (this == &other) {
			return true;
		}
		return m_node.lock().get() == other.m_node.lock().get();
	}

	// Проверка на неравенство
	template <typename T>
	bool base_iterator<T>::operator!=(const base_iterator& other) const
	{
		return !operator==(other);
	}

	template<typename T>
	base_iterator<T>& base_iterator<T>::operator=(const base_iterator <T>& iter) 
	{
		if (this != &iter) {
			this->m_node = iter.m_node;
		}
		return *this;
	}
	
	// Переход к следующему узлу
	template <typename T>
	base_iterator<T> &base_iterator<T>::operator++()
	{
		if (m_node.lock())
			m_node = m_node.lock()->get_next();
		return *this;
	}

	template <typename T>
	void base_iterator<T>::insert_elem(T elem)
	{
		std::shared_ptr<Node<T>> my_node = std::shared_ptr<Node<T>>(new Node<T>);

		my_node->set_data(elem);
		my_node->set_next(m_node.lock()->get_next());
		m_node.lock()->set_next(my_node);
	}

	template <typename T>
	void base_iterator<T>::remove_elem(void)
	{
		std::shared_ptr<Node<T>> my_node = m_node.lock()->get_next();
		if (my_node)
		{
			m_node.lock()->set_next(my_node->get_next());
		}
		my_node.reset();
	}

	template <typename T>
	base_iterator<T> base_iterator<T>::operator++(int)
	{
		base_iterator<T> tmp(*this);
		if (m_node.lock())
			m_node = m_node.lock()->get_next();
		return tmp;
	}	

	template <typename T>
	bool base_iterator<T>::check_null()
	{
		if (m_node.lock())
			return false;
		else
			return true;
	}

}