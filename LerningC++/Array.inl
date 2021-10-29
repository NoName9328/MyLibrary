#ifndef ARRAY_H
#define ARRAY_H

#include"MyArray.h";
#include<exception>


template<typename T>
Array<T>::Array(int size)
{
	this->Capacity =size;
	this->arr = new T[Capacity];
	SizeArray = 0;
}

template<typename T>
Array<T>::Array(const Array& other)
{
	this->Capacity = other.Capacity;
	this->SizeArray = 0;

	this->arr = new T[other.Capacity];

	for (int i = 0; i < other.getSizeArray(); i++)		//Copy_constructor
	{
		this->pushback(other[i]);
	}
	std::cout << "\n\nconstructor copy\n\n";
}

template<typename T>
 void Array<T>::DeleteElem(int pos)
{
	if (pos <= SizeArray)
	{
		SizeArray--;
		T* NewArray = new T[SizeArray];

		for (int i = 0; i < SizeArray; i++)
		{
			if (i != pos)
			{
				NewArray[i] = arr[i];
			}
			else
			{
				break;
			}
		}
		for (int i = pos; i < SizeArray; i++)
		{
			NewArray[i] = arr[i + 1];
		}
		delete[] arr;
		arr = NewArray;
	}
	else
	{
		throw std::out_of_range("no such element found! ");
	}

}


template<typename T>
Array<T>::~Array()
{
	delete[]arr;
}

template<typename T>
T& Array<T>::operator[](const int element)const
{
	return arr[element];
}

template<typename T>
void Array<T>::pushback(T elemt)
{
	if (SizeArray >= Capacity)
	{
		ResizingArray();
		arr[SizeArray] = elemt;			// add.Elemets
		SizeArray++;
	}
	else
	{
		arr[SizeArray] = elemt;
		SizeArray++;
	}
}

template<typename T>
const Array<T>& Array<T>::operator+(const Array& one)
{
	for (size_t i = 0; i < one.getSizeArray(); i++)
	{
		this->pushback(one[i]);	// temp добавить one[i]
	}
	return *this;
}

template<typename T>
void Array<T>::ResizingArray()
{
	std::cout << "called resizing \n\n";

	Capacity = Capacity * 2;

	T* NewArray = new T[Capacity];

	std::memcpy(NewArray, arr, SizeArray * sizeof(T));
	
	delete[]arr;
	arr = NewArray;
}

template<typename T>
void Array<T>::insert(int pos, T elem)
{
	if (pos > SizeArray)
	{
		throw std::out_of_range("...");					// search elements
	}
	else
	{
		arr[pos] = elem;
	}
}

template<typename T>
int const Array<T>::at(const int a)
{
	if (a < SizeArray)
	{
		return arr[a];
	}
	return -1;
}

template<typename T>
const int Array<T>::getSizeArray() const
{
	return SizeArray;
}

template<typename T>
void Array<T>::SortArray(std::function<bool( T a, T b)> lambdasort)
{
 	for (int i = 0; i < SizeArray; i++)
	{
		for (int j = 0; j < SizeArray - 1; j++)
		{
			if (lambdasort(arr[j], arr[j + 1]))					//Sort_Array
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
const int Array<T>::getCapacity() const
{
	return Capacity;
}



#endif ARRAY_H

