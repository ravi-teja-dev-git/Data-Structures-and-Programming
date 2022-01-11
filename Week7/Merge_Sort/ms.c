/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#define MAX 100
#include<stdlib.h>
#include<time.h>
#include<math.h>
 
int *swapFun(int *randArray, int n, int swapCount)
{
    for(int i=0;i<swapCount && i < n-1 ;i++)
    {
        int temp = randArray[i];
        randArray[i] = randArray[i+1];
        randArray[i+1] = temp;
    }
    return randArray;
}
 
int *bubble_sort(int *randArray, int n)
{
    int a;
    for (int i = 0; i < n; ++i) 
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (randArray[i] > randArray[j]) 
                    {
                        a =  randArray[i];
                        randArray[i] = randArray[j];
                        randArray[j] = a;
     
                    }
                }
            }
    return randArray;
}
 
 
int *randomArray(int n, int *randArray,int kVal)
{
    int j;
    for(j=0;j<n;j++)
       randArray[j]=rand()%kVal;
    
    printf("\n Elements of the array::");
    for(int i=0;i<n;i++)
    {
     printf("\n Element number %d :%d",i+1,randArray[i]);
    } 
       
    return randArray;
}





//Merges arr[left1:right1] and arr[left2:right2] to temp[left1:right2]
void merge( int arr[], int temp[], int left1, int right1, int left2, int right2 )
{
	int i = left1;
	int j = left2 ;
	int k = left1 ;

	while( (i <= right1) && (j <=right2))
		temp[k++] = (arr[i]<=arr[j])? arr[i++]: arr[j++];
	while( i <= right1 )//If any elements were left on left side of array
		temp[k++]=arr[i++];
	while( j <= right2 )//If any elements were left on right side of array
		temp[k++]=arr[j++];
}


//After completing every division of problem, we keep writing over and over again,atlast we will have sorted order.
void copy(int *arr, int *temp, int left, int right )
{
	for(int i=left; i<=right; i++)
		arr[i]=temp[i];
}


void merge_sort(int *arr, int left, int right)
{
	int mid;
	int temp[MAX];
	if(left<right)//if more than one element
	{
		mid = (left+right)/2; //Finding the mid,it would be useful for dividing
		merge_sort( arr, left , mid );  //Sort array from low to mid
		merge_sort( arr, mid+1, right );  //Sort array from mid+1 to right
		//Merge arr[low:mid] and arr[mid+1:right] to temp[left:right]
		merge( arr, temp, left, mid, mid+1, right ); 
		//Copy temp[left:right] to arr[left:right] 
		copy(arr,temp,left, right);	
	}
}






int main()
{
	int arr[MAX],n,i,inp,k;
   while(1)
   {
   printf("\n Choose Input");
   printf("\n 1. Random Integers in the range of 10^k, k between 4 and 7 \n 2. Sorted array \n 3. Almost sorted array \n 4. Exit \n");
   scanf("%d", &inp);
   printf("\n Enter the value of k in 10^k");
   scanf("%d",&k);
   printf("Enter the size of array: ");
   scanf("%d",&n);
   int *randArrayPointer;
   int randArray[n];
   int val = pow(10,k);
   if(inp ==1) 
   {
       randArrayPointer = randomArray(n, randArray,val);
      /* for(i=0;i<n;i++)
        {
         printf("\n Main_Element number %d :%d",i+1,randArrayPointer[i]);
        } */
       
     
   }//End of inp1
   
   
   else if (inp == 2)
   {
      randArrayPointer = randomArray(n, randArray,val);
       
      randArrayPointer =  bubble_sort(randArrayPointer, n);
      /*for(i=0;i<n;i++)
        {
         printf("\n Main_inp2_Element number %d :%d",i+1,randArrayPointer[i]);
        }
           */
           
   }
   
   else if (inp ==3)
   {
      randArrayPointer = randomArray(n, randArray, val);
       
      randArrayPointer =  bubble_sort(randArrayPointer, n);
      int pairCount = (n*(n-1))/2;
      int swapCount =(int)( 0.01 * (float)pairCount);
      printf("\n Swap Count %d",swapCount);
      randArrayPointer = swapFun(randArrayPointer, n,swapCount);
      /*for(i=0;i<n;i++)
        {
         printf("\n Main_inp3_Element number %d :%d",i+1,randArrayPointer[i]);
        }*/
   }
   
   else if(inp == 4)
   {
       break;
   }
   
   int l=0,r=n-1;

   
   clock_t t;
   t = clock();
   
   merge_sort( randArrayPointer, l, r);
   
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
   printf("\n merge_sort() took %f seconds to execute \n", time_taken);
     
   printf(" Sorted list is :\n");
     
    for( i=0; i<n; i++ )
    	printf("%d ",randArrayPointer[i]);
    printf("\n"); 
    
    printf("\n merge_sort() took %f seconds to execute \n", time_taken);
   
   }//End of while
}

