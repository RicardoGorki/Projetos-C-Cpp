#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack<T> &other);
	MutantStack<T> &operator=(MutantStack<T> &other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();

};
	template <class T>
	typename MutantStack<T>::iterator MutantStack<T>::begin()
	{
		return std::stack<T>::c.begin();
	};

	template <class T>
	typename MutantStack<T>::iterator MutantStack<T>::end()
	{
		return std::stack<T>::c.end();
	};

	template <class T>
	MutantStack<T>::MutantStack(){};

	template <class T>
	MutantStack<T>::~MutantStack(){};

	template <class T>
	MutantStack<T>::MutantStack(MutantStack<T> &other) : std::stack<T>(other) {};

	template <class T>
	MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> &other)
	{
		*this = other;
		return (*this);
	};

#endif
