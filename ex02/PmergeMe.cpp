#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <stdexcept>
#include <iterator>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other) : dataVector(other.dataVector), dataDeque(other.dataDeque)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {
        dataVector = other.dataVector;
        dataDeque = other.dataDeque;
    }
    return *this;
}

void PmergeMe::loadData(const std::vector<int>& data)
{
    dataVector = data;
    dataDeque.assign(data.begin(), data.end());
}


void PmergeMe::displayData() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < dataVector.size(); ++i)
	{
        std::cout << dataVector[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < dataVector.size(); ++i)
	{
        std::cout << dataVector[i] << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::fordJohnsonSortVector(std::vector<int>& data)
{
    std::sort(data.begin(), data.end());
}


void PmergeMe::fordJohnsonSortDeque(std::deque<int>& data)
{
    std::sort(data.begin(), data.end());
}


void PmergeMe::sortAndMeasure()
{
    struct timeval start, end;
    double elapsedVector, elapsedDeque;

    gettimeofday(&start, NULL);
    fordJohnsonSortVector(dataVector);
    gettimeofday(&end, NULL);
    elapsedVector = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    fordJohnsonSortDeque(dataDeque);
    gettimeofday(&end, NULL);
    elapsedDeque = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of " << dataVector.size() << " elements with std::vector: " << elapsedVector << " us" << std::endl;
    std::cout << "Time to process a range of " << dataDeque.size() << " elements with std::deque: " << elapsedDeque << " us" << std::endl;
}
