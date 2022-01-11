#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define N 10

int h_table[N] = {0};

//Display the hash table
void display()
{
   for(int i =0; i<N; i++)
   {
       printf("\n At index %d key present is %d ",i,h_table[i]);
   }
}


//Inserting into the hash table.
void insert()
{

 int key,pos,i,flag=0,hkey,h1key;
 printf("\n Enter a value to insert into hash table \n");
 scanf("%d",&key);
 hkey = key%N;
 h1key = 7-key%7;
 for(i=0;i<N;i++)
    {

         pos=(hkey + i* h1key )%N; //Hash formula for double hashing
    
         if(h_table[pos] == 0 || h_table[pos] == INT_MAX)//If the pos is empty, we insert
         {
            h_table[pos]=key;
             break;
         }

    }

    if(i == N)
     printf("\nInsertion not possible \n");
}


//Deleting the key in hash table
void delete()
{
    int value,flag = 0;
    printf("\nEnter key to delete : ");
    scanf("%d",&value);
    
    
    int hkey = value % N,pos;
    int h1key = 7-(value %7);
   // printf("Key value is %d",hkey);
    if(h_table[hkey] == value)
        h_table[hkey] = INT_MAX;
        
    //search in other positions
    else if(h_table[hkey]!=value)
    {
        for(int i=0; i<N; i++)
        {
           pos = (hkey + i*h1key) % N;
           if(h_table[pos]==value)
           {
            h_table[pos] = INT_MAX;
            flag = 1;
            
            break;
            }
         }
    
    }
    
    if(flag == 0){
        printf("%d not present in the hash table\n",value);
    }
     
}


void search()
{

 int key, pos,i,hkey;
 printf("\nEnter element to search \n");
 scanf("%d",&key);
 hkey = key%N;
 int h1key = 7-(key %7);
 for(i=0;i<N; i++)
 {
    pos = (hkey+i*h1key)%N;
    if(h_table[pos]==key)
    {
      printf("\n Key is found at position %d",pos);
      break;
    }
  }
  if(i == N)
    printf("\n Key is not found ");
}



void loadFactor()
{
   float ele_count = 0, lf;
   int i=0;
   while(i<N)
   {
     if(h_table[i]!= 0 && h_table[i]!= INT_MAX)
     ele_count+=1;
     i++;
   }
   lf = ele_count / N;
   printf("\n Load Factor is %f",lf);
}



int main()
{
    int choice,i;
    while(1)
    {
        printf("\nEnter your choice \n1. Insert\n2. Delete \n3. Search \n4. Display \n5. Load Factor \n6. Exit \n ");
        scanf("%d",&choice);
        if(choice == 1)
        {
           insert();
           
        }
        else if(choice == 2)
        {
            delete();
            
        }
        else if(choice == 3)
        {
            search();
            
        }
        else if(choice == 4)
        {
             display();
             
        }
        else if(choice == 5)
        {
             loadFactor();
             
        }
        else if(choice == 6)
        {
            exit(1);
            
        }
        
    }
}

