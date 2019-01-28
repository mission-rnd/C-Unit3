/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E01_Files.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E02_Arrays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E02_ArraysSpec
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
        // oneTwoCount
        //
        
        [TestMethod, Timeout(3000)]
        void TestOneTwoCountSpec() {
            int input[10] = { 1, 2, 2, 1, 1, 2, 1, 2, 1, 1 };
            int* Arr;
            Arr = oneTwoCount(input,10);
            int output[2] = { 6, 4 };
            for (int i = 0; i < 2; i++)
            {
                Assert::AreEqual(Arr[i], output[i], L"Valid input should return one's two's count", 1, 2);
            }
            
            int input2[8] = { 1, 1, 1, 1, 2, 2, 2, 2 };
            int* Arr2;
            Arr2 = oneTwoCount(input2,8);
            int output2[2] = { 4, 4 };
            for (int i = 0; i < 2; i++)
            {
                Assert::AreEqual(Arr2[i], output2[i], L"Valid input should return one's two's count", 1, 2);
            }
            
            int input3[5] = { 1, 1, 1, 1, 1 };
            int* Arr3;
            Arr3 = oneTwoCount(input3, 5);
            int output3[2] = { 5, 0 };
            for (int i = 0; i < 2; i++)
            {
                Assert::AreEqual(Arr3[i], output3[i], L"Valid input should return one's two's count", 1, 2);
            }
        }
        
        //
        // sortedArrayPositionsChange
        //
        
        [TestMethod, Timeout(3000)]
        void SAPnoValuesAreSwapped() {
            int Arr[5] = { 10, 20, 30, 40, 50 };
            sortedArrayPositionsChange(Arr, 5);
            Assert::AreEqual(20, Arr[1], L"Value at index 1 should be 20", 1, 2);
            Assert::AreEqual(40, Arr[3], L"Value at index 3 should be 40", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void SAPfirstAndLastValuesAreSwapped() {
            int Arr[5] = { 50, 20, 30, 40, 10 };
            sortedArrayPositionsChange(Arr, 5);
            Assert::AreEqual(10, Arr[0], L"Value at index 0 should be 10", 1, 2);
            Assert::AreEqual(50, Arr[4], L"Value at index 4 should be 50", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void SAPpositionsChange() {
            int Arr[5] = { 10, 40, 30, 20, 50 };
            sortedArrayPositionsChange(Arr, 5);
            Assert::AreEqual(20, Arr[1], L"Value at index 1 should be 20", 1, 2);
            Assert::AreEqual(40, Arr[3], L"Value at index 3 should be 40", 1, 2);
        }
        
        //
        // findSingleOccurenceNumber
        //
        
        [TestMethod, Timeout(1000)]
        void FSON_sortedArray()
        {
            int A[7] = { 2, 2, 2, 3, 6, 6, 6 };
            Assert::AreEqual(findSingleOccurenceNumber(A, 7), 3, L"sorted Array case failed.", 1,2 );
            
            int A1[7] = { 2, 2, 2, 3, 3, 3, 6 };
            Assert::AreEqual(findSingleOccurenceNumber(A1, 7), 6, L"sorted Array case failed.", 1,2 );
            
            int A2[7] = { 2, 3, 3, 3, 6, 6, 6 };
            Assert::AreEqual(findSingleOccurenceNumber(A2, 7), 2, L"sorted Array case failed.", 1,2 );
        }
        
        [TestMethod, Timeout(1000)]
        void FSON_unSortedArray()
        {
            int A[10] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
            Assert::AreEqual(findSingleOccurenceNumber(A, 10), 2, L"un sorted Array case failed.", 1,2 );
            
            int A1[10] = { 12, 1, 2, 3, 2, 1, 1, 2, 3, 3 };
            Assert::AreEqual(findSingleOccurenceNumber(A1, 10), 12, L"un sorted Array case failed.", 1,2 );
            
            int A2[10] = { 12, 1, 12, 3, 12, 2, 2, 2, 3, 3 };
            Assert::AreEqual(findSingleOccurenceNumber(A2, 10), 1, L"un sorted Array case failed.", 1,2 );
        }
        
        //
        // studentsCount
        //
        [TestMethod, Timeout(3000)]
        void SCsingleElement() {
            int Arr1[1] = { 1 }, lessCount, moreCount;
            studentsCount(Arr1, 1, 1, &lessCount, &moreCount);
            Assert::AreEqual(0, lessCount, L"Single element lessCount 0 case failed.", 1, 2);
            Assert::AreEqual(0, moreCount, L"Single element moreCount 0 case failed.", 1, 2);
            int Arr2[1] = { 1 };
            studentsCount(Arr2, 1, 12, &lessCount, &moreCount);
            Assert::AreEqual(1, lessCount, L"Single element lessCount 1 case failed.", 1, 2);
            Assert::AreEqual(0, moreCount, L"Single element moreCount 0 case failed.", 1, 2);
            int Arr3[1] = { 111 };
            studentsCount(Arr3, 1, 12, &lessCount, &moreCount);
            Assert::AreEqual(0, lessCount, L"Single element lessCount 0 case failed.", 1, 2);
            Assert::AreEqual(1, moreCount, L"Single element moreCount 1 case failed.", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void SCsameElements() {
            int Arr[4] = { 12, 12, 12, 12 }, lessCount, moreCount;
            studentsCount(Arr, 4, 12, &lessCount, &moreCount);
            Assert::AreEqual(0, lessCount, L"Same elements lessCount 0 case failed.", 1, 2);
            Assert::AreEqual(0, moreCount, L"Same elements moreCount 0 case failed.", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void SCdifferentElements() {
            int Arr[5] = { 10, 20, 30, 40, 50 }, lessCount, moreCount;
            studentsCount(Arr, 5, 30, &lessCount, &moreCount);
            Assert::AreEqual(2, lessCount, L"Score equal to one element case failed.", 1, 2);
            Assert::AreEqual(2, moreCount, L"Score equal to one element case failed.", 1, 2);
            int Arr1[5] = { 10, 20, 31, 40, 50 };
            studentsCount(Arr1, 5, 30, &lessCount, &moreCount);
            Assert::AreEqual(2, lessCount, L"Score not equal to any element case failed.", 1, 2);
            Assert::AreEqual(3, moreCount, L"Score not equal to any element case failed.", 1, 2);
        }
    };
}
