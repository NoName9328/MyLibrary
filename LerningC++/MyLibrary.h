#pragma once
#include "MyArray.h"
#include"Book.h"
#include<functional>
#include<exception>


class MyLibrary
{
private:

	Array<Book> Library;


public:

	enum class Sort {BY_DATE_RELEAS,BY_TITLE_BOOK,BY_GENRE_BOOK};
	friend std::ostream& operator << (std::ostream& out, const Array<Book>& a);
	MyLibrary();
	void AddBook(Book & book);
	bool DuplicateCheck(Book& book);
	void SortBook(Sort type);
	Book &SearchBook(std::string &title);
	void DeleteBook(int pos) noexcept(false);
	void DeleteBook(std::string title) noexcept(false);
	void PrintLibrary();


};	


