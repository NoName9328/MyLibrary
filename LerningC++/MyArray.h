#pragma once
#include <functional>
#include<fstream>
#include<iostream>

template<typename T>
class Array
{
public:
	
	Array(int size = 10);
	Array(const Array& other);
	~Array();
	 T &operator[](const int element)const ;
	const Array& operator + (const Array& one);
	void ResizingArray() ;
	void pushback(T elemt);
	void DeleteElem(int pos) noexcept(false);
	void insert(int pos, T elem) noexcept(false);
	int const at(const int a);
	const int getSizeArray()const ;
	void SortArray(std::function<bool(T a, T b)> lambdasort);
	const int getCapacity()const;

private:

	int Capacity;
	int SizeArray;
	T * arr;
	friend std::ostream& operator << (std::ostream& out, const Array& a);
	friend std::istream& operator >> (std::istream& out, const Array& a);

};

#include"Array.inl"