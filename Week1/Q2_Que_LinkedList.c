#include <stdio.h>
#include<stdlib.h>
#define MAX 9


struct node{
    int data;
    struct node *link;
}*front =NULL, *rear =NULL;


void enque(int ele){
    
   struct node *tmp = (struct node *)malloc(sizeof(struct node));
   if(tmp == NULL){
       printf("\n Memory not exists");
       return;
   }
   tmp->data =ele;
   tmp->link = NULL;
   
   if(front == NULL){  //When inserting for first time
   front = tmp;
   }
   
   else{
       rear->link =tmp;
       }
    rear = tmp; //changing the rear position after insertion.
   
    
}


int deque(){
   int ele;
   struct node * tmp;
   if(front == NULL){
       printf("\n Que Underflow");
       exit(1);
   }
   
   tmp =front;
   ele = tmp->data;
   front = front->link;
   free(tmp);           
   
   return ele;
   
}


void display(){
    struct node *p;
	p=front;
	if(front == NULL)
	{
		printf("\n Queue is empty");
		return;
	}
	
	
	while(p->link!=NULL) //traverse over each node
	{
		printf("%d  -->",p->data);
		p=p->link;
	}
	printf("%d --> NULL \n",p->data);
	
}


int main()  //Implementation of que using linked list
{
   
   int ele, choice;
   printf("\n  Queue using LinkedList \n");
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

