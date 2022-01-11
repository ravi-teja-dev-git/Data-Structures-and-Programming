#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

// Structure for the elements in the
// priority queue
struct student {
	int g_score;
	int priority;
	char name[30];
	
};

// Store the element of a priority queue
struct student pr_que[1000];

// Pointer to the last index
int size = -1;

// Function to insert a new record into priority queue
void Enque(int g_score, int priority, char name[])
{
	// Increase the size
	size++;

	// Insert the element
	strcpy(pr_que[size].name, name);
	pr_que[size].g_score = g_score;
	pr_que[size].priority = priority;
}

// Function to check the top element
int Check_Top()
{
	int high_Priority = -1;
	int index = -1;

	// Check for the element with 
	// highest priority
	for (int i = 0; i <= size; i++) {

		if (high_Priority == pr_que[i].g_score && index > -1 && 
		     pr_que[index].name < pr_que[i].name) 
		{
			high_Priority = pr_que[i].g_score;
			index = i;
		}
		else if (high_Priority < pr_que[i].g_score)
		{
			high_Priority = pr_que[i].g_score;
			index = i;
		}
	}

	// return the priority index
	return index;
}


/* Below function removes element with high priority*/
void Deque()
{
    
	// We find the index of element with highest priority
	int ind = Check_Top();

	// Shifting the records such that all the records next to 
	//priority index will start at priority index
	
	for (int i = ind; i < size; i++) {
		pr_que[i] = pr_que[i + 1];
	}

	// Decrease the size of priority after deletion
	size--;
}




int main()
{
	Enque(590, 5,"Ravi");
	Enque(650, 7, "Sai");
	Enque(610, 6,"Krish");
	Enque(650, 7,"Teja");
	printf("\n\n After Enqueue...");
	for(int j=0; j<=size;j++)
	{
    	printf("\n Name is %s Gate score is  %d ",pr_que[j].name,pr_que[j].g_score);
	}
	
	
	
	// Dequeue the top element
	Deque();
	
	printf("\n\n After Dequeue...");
	for(int j=0; j<=size;j++)
	{
    	printf("\n Name is %s Gate score is  %d ",pr_que[j].name,pr_que[j].g_score);
	}
	
	printf("\n\n Another record is inserted \n");
	
	Enque(410,4,"Ram");
    
  
	// Dequeue the top element
	Deque();
	
	printf("\n\n After Dequeue...");
	for(int j=0; j<=size;j++)
	{
    	printf("\n Name is %s Gate score is  %d ",pr_que[j].name,pr_que[j].g_score);
	}
	
	
	printf("\n\n Finally in Queue...");
	for(int j=0; j<=size;j++)
	{
    	printf("\n Name is %s Gate score is  %d ",pr_que[j].name,pr_que[j].g_score);
	}
	return 0;
}
