#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

class Span{
	public:
		virtual ~Span(void);
		Span(unsigned int N);
		Span(const Span & span);

		void addNumber(int value);
		template<typename T> void addRange(T first, T last);

		long shortestSpan(void) const;
		long longestSpan(void) const;

		void print() const;
		void printDiffs() const;

	private:
		Span(void);
		const Span & operator=(const Span & span);
		std::vector<long> diffsBetwinElements() const;

		template<typename T> void printVector(T container) const;

		std::vector<int> _vector;
		const unsigned int _maxSize;
};

#include "Span.tpp"
