#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 30

// Stack Declaration

int top=-1;
int stack[MAX];

// Stack Overflow Condition and push

void push(char item){
    //printf("%c pushed item", item);
    if(item == MAX-1)
    {
        printf("\n Stack Overflow \n");
        return;
    }
    else
    {
        top = top +1;
        stack[top] = item;
    }
}
// Stack Underflow Condition and pop

char pop(){
    if(top == -1)
    {
        printf("\n Stack Underflow \n");
        exit(1);
    }
    
    return(stack[top--]);
}

// Checking whether input given is valid or not.
int isBracket(char bracket)
{
    if(bracket == '(' || bracket == ')' || bracket == '{' || bracket == '}' || bracket == '[' || bracket == ']')
        return 1;
    else
        return 0;
}



int isMatchingPair(char bracket1, char bracket2)
{
    if(bracket1 == '(' && bracket2 == ')')
        return 1;
    else if(bracket1 == '{' && bracket2 == '}')
        return 1;
    else if(bracket1 == '[' && bracket2 == ']')
        return 1;
    else
        return 0;
}





// Checking whether it is a balanced one or not
int isExpression(char expression[])
{
    int i;
    char bracket2,bracket1;
    for(int i = 0; i<strlen(expression); i++)
    {
       
             if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
    			push(expression[i]);
    			
    	     if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
    	     {
    			if(top==-1)    /*stack empty*/
    			{
    				printf("Not balanced\n"); //Right parentheses are more than left parentheses
    				return 0;
    			}
    			else 
    			{
    			    bracket2 = pop();
    			    bracket1 = expression[i];
    			    if(!isMatchingPair(bracket2,bracket1))
    			    {
    			        printf(" \n Mismatched parentheses are : "); 
    					printf("%c and %c\n",bracket2,bracket1);	
    					return 0;
    			    }//end of if
    			}//end of else
    	     
       
                if(top == -1 && i == strlen(expression)-1) /*stack empty*/
            	{
        		printf("\n Balanced Parentheses \n"); 
        		return 1;
        	    }
        	    
             }
    }
    return 0;
}




int main() 
{
	//code
	char expression[MAX];
	int valid,i;
	//char bracket2,bracket1;
	printf("Enter an algebraic expression : ");
	gets(expression);
	printf("\n Entered expression is: ");
	puts(expression);
	
	valid = isExpression(expression);
	
	if(valid == 1)
		printf(" True \n");
	else
		printf(" False \n");
 
	return 0;
}
