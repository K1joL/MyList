#include "pch.h"
#include "../MyList.cpp"

struct MyClassTest : public testing::Test {
	List* list = nullptr;

	void SetUp() { list = new List(1); } // аналог конструктора
	void TearDown() { delete list; } // аналог деструктора
};

TEST_F(MyClassTest, copy_test)
{
	//Act
	List* newList = list->copy();
	auto head = list->getHead();
	auto newHead = newList->getHead();

	//Assert
	EXPECT_NE(head, newHead);
	EXPECT_NE(head->another, newHead->another);
	EXPECT_EQ(head->value, newHead->value);

	//Act
	auto scndNode = head->next;
	auto scndNodeNew = newHead->next;

	//Assert
	EXPECT_NE(scndNode, scndNodeNew);
	EXPECT_NE(scndNode->another, scndNodeNew->another);
	EXPECT_EQ(scndNode->value, scndNodeNew->value);

	//Act
	auto thrdNode = scndNode->next;
	auto thrdNodeNew = scndNodeNew->next;

	//Assert
	EXPECT_NE(thrdNode, thrdNodeNew);
	EXPECT_NE(thrdNode->another, thrdNodeNew->another);
	EXPECT_EQ(thrdNode->value, thrdNodeNew->value);

	//Act
	size_t size = list->size();
	size_t newSize = newList->size();

	//Assert
	EXPECT_EQ(size, newSize);
}
