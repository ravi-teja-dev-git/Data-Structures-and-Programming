#include <stdio.h>
#include<stdlib.h>


int getMax(int * array, int size)
{
  
  int i;
  int max = -1;
  
  for(i = 0; i < size; i++)
  {
    if(array[i] > max)
      max = array[i];
  }
  
  return max;
}

// Radix Sort
void radixSort(int * array, int size)
{
  
  int i;
  int semiSorted[size];
  int sigDigit = 1;
  int max = getMax(array, size);
  
  // Loop until we reach the largest significant digit
  while (max / sigDigit > 0)
  {
    
    int bucket[10] = { 0 };
    
    // Counting the number of keys or digits that goes to each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / sigDigit) % 10]++;
      
    
    /* Add the count of the previous buckets,
     Acquires the indexes after the end of each bucket location in the array*/
     
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a semiSorted array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / sigDigit) % 10]] = array[i];
    
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    // Get to the next significant digit
    sigDigit *= 10;
    
    
  }
}

int main()
{
  int n,a[20];
  printf("\n Enter number of elements \n");
  scanf("%d",&n);
  for(int i =0;i<n-1;i++)
  {
      scanf("%d ",&a[i]);
  }
  
  printf("\n The elements in array are: \n ");
  
  for(int i =0;i<n;i++)
  {
      printf("%d ",a[i]);
  }
  
  
  radixSort(&a[0], n);
  
  printf("\nThe elements in array after sorting are: \n");
  
  for(int i =0;i<n;i++)
  {
      printf(" %d ",a[i]);
  }
  
  return 0;
}
