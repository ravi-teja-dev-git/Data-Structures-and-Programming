// Heap Sort in C using MaxHeap
  
  #include<stdio.h>
  #include<stdlib.h>
  
  
  // Swaps the elements
  void swapElements(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) 
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // if root is not largest,swap with largest and continue heapify
    if (largest != i) {
      swapElements(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  
  //Heap sort
  void heapSort(int arr[], int n) 
  {
  // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)//starts from non leaf node
      heapify(arr, n, i);
  
    // Swap the last element and do heapify
    for (int i = n - 1; i >= 0; i--)
        {
          swapElements(&arr[0], &arr[i]);
      
          // Heapify root element to get highest element at root again
          heapify(arr, i, 0);
         }   
    
    }
  
  
  
  
  int main() 
  {
      
    int n;
      
    printf("\nEnter number of elements");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter elements into the array ");
    for(int i=0;i<n;i++)
    {
        scanf("\n%d",&arr[i]);
    }
    
    printf("\nImplemented sort using Max Heapify");
    heapSort(arr, n);
  
    printf("\nArray after sorting is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
  }