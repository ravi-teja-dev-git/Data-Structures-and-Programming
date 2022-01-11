#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
} *top = NULL;



void push(int ele){
    struct node *tmp = (struct node *)malloc(sizeof(struct node ));
    tmp -> data = ele;
    tmp -> link = top;
    top = tmp;
}

int pop(){
    struct node *tmp;
    int ele;
    if(top == NULL){
      printf("\n stack is empty. ");
      exit(1);
     }
     tmp = top;
     ele = tmp -> data;
     top = top -> link;
     free(tmp);
     
     return ele;
  }

void display(){
    printf("\n Elements in list are: \n");
    
    if(top == NULL){
      printf("\n stack is empty \n ");
      exit(1);
    }
    
        struct node *p = top;
        while(p->link){
            printf(" %d --> ",p->data);
	     	p=p->link;
        }
        
        printf(" %d \n ", p->data);
    
    
}



int main()  //Implementation of stack using LinkedLists
{
   
   int ele, choice;
   printf("\n Implementation using Linked List \n");
   while(1)
   {
       printf(" \n 1. Push\n 2. Pop \n 3. display \n 4. exit \n");
       printf("\n enter your choice \n ");
       scanf("%d",&choice);
       if(choice == 1)
       { 
          printf("\n Enter element \n");
          scanf("\n %d", &ele);
          push(ele); //push the element 
       }
       else if(choice == 2)
       {
           ele = pop(); //pop the element
           printf("\n The popped element is %d \n",ele);
       }
        else if (choice == 3)  
        {
             display(); //display the stack
             
        }
        else if(choice == 4)
        {
            exit(1);
        }
        else
        {
            printf("\n Check your choice again \n");
            continue;
        }          
            
    }
           
       
   
 return 0;
}
