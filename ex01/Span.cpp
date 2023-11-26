#include "Span.hpp"

Span::~Span(void){}
Span::Span(unsigned int N): _maxSize(N){}
Span::Span(const Span & span): _vector(span._vector), _maxSize(span._maxSize){}

void Span::addNumber(int value){
	if (this->_vector.size() >= this->_maxSize) throw std::exception();
	this->_vector.push_back(value);
}

long Span::shortestSpan(void) const{
	std::vector<long> diffs = this->diffsBetwinElements();
	return *std::min_element(diffs.begin(), diffs.end());
}
long Span::longestSpan(void) const{
	std::vector<long> diffs = this->diffsBetwinElements();
	return *std::max_element(diffs.begin(), diffs.end());
}

std::vector<long> Span::diffsBetwinElements() const{
	if (this->_vector.size() < 2) throw std::exception();
	std::vector<long> diffs(this->_vector.begin(), this->_vector.end());
	std::adjacent_difference(diffs.begin(), diffs.end(), diffs.begin());
	diffs.erase(diffs.begin());
	std::transform(diffs.begin(), diffs.end(), diffs.begin(), labs);
	return diffs;
}

void Span::print() const{
	Span::printVector(this->_vector);
}

void Span::printDiffs() const{
	Span::printVector(this->diffsBetwinElements());
}





