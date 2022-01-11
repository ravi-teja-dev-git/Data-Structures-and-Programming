#include <stdio.h>
#include<stdlib.h>
#define MAX 9

int arr_stack[MAX];
int top = -1;

void push(int ele){
    if(top == MAX - 1){
        printf("\n stack is full !"); //Overflow
    }
    else {
        top++;
        arr_stack[top] = ele;
    }
}


int pop(){
    if(top == -1){
        printf("\n stack is empty"); //Underflow
        exit(1);
    }
    
    else{
    int item;
    item = arr_stack[top];
    top--;
    return item;
    }
}
    
void display(){
    
    if(top == -1){
      printf("\n stack is empty \n ");
    }
    
   else{
      
      printf("\n Elements in stack are: \n");
      for(int i=top; i>=0; i--){
	     printf("%d\n",arr_stack[i]);
      }
   }
}


int main()  //Implementation of stack using arrays
{
   
   int ele, choice;
   while(1)
   {
       printf("\n 1. Push\n 2. Pop \n 3. display \n 4. exit \n");
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
