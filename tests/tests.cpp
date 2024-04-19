#include <gtest/gtest.h>
#include "MySharedPtr.h"
#include <string>

//Test cases
TEST(MySharedPtrTest, Initialization) {
    MySharedPtr<int> msp1 (new int (25));
    MySharedPtr<int> msp2 = msp1;
}


TEST(MySharedPtrTest, DereferenceInt) {
    MySharedPtr<int> msp1 (new int (25));
    ASSERT_EQ(*msp1, 25);
    MySharedPtr<int> msp2 = msp1;
    ASSERT_EQ(*msp2, 25);
}

TEST(MySharedPtrTest, DereferenceString) {
    MySharedPtr<std::string> msp1 (new std::string ("Hello!"));
    EXPECT_EQ(*msp1, "Hello!");
    MySharedPtr<std::string> msp2 = msp1;
    EXPECT_EQ(*msp2, "Hello!");
}

TEST(MySharedPtrTest, DereferenceNullPointer) {
    MySharedPtr<int> sharedPtr;
    try {
        int value = *sharedPtr;
        FAIL() << "Expected std::runtime_error";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "Dereferencing a nullptr");
    }
}

TEST(MySharedPtrTest, ArrowOperatorNullptr) {
    MySharedPtr<int> msp(nullptr);
    ASSERT_EQ(msp.operator->(), nullptr); 
}

TEST(MySharedPtrTest, ArrowOperatorValid) {
    MySharedPtr<int> msp(new int(22));
    ASSERT_NE(msp.operator->(), nullptr); 
    ASSERT_EQ(*msp.operator->(), 22);     
}


TEST(MySharedPtrTest, CounterOutOfScope) {
    MySharedPtr<std::string> msp1 (new std::string ("Hello!"));
    ASSERT_EQ(msp1.get_count(), 1); 
    {
        MySharedPtr<std::string> msp2 = msp1;
        ASSERT_EQ(msp1.get_count(), 2); 
        ASSERT_EQ(msp2.get_count(), 2); 
    }
    ASSERT_EQ(msp1.get_count(), 1); 
}

TEST(MySharedPtrTest, BoolOperatorTrue) {
    MySharedPtr<int> msp (new int(1));
    ASSERT_TRUE(msp);
}

TEST(MySharedPtrTest, BoolOperatorFalse) {
    MySharedPtr<int> msp (nullptr);
    ASSERT_FALSE(msp);
}

TEST(MySharedPtrTest, GetValidPointer) {
    int *p = new int (12);
    MySharedPtr<int> msp (p);
    ASSERT_EQ(msp.get(),p);
}

TEST(MySharedPtrTest, GetNullPointer) {
    MySharedPtr<int> msp;
    EXPECT_EQ(msp.get(), nullptr);
}

TEST(MySharedPtrTest, MoveConstructor) {
    MySharedPtr<int> ptr1(new int(33));
    MySharedPtr<int> ptr2(std::move(ptr1));
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(*ptr2, 33);
}

TEST(MySharedPtrTest, MoveAssignmentOperator) {
    MySharedPtr<int> ptr1(new int(33));
    MySharedPtr<int> ptr2(new int(10));
    ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(*ptr2, 33);
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
