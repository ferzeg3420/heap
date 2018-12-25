/* ------------------------------------------------------------------------TODO

--  Maybe look into newHeap() having a set size that's part of the arguments and the length of the array is just the heapSize. In other words, you take the array check the size and if the input size is greater create a heap of that size and fill the entries with zeroes and then insert the values of the array. No need to use buildHeap?. 

-- Test if I need to add a test of the bounds for the index in heapify(). Do the drawing!

-- See if you can come up with more robust tests.

-- Translate the sparse matrix implementation in java that I have.

-- Move to Graph and implement the last parts of djisktras algorithm.

-- Do the weight function by implementing graph using sparse matrices.

-----------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------
// priorityQueue.c
// Implementation file for Heap ADT
//-----------------------------------------------------------------------------

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"
#include "Heap.h"
#define INF -2
#define NIL 0

// structs --------------------------------------------------------------------

// private heapObj type
typedef struct HeapObj
{
   int* array;
   int heapSize;
   int arrayLength;
} HeapObj;

// Constructors and destructors ------------------------------------------------
// newHeap()
// Returns reference to new heap object containing an array passed as input.
Heap newHeap(int arrayLength, int * array)
{
   Heap H;
   H = malloc(sizeof(HeapObj));
   H->arrayLength = arrayLength + 1; // the zeroth entry is always empty.
   H->heapSize = arrayLength;

   //printf("H->heapSize = %d, H->arrayLength = %d\n", H->heapSize, H->arrayLength); // debug

   H->array = (int *)malloc( (arrayLength + 1) * sizeof(int));
   H->array[0] = 0;
   /* printf("Index %d : %d\n", 0, H->array[0]); // debug */
   for( int i = 1; i <= arrayLength; i++ )
   {
      H->array[i] = array[i - 1];
      /* printf("Index %d : %d\n", i, H->array[i]); // debug */
   }
   buildHeap(H);

   return(H);
}

// freeHeap()
// Frees all heap memory associated with Heap *pH, and sets *pH to NULL.S
void freeHeap(Heap* pH){
   if(pH!=NULL && *pH!=NULL)
   {
      free( (*pH)->array );
      free(*pH);
      *pH = NULL;
   }
}

// Access functions -----------------------------------------------------------

// parent()
// Returns the index of the parent.
int parent(int index)
{
   return (index / 2);
}

// left()
// Returns the index of the left child.
int left(int index)
{
   return 2 * index;
}

// right()
// Returns the index of the right child.
int right(int index)
{
   return (2 * index) + 1;
}

// Manipulation procedures ----------------------------------------------------

// heapify()
// Establishes the minimumHeap property.
void heapify( Heap H, int index)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapify() on NULL Heap reference.\n");
      exit(1);
   }
   int least = 0;
   int Left = left(index);
   int Right = right(index);

   if( Left <= H->heapSize && H->array[Left] < H->array[index] )
   {
      least = Left;
   }
   else
   {
      least = index;
   }
   if( Right <= H->heapSize && H->array[Right] < H->array[least] )
   {
      least = Right;
   }
   if( index != least )
   {
      swap(H->array, index, least);
      heapify(H, least);
   }
}

// buildHeap()
// Takes an array and returns an array that represents a heap.
void buildHeap(Heap H)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapify() on NULL Heap reference.\n");
      exit(1);
   }
   /* printf("Inside buildHeap():\n");// debug */
   for( int i = (H->heapSize / 2); i >= 1; i--)
   {
     /* printf("Heapifying %d\n", i);// debug     */
     heapify(H, i);
   }
   /* printHeap(H);// debug */
   /* printf("\n\n"); // debug */
}

