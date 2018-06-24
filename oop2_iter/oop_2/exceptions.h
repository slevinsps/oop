#pragma once
#include <exception>
#include <string>
#include <time.h>

class BaseException : public std::exception 
{
public:
	BaseException(const char *str);
	BaseException(const char *str, const char *msg);
	BaseException(const char *str, const std::string& mesg);
	BaseException(const char *str, const char *msg, int data);
	BaseException(const char *str, const char *msg, const char* time);

	const char* what() const;
private:
	char *msg;
};


class MemoryException : public BaseException
{
public:
	MemoryException();
	MemoryException(const char* mesg);
	MemoryException(const std::string& mesg);
	MemoryException(const char* mesg, int data);
	MemoryException(const char* mesg, const char* time);
};

class RangeException : public BaseException
{
public:
	RangeException();
	RangeException(const char* mesg);
	RangeException(const std::string& mesg);
	RangeException(const char* mesg, int data);
	RangeException(const char* mesg, const char* time);
};

class AccessException : public BaseException
{
public:
	AccessException();
	AccessException(const char* mesg);
	AccessException(const std::string& mesg);
	AccessException(const char* mesg, int data);
	AccessException(const char* mesg, const char* time);
};