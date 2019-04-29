#include "gtest/gtest.h"
#include "../opencv/selection_sort.cpp"
#include <time.h>
#include <opencv2/opencv.hpp>

class TestSelectionSort : public testing::Test
{
protected:

	std::vector<int> randomList;
	std::vector<int> nearlySortedList;
	std::vector<int> reversedList;
	std::vector<int> fewUniqueList;

	virtual void SetUp()
	{
		srand(time(NULL));
		int numberOfElements = rand() % 400 + 100;
		for (int i = 0; i < numberOfElements; i++) {
			randomList.push_back(rand());
		}
		for (int i = 0; i < numberOfElements; i++) {
			nearlySortedList.push_back(i);
			if (i % 4 == 0)
				nearlySortedList.at(i) = i + 3;
		}
		for (int i = numberOfElements; i > 0; i--) {
			reversedList.push_back(i);
		}
		for (int i = 0; i < numberOfElements; i++) {
			int number = i % 4;
			fewUniqueList.push_back(number);
		}
	}
};

TEST_F(TestSelectionSort, vectorSameSize) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = selectionSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestSelectionSort, vectorAscendingTrue) {
	std::vector<int>resultList = selectionSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestSelectionSort, vectorDescendingTrue) {
	std::vector<int>resultList = selectionSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestSelectionSort, isAscTheOppositeOfDesc) {
	std::vector<int> resultListAsc = selectionSort(randomList, true);
	std::vector<int> resultListDesc = selectionSort(randomList, false);
	for (int i = 0; i < resultListAsc.size() - 1; i++) {

		EXPECT_EQ(resultListAsc[i], resultListDesc[resultListDesc.size() - 1 - i]);
	}
}

TEST_F(TestSelectionSort, sortingNearlySortedList) {
	std::vector<int>resultList = selectionSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestSelectionSort, sortingReversedList) {
	std::vector<int>resultList = selectionSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestSelectionSort, sortingFewUniqueList) {
	std::vector<int>resultList = selectionSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
