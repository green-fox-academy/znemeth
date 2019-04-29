#include "shaker_sort.h"
#include "swap.h"

std::vector<int> shakerSort(std::vector<int> list, bool isAscending)
{
	for (int i = 0; i < list.size(); i++) {
		bool swapped = false;
		for (int j = i; j < list.size()-1-i; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		for (int j = list.size() - 1 - i; j > i; j--) {
			if (list[j] < list[j - 1]) {
				swap(list[j], list[j - 1]);
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
