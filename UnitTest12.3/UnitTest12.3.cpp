#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123
{
	TEST_CLASS(UnitTest123)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Створюємо списки L1 і L2
			Node* FirstL1 = NULL;
			Node* LastL1 = NULL;

			Node* FirstL2 = NULL;
			Node* LastL2 = NULL;


			// Заповнюємо списки L1 і L2 згідно макету
			enqueue(FirstL1, LastL1, 22);
			enqueue(FirstL1, LastL1, 44);

			enqueue(FirstL2, LastL2, 14);
			enqueue(FirstL2, LastL2, 423);
			enqueue(FirstL2, LastL2, 22);
			enqueue(FirstL2, LastL2, 44);
			enqueue(FirstL2, LastL2, 55);

			// Викликаємо функцію isSublist і перевіряємо результат
			bool result = isSublist(FirstL1, FirstL2);
			Assert::IsTrue(result, L"L1 is a part of L2");

			// Звільняємо пам'ять списків L1 і L2
			Node* curr = LastL1;
			while (curr != nullptr)
			{
				Node* temp = curr;
				curr = curr->next;
				delete temp;
			}

			curr = LastL2;
			while (curr != nullptr)
			{
				Node* temp = curr;
				curr = curr->next;
				delete temp;
			}
		}
	};
}
