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

void merge(std::deque<int>& dq, unsigned long *order)
{
    if (*order <= (dq.size() / 2))
	{
        for (unsigned long i = 0; i < (dq.size() / *order); i++)
		{
			unsigned long index1 = *order - 1 + (*order * 2 * i);
            unsigned long index2 = *order * 2 - 1 + (*order * 2 * i);
			if (i == 0)
			{
				index1 = *order - 1;
            	index2 = *order * 2 - 1;
			}
            if (index1 >= 0 && index2 < dq.size())
			{
				unsigned long pack_size = *order;
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
		*order = *order * 2;
        merge(dq, order);
    }
}

void insert(std::deque<int>& dq, unsigned long *order, unsigned long original)
{
	std::cout << "Order is: "<< *order << std::endl;
	if (*order > 1)
	{
		unsigned long start = original - *order - 1;
		std::cout << "start: "<< start << std::endl;
		if (start > dq.size() - 1)
		{
			*order = *order / 2;
			insert(dq, order, original);
			return;
		}
		// Buscar la posición correcta para insertar el bloque.
		unsigned long correct = start;
		for (unsigned long i = 0; i < dq.size(); i++)
		{
			if (dq[start] < dq[i])
			{
				correct = i;
				break;
			}
		}
		std::cout << "Correct: "<< correct << std::endl;
		if (correct >= start)
		{
			*order = *order / 2;
			insert(dq, order, original);
			return;
		}
		std::deque <int> auxDq;
		for (unsigned long j = 0; j < dq.size(); j++)
		{
			if (j < correct || (j > (start - *order) && j <= start))
				continue;
			auxDq.push_back(dq[j]);
		}
		for (std::deque<int>::iterator it = auxDq.begin(); it != auxDq.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		for (unsigned long j = start; j > start - *order; j--)
		{
			auxDq.push_front(dq[j]);
		}
		for (std::deque<int>::iterator it = auxDq.begin(); it != auxDq.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		for (unsigned long j = correct; j > 0; j--)
		{
			auxDq.push_front(dq[j]);
		}
		for (std::deque<int>::iterator it = auxDq.begin(); it != auxDq.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		*order = *order / 2;
		insert(auxDq, order, original - *order);
	}
}

void sort(std::deque<int> dq)
{
	unsigned long order = 1;
	merge(dq, &order);
	order = order / 2;
	insert(dq, &order, order * 4);
}

int main(void)
{
	std::deque<int> dq;
	/*for (int i = 25; i >= 1; --i)
	{
		queue.push_back(i);
	}*/
	for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	sort(dq);
	for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
	{
		std::cout << *it << " ";
	}
}