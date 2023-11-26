#pragma once
#include "Span.hpp"

template<typename T>
void Span::addRange(T first, T last){
	if (this->_vector.size() + std::distance(first,last) > this->_maxSize) throw std::exception();
	std::copy(first, last, std::back_inserter(this->_vector));
}

template<typename T>
void Span::printVector(T container) const{
	struct op{static void print (long l) { std::cout << ' ' << l;}};
	std::cout << "[";	std::for_each(container.begin(), container.end(), op::print);	std::cout << "]" << std::endl;
}