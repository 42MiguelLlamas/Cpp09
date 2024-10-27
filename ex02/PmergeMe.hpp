#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    // Constructors
    PmergeMe(); // Default constructor
    PmergeMe(const PmergeMe& other); // Copy constructor

    // Destructor
    ~PmergeMe();

    // Assignment operator
    PmergeMe& operator=(const PmergeMe& other);

    // Member functions
    void loadData(const std::vector<int>& data); // Load data into the containers
    void sortAndMeasure(); // Sort data and measure time for each container
    void displayData() const; // Display unsorted and sorted data

private:
    std::vector<int> dataVector;
    std::deque<int> dataDeque;

    void fordJohnsonSortVector(std::vector<int>& data); // Ford-Johnson sort for vector
    void fordJohnsonSortDeque(std::deque<int>& data); // Ford-Johnson sort for deque
};

#endif
