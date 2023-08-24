#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _n;

public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const &other);
	Array<T> &operator=(Array<T> const &other);
	T &operator[](unsigned int n);
	unsigned int size();
	~Array();
};

template <class T>
Array<T>::Array()
{
	_array = new T[0];
};

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
	if (_n <= 0)
		throw std::logic_error("its index is out of bounds");
	_array = new T[_n];
};

template <class T>
Array<T>::Array(Array const &other)
{
	_array = NULL;
	_n = other._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < other._n; i++)
		_array[i] = other._array[i];
};

template <class T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (_n > 0)
		delete[] _array;
	_n = other._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = other._array[i];
	return (*this);
};

template <class T>
T &Array<T>::operator[](unsigned int n)
{
	if (n > _n - 1)
		throw std::logic_error("its index is out of bounds");
	return (_array[n]);
};

template <class T>
unsigned int Array<T>::size()
{
	return (_n);
}

template <class T>
Array<T>::~Array()
{
	if (_n != 0)
		delete[] _array;
}

#endif
