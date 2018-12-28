#include<stdio.h>
#include"Heap.h"

int main(int argc, char* argv[])
{
   int i;
   int array[14] = {16, 6, 12, 12, 18, 10, 11, 7, 14, 13, 15, 5, 17, 9};
   int carray[1] = {100};
   int length = sizeof(array) / sizeof(int);
   printf("The length of this array: %d\n", length); // should be 14.
   int *error = NULL;
   int *barray = NULL;
   Heap A = newHeap(14, 14,  array);
   Heap B = NULL;

   printf("\nTesting parent, left, and right.\n");
   for( int i = 1; i <= 4;  i++ )
   {
      printf("The parent of index %d is %d\n", i, parent(i));
      printf("The left child of index %d is %d\n", i, left(i));
      printf("The right child of index %d is %d\n\n", i, right(i));
   }
   printf("\nTesting heapify\n");
   for( int i = 1; i <= length;  i++ )
   {
      heapify(A, i);
   }
   printf("\nTesting heapSort()\n");
   barray = heapSort(array, 14);

   // printing Heap
   printf("\n\nPrinting sorted barray:\n"); // debug
   for( int i = 1; i <= length;  i++ )
   {
      printf("Index %d : %d\n", i, barray[i]); // debug
   }
   barray = heapSort(carray, 1);

   // printing Heap
   printf("\n\nPrinting sorted barray:\n"); // debug
   for( int i = 1; i <= 1;  i++ )
   {
      printf("Index %d : %d\n", i, barray[i]); // debug
   }


   printf("\nPriorityQueue Methods tests: --------------------------\n");

   printf("Original state of the heap.\n");
   printHeap(A);

   printf("\nPriorityQueue heapDecreaseKey() tests -------------------\n");

   heapDecreaseKey(A, 6, 3);
   printf("Heap after decreasing sixth index's key.\n");
   printHeap(A);

   heapDecreaseKey(A, 5, 1);
   printf("Heap after decreasing fifth index's key.\n");
   printHeap(A);

   heapDecreaseKey(A, 4, 4);
   printf("Heap after decreasing fourth index's key.\n");
   printHeap(A);

   heapDecreaseKey(A, 2, 2);
   printf("Heap after decreasing second index's key.\n");
   printHeap(A);

   printf("\n");
   printf("The minimum again is: %d\n\n", heapMinimum(A));

   printf("\nPriorityQueue heapExtractMin() tests -------------------\n");

   printf("Printing what should be the original heap:\n");
   printHeap(A);

   int minimum = 0;
   for( int i = 1; i <= 13; i++)
   {
      minimum = heapExtractMin(A);
      printf("The minimum is %d\n\n", minimum);
      printHeap(A);
   }
   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);
   printf("Printing what should be an empty heap:\n");
   printHeap(A);

   printf("\nPriorityQueue heapInsert() tests -------------------\n");

   for( int i = 3; i < 14; i += 2)
   {
      heapInsert(A, i);
      printf("\nInserted a %d and printing:\n", i);
      printHeap(A);
      printf("\n");
   }
   for( int i = 2; i <= 14; i += 2)
   {
      heapInsert(A, i);
      printf("\nInserted a %d and printing:\n", i);
      printHeap(A);
      printf("\n");
   }
   heapInsert(A, 1);
   printf("\nInserted a 1 and printing:\n");
   printHeap(A);
   printf("\n");

   printf("\nPriorityQueue testing error messages -------------------\n");

   /* freeHeap(&B); */

   /* heapify( A, 0); */
   /* heapify( A, 14); */
   /* heapify( A, 7); */
   /* heapify( A, 0); */

   //   buildHeap(B);

   for( int i = 1; i <= 14; i++) // making the heap be empty.
   {
      heapExtractMin(A);
   }
   /* heapSort(error, 1000); */
   /* heapSort(array, 0); */

   /* heapMinimum(B); */
   /* heapMinimum(A); */

   /* heapDeleteMin(B); */
   /* heapDeleteMin(A); */

   /* heapExtractMin(B); */
   /* heapExtractMin(A); */

   heapInsert(A, 10);

   /* heapDecreaseKey(B, 0, 10); // more tests are possible. */
   /* heapDecreaseKey(B, 1, 10); // more tests are possible. */
   /* heapDecreaseKey(A, 2, 10); // more tests are possible. */

   /* heapInsert(B, 10); */
   /* heapInsert(B, 25); */

   printf("Ping!\n");
   
   freeHeap(&A);
   return(0);
}

