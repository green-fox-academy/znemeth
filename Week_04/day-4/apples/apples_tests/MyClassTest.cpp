//
// Created by NEMETH on 2019.02.07..
//

#include <gtest/gtest.h>
#include "MyClass.h"

TEST(MyClass, Teszteles)
{
    ASSERT_EQ (getApple(), "apple");
}