#pragma once

template<typename T>
typename T::iterator easyfind(T & container, int value){
	typename T::iterator ret = std::find(container.begin(), container.end(), value);
	if (ret == container.end()) throw std::exception();
	return ret;
}