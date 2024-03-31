#include "pch.h"
#include "LinkedList.h"
#include "StaxAppData.h"

// place in namespace so that VS Test Explorer lists the namespace correctly
namespace StaxLinkedListTests
{
	TEST(LinkedListLogicTests, TestPushFrontOnEmptyList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
		ll.push_front(data);

		ASSERT_EQ(ll.size(), 1);
		ASSERT_EQ(ll.front()->userId, data->userId);
	}

	TEST(LinkedListLogicTests, TestPushBackOnEmptyList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data = std::make_shared<StaxAppData>("a", "b", "c", 99);
		ll.push_back(data);

		ASSERT_EQ(ll.size(), 1);
		ASSERT_EQ(ll.front()->userId, data->userId);
	}

	TEST(LinkedListLogicTests, TestPushFrontOnNonEmptyList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_front(data2);

		ASSERT_EQ(ll.size(), 2);
		ASSERT_EQ(ll.front()->userId, data2->userId);
	}

	TEST(LinkedListLogicTests, TestPushBackOnNonEmptyList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_back(data2);

		ASSERT_EQ(ll.size(), 2);
		ASSERT_EQ(ll.back()->userId, data2->userId);
	}

	TEST(LinkedListLogicTests, TestReusingClearedList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ll.push_front(std::make_shared<StaxAppData>());
		ll.clear();
		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_EQ(ll.size(), 1);
		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_EQ(ll.size(), 2);

		ll.clear();
		ASSERT_TRUE(ll.empty());
	}

	TEST(LinkedListLogicTests, TestPopBackOnSingleNodeList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_EQ(ll.size(), 1);

		ll.pop_back();
		ASSERT_TRUE(ll.empty());
	}

	TEST(LinkedListLogicTests, TestPopFrontOnSingleNodeList)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		ll.push_front(std::make_shared<StaxAppData>());
		ASSERT_EQ(ll.size(), 1);

		ll.pop_front();
		ASSERT_TRUE(ll.empty());
	}
}
