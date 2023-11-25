#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(){
	std::vector<int> v(5, 42);
	std::cout << *easyfind(v,42) << std::endl;

	try
	{
		std::cout << *easyfind(v,2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}