
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;
int stack1[MAX];
int top1 = -1;


int
isOperator (char symbol)
{
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'
      || symbol == '^')
    {
      return 1;
    }
  return 0;
}

int
precedenceValue (char symbol)
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

void
push (char value)
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


void
push1 (int value)
{
  if (top1 >= MAX - 1)
    {
      printf ("\nStack Overflow");
    }
  else
    {
      top1++;
      stack1[top1] = value;
    }
}


char
pop ()
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



int
pop1 ()
{
  int value;

  if (top1 < 0)
    {
      printf ("\nStack Underflow");
      getchar ();
      exit (1);
    }
  else
    {
      value = stack1[top1];
      top1 = top1 - 1;
      return (value);
    }
}






void
infixToPostfix (char infix[], char postfix[])
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
	  holder = pop ();	//holder ayite stack lo undhi
	  while (isOperator (holder) == 1
		 && precedenceValue (holder) >= precedenceValue (value))
	    {
	      postfix[postfixIndex] = holder;
	      postfixIndex++;
	      holder = pop ();
	    }
	  push (holder);
	  push (value);
	  postfix[postfixIndex] = 's';
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
      else if (isdigit (value))
	{
	  postfix[postfixIndex] = value;
	  postfixIndex++;
	}
      else
	{
	  printf ("\nInvalid infix Expression");	/* the it is illegeal  symbol */
	  getchar ();
	  exit (1);
	}
      index++;
      value = infix[index];
    }
  postfix[postfixIndex] = '\0';

}


int
postfix_eval (char postfix[])
{
  int a,b, temp, result, i, j = 0;
  int number = 0;
  /*for(j=0,i=0;j<length;j++){
     if((postfix[j]>='0' && postfix[j]<='9') && postfix[j]!='s'){
     res_postfix[j] = postfix[i];
     j++;
     }
     else{
     j++;
     }
     }
   */
  for (i = 0; i < strlen (postfix); i++)
    {
      if (postfix[i] <= '9' && postfix[i] >= '0')
    	{
    	  j = i;
    	  while (postfix[j] <= '9' && postfix[j] >= '0')
    	  //while(isdigit(postfix[j]))
    	    {
    	      number = number * 10 + (postfix[j] - '0');
    	      j++;
    	    }
    	    
    	  push1(number);
    	  i = j-1;
    	  number = 0;
    	}
    else if(postfix[i]=='s'){
	    continue;
	}

      else
    	{
    	  a = pop1 ();
    	  b = pop1 ();
    	  //printf(" \n a is %d  b is  %d\n", a,b);
    	  switch (postfix[i])
    	    {
    	    case '+':
    	      temp = b + a;
    	      break;
    	    case '-':
    	      temp = b - a;
    	      break;
    	    case '*':
    	      temp = b * a;
    	      break;
    	    case '/':
    	      temp = b / a;
    	      break;
    	    case '%':
    	      temp = b % a;
    	      break;
    	    /*case '^':
    	      temp = pow (b, a);
    	      break;*/
    	    }
    	  push1(temp);
    	  //printf(" \n %d    %d\n", temp,i);
    	}
    }

  result = pop1();
  return result;
}



int
main ()
{
  //code
  char infix[MAX];
  char postfix[MAX];
  char res_postfix[MAX];
  int length;
  length = sizeof (postfix) / sizeof (int);
  printf("\n Enter the expression \n");
  gets(infix);
  infixToPostfix (infix, postfix);
  infix[strlen(infix)-1] = '\0';
  printf("Infix expression is ");
  puts(infix);
  printf ("Postfix Expression: ");
  puts (postfix);
  int answer = postfix_eval (postfix);
  printf("postfix evaluated resullt is %d", answer);
  return 0;
}
