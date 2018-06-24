#include "stdafx.h"
#include "base_list.h"
#include "exceptions.h"

#include <iostream>
using namespace myList;
Base_list::Base_list() : length(0) {}
Base_list::Base_list(size_t len)
{
	std::cout << "Hello\n";
	if (len < 0)
		throw RangeException();
	else
	{
		length = len;	
	}
}
Base_list::~Base_list()
{
	length = 0;
}
size_t Base_list::size() const
{
	return length;
}
