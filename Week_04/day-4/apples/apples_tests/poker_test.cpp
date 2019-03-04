//
// Created by NEMETH on 2019.03.04..
//

#include "gtest/gtest.h"
#include "poker.c"

extern "C" {
#include "poker.h"
}

TEST(PokerTest, TestNumber)
{
    EXPECT_EQ(get_cardValue("3D"), 3);
}

TEST(PokerTest, TestNumberOver9_1)
{
    EXPECT_EQ(get_cardValue("TD"), 10);
}

TEST(PokerTest, TestNumberOver9_2)
{
    EXPECT_EQ(get_cardValue("JS"), 11);
}

TEST(PokerTest, TestNumberOver9_3)
{
    EXPECT_EQ(get_cardValue("QS"), 12);
}

TEST(PokerTest, TestNumberOver9_4)
{
    EXPECT_EQ(get_cardValue("KS"), 13);
}

TEST(PokerTest, TestNumberOver9_5)
{
    EXPECT_EQ(get_cardValue("AD"), 14);
}

TEST(PokerTest, TestCardColor_1)
{
    EXPECT_EQ(get_cardColor("3H"), 'H');
}