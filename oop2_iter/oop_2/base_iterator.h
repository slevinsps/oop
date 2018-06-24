#pragma once
namespace myList
{
	template <typename T>
	class base_iterator
	{
	public:
		base_iterator();
		base_iterator(const base_iterator<T> &);
		base_iterator(std::shared_ptr<Node<T>> ptr);

		virtual ~base_iterator();

		base_iterator<T> &operator=(const base_iterator<T> &);

		base_iterator<T> &operator++();

		base_iterator<T> operator++(int);

		void insert_elem(T elem);

		void remove_elem(void);

		bool operator==(const base_iterator &other) const;

		bool operator!=(const base_iterator &other) const;

		bool check_null();

	protected:
		std::weak_ptr<Node<T>> m_node;
	};

}
#include "base_iterator_implem.h"