/* -------------------------------- OUTPUT ------------------------------------

The length of this array: 14

Testing parent, left, and right.
The parent of index 1 is 0
The left child of index 1 is 2
The right child of index 1 is 3

The parent of index 2 is 1
The left child of index 2 is 4
The right child of index 2 is 5

The parent of index 3 is 1
The left child of index 3 is 6
The right child of index 3 is 7

The parent of index 4 is 2
The left child of index 4 is 8
The right child of index 4 is 9


Testing heapify

Testing heapSort()


Printing sorted barray:
Index 1 : 18
Index 2 : 17
Index 3 : 16
Index 4 : 15
Index 5 : 14
Index 6 : 13
Index 7 : 12
Index 8 : 12
Index 9 : 11
Index 10 : 10
Index 11 : 9
Index 12 : 7
Index 13 : 6
Index 14 : 5


Printing sorted barray:
Index 1 : 100

PriorityQueue Methods tests: --------------------------
Original state of the heap.
5 6 9 7 13 10 11 12 14 18 15 12 17 16 

PriorityQueue heapDecreaseKey() tests -------------------
Heap after decreasing sixth index's key.
3 6 5 7 13 9 11 12 14 18 15 12 17 16 
Heap after decreasing fifth index's key.
1 3 5 7 6 9 11 12 14 18 15 12 17 16 
Heap after decreasing fourth index's key.
1 3 5 4 6 9 11 12 14 18 15 12 17 16 
Heap after decreasing second index's key.
1 2 5 4 6 9 11 12 14 18 15 12 17 16 

The minimum again is: 1


PriorityQueue heapExtractMin() tests -------------------
Printing what should be the original heap:
1 2 5 4 6 9 11 12 14 18 15 12 17 16 
The minimum is 1

2 4 5 12 6 9 11 16 14 18 15 12 17 
The minimum is 2

4 6 5 12 15 9 11 16 14 18 17 12 
The minimum is 4

5 6 9 12 15 12 11 16 14 18 17 
The minimum is 5

6 12 9 14 15 12 11 16 17 18 
The minimum is 6

9 12 11 14 15 12 18 16 17 
The minimum is 9

11 12 12 14 15 17 18 16 
The minimum is 11

12 14 12 16 15 17 18 
The minimum is 12

12 14 17 16 15 18 
The minimum is 12

14 15 17 16 18 
The minimum is 14

15 16 17 18 
The minimum is 15

16 18 17 
The minimum is 16

17 18 
The minimum is 17

18 
The minimum is 18
Printing what should be an empty heap:


PriorityQueue heapInsert() tests -------------------

Inserted a 3 and printing:
3 


Inserted a 5 and printing:
3 5 


Inserted a 7 and printing:
3 5 7 


Inserted a 9 and printing:
3 5 7 9 


Inserted a 11 and printing:
3 5 7 9 11 


Inserted a 13 and printing:
3 5 7 9 11 13 


Inserted a 2 and printing:
2 5 3 9 11 13 7 


Inserted a 4 and printing:
2 4 3 5 11 13 7 9 


Inserted a 6 and printing:
2 4 3 5 11 13 7 9 6 


Inserted a 8 and printing:
2 4 3 5 8 13 7 9 6 11 


Inserted a 10 and printing:
2 4 3 5 8 13 7 9 6 11 10 


Inserted a 12 and printing:
2 4 3 5 8 12 7 9 6 11 10 13 


Inserted a 14 and printing:
2 4 3 5 8 12 7 9 6 11 10 13 14 


Inserted a 1 and printing:
1 4 2 5 8 12 3 9 6 11 10 13 14 7 


PriorityQueue testing error messages -------------------
Ping!

---------------------------------------------------------------------------- */
