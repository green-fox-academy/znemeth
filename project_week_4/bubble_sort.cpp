#include "bubble_sort.h"
#include "swap.h"

std::vector<int> bubbleSort(std::vector<int> list, bool isAscending)
{
	for (int i = 0; i < list.size() - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < list.size() - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	} 
	if (isAscending == false) {
		for (int i = 0; i < list.size() / 2; i++) {
			swap(list[i], list[list.size() - 1 - i]);
		}
	}

	return list;
}
