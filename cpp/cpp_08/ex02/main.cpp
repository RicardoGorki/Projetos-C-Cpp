#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << " TOP " << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << " SIZE " << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	std::cout << " MSTACK " << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int> copyStack(mstack);
	MutantStack<int> copyStackATT = mstack;
	mstack.push(20);
	copyStack.push(666);
	copyStackATT.push(444);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::iterator it1 = copyStack.begin();
	MutantStack<int>::iterator ite1 = copyStack.end();
	MutantStack<int>::iterator it2 = copyStackATT.begin();
	MutantStack<int>::iterator ite2 = copyStackATT.end();
	++it;
	--it;
	++it1;
	--it1;
	++it2;
	--it2;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::cout << "COPY " << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
		std::cout << std::endl;
		std::cout << "COPY ATT " << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int> s(mstack);
	return 0;
}
