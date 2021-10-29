#include "Book.h"


Book::Book()
{
	m_nDateRelease = 0;
}

Book::Book(std::string title, int date, std::string genre)
{
	this->m_sTitleBook = title;
	this->m_nDateRelease = date;
	this->m_sGenreBook = genre;	
}

const int Book::getDateRelease()
{
	return m_nDateRelease;
}


const std::string Book::getTitileBook()
{
	return m_sTitleBook;
}

const std::string Book::getGenreBook() 
{
	return m_sGenreBook;
}

std::ostream& operator << (std::ostream& out,  Book& a)
{
	out << "	Titile book - " << a.getTitileBook() << "	 date relase - " << a.getDateRelease() << "	genre book - " << a.getGenreBook() ;
	return out;
}

bool operator==(const Book& book, const Book& book2)
{
	return book.m_nDateRelease == book2.m_nDateRelease
		  && book.m_sGenreBook == book2.m_sGenreBook
		  && book.m_sTitleBook == book2.m_sTitleBook;
}


