//
//  E03_Arrays.cpp
//  Unit03_Exercise03_Understanding_Arrays
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E03_ArraysSpec.cpp file.
 
 */

#include "E03_Arrays.h"




/*
 OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
 Input is array of structures of type student (each student has name and score).
 E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
 return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]
 
 INPUTS: array of structures of type student, length of the array, integer K.
 
 OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.
 
 NOTES:
 Problem Code :TK
 */


struct student ** topKStudents(struct student *students, int size, int K) {
    return NULL;
}



/*
 OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
 -- find the count of numbers greater than a given number in a sorted array.
 E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 date = "19-10-2004"
 Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })
 
 INPUTS: One bank statement (array of transactions) and date.
 
 OUTPUT: Return the number of transactions in that statement after a given date.

 NOTES:
 Problem Code: CGT
 
 */

int countGreaterTransactions(struct transaction *transactions, int len, char *date) {
    return -1;
}



/*
 OVERVIEW: You are given 2 bank statements that are ordered by date -
 Write a function that produces a single merged statement ordered by dates.
 E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
 Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }
 
 INPUTS: Two bank statements (array of transactions).
 
 OUTPUT: Combined statement ordered by transaction date.
 
 NOTES:
 */

struct transaction *mergeSortedTransactions(struct transaction *A, int ALen, struct transaction *B, int BLen) {
    return NULL;
}


/*
 OVERVIEW: You are given 2 bank statements that are ordered by date.
 Write a function that returns dates common to both statements
 (ie both statements have transactions in these dates).
 E.g.: Input:
 A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
 Output: { { 10, "09-10-2003", "First" } }
 
 INPUTS: Two bank statements (array of transactions).
 
 OUTPUT: Transactions having same dates.
 
 
 ERROR CASES: Return NULL for invalid inputs.
 
 NOTES:
 */

struct transaction *sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
    return NULL;
}
