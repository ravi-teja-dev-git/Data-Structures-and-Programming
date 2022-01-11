#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;
int stack1[MAX];
int top1 = -1;


//Checking for operator
int isOperator (char symbol)
{
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'
      || symbol == '^')
    {
      return 1;
    }
  return 0;
}


//Finding the priority of operators
int precedenceValue (char symbol)
{
  if (symbol == '+' || symbol == '-')
    {
      return 1;
    }
  else if (symbol == '*' || symbol == '/')
    {
      return 2;
    }
  else if (symbol == '^')
    {
      return 3;
    }
  else
    {
      return 0;
    }
}


//push the operators to stack
void push (char value)
{
  if (top >= MAX - 1)
    {
      printf ("\nStack Overflow");
    }
  else
    {
      top++;
      stack[top] = value;
    }
}


//poping from the stack
char pop ()
{
  char value;

  if (top < 0)
    {
      printf ("\nStack Underflow");
      getchar ();
      exit (1);
    }
  else
    {
      value = stack[top];
      top = top - 1;
      return (value);
    }
}


//convert infix to postfix
void infixToPostfix (char infix[], char postfix[])
{
  push ('(');			/* push '(' onto stack */
  strcat (infix, ")");
  //char convert[MAX];
  int index = 0;
  int postfixIndex = 0;
  //int cIndex= 0;
  char value = infix[index];
  char holder;
  while (value != '\0')
    {
      if (value == '(')
	{
	  push (value);
	}
      else if (isOperator (value) == 1)
	{
	  holder = pop ();	//element on top of stack, this is used to compare with parsing element
	  while (isOperator(holder) == 1 && precedenceValue(holder) >= precedenceValue(value))
	    {
	      postfix[postfixIndex] = holder;
	      postfixIndex++;
	      holder = pop ();
	    }
	  push(holder);
	  push(value);
	  postfix[postfixIndex] = ' ';
	  postfixIndex++;
	}
      else if (value == ')')
	{
	  holder = pop ();
	  while (holder != '(')
	    {
	      postfix[postfixIndex] = holder;
	      postfixIndex++;
	      holder = pop ();
	    }
	}
      else if (!isdigit (value))
	{
	  postfix[postfixIndex] = value;
	  postfixIndex++;
	}
      else
	{
	  printf ("\n Invalid infix Expression");	/* When it is illegal  symbol */
	  getchar ();
	  exit (1);
	}
      index++;
      value = infix[index];
    }
  postfix[postfixIndex] = '\0';

}



//Validating the infix expression
int validate(char expr[])
{
    int n = strlen(expr);
    if(isOperator(expr[0]) || isOperator(expr[n-1]) )
    {
        return 0;
    }
    for(int i=0; i<n-1; i++)
    {
        if(isOperator(expr[i]) && isOperator(expr[i+1]) )
        {
            return 0;
        }
    }
    
    return 1;
}




int main ()
{
  //code
  char infix[MAX];
  char postfix[MAX];
  int length, i = 0, j = 0;
  char temp;
  
  length = sizeof (postfix) / sizeof (int);
  printf("\nEnter the expression \n");
  gets(infix);
  
  if(validate(infix))
  {
     printf("\nInfix expression is Valid");
     infixToPostfix (infix, postfix);
      infix[strlen(infix)-1] = '\0';
      printf("\nInfix expression is ");
      puts(infix);
      printf ("\nPostfix Expression: ");
      puts (postfix);
      
      //Reversing the infix expression
      j = strlen(infix) - 1;
      
      while(i<j)
      {
          temp = infix[i];
         infix[i] = infix[j] ;
         infix[j] = temp;
         i++;
         j--;
      }
      
     
      //Converting the reverse of infix to postfix
      
      infixToPostfix(infix,postfix);
      
      
       //Reversing the converted postfix expression
      
      int k = 0,l = 0;
      
      l = strlen(postfix) - 1;
      
      while(k<l)
      {
          temp = postfix[k];
          postfix[k] = postfix[l] ;
          postfix[l] = temp;
         k++;
         l--;
      }
      
      printf("Prefix expression is: ");
      puts(postfix);
      
    }
      
      
    else
      {
         printf("\nInfix expression is Invalid");
      }
      
  return 0;
}

