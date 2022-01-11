#include <stdio.h>
#include <stdlib.h>
#include<math.h>


// Structure for stack,represents pole
struct Stack
{
int size; //capacity
int top;
int *arr;
};

// function for creating a stack of given size.
struct Stack* Create_stack(int size)
{
	struct Stack* stack =
		(struct Stack*) malloc(sizeof(struct Stack));
	stack -> size = size;
	stack -> top = -1;
	stack -> arr = (int*) malloc(stack -> size * sizeof(int));
	return stack;
}


int Check_Full(struct Stack* stack)
{
return (stack->top == stack->size - 1);
}


int Check_Empty(struct Stack* stack)
{
return (stack->top == -1);
}



void push(struct Stack *stack, int item) //pushes the disk
{
	if (Check_Full(stack))
		return;
	stack -> arr[++stack -> top] = item;
}



int pop(struct Stack* stack) //pops the disk
{
	if (Check_Empty(stack))
		return -1;
	return stack -> arr[stack -> top--];
}


//prints all the disk moves
void print_DiskMove(char fromPole, char toPole, int disk)
{
	printf("\n Move the disk %d from %c to %c \n",
		disk, fromPole, toPole);
}



// Implementation of moves between two poles
void diskMovement(struct Stack *src,
			struct Stack *dest, char s, char d)
{
	int Top1_Disk = pop(src);
	int Top2_Disk = pop(dest);

	// When pole 1 is empty
	if (Top1_Disk == -1)
	{
		push(src, Top2_Disk);
		print_DiskMove(d, s, Top2_Disk);
	}

	// When pole2 pole is empty
	else if (Top2_Disk == -1)
	{
		push(dest, Top1_Disk);
		print_DiskMove(s, d, Top1_Disk);
	}

	// When top disk of pole1 > top disk of pole2
	else if (Top1_Disk > Top2_Disk)
	{
		push(src, Top1_Disk);
		push(src, Top2_Disk);
		print_DiskMove(d, s, Top2_Disk);
	}

	// When top disk of pole1 < top disk of pole2
	else
	{
		push(dest, Top2_Disk);
		push(dest, Top1_Disk);
		print_DiskMove(s, d, Top1_Disk);
	}
}



//Function to implement TOH Iterative
void TowerOfHanoii(int disk_count, struct Stack
			*src, struct Stack *aux,
			struct Stack *dest)
{
	int i, total_moves;
	char s = 'S', d = 'D', a = 'A';

	//If number of disks is even, then exchange between destination pole and auxiliary pole
	if (disk_count % 2 == 0)
	{
		char tmp = d;
		d = a;
		a = tmp;
	}
	total_moves = pow(2, disk_count) - 1;

	//Larger disks will be pushed first
	for (i = disk_count; i >= 1; i--)
		push(src, i);

	for (i = 1; i <= total_moves; i++)
	{
	    if (i % 3 == 0)
		diskMovement(aux, dest, a, d);
		
		else if (i % 3 == 1)
		diskMovement(src, dest, s, d);

		else if (i % 3 == 2)
		diskMovement(src, aux, s, a);

		
	}
}


int main()
{
    int disc_count;
	// Input: number of disks
	printf("\n Enter number of disks \n");
    scanf("%d",&disc_count);
    printf("There are %d disk's \n",disc_count);

	struct Stack *src, *dest, *aux;

	// Creating three stacks of size 'disc_count'
	
	src = Create_stack(disc_count);
	aux = Create_stack(disc_count);
	dest = Create_stack(disc_count);
	printf("\n S is Source Pole \n D is Destination Pole\n A is Auxilary Pole \n");

	TowerOfHanoii(disc_count, src, aux, dest);
	return 0;
}

