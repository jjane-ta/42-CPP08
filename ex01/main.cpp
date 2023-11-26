#include <iostream>
#include <climits>
#include "Span.hpp"


int main()
{
	std::cout << "subject test:" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "subject test with prints:" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "internal vector: "; sp.print();
		std::cout << "diffs Betwin Elements: "; sp.printDiffs();

	}
	std::cout << std::endl;
	std::cout << "test addNumber exception:" << std::endl;
	{
		try
		{
			Span sp = Span(0);
			sp.addNumber(6);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << std::endl;
	std::cout << "test shortestSpan exception:" << std::endl;
	{
		try
		{
			Span sp = Span(0);
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << std::endl;
	std::cout << "test longestSpan exception:" << std::endl;
	{
		try
		{
			Span sp = Span(0);
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << std::endl;
	std::cout << "test long MAX diff:" << std::endl;
	{
		Span sp = Span(2);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.print();
		sp.printDiffs();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "test 50.000 addNumber to vector:" << std::endl;
	{
		Span sp = Span(50000);
		for (int i=0; i < 50000; i++)
			sp.addNumber(42);
		// sp.print();
	}
	std::cout << std::endl;
	std::cout << "test addRange with vector of 50000 size:" << std::endl;
	{
		Span sp = Span(50000);

		std::vector<int> vec;
		vec.insert(vec.end(),50000,42);
		sp.addRange(vec.begin(), vec.end());
		// sp.print();
	}
	return 0;
}