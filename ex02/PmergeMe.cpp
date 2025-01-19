#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(char **src, int argc)
{
	std::deque<int> queue;
    std::list<int> list;

	for (int i = 1; i < argc; i++)
	{
		int value = stringToInt(src[i]);
		queue.push_back(value);
		list.push_back(value);
	}
	std::cout << "Before: ";
	display(list);

	clock_t start1 = clock();
    sortDeque(queue);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	clock_t start2 = clock();
    sortList(list);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	display(list);
	std::cout << "Time to process a range of " << queue.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list container: " << time2 << " us" << std::endl;

}

void PmergeMe::sortDeque(std::deque<int> &arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin())
        {
            std::deque<int>::iterator prev = it2;
            --prev;
            if (*prev <= temp)
                break;
            *it2 = *prev;
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::sortList(std::list<int> &arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin())
        {
            std::list<int>::iterator prev = it2;
            --prev;
            if (*prev <= temp)
                break;
            *it2 = *prev;
            --it2;
        }
        *it2 = temp;
    }
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
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
	if (iss.fail() || !iss.eof() || num < 1)
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