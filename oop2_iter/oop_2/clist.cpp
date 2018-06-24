#include "stdafx.h"
#include "clist.h"
namespace myList
{
	template <typename T>
	Clist<T>::Clist(size_t len) : myList::Base_list(len)
	{
		Node *my_node;
		front = nullptr;
		back = nullptr;
		for (int i = 0; i < len; i++)
		{
			my_node = new Node;
			my_node->next = front;
			my_node->data = (int)5;
			if (!back)
			{
				tail = my_node;
			}
			head = my_node;
		}
	}
}