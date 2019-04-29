#include "gtest/gtest.h"
#include "../opencv/bubble_sort.cpp"
#include <time.h>
#include <opencv2/opencv.hpp>

class TestBubbleSort : public testing::Test
{

protected:

	std::vector<int> randomList;
	std::vector<int> nearlySortedList;
	std::vector<int> reversedList;
	std::vector<int> fewUniqueList;

	virtual void SetUp()
	{
		srand(time(NULL));
		int randomListSize = rand() % 400 + 100;
		for (int i = 0; i < randomListSize; i++) {
			randomList.push_back(rand());
		}
		
		for (int i = 0; i < randomListSize; i++) {
			nearlySortedList.push_back(i);
			if (i % 4 == 0) {
				nearlySortedList.at(i) = i + 3;
			}
		}
		
		for (int i = randomListSize; i > 0; i--) {
			reversedList.push_back(i);
		}

		for (int i = 0; i < randomListSize; i++) {
			int number = i % 4;
			fewUniqueList.push_back(number);

		}
	}
};

TEST_F(TestBubbleSort, isAscendingTrue)
{
	std::vector<int> resultList = bubbleSort(randomList, true);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] <= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestBubbleSort, isDescendingTrue)
{
	std::vector<int> resultList = bubbleSort(randomList, false);
	for (int i = 0; i < resultList.size() - 1; i++) {

		EXPECT_TRUE(resultList[i] >= resultList[i + 1]);
	}

	EXPECT_TRUE(resultList[0] != resultList[resultList.size() - 1]);
}

TEST_F(TestBubbleSort, isSameSizeTrue)
{
	std::vector<int> resultListAsc = bubbleSort(randomList, true);
	std::vector<int> resultListDesc = bubbleSort(randomList, false);

	EXPECT_TRUE(resultListAsc.size() == randomList.size());
	EXPECT_TRUE(resultListDesc.size() == randomList.size());
}

TEST_F(TestBubbleSort, isSameSumTrue)
{
	std::vector<int> resultListAsc = bubbleSort(randomList, true);
	std::vector<int> resultListDesc = bubbleSort(randomList, false);
	int sumAsc = 0;
	int sumDesc = 0;
	int sumOrigin = 0;
	for (int i = 0; i < randomList.size(); i++) {
		sumAsc += resultListAsc[i];
		sumDesc += resultListDesc[i];
		sumOrigin += randomList[i];
	}

	EXPECT_TRUE(sumAsc == sumDesc);
	EXPECT_TRUE(sumAsc == sumOrigin);
	EXPECT_TRUE(sumDesc == sumOrigin);
}

TEST_F(TestBubbleSort, isAscTheOppositeOfDesc) {
	std::vector<int> resultAsc = bubbleSort(randomList, true);
	std::vector<int> resultDesc = bubbleSort(randomList, false);
	for (int i = 0; i < resultAsc.size() - 1; i++) {

		EXPECT_EQ(resultAsc[i], resultDesc[resultDesc.size() - 1 - i]);
	}
}

TEST_F(TestBubbleSort, isAscendingTrueOtherTypeOfVectors)
{
	std::vector<int> resultListNearlySorted = bubbleSort(nearlySortedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListNearlySorted[i] <= resultListNearlySorted[i + 1]);
	}

	EXPECT_TRUE(resultListNearlySorted[0] < resultListNearlySorted[resultListNearlySorted.size() - 1]);
}

TEST_F(TestBubbleSort, isAscendingTrueOtherTypeOfVectors2)
{
	std::vector<int> resultListReversed = bubbleSort(reversedList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListReversed[i] <= resultListReversed[i + 1]);
	}

	EXPECT_TRUE(resultListReversed[0] < resultListReversed[resultListReversed.size() - 1]);
}

TEST_F(TestBubbleSort, isAscendingTrueOtherTypeOfVectors3)
{
	std::vector<int> resultListFewUnique = bubbleSort(fewUniqueList, true);
	for (int i = 0; i < randomList.size() - 1; i++) {

		EXPECT_TRUE(resultListFewUnique[i] <= resultListFewUnique[i + 1]);
	}

	EXPECT_TRUE(resultListFewUnique[0] < resultListFewUnique[resultListFewUnique.size() - 1]);
}
