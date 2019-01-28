//
//  E02_Arrays.cpp
//  Unit03_Exercise02_Understanding_Arrays
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_ArraysSpec.cpp file.
 
 */

#include "E02_Arrays.h"

/*
 OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
 Ex: input: [1,2,2,1,2,1,2]
 output: [3,4]
 where 3 is the count of 1's and 4 is the count of 2's
 
 INPUTS: An Integer Array and length of the array
 
 OUTPUT: An Array with 1's count and 2's count
 */

int *oneTwoCount(int *numbers, int size)
{
    return NULL;
}


/*
 OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
 E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]
 
 INPUTS: Ascending sorted array with two positions swapped, length of the array.
 
 OUTPUT: Update sorted array by fixing swapped numbers.
 
 Problem Code :SAP
 */

void sortedArrayPositionsChange(int *numbers, int size)
{
    return;
}


/*
 OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
 once. Find the element that occurs once.
 E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
 ouput: 2
 
 INPUTS: Integer array and length of the array.
 
 OUTPUT: Element that occurs only once.
 
 NOTES:
 There are better ways of solving the problem than a brute-force solution which is of O(n^2)
 complexity .
 */

int findSingleOccurenceNumber(int *numbers, int size) {
    return -1;
}

/*
 OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
 E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).
 
 INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
 used to store final results.
 
 OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.
 
 Problem Code :SC
 */

void studentsCount(int *marks, int size, int score, int *lessCount, int *moreCount) {
    return;
}

