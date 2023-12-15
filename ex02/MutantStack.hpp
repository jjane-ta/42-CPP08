#pragma once

#include <stack>
#include <deque>


template<typename T>
class MutantStack: public std::stack<T>{
	public:
	
		virtual ~MutantStack(void){}
		MutantStack(void): std::stack<T,std::deque<T> >(){}
		MutantStack(MutantStack  & cv): std::stack<T,std::deque<T> >(cv){}

		class iterator : public std::iterator<std::input_iterator_tag, T>
		{
				T* p;
			public:
				iterator(T* x) :p(x) {}
				iterator(const iterator& mit) : p(mit.p) {}
				iterator& operator++() {++p;return *this;}
				iterator operator++(T) {iterator tmp(*this); operator++(); return tmp;}
				iterator& operator--() {--p;return *this;}
				iterator operator--(T) {iterator tmp(*this); operator--(); return tmp;}
				bool operator==(const iterator& rhs) const {return p==rhs.p;}
				bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
				T& operator*() {return *p;}
		};

		iterator begin(){return iterator( &(this->c[0]));}
		iterator end(){return iterator(&(this->c[0]) + this->size());}
};