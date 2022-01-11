#include <stdio.h>
#include<stdlib.h>
#define MAX 9


int front=-1;
int rear =-1;
int q_arr[MAX];


void enque(int ele)
  {
    
    if(front == rear +1 || (front==0 && rear == MAX -1)){
        printf("\n Que Oveflow");
        return;
    }
    if(front == -1){
        front = 0;
    }
    
    if(rear == MAX-1){
        rear = 0;
        
    }
    else
        rear++;
    q_arr[rear] = ele;
    
  }


int deque()
  {
    int ele;
    if (front ==-1){
        printf("\n Que Underflow \n");
        exit(1);
    }
    
    ele = q_arr[front];
    
    if(front==rear) // que has single element
	{
		front=-1;
		rear=-1;
	}
	else if(front == MAX-1) //front reached end of array,so initialize it to start.
		front=0;
	else
		front=front+1; 
	return ele;
  }


void display(){
    int i;
    if(rear == -1){
        printf("\n Que is empty \n");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("\n %d",q_arr[i]);
        }
    }
}


int main()  //Implementation of que using array
{
   
   int ele, choice;
   while(1)
   {
       printf("\n 1. Enqueue\n 2. Dequeue \n 3. Display \n 4. Exit \n");
       printf("enter your choice ");
       scanf("%d",&choice);
       if(choice ==1 ){
           printf("\n Enter element ");
           scanf("%d", &ele);
           enque(ele); //insert the element
       } 
        
       else if(choice == 2)
       {
           ele = deque(); //delete the element
           printf("\n The deleted element is %d ",ele);
                    
       }
       
       else if(choice == 3)
       {
           display();
       }
                    
       else if(choice ==4)
       {
           exit(1);
       }
                    
        else 
        {
            printf("\n Check your choice again");
        }
            
        
   }
           
       
 return 0;
}

