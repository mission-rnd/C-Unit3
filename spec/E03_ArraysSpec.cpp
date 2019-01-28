/*
 
 Note:
 *****important******
 DO NOT modify anything in this file.
 
 Implement the function stubs in E01_Files.cpp to make
 all the test cases in this file to pass.
 */

#include "stdafx.h"

#include "../src/E03_Arrays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E03_ArraysSpec
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
        

        
        void swap(int *a, int *b) {
            *a = *a + *b;
            *b = *a - *b;
            *a = *a - *b;
        }
        
        void sort(int arr[], int len) {
            for (int i = 0; i < len - 1; ++i) {
                for (int j = 0; j < len - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        swap(&arr[j], &arr[j + 1]);
                    }
                }
            }
        }
        
        bool validate(int expected[], int len, struct student **result) {
            int *actual = (int *)malloc(len * sizeof(int));
            for (int i = 0; i < len; ++i) {
                actual[i] = result[i]->score;
            }
            sort(actual, len);
            for (int i = 0; i < len; ++i) {
                if (expected[i] != actual[i]) {
                    return false;
                }
            }
            return true;
        }
        
        //
        // topKStudents
        //
        
        [TestMethod, Timeout(3000)]
        void TKValue1() {
            struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
            struct student **result = topKStudents(students, 3, 1);
            Assert::AreEqual(70, result[0]->score, L"K value 1 case failed.", 1, 2);
        }
        
        [TestMethod, Timeout(3000)]
        void positiveKValue() {
            struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
            struct student **result = topKStudents(students, 3, 2);
            int exp[] = { 60, 70 };
            Assert::IsTrue(validate(exp, 2, result), L"K value 2 case failed.", 1, 2);
            
            struct student students1[6] = { { "stud1", 30 }, { "stud2", 10 }, { "stud3", 60 }, { "stud4", 50 }, { "stud5", 20 }, { "stud6", 40 } };
            struct student **result1 = topKStudents(students1, 6, 3);
            int exp1[] = { 40, 50, 60 };
            Assert::IsTrue(validate(exp1, 3, result1), L"K value 3 case failed.", 1, 2);
        }
        
        //
        // countGreaterTransactions
        //
        
        [TestMethod, Timeout(1000)]
        void CGT_dateNotPresent()
        {
            struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
            int count = countGreaterTransactions(Arr, 5, "11-11-2015");
            Assert::AreEqual(0, count, L"count should be 0", 1,2);
        }
        
        [TestMethod, Timeout(1000)]
        void CGT_lastDate()
        {
            struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
            int count = countGreaterTransactions(Arr, 5, "29-11-2007");
            Assert::AreEqual(0, count, L"count should be 0", 1, 2);
        }
        
        [TestMethod, Timeout(1000)]
        void CGT_sameDatesArray()
        {
            struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "09-10-2003", "Second" }, { 30, "09-10-2003", "Third" }, { 90, "09-10-2003", "Fourth" }, { 10, "09-10-2003", "Fifth" } };
            int count = countGreaterTransactions(Arr, 5, "09-10-2003");
            Assert::AreEqual(0, count, L"count should be 0", 1, 2);
        }
        
        [TestMethod, Timeout(1000)]
        void CGT_firstDate()
        {
            struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
            int count = countGreaterTransactions(Arr, 5, "09-10-2003");
            Assert::AreEqual(4, count, L"count should be 4", 1, 2);
        }
        
        [TestMethod, Timeout(1000)]
        void CGT_middleDate()
        {
            struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
            int count = countGreaterTransactions(Arr, 5, "03-03-2005");
            Assert::AreEqual(2, count, L"count should be 2", 1, 2);
        }
        
        
        //
        // mergeSortedTransactions
        //
        bool compare(struct transaction *actual, struct transaction *expected, int length) {
            for (int i = 0; i < length; ++i) {
                if (actual[i].amount != expected[i].amount) {
                    return false;
                }
            }
            return true;
        }
        
        [TestMethod, Timeout(1000)]
        void MST_sameArrays()
        {
            struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            //int A[3] = { 1, 2, 3 }, B[3] = { 1, 2, 3 };
            struct transaction *result = mergeSortedTransactions(A, 3, B, 3);
            struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 30, "03-03-2005", "Third" } };
            Assert::IsTrue(compare(result, expected, 6), L"Same arrays case failed.", 1,2 );
            
            //int A1[3] = { 1, 1, 1 }, B1[3] = { 1, 1, 1 };
            struct transaction A1[3] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
            struct transaction B1[3] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
            struct transaction *result1 = mergeSortedTransactions(A1, 3, B1, 3);
            struct transaction expected1[6] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
            Assert::IsTrue(compare(result1, expected1, 6), L"Same arrays case failed.", 1,2 );
        }
        
        [TestMethod, Timeout(1000)]
        void MST_differentArrays()
        {
            struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
            //int A[3] = { 1, 2, 3 }, B[3] = { 4, 5, 6 };
            struct transaction *result = mergeSortedTransactions(A, 3, B, 3);
            struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
            Assert::IsTrue(compare(result, expected, 6), L"Different arrays case failed.", 1,2 );
            
            struct transaction A1[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
            struct transaction B1[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            //struct transaction A1[3] = { 4, 5, 6 }, B1[3] = { 1, 2, 3 };
            struct transaction *result1 = mergeSortedTransactions(A1, 3, B1, 3);
            Assert::IsTrue(compare(result1, expected, 6), L"Different arrays case failed.", 1,2 );
        }
        
        [TestMethod, Timeout(1000)]
        void MST_commonElements()
        {
            struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction B[3] = { { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
            //int A[3] = { 1, 2, 3 }, B[3] = { 2, 3, 6 };
            struct transaction *result = mergeSortedTransactions(A, 3, B, 3);
            struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
            Assert::IsTrue(compare(result, expected, 6), L"Different arrays case failed.", 1,2 );
            
            struct transaction A1[3] = { { 40, "09-10-2003", "Fourth" }, { 60, "19-10-2004", "Sixth" }, { 80, "03-03-2005", "Eigth" } };
            struct transaction B1[3] = { { 40, "09-10-2003", "Fourth" }, { 50, "19-10-2003", "Fifth" }, { 60, "19-10-2004", "Sixth" } };
            //int A1[3] = { 4, 6, 8 }, B1[3] = { 4, 5, 6 };
            struct transaction *result1 = mergeSortedTransactions(A1, 3, B1, 3);
            struct transaction expected1[6] = { { 40, "09-10-2003", "Fourth" }, { 40, "09-10-2003", "Fourth" }, { 50, "19-10-2003", "Fifth" }, { 60, "19-10-2004", "Sixth" }, { 60, "19-10-2004", "Sixth" }, { 80, "03-03-2005", "Eigth" } };
            Assert::IsTrue(compare(result1, expected1, 6), L"Different arrays case failed.", 1,2 );
        }
        
        
        [TestMethod, Timeout(1000)]
        void SACE_noCommonElements()
        {
            struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
            if (sortedArraysCommonElements(A, 3, B, 3) != NULL){
                Assert::Fail("SACE No common elements Check failed.");
            }
        }
        
        [TestMethod, Timeout(1000)]
        void SACE_sameArray()
        {
            struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            //int A[3] = { 1, 2, 3 }, expected[3] = { 1, 2, 3 };
            struct transaction expected[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
            struct transaction *result = sortedArraysCommonElements(A, 3, A, 3);
            Assert::IsTrue(compare(result, expected, 3), L"All common elements Check failed.", 1,2 );
        }
        
        [TestMethod, Timeout(1000)]
        void SACE_radomCommonElements()
        {
            struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" } };
            struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "22nd" }, { 320, "27-08-2015", "32nd" } };
            //int A[5] = { 1, 2, 3, 4, 5 }, B[3] = { 1, 22, 32 }, expected[1] = { 1 };
            struct transaction expected[3] = { { 10, "09-10-2003", "First" } };
            struct transaction *result = sortedArraysCommonElements(A, 5, B, 3);
            Assert::IsTrue(compare(result, expected, 1), L"One common element Check failed.", 1,2 );
        }
        
    };
}
