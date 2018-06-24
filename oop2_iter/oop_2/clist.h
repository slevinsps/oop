#pragma once
#include "iterator.h"

#include "node.h"

#include <ostream> 
#include <initializer_list>
#include "base_list.h"
#include <memory>
namespace myList
{
	template <typename T>
	class Clist : public myList::Base_list
	{
	public:
		Clist();
		Clist(std::initializer_list<T> list);
		Clist(size_t len, const T* array);
		explicit Clist(const Clist<T>& obj);
		Clist(Clist<T>&& obj);
		virtual ~Clist();

		const T& get_head(void) const;
		T& get_head();

		const T get_tail(void) const;
		T get_tail(void);

		void push_back(const T& element);
		void push_begin(T element);
//		void pop_back(void);
		void pop_begin(void);
		void merge_list(const Clist<T>& merge_list);


		Clist<T>& operator= (const Clist<T>& obj);
		Clist<T>& operator=(Clist<T>&& obj);


		const_Iterator_list<T> begin() const;
		const_Iterator_list<T> end() const;
		Iterator_list<T> begin();
		Iterator_list<T> end();
		
		template <typename T>
		friend std::ostream& operator<<(std::ostream& os, const Clist<T>& obj);
		template <typename T>
		friend std::istream& operator>>(std::istream& os, Clist<T>& obj);
		template <typename T>
		friend bool operator==(const Clist<T>& L1, const Clist<T>& L2);
		template <typename T>
		friend bool operator!=(const Clist<T>& L1, const Clist<T>& L2);
		void clear(void);

	private:
		std::shared_ptr<Node<T>> head;
		std::shared_ptr<Node<T>> tail;
	};
}

#include "clist_implem.h"