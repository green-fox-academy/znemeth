#include "selection_sort.h"
#include "swap.h"

std::vector<int> countSort(std::vector<int> list, bool isAscending)
{
	std::map<int, int> count;

	for (int i = 0; i < list.size(); i++) {
		count[list.at(i)]++;
	}

	int i = 0;

	for (auto it : count) {
		while (it.second--) {
			list[i++] = it.first;
		}
	}

	if (isAscending == false) {
		for (int i = 0; i < list.size() / 2; i++) {
			swap(list[i], list[list.size() - 1 - i]);
		}
	}
	
	return list;
}
