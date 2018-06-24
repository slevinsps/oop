#pragma once
#include "stdafx.h"
#include "base_list.h"
#include "exceptions.h"

#include <iostream>
namespace myList
{
	Base_list::Base_list() : length(0) {}
	Base_list::Base_list(size_t len)
	{
		if ((int)len < 0)
			throw RangeException("in constructor ", -1);
		length = len;	
	}
	Base_list::~Base_list()
	{
		length = 0;
	}
	size_t Base_list::size() const
	{
		return length;
	}
	bool Base_list::empty() const
	{
		if (length > 0)
			return true;
		else
			return false;
	}
}