#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

struct Node{
    int val;
    struct Node *next;
};
struct Node * head =NULL;

int decimalVal(struct Node *head)
{
    
    int  dec = 0;
    
    while (head != NULL)
    {
        // Left shift is equivalent to multiply
        dec = (dec  << 1) + head->val;
        head = head->next;
    }
    return dec;
}


void insert(int ele){
    
    struct Node *temp, *curr;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = ele;  
    temp->next =NULL;
    if(head==NULL){
        head = temp;
    }
    else{
    curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp; 
    }
}

void display()
{
    
    struct Node *temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
    }
    
}

int main()
{
    char bin[MAX];
    //int bin1[MAX];
    int i=0,j=0,res,digit;
    printf("\n Enter the binary number: ");
    gets(bin);
    while(i<strlen(bin))
    {
        digit =bin[i]-'0' ;
        insert(digit);
        i++;
    }
    display();
    res = decimalVal(head);
    printf("\n Decimal Value is %d ",res);
    
   
    return 0;
}
