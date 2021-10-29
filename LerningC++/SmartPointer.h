#pragma once

template<typename T>
class SmartPionter
{
private:
	T *ptr;
public:
	SmartPionter(T*arr = nullptr);
	~SmartPionter();
	T& operator*();
	T* operator ->();
};

template<typename T>
inline SmartPionter<T>::SmartPionter(T* arr )
{
	this->ptr = arr;
	ptr = new T[10];

}

template<typename T>
 SmartPionter<T>::~SmartPionter()
{
	delete[]ptr;
}

template<typename T>
T &SmartPionter<T>::operator*()
{
	return *ptr;
}

template<typename T>
T* SmartPionter<T>::operator->()
{
	return ptr;
}
 