// heapSort()
// Sorts an input array greatest to smallest, descending order by using a heap.
// Preconditions: array length must be positive.
int * heapSort(int * array, int length)
{
   if( array == NULL )
   {
      printf("Heap Error: calling heapSort() on NULL array reference.\n");
      exit(1);
   }
   if( length < 1 )
   {
      printf("Heap Error: calling heapSort() on zero or negative"
              "argument array length.\n");
      exit(1);
   }      
   Heap H = newHeap(length, array);
   /* printf("\n\n---------- From inside heapSort()\nHeap: ");// debug */
   /* printHeap(H); // debug */
   /* printf("\nheapSize = %d\n", H->heapSize);// debug       */
   while( H->heapSize >= 2 )
   {
      swap(H->array, H->heapSize, 1);
      H->heapSize--;
      /* printf("\nheapSize = %d\n", H->heapSize);// debug       */
      heapify(H, 1);
      /* printHeap(H);// debug       */
   }
   /* printf("\n---------------End Of heapSort()\n");// debug */
   /* for( int i = 0; i <= 5; i++) */
   /* { */
   /*   printf("%d ", H->array[i]);      */
   /* } // debug */

   return H->array;
}

// Priority Queue Methods -----------------------------------------------------

// heapMinimum()
// returns the minimum value in the minHeap.
// Precondition: The size of the heap must not be zero.
int heapMinimum(Heap H)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapMinimum() on NULL Heap reference.\n");
      exit(1);
   }
   if( H->heapSize < 1 )
   {
      printf("Heap Error: calling heapMinimum() on heap with zero elements.\n");
      exit(1);
   }
   return H->array[1];
}

// heapDeleteMin()
// deletes the first element in a priorityQueue.
// Precondition: The size of the heap must not be zero.
void heapDeleteMin(Heap H)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapDeleteMin() on NULL Heap reference.\n");
      exit(1);
   }
   if( H->heapSize < 1 )
   {
      printf("Heap Error: calling heapMinimum() on heap with zero elements.\n");
      exit(1);
   }
   swap(H->array, H->heapSize, 1);
   H->heapSize--;
   heapify(H, 1);
}

// heapExtractMin()
// Returns the minimum and deletes it using heapDeleteMin()
// Precondition: The size of the heap must not be zero.
int heapExtractMin(Heap H)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapExtractMin() on NULL Heap reference.\n");
      exit(1);
   }
   if( H->heapSize < 1 )
   {
      printf("Heap Error: calling heapExtractMin() on heap with "
             "zero elements.\n");
      exit(1);
   }
   int min = H->array[1];
   heapDeleteMin(H);
   return min;
}


// heapDecreaseKey()
// Modifies the key of an index only if this decreases its old value.
// Precondition: The index must be less than heap size and greater than zero.
void heapDecreaseKey(Heap H, int index, int key)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapDecreaseKey() on NULL Heap"
	     "reference.\n");
      exit(1);
   }
   if( H->heapSize < 1 || index > H->heapSize )
   {
      printf("Heap Error: calling heapDecreaseKey() with out of bounds index.");
      exit(1);
   }
   if( H->array[index] > key )
   {
      H->array[index] = key;
      while( parent(index) > 0 &&  H->array[parent(index)] > H->array[index] )
      {
         swap(H->array, index, parent(index));
         index = parent(index);
      }
   }
}

// heapInsert()
// Inserts a record to the priorityQueue
// Precondition: The size of the heap must be strictly less than that of the
// inner array
void heapInsert(Heap H, int k)
{
   if( H == NULL )
   {
      printf("Heap Error: calling heapInsert() on NULL Heap reference.\n");
      exit(1);
   }
   if( H->heapSize >= H->arrayLength )
   {
      printf("Heap Error: calling heapInsert() when maximum capacity of"
             " inner array would be surpassed.\n");
      exit(1);
   }
   H->heapSize++;
   H->array[H->heapSize] = INT_MAX;
   heapDecreaseKey(H, H->heapSize, k);
}

// Helper functions -----------------------------------------------------------

// swap()
// swaps two indices in an input array.
void swap(int * array, int index1, int index2)
{
  /* printf("\n\nSwap()\nindex: %d\nvalue: %d\n\nindex: %d\nvalue: %d\n\n" */
  /*        , index1, array[index1], index2, array[index2]); // debug */
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

// printHeap()
// prints heap.
void printHeap(Heap H)
{
   if( H == NULL )
   {
      printf("Heap Error: calling printHeap() on NULL Heap reference.\n");
      exit(1);
   }
   for( int i = 1; i <= H->heapSize; i++ )
   {
      printf("%d ", H->array[i]);
   }
   printf("\n");
}
