#pragma once
class Book
{
public:
	static int baseConstructorCalls;
	static int parametersConstructorCalls;
	static int copyConstructorCalls;
	static int moveConstructorCalls;

	char* title;
	char* author;
	int pageCount;

	Book();
	Book(char* title, char* author, int pageCount);
	Book(const Book &other);
	Book(Book&& other);
	~Book();

	Book & operator= (const Book &other);
	Book & operator= (Book&& other);

};

