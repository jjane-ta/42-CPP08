#include <iostream>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;	
		}
		std::stack<int> s(mstack);
	}
	std::cout  << std::endl;

	{
		MutantStack<char> mstack;

		mstack.push('a');
		mstack.push('b');
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		//[...]
		mstack.push('f');
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;	
		}
		std::stack<char> s(mstack);
	}	

	std::cout  << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		MutantStack<int>::iterator it = mstack.begin();

		it++;
		it--;

		std::cout << *it << std::endl;
		
		std::cout << *(--mstack.end()) << std::endl;
	}
}