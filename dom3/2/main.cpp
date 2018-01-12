#include "Book.h"
#include <vector>
#include <cstdio>

int comparatorTitle(Book &left, Book &right);
int comparatorAuthor(Book &left, Book &right);
int comparatorPageCount(Book &left, Book &right);

void swap(Book *left, Book *right);
void sort(std::vector<Book> &books, int comparator(Book &left, Book &right));
void printBook(Book book);
void printBooksVector(std::vector<Book> books);

int main()
{
	std::vector<Book> books;
	
	books.emplace_back(Book("Dawca Przysiegi I", "Brandon Sanderson", 500));
	books.emplace_back(Book("Terapia", "Kathryn Perez", 230));
	books.emplace_back(Book("Artemis", "Andy Weir", 556));
	books.emplace_back(Book("Turbulencja", "Whitney Gracia Williams", 158));
	books.emplace_back(Book("Komisarz", "Paulina Œwist", 395));
	books.emplace_back(Book("Tekst", "Dmitry Glukhovsky", 452));
	books.emplace_back(Book("Pudelko z guzikami Gwendy", "Richard Chizmar", 687));
	books.emplace_back(Book("Womanizer", "Katy Evans", 96));
	books.emplace_back(Book("Zolwie az do konca", "ohn Green", 850));
	books.emplace_back(Book("Exodus", "£ukasz Orbitowski", 80));

	
	printf("Original:\n");
	printBooksVector(books);

	sort(books, comparatorTitle);
	printf("\nSorted by title:\n");
	printBooksVector(books);

	sort(books, comparatorAuthor);
	printf("\nSorted by author:\n");
	printBooksVector(books);

	sort(books, comparatorPageCount);
	printf("\nSorted by page count:\n");
	printBooksVector(books);

	system("PAUSE");
    return 0;
}



int comparatorTitle(Book &left, Book &right)
{
	return strcmp(left.title, right.title);
}

int comparatorAuthor(Book &left, Book &right)
{
	return strcmp(left.author, right.author);
}

int comparatorPageCount(Book &left, Book &right)
{
	if (left.pageCount == right.pageCount)
	{
		return 0;
	}

	return left.pageCount < right.pageCount ? -1 : 1;
}


void swap(Book *left, Book *right)
{
	Book temp = *left;
	*left = *right;
	*right = temp;
}

void sort(std::vector<Book> &books, int comparator(Book &left, Book &right))
{
	for (size_t i = 0; i < books.size(); i++)
	{
		for (size_t j = 0; j < books.size() - 1; j++)
		{
			if (comparator(books[j], books[j + 1]) > 0)
			{
				swap(&books[j], &books[j + 1]);
			}
		}
	}
}

void printBook(Book book)
{
	printf("%s, %s, %i\n", book.title, book.author, book.pageCount);
}

void printBooksVector(std::vector<Book> books)
{
	int baseConstructorCalls = 0;
	int parametersConstructorCalls = 0;
	int copyConstructorCalls = 0;
	int moveConstructorCalls = 0;

	for (size_t i = 0; i < books.size(); i++)
	{
		printBook(books[i]);

		baseConstructorCalls += books[i].baseConstructorCalls;
		parametersConstructorCalls += books[i].parametersConstructorCalls;
		copyConstructorCalls += books[i].copyConstructorCalls;
		moveConstructorCalls += books[i].moveConstructorCalls;
	}

	printf("\nConstructor calls:\n Base: %i \n", baseConstructorCalls);
	printf(" Parameters:  %i \n", parametersConstructorCalls);
	printf(" Copy:  %i \n", copyConstructorCalls);
	printf(" Move:  %i \n", moveConstructorCalls);
}