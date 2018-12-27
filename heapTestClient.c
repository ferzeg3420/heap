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
   printf("Heap after decreasing key.\n");
   printHeap(A);

   heapDecreaseKey(A, 5, 1);
   printf("Heap after decreasing key.\n");
   printHeap(A);

   heapDecreaseKey(A, 4, 4);
   printf("Heap after decreasing key.\n");
   printHeap(A);

   heapDecreaseKey(A, 2, 2);
   printf("Heap after decreasing key.\n");
   printHeap(A);

   printf("\n");
   printf("The minimum again is: %d\n\n", heapMinimum(A));

   printf("\nPriorityQueue heapExtractMin() tests -------------------\n");

   printf("Printing what should be the original heap:\n");
   printHeap(A);

   int minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);

   for( int i = 2; i <= 14; i++)
   {
      minimum = heapExtractMin(A);
      printf("\nThe minimum is %d\n", minimum);
      printHeap(A);
   }
   printf("Printing what should be an empty heap:\n");
   printHeap(A);

   printf("\nPriorityQueue heapInsert() tests -------------------\n");

   for( int i = 3; i < 14; i += 2)
   {
      heapInsert(A, i);
      printf("\nInserted one element and printing:\n");
      printHeap(A);
      printf("\n");
   }
   for( int i = 2; i <= 14; i += 2)
   {
      heapInsert(A, i);
      printf("\nInserted one element and printing:\n");
      printHeap(A);
      printf("\n");
   }
   heapInsert(A, 1);
   printf("\nInserted one element and printing:\n");
   printHeap(A);
   printf("\n");

   printf("\nPriorityQueue testing error messages -------------------\n");

   /* freeHeap(&B); */

    heapify( A, 0);
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
