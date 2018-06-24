#include "stdafx.h"
#include "exceptions.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
BaseException::BaseException(const char *str)
{
	int len = strlen(str);
	msg = new char[len+1];
	memcpy(msg, str, len+1);
}

BaseException::BaseException(const char *str, const char *mesg)
{
	int len1 = strlen(str);
	int len = strlen(str) + strlen(mesg) + 1;
	msg = new char[len];
	if (!msg)
		return;
	memcpy(msg, str, len1 + 1);
	strcat_s(msg, len, mesg);
}

BaseException::BaseException(const char *str, const std::string& mesg)
{
	int len = strlen(str) + mesg.size() + 1;
	msg = new char[len];
	if (!msg)
		return;
	strcat_s(msg, len, mesg.c_str());
}

BaseException::BaseException(const char *str, const char *mesg, const char *time)
{
	int len1 = strlen(str);
	int len = strlen(str) + strlen(mesg) + strlen(time) + 1;
	msg = new char[len];
	if (!msg)
		return;
	memcpy(msg, str, len1 + 1);
	strcat_s(msg, len, mesg);
	strcat_s(msg, len, time);
}

BaseException::BaseException(const char *str, const char *mesg, int data)
{
	int len1 = strlen(str);
	int len = strlen(str) + strlen(mesg) + 11;
	msg = new char[len];
	if (!msg)
		return;
	memcpy(msg, str, len1 + 1);
	char data_s[10];
	_itoa_s(data, data_s, 10);
	strcat_s(msg, len, mesg);
	strcat_s(msg, len, data_s);
}

const char* BaseException::what() const
{
	return msg;
}

char memory_msg[] = "Memory error ";
char range_msg[] = "Range error ";
char null_msg[] = "Access error ";

MemoryException::MemoryException() : BaseException(memory_msg) {}
RangeException::RangeException() : BaseException(range_msg) {}
AccessException::AccessException() : BaseException(null_msg) {}

MemoryException::MemoryException(const char* mesg) : BaseException(memory_msg, mesg) {}
RangeException::RangeException(const char* mesg) : BaseException(range_msg, mesg) {}
AccessException::AccessException(const char* mesg) : BaseException(null_msg, mesg) {}

MemoryException::MemoryException(const std::string& mesg) : BaseException(memory_msg, mesg) {}
RangeException::RangeException(const std::string& mesg) : BaseException(memory_msg, mesg) {}
AccessException::AccessException(const std::string& mesg) : BaseException(memory_msg, mesg) {}

MemoryException::MemoryException(const char* mesg, int data) : BaseException(memory_msg, mesg, data) {}
RangeException::RangeException(const char* mesg, int data) : BaseException(range_msg, mesg, data) {}
AccessException::AccessException(const char* mesg, int data) : BaseException(null_msg, mesg, data) {}

MemoryException::MemoryException(const char* mesg, const char* time) : BaseException(memory_msg, mesg, time) {}
RangeException::RangeException(const char* mesg, const char* time) : BaseException(range_msg, mesg, time) {}
AccessException::AccessException(const char* mesg, const char* time) : BaseException(null_msg, mesg, time) {}