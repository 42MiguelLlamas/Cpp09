#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(char **src, int argc)
{
	std::deque<int> queue;
    std::list<int> lista;

	for (int i = 1; i < argc; i++)
	{
		int value = stringToInt(src[i]);
		queue.push_back(value);
		lista.push_back(value);
	}
	std::cout << "Before: ";
	display(lista);

	clock_t start1 = clock();
    mergeInsertSortDeque(queque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

}

PmergeMe::PmergeMe(const PmergeMe &src)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	return *this;
}

PmergeMe::~PmergeMe()
{
	
}

int PmergeMe::stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	if (iss.fail() || !iss.eof())
	{
		throw PmergeMeException();
	}
	return num;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

const char *PmergeMe::PmergeMeException::what() const throw()
{
	return "Error: Invalid number.";
};