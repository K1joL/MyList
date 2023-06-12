#include "pch.h"
#include "../MyList.cpp"

struct MyClassTest : public testing::Test {
	List* list = nullptr;

	void SetUp() { list = new List(); } // аналог конструктора
	void TearDown() { delete list; } // аналог деструктора
};

TEST_F(MyClassTest, init_class)
{
	//Act
	size_t size = list->size();

	//Assert
	EXPECT_EQ(size, 0);

	EXPECT_EQ(list->getHead(), nullptr);
}

TEST_F(MyClassTest, push_back_test)
{
	//Act
	list->push_back(1);
	size_t size = list->size();

	//Assert
	EXPECT_EQ(list->getHead()->value, 1);
	EXPECT_EQ(size, 1);

	//Act
	list->push_back(2);
	size = list->size();

	//Assert
	EXPECT_EQ(list->getHead()->next->value, 2);
	EXPECT_EQ(size, 2);
}

TEST_F(MyClassTest, pop_back_test)
{
	//Assert
	EXPECT_THROW(list->pop_back(), std::out_of_range);

	//Act
	list->push_back(1);
	list->pop_back();
	size_t size = list->size();

	//Assert
	EXPECT_EQ(size, 0);
	EXPECT_EQ(list->getHead(), nullptr);

	//Act
	list->push_back(1);
	list->push_back(2);
	list->pop_back();
	size = list->size();

	//Assert
	EXPECT_EQ(size, 1);
	EXPECT_EQ(list->getHead()->value, 1);
	EXPECT_EQ(list->getHead()->next, nullptr);
}

TEST_F(MyClassTest, insert_test)
{
	//Act
	list->insert(1, 10);
	size_t size = list->size();

	//Assert
	EXPECT_EQ(size, 1);
	EXPECT_EQ(list->getHead()->value, 10);

	//Act
	list->insert(0, 1);
	size = list->size();

	//Assert
	EXPECT_EQ(size, 2);
	EXPECT_EQ(list->getHead()->value, 1);
	EXPECT_EQ(list->getHead()->next->value, 10);


	//Act
	list->pop_back();
	list->insert(1, 2);
	size = list->size();

	//Assert
	EXPECT_EQ(size, 2);
	EXPECT_EQ(list->getHead()->next->value, 2);

	//Act
	list->insert(1, 5);
	size = list->size();

	//Assert
	EXPECT_EQ(size, 3);
	EXPECT_EQ(list->getHead()->next->next->value, 2);
	EXPECT_EQ(list->getHead()->next->value, 5);

	EXPECT_THROW(list->insert(10, 5), std::out_of_range);
	EXPECT_THROW(list->insert(-1, 5), std::out_of_range);
}

TEST_F(MyClassTest, erase_test)
{
	//Assert
	EXPECT_THROW(list->erase(0), std::out_of_range);

	//Act
	list->push_back(6);
	//Assert
	EXPECT_THROW(list->erase(10), std::out_of_range);
	EXPECT_THROW(list->erase(-1), std::out_of_range);

	//list = {6}
	//Act
	list->erase(0);
	size_t size = list->size();

	//list = {}
	//Assert
	EXPECT_EQ(list->getHead(), nullptr);
	EXPECT_EQ(size, 0);

	//list = {}
	//Act
	list->push_back(1);
	list->push_back(2);
	list->erase(0);
	size = list->size();

	//list = {2}
	//Assert
	EXPECT_EQ(list->getHead()->value, 2);
	EXPECT_EQ(size, 1);

	//list = {2}
	//Act
	list->push_back(3);
	list->erase(1);
	size = list->size();

	//list = {2}
	//Assert
	EXPECT_EQ(list->getHead()->next, nullptr);
	EXPECT_EQ(size, 1);

	//list = {2}
	//Act
	list->push_back(4);
	list->push_back(5);
	list->erase(1);
	size = list->size();

	//list = {2, 5}
	//Assert
	EXPECT_EQ(list->getHead()->value, 2);
	EXPECT_EQ(list->getHead()->next->value, 5);
	EXPECT_EQ(size, 2);
}

TEST_F(MyClassTest, sort_test)
{
	//Assert
	EXPECT_THROW(list->sort(), std::logic_error);

	//Act
	list->push_back(0);
	list->push_back(4);
	list->push_back(-5);
	list->sort();

	//Assert
	EXPECT_EQ(list->pop_back(), 4);
	EXPECT_EQ(list->pop_back(), 0);
	EXPECT_EQ(list->pop_back(), -5);

	//Act
	list->push_back(1);
	list->push_back(0);
	list->sort();

	//Assert
	EXPECT_EQ(list->pop_back(), 1);
	EXPECT_EQ(list->pop_back(), 0);
}

TEST_F(MyClassTest, clear_test)
{

	//Act
	list->push_back(1);
	list->push_back(2);
	list->push_back(3);
	auto node = list->cback();
	size_t size = list->size();
	//Assert
	EXPECT_EQ(size, 3);

	list->clear();
	size = list->size();
	//Assert
	EXPECT_EQ(size, 0);
	EXPECT_NE(node->value, 3);
	EXPECT_EQ(list->getHead(), nullptr);
}

TEST_F(MyClassTest, invert_test)
{
	//Assert
	EXPECT_THROW(list->invert(), std::out_of_range);

	//Act
	list->push_back(0);
	list->push_back(4);
	list->push_back(-5);
	list->invert();

	//Assert
	EXPECT_EQ(list->pop_back(), 0);
	EXPECT_EQ(list->pop_back(), 4);
	EXPECT_EQ(list->pop_back(), -5);

	//Act
	list->clear();
	list->push_back(1);
	list->push_back(2);
	list->invert();
	EXPECT_EQ(list->pop_back(), 1);
	EXPECT_EQ(list->pop_back(), 2);
}

TEST_F(MyClassTest, middle_test)
{
	//Assert
	EXPECT_THROW(list->middle(), std::out_of_range);

	//Act
	list->push_back(1);

	//list = {1}
	//Assert
	EXPECT_EQ(list->middle(), 1);

	//Act
	list->push_back(2);

	//list = {1,2}
	//Assert
	EXPECT_EQ(list->middle(), 1);

	//Act
	list->push_back(1);
	
	//list = {1,2,1}
	//Assert
	EXPECT_EQ(list->middle(), 2);

	//Act
	list->push_back(4);

	//list = {1,2,1,4}
	//Assert
	EXPECT_EQ(list->middle(), 2);
}