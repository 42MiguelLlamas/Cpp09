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


int powerOfTwo(int x)
{
    int result = 1;
    while (x-- > 0) result *= 2;
    return result;
}

void merge(std::deque<int>& dq, unsigned long order)
{
	std::cout << "Order is: "<< order << std::endl;
    if (order <= (dq.size() / 2))
	{
		std::cout << "Merge."<< std::endl;
        for (unsigned long i = 0; i < (dq.size() / order); i++)
		{
			unsigned long index1 = order - 1 + (order * 2 * i);
            unsigned long index2 = order * 2 - 1 + (order * 2 * i);
			if (i == 0)
			{
				index1 = order - 1;
            	index2 = order * 2 - 1;
			}
			std::cout << "Index 1: " << index1 << " | " << "Index 2: " << index2 << std::endl;
            if (index1 >= 0 && index2 < dq.size())
			{
				unsigned long pack_size = order;
                unsigned long start1 = index1 - (pack_size - 1);
                unsigned long start2 = index2 - (pack_size - 1);
                if (dq[index1] > dq[index2])
				{
					for (unsigned long j = 0; j < pack_size; ++j)
                    {
                        if (start1 + j < dq.size() && start2 + j < dq.size())
                        {
                            std::swap(dq[start1 + j], dq[start2 + j]);
                        }
                    }
                }
            }
			else
				break;
        }
		for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
        merge(dq, order * 2);
    }
}

void sort(std::deque<int> dq)
{
	merge(dq, 1);
	//insert(dq);
}

int main(void)
{
	std::deque<int> queue;
	for (int i = 25; i >= 0; --i)
	{
		queue.push_back(i);
	}
	for (std::deque<int>::iterator it = queue.begin(); it != queue.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	sort(queue);
}