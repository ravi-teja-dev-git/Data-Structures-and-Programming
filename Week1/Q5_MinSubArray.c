#include <stdio.h>
#include<stdlib.h>

int m;
// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int Min_len_SubArray(int arr[], int n, int x)
{
	// Initialize length of smallest subarray as n+1
	int min_len = n + 1,j;
	

	
	for (int i=0; i<n; i++)
	{
		
		int curr_sum = arr[i]; // Initialize sum to starting element

		
		if (curr_sum > x) return 1; // If first element is greater

		
		j = i+1; //varying the end points
		 while(j<n)
		 {
			
			curr_sum += arr[j]; // add element to present sum

			
			if (curr_sum > x && (j - i + 1) < min_len){
				min_len = (j - i + 1); //update the smallest length
				//printf("start is %d \n ",i);
				//printf("end is %d \n", j);
				m = i; //to keep track of where minimum length starts
				
			}
			j++;
		}
	}
	return min_len;
}


int main()
{
	int arr1[] = {1,11,100,1,0,200,3,2,1,250}; //Input array
	int arr2[30],giv_num; //Result array, number
	printf("\n Enter a value \n ");
	scanf("%d",&giv_num);

	int arr_size = sizeof(arr1)/sizeof(arr1[0]); // finding size of array
    printf("\n Given array is \n");
	for(int i=0;i<arr_size;i++){
	    printf(" %d ",arr1[i]);
	}
	int res = Min_len_SubArray(arr1, arr_size,giv_num);
	if(res == arr_size+1)
	{ 
	    printf("\n Not possible to have \n"); 
	    
	}
	else
	{
		printf("\n\n Final length of min subarray %d\n",res);
	}
    //printf("\n start index is %d \n",m);
    
    printf("\n Resultant minimal sub array is \n");
    for(int i=m;i<m+res;i++){
        //arr2[j] =arr1[i];
        printf(" %d ",arr1[i]);
    }
    
    printf("\n Resultant array after adding length %d is \n",res);
    for(int i =m,j=0;i<m+res;i++,j++){
        arr2[j] =arr1[i]+ res;
        printf(" %d ",arr2[j]);
    }
	
	return 0;
}
