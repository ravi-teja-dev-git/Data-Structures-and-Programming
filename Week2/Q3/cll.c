#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node {
    char a[3][10]; //info part
    struct Node *next;
};
struct Node *head = NULL;


void lastinsert()  
{  
    struct Node *newNode,*temp;   
    newNode = (struct Node *)malloc(sizeof(struct Node));  
    
    
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
            for(int i=0;i<3;i++)
            {
               //printf("\nEnter a string %d: ",i+1);
               scanf("%s",newNode -> a[i]);
            }
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
            for(int i=0;i<3;i++)
            {
               scanf(" %s",newNode->a[i]);
            }
        }//end of else  
          
        printf("\n Node inserted \n");  
    }  
  
}  



int isMatch(){
    struct Node *ptr;
    ptr =head;
    while(ptr->next != head)
    {
        
        if(strcmp(ptr->a[2],ptr->next->a[0])!=0)
        { 
            return 0;
        }
        ptr = ptr->next;
    
    }
    return 1;
}

void display()
{
    struct Node *ptr;
    ptr =head;
    printf("\n The colors are \n");
    while(ptr->next != head)
    {
        for(int i=0;i<3;i++)
        {
        printf(" %s\t", ptr->a[i]);
        }
        ptr = ptr->next;
        printf("\n");
    }
    //printf("\n");
    
    for(int i=0;i<3;i++)
        {
        printf(" %s\t ", ptr->a[i]);
        }
        
    printf("\n");
}


void display_SecString()
{
    struct Node *ptr;
    ptr =head;
    while(ptr->next != head)
    {
        
        printf(" %s \n", ptr->a[1]);
        
        ptr = ptr->next;
        
    }
    
    printf(" %s \n", ptr->a[1]);

}



void display_Replace()
{
   struct Node *ptr;
   ptr =head;
   strcpy(ptr->a[0],"color");
    while(ptr->next != head)
    {
        
        ptr = ptr->next;
        
    }
    
    strcpy(ptr->a[0],"color");
    
    display();  
}


int main()
{
    int cnt;
    printf("Enter number of Nodes ");
    scanf("%d",&cnt);
    printf("Node are %d \n",cnt);
    printf("Enter elements to Insert \n");
    for(int j=0; j<cnt ; j++)
    {
        lastinsert();
        printf("Enter Again!\n");
    }
	
	display();
	printf("\n The second string colors in the  list are: \n");
	display_SecString();
	
	if(isMatch())
	{
	    printf("\n String Matching \n");
	}
	else
    {
        printf("\n String not Matching ");
    }
	
	display_Replace();
	
	if(isMatch())
	{
	    printf("\n String Matching ");
	}
	else
    {
        printf("\n String not Matching ");
    }
	
	return 0;
}