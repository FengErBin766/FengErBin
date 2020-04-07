#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int getmax(int* arr, int N)
{
    int max1, max2, i;
    for (i = 0, max1 = 0, max2 = 0; i < N; i++)
    {
        max1 += arr[i];
        if (max2 < max1)
        {
            max2 = max1;
        }
        if (max1 < 0)
        {
            max1 = 0;
        }
    }
    if (max2 < 0)
    {
        return 0;
    }
    else
        return max2;
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int arr[] = { -1,2,3 };

            int n = 3;

            int k;

            k = getmax(arr, n);

            Assert::AreEqual(k, 5);
		}

        TEST_METHOD(TestMethod2)
        {
            int arr[] = { 5,-2,-1,2 };

            int n = 4;

            int k;

            k = getmax(arr, n);

            Assert::AreEqual(k, 5);
        }
	};
}
