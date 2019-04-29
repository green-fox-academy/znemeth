#include "gtest/gtest.h"
#include "../opencv/counting_sort.cpp"
#include <time.h>
#include <opencv2/opencv.hpp>

class TestCountingSort : public testing::Test
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
			if (i % 4 == 0) {
				nearlySortedList.at(i) = i + 3;
			}
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

TEST_F(TestCountingSort, vectorSameSize) {
	int sizeOfOrigin = randomList.size();
	std::vector<int>resultList = countSort(randomList, true);
	int sizeOfResult = resultList.size();

	EXPECT_EQ(sizeOfOrigin, sizeOfResult);
}

TEST_F(TestCountingSort, vectorAscendingTrue) {
	std::vector<int>resultList = countSort(randomList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[randomList.size() - 1]);
}

TEST_F(TestCountingSort, vectorDescendingTrue) {
	std::vector<int>resultList = countSort(randomList, false);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] > resultList[randomList.size() - 1]);
}

TEST_F(TestCountingSort, isAscTheOppositeOfDesc) {
	std::vector<int> resultListAsc = countSort(randomList, true);
	std::vector<int> resultListDesc = countSort(randomList, false);
	for (int i = 0; i < resultListAsc.size() - 1; i++) {

		EXPECT_EQ(resultListAsc[i], resultListDesc[resultListDesc.size() - 1 - i]);
	}
}

TEST_F(TestCountingSort, sortingNearlySortedList) {
	std::vector<int>resultList = countSort(nearlySortedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}

TEST_F(TestCountingSort, sortingReversedList) {
	std::vector<int>resultList = countSort(reversedList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
TEST_F(TestCountingSort, sortingFewUniqueList) {
	std::vector<int>resultList = countSort(fewUniqueList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] < resultList[resultList.size() - 1]);
}
