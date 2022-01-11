#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;


void display()
{
    struct Node *ptr;
    ptr =head;
    while(ptr->next != head)
    {
        printf("%d -->",ptr->data);
        ptr = ptr->next;
        
    }
    printf("%d ",ptr->data);
    printf("\n");
    
    
}


void lastinsert()  
{  
    struct Node *newNode,*temp; 
    int ele;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\n Enter data");
    scanf("%d",&ele);
    newNode->data = ele;
    
    if(newNode == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }
    
    else  
    {  
         
        if(head == NULL)  
        {  
            head = newNode;  
            newNode -> next = head; 
        } //end of if 
        
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = newNode;   
            newNode -> next = head;
        }//end of else  
          
        printf("\n Node inserted \n");  
    }
    
  
}  




int main()
{
    struct Node *tmp1,*tmp2, *ptr1,*ptr2,*head2;
    int cnt,break_point;
    printf("\n Enter number of nodes ");
    scanf("%d",&cnt);
    
    for(int i=0;i<cnt;i++)
    {
        lastinsert();
    }
    
    printf("\n Displaying the nodes \n");
    display();
    
    if(cnt % 2 == 0)
        {
            break_point = (cnt/2) ;
            
        }
    else 
        {
           break_point = (cnt/2)+1;
        }
        
    
    
    tmp1= head;
        
     for(int j=0;j<break_point-1;j++)
        {
            tmp1 = tmp1->next;
        }
     head2 = tmp1->next;
     tmp1->next = head;
     tmp2 = head2;
           
     //display 1st list
     printf("List1 is \n");
     ptr1 = head;
     while(ptr1->next != head)
        {
         printf("%d -->",ptr1->data);
         ptr1 = ptr1->next;
        }
       printf("%d ",ptr1->data);     
    
    //After the break_point
    
    while(tmp2->next!= head)
        {
            tmp2 = tmp2->next;
        }
            
    tmp2->next = head2;
    ptr2 = head2;
    
    printf("\n");
    
    //display 2nd list
    printf("List2 is \n");
    while(ptr2->next != head2)
        {
        printf("%d -->",ptr2->data);
        ptr2 = ptr2->next;
        }
     printf("%d",ptr2->data);       
        
    return 0;
}

