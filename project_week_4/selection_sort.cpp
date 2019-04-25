#include "selection_sort.h"

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

std::vector<int> selectionSort(std::vector<int> list, bool isAscending)
{
	double time = (double)cv::getTickCount();
	int stepCounter = 0;

	for (int i = 0; i < list.size() - 1; i++)
	{
		int i_min = i;
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[j] < list[i_min]) {
				i_min = j;
				swap(&list[i_min], &list[i]);
				stepCounter++;
			}
		}
	}

	if (isAscending == false) {
		for (int i = 0; i < list.size() / 2; i++) {
			swap(&list[i], &list[list.size() - 1 - i]);
			stepCounter++;
		}
	}

	time = (double)cv::getTickCount() - time;
	std::cout << "Number of swaps: " << stepCounter << std::endl;
	std::cout << "Time for sorting [ms]: " << time << std::endl;
	std::cin.get();

	return list;
}
