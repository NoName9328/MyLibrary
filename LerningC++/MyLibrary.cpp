#include "MyLibrary.h"
#include"Book.h"
#include<iostream>
#include<functional>


MyLibrary::MyLibrary()
{

}


void MyLibrary::AddBook(Book & book)
{
	if (DuplicateCheck(book))
	{
		std::cout << "same element found!";
	}
	else
	{
		Library.pushback(book);
	}
}

bool MyLibrary::DuplicateCheck(Book& book)
{
	bool result = false;

	for (int  i = 0; i < Library.getSizeArray(); i++)
	{
		if (Library[i] == book)
		{
			result = true;
			break;
		}
		else
		{
			result = false;
		}
	}
	return result;
}


Book &MyLibrary::SearchBook(std::string &title)
{
	Book buffer;
	for (int i = 0; i < Library.getSizeArray(); i++)
	{
		if (Library[i].getTitileBook() == title)
		{
			return Library[i];
		}
	}
	return buffer;
}

void MyLibrary::SortBook(Sort type)
{
	std::string genre;
	switch (type)
	{
		case Sort::BY_DATE_RELEAS:
		{
			for (int i = 0; i < Library.getSizeArray(); i++)
			{
				for (int j = 0; j < Library.getSizeArray() - 1; j++)
				{
					if (Library[j].getDateRelease() > Library[j + 1].getDateRelease())
					{
						std::swap(Library[j], Library[j + 1]);
					}
				}
			}
			break;
		}
		case Sort::BY_TITLE_BOOK:
		{
			break;
		}
		case Sort::BY_GENRE_BOOK:
		{
			std::cout << "\tEnter the genre of the book: ";
			std::cin >> genre;
			for (size_t i = 0; i < Library.getSizeArray(); i++)
			{
				if (Library[i].getGenreBook() == genre)
				{
					std::cout << Library[i];
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}
}



void MyLibrary::PrintLibrary()
{
	for (int i = 0; i < Library.getSizeArray(); i++)
	{
		std::cout << Library[i] << ' ';
	}
}

void MyLibrary::DeleteBook(int pos)
{
	try
	{
		Library.DeleteElem(pos);
	}
	catch (const std::exception& a)
	{
		std::cout << " \t" << a.what() << std::endl << std::endl;
	}
	
}

void MyLibrary::DeleteBook(std::string title )
{
	for (size_t i = 0; i < Library.getSizeArray(); i++)
	{
		if (!SearchBook(title))
		{
			continue;
		}
		else
		{
			try
			{
				Library.DeleteElem(i);
			}
			catch (const std::exception& a)
			{
				std::cout << a.what() << std::endl;
			}
			break;
		}
	}
}

