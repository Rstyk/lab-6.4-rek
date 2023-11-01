#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4 rek/lab 6.4 rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace laba64rek
{
	TEST_CLASS(laba64rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double b[] = { -1, 2, -3, 4, 5 };
			int result = Max(b, 5, 0, b[0]);
			Assert::AreEqual(5, result);

		}
	};
}
