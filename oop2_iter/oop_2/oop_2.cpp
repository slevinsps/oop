#include "stdafx.h"
#include <iostream>
#include "base_list.h"
#include "clist.h"
#include "iterator.h"
#include <cstdlib>
#include <vector>


int main()
{
	try
	{
		int len = 5;
		int *arr = (int*)malloc(sizeof(int) * len);
		for (int i = 0; i < len; i++)
		{
			arr[i] = i;
		}

		myList::Clist<int> list(5, arr);
		std::cout << list << "\n";
		//std::cout << list.get_element(-3) << "\n";
		myList::Clist<int> list_list = {1,2,3,4,-1,5,8};
		std::cout << list_list << "\n";

		myList::Iterator_list<int> my_it = list_list.begin();
		/*for (int i = 0; i < 2; i++)
		{
			my_it++;
		}*/
		my_it.remove_elem();
		std::cout << list_list << "\n";
		myList::Clist<int> list_copy(list);
		std::cout << list_copy << "\n";
		list.pop_back();
		list.push_back(4);
		std::cout << "!!! " << (list == list_copy) << "\n";

		list.merge_list(list_copy);
		std::cout << list << "\n";
		std::cout << list << "\n";

		myList::Clist<int> list3(3, arr);
		std::cout << list3 << "1\n";
		list3 = list;
		std::cout << list3 << "\n";
		list3.pop_begin();
		std::cout << list3 << "\n";
		list3.push_back(10);
		std::cout << list3 << "\n";
		list3.push_begin(10);
		std::cin >> list3;
		std::cout << list3 << "sdsdsdsd\n";
		//int p = list3.get_element(-1);
		list3.pop_begin();
		std::cout << list3 << "\n";
		list3.pop_back();
		std::cout << list3 << "\n";
		std::cout << list3 << "\n"; 
	}
	catch (BaseException ex)
	{
		std::cout << ex.what();
	}

	system("pause");



    return 0;
}

