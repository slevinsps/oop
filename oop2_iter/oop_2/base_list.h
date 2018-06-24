#pragma once
#include <iostream>

namespace myList
{
	class Base_list 
	{
	public:
		explicit Base_list();
		explicit Base_list(size_t len);
		virtual ~Base_list();
		size_t size() const;
		bool empty() const;
	protected:
		size_t length;
	};
}
#include "base_list_implem.h"

