#include"MyArray.h"
#include"MyLibrary.h"
#include"Book.h"
#include<Windows.h>
#include<ctime>
#include<iostream>
#include<exception>
#include<string>



void ClearScreen()
{
	DWORD n;
	DWORD size;
	COORD coord = { 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	SetConsoleCursorPosition(h, coord);
}

template<typename T>
void print(Array<T>& temp)
{
	for (int i = 0; i < temp.getSizeArray(); i++)
	{
		std::cout << i << ' - ' << temp[i] << ' ';
	}
	std::cout << std::endl;
}

void menu()
{
	std::cout << std::endl << " \t\t\t\t The library welcomes you" << std::endl << std::endl;

	MyLibrary MyLibrary;

	Book book1("Harry Potter", 2003, "Fantastic");
	Book book2("Metro", 2008, "Fantastic");
	Book book3("Sherlock Holmes", 1892, "Detective");
	Book book4("Sanya is learning C++", 2021, "Comedy");

	MyLibrary.AddBook(book1);
	MyLibrary.AddBook(book3);
	MyLibrary.AddBook(book2);
	MyLibrary.AddBook(book4);

	int operation;
	std::string title;
	std::string what;

	std::cout << std::endl;
	
	bool isative = true;
	while (isative)
	{

		std::cout << "\tOperetion: " << std::endl << std::endl;
		std::cout << "\t     1 -  Print all books; " << std::endl;
		std::cout << "\t     2 -  Book search; " << std::endl;
		std::cout << "\t     3 -  Sorted by publication date; " << std::endl;
		std::cout << "\t     4 -  Sorted by genre; " << std::endl;
		std::cout << "\t     5 -  Delete a book; " << std::endl << std::endl;

		std::cout << "\tEnter the number of actions: ";
		std::cin >> operation;
		switch (operation)
		{
			case 1:
			{

				std::cout << " \tAll the books: " << std::endl << std::endl;
				MyLibrary.PrintLibrary();

				break;
			}
			case 2:
			{
				std::cout << "\tBook search: " << std::endl << std::endl;
				std::cout << "\tEnter the title of the book: ";

				getline(std::cin >> std::ws, title);

				if (!MyLibrary.SearchBook(title))
				{
					std::cout << "nema" << std::endl;
				}
				else
				{
					unsigned int start_time = clock();
					std::cout << MyLibrary.SearchBook(title);
					unsigned int end_time = clock();
					unsigned int search_time = end_time - start_time;
					std::cout << ". Runtime : " << search_time / 1000.0 << " sek " << std::endl << std::endl;
				}

				break;
			}
			case 3:
			{

				std::cout << " \t Sorted by publication date: " << std::endl << std::endl;
				MyLibrary.SortBook(MyLibrary::Sort::BY_DATE_RELEAS);
				MyLibrary.PrintLibrary();

				break;
			}
			case 4:
			{

				std::cout << " \t Sorted by genre: " << std::endl << std::endl;
				MyLibrary.SortBook(MyLibrary::Sort::BY_GENRE_BOOK);

				break;
			}
			case 5:
			{

				std::string title;
				int Delete_pos;
				std::cout << "\tEnter the number  or title of the book wich you want to delete (starting with 0): ";
				std::cin >> Delete_pos;
				getline(std::cin >> std::ws, title);
				std::cout << " \tDelete a book: " << std::endl << std::endl;

				break;
			}
			default:
			{

				std::cout << "no such action found";

				break;
			}
		}

		std::cout << "\tDo you want to continue (Yes/No)? : ";
		getline(std::cin >> std::ws, what);

		if (what == "yes"||what == "Yes")
		{
			ClearScreen();
			continue;
		}
		else if (what == "no" ||what == "No")
		{
			isative = false;
			ClearScreen();
		}
	}	
}

int main()
{

	menu();
	
	return 0;
}