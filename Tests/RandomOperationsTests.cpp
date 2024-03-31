#include "pch.h"
#include "LinkedList.h"

namespace StaxLinkedListTests
{
	enum class Operation
	{
		AddFirst,
		AddLast,
		PeekFirst,
		PeekLast,
		RemoveFirst,
		RemoveLast,
	};

	const int OPERATION_COUNT = 6;

	TEST(RandomOperationsTests, RandomOperationsProduceCorrectList) {

		LinkedList<int> linkedList;
		std::vector<int> verificationList;

		auto iterations = static_cast<int>(4e6);	// 4,000,000
		auto maxInt = 100000;

		std::srand(static_cast<unsigned>(std::time(0)));

		for (auto i = 0; i < iterations; i++)
		{
			auto val = std::rand() % maxInt;
			auto operation = static_cast<Operation>(std::rand() % OPERATION_COUNT);

			switch (operation)
			{
			case Operation::AddFirst:
				linkedList.push_front(val);
				verificationList.insert(verificationList.begin(), val);
				break;
			case Operation::AddLast:
				linkedList.push_back(val);
				verificationList.push_back(val);
				break;
			case Operation::RemoveFirst:
				if (linkedList.size() > 0)
				{
					linkedList.pop_front();
					verificationList.erase(verificationList.begin());
				}
				break;
			case Operation::RemoveLast:
				if (linkedList.size() > 0)
				{
					linkedList.pop_back();
					verificationList.pop_back();
				}
				break;
			case Operation::PeekFirst:
				if (linkedList.size() > 0)
				{
					ASSERT_EQ(linkedList.front(), verificationList.front());
				}
				break;
			case Operation::PeekLast:
				if (linkedList.size() > 0)
				{
					ASSERT_EQ(linkedList.back(), verificationList.back());
				}
				break;
			}
		}

		// check if lists are the same (i.e. all values are the same)
		for (auto val : verificationList)
		{
			auto llVal = linkedList.pop_front();
			ASSERT_EQ(llVal, val);
		}

		// check if linked list is empty, i.e. it was the same size as the verification list
		ASSERT_TRUE(linkedList.empty());
	}
}