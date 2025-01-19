#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(char **src, int argc);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		int stringToInt(const std::string& str);
		template <typename T>
		void display(const T& container);

		void sortDeque(std::deque<int>& arr);
		void sortList(std::list<int>& arr);

		class PmergeMeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};


#endif