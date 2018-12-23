#include<stdio.h>
#include"Heap.h"

int main(int argc, char* argv[])
{
   int i;
   int array[6] = {5, 6, 7, 8, 9, 10 };
   int length = sizeof(array) / sizeof(int);
   printf("The length of this array: %d\n", length); // should be 5.
   
   int *barray = NULL;
   Heap A = newHeap(6, array);
 
   printf("\nTesting parent, left, and right.\n");
 
   for( int i = 1; i <= 5;  i++ )
   {
      printf("The parent of index %d is %d\n", i, parent(i));
   }

   for( int i = 1; i <= 5;  i++ )
   {
      printf("The left child of index %d is %d\n", i, left(i));
   }

   for( int i = 1; i <= 5;  i++ )
   {
      printf("The right child of index %d is %d\n", i, right(i));
   }

   printf("\nTesting heapify\n");
   for( int i = 1; i <= 5;  i++ )
   {
      heapify(A, i); 
   }

   //buildHeap(A);
   printf("\nTesting heapSort()\n");
   barray = heapSort(array, 6);

   //  printing Heap
   printf("\n\nPrinting sorted barray:\n"); // debug
   for( int i = 1; i <= 6;  i++ )
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

   int minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);

   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);

   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);

   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);

   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);   

   minimum = heapExtractMin(A);
   printf("The minimum is %d\n", minimum);
   
   printf("Printing what should be an empty heap:\n");   
   printHeap(A);

   printf("\nPriorityQueue heapInsert() tests -------------------\n");

   heapInsert(A, 3);
   printf("\nInserted one element and printing:\n");
   printHeap(A);
   printf("\n");

   heapInsert(A, 5);
   printf("\nInserted one element and printing:\n");
   printHeap(A);
   printf("\n");
   
   heapInsert(A, 1);
   printf("\nInserted one element and printing:\n");
   printHeap(A);
   printf("\n");

   heapInsert(A, 4);
   printf("\nInserted one element and printing:\n");
   printHeap(A);
   printf("\n");


   freeHeap(&A);
   return(0);
}
