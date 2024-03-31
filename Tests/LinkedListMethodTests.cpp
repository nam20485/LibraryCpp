#include "pch.h"
#include "LinkedList.h"
#include "StaxAppData.h"

// place in namespace so that VS Test Explorer lists the namespace correctly
namespace StaxLinkedListTests
{
	TEST(LinkedListMethodTests, TestFront)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		ASSERT_EQ(ll.front()->userId, data1->userId);

		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_front(data2);
		ASSERT_EQ(ll.front()->userId, data2->userId);

		auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
		ll.push_back(data3);
		ASSERT_EQ(ll.front()->userId, data2->userId);
	}

	TEST(LinkedListMethodTests, TestBack)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		ASSERT_EQ(ll.back()->userId, data1->userId);

		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_front(data2);
		ASSERT_EQ(ll.back()->userId, data1->userId);

		auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
		ll.push_back(data3);
		ASSERT_EQ(ll.back()->userId, data3->userId);
	}

	TEST(LinkedListMethodTests, TestPopFront)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		ASSERT_EQ(ll.front()->userId, data1->userId);

		auto val1 = ll.pop_front();
		ASSERT_EQ(val1->userId, data1->userId);
		ASSERT_TRUE(ll.empty());

		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_back(data2);
		auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
		ll.push_back(data3);

		auto val = ll.pop_front();
		ASSERT_EQ(val->userId, data2->userId);
		ASSERT_EQ(ll.size(), 1);

		val = ll.pop_front();
		ASSERT_EQ(val->userId, data3->userId);
		ASSERT_TRUE(ll.empty());
	}

	TEST(LinkedListMethodTests, TestPopBack)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		auto data1 = std::make_shared<StaxAppData>("a", "b", "c", 1);
		ll.push_front(data1);
		ASSERT_EQ(ll.front()->userId, data1->userId);

		auto val1 = ll.pop_back();
		ASSERT_EQ(val1->userId, data1->userId);
		ASSERT_TRUE(ll.empty());

		auto data2 = std::make_shared<StaxAppData>("a", "b", "c", 2);
		ll.push_back(data2);
		auto data3 = std::make_shared<StaxAppData>("a", "b", "c", 3);
		ll.push_back(data3);

		auto val = ll.pop_back();
		ASSERT_EQ(val->userId, data3->userId);
		ASSERT_EQ(ll.size(), 1);

		val = ll.pop_back();
		ASSERT_EQ(val->userId, data2->userId);
		ASSERT_TRUE(ll.empty());
	}

	TEST(LinkedListMethodTests, TestSize)
	{
		StaxAppData::LinkedList ll;

		ASSERT_EQ(ll.size(), 0);

		const int TOTAL = 1000;

		for (int i = 0; i < TOTAL; i++)
		{
			ll.push_back(std::make_shared<StaxAppData>());
			ASSERT_EQ(ll.size(), i + 1);
		}

		for (int i = TOTAL; i > 0; i--)
		{
			ll.pop_back();
			ASSERT_EQ(ll.size(), i - 1);
		}

		ASSERT_EQ(ll.size(), 0);
	}

	TEST(LinkedListMethodTests, TestEmpty)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_FALSE(ll.empty());

		ll.pop_front();
		ASSERT_TRUE(ll.empty());

		ll.push_front(std::make_shared<StaxAppData>());
		ASSERT_FALSE(ll.empty());

		ll.pop_back();
		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_FALSE(ll.empty());
		ll.push_back(std::make_shared<StaxAppData>());
		ASSERT_FALSE(ll.empty());

		ll.clear();

		ASSERT_TRUE(ll.empty());
	}

	TEST(LinkedListMethodTests, TestClear)
	{
		StaxAppData::LinkedList ll;

		ASSERT_TRUE(ll.empty());

		ll.push_back(std::make_shared<StaxAppData>());
		ll.push_front(std::make_shared<StaxAppData>());
		ll.clear();
		ASSERT_TRUE(ll.empty());
	}
}