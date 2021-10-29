#pragma once
#include<iostream>
#include"MyArray.h"

class Book
{
private:

	std::string m_sTitleBook;
	int	m_nDateRelease;
	std::string m_sGenreBook;

public:
	friend std::ostream& operator << (std::ostream& out,  Book& a);
	Book();
	Book(std::string title, int date, std::string genre);
	const int getDateRelease();
	const std::string getTitileBook();
	const std::string getGenreBook();
	friend bool operator == (const Book& book, const Book& book2);
	 bool operator!()
	{
		 if (m_sTitleBook.empty())
		 {
			 return true;
		 }
		 return false;
	}
};

