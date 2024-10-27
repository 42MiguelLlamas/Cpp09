#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char** argv)
{
    if (argc < 2)
	{
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    try
	{
        std::vector<int> data;
        for (int i = 1; i < argc; ++i)
		{
            int value = std::atoi(argv[i]);
            if (value <= 0)
			{
                std::cerr << "Error: Only positive integers are allowed" << std::endl;
                return 1;
            }
            data.push_back(value);
        }
        PmergeMe sorter;
        sorter.loadData(data);
        sorter.displayData();
        sorter.sortAndMeasure();
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
