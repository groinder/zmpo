#include "Book.h"
#include <cstddef>

int Book::baseConstructorCalls = 0;
int Book::parametersConstructorCalls = 0;
int Book::copyConstructorCalls = 0;
int Book::moveConstructorCalls = 0;

Book::Book() : 
	title(nullptr), author(nullptr), pageCount(0)
{
	baseConstructorCalls++;
}


Book::Book(char * title, char * author, int pageCount) :
	title(title), author(author), pageCount(pageCount)
{
	parametersConstructorCalls++;
}

Book::Book(const Book & other) :
	title(other.title),
	author(other.author),
	pageCount(other.pageCount)
{
	copyConstructorCalls++;
}

Book::Book(Book && other):
	title(other.title),
	author(other.author),
	pageCount(other.pageCount)
{
	other.title = nullptr;
	other.author = nullptr;
	other.pageCount = NULL;

	moveConstructorCalls++;
}

Book::~Book()
{
}

Book & Book::operator=(const Book & other)
{
	if (&other != this)
	{
		title = other.title;
		author = other.author;
		pageCount = other.pageCount;
	}

	copyConstructorCalls++;

	return *this;
}

Book & Book::operator=(Book && other)
{
	if (&other != this)
	{
		title = other.title;
		author = other.author;
		pageCount = other.pageCount;

		other.title = nullptr;
		other.author = nullptr;
		other.pageCount = NULL;
	}

	moveConstructorCalls++;

	return *this;
}
