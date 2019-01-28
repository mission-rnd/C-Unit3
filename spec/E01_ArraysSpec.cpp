/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E01_Files.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E01_Arrays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E01_ArraysSpec
    {
    private:
        TestContext^ testContextInstance;
        
    public:
        /// <summary>
        ///Gets or sets the test context which provides
        ///information about and functionality for the current test run.
        ///</summary>
        property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
        {
            Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
            {
                return testContextInstance;
            }
            System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
            {
                testContextInstance = value;
            }
        };
        
        //
        // maxPosNegSum
        //
        
        [TestMethod, Timeout(3000)]
        void TestMaxPosNegSuminInValidInputCheck() {
            int Arr1[5] = { 1, 9, 8, 2, 3 };
            Assert::AreEqual(0,maxPosNegSum(Arr1,5), L"Array invalid input failed.", 1, 2);
            int Arr2[5] = { -1, -9, -8, -2, -3 };
			Assert::AreEqual(0, maxPosNegSum(Arr2, 5), L"Array invalid input failed.", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void maxPosNegSuminsertValidInputCheck() {
            int Arr1[8] = {1, 9, 8, 2, 3, -1, -10, -5};
            Assert::AreEqual(8, maxPosNegSum(Arr1, 8), L"Valid input check failed", 1, 2);
            int Arr2[6] = {-10, -1, -2, -9, -12, 0};
            Assert::AreEqual(-1, maxPosNegSum(Arr2, 6), L"Valid input check failed", 1, 2);
            int Arr3[30] = { -2, -83, 67, 98, -72, -74, 29, 39, 60, 36, 4, -93, 83, -55, 69, -10, -29, 38, -64, -14, -93, 76, -58, 32, -84, 17, -64, 96, -40, -74 };
            Assert::AreEqual(96, maxPosNegSum(Arr3, 30), L"Valid input check failed", 1, 2);
        }
        
        
        //
        // removeDuplicates
        //
        
        [TestMethod, Timeout(3000)]
        void RDnoDuplicates() {
            int Arr[3] = { 1, 2, 3 };
            int len=removeDuplicates(Arr, 3);
            Assert::AreEqual(3, len, L"Length should be 3", 1, 2);
            Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", 1, 2);
            Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", 1, 2);
            Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void RDunSortedArray() {
            int Arr[7] = { 1, 2, 3, 1, 2, 3, 4 };
            int len=removeDuplicates(Arr, 7);
            Assert::AreEqual(4, len, L"Length should be 4", 1, 2);
            Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", 1, 2);
            Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", 1, 2);
            Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", 1, 2);
            Assert::AreEqual(4, Arr[3], L"Value at index 3 should be 4", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void RDsortedArray() {
            int Arr[6] = { 1, 1, 2, 2, 3, 3 };
            int len=removeDuplicates(Arr, 6);
            Assert::AreEqual(3, len, L"Length should be 3", 1, 2);
            Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", 1, 2);
            Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", 1, 2);
            Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", 1, 2);
        }
        
    };
}
