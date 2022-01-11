#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define queue_count 4
#define max_queue_length 10
int array[queue_count * max_queue_length];
int front[queue_count],rear[queue_count];

void question_elements(){
    
    rear[0] = 5;
    rear[1] = 13;
    rear[2] = 22;
    rear[3] = 36;
    for(int i=0;i<5;i++){
        array[i] = i+1; //insering elements in array - 1st que
    }
    for(int i=10;i<13;i++){
        array[i] = i+1; //insering elements in array - 2nd que
    }
    for(int i=20;i<22;i++){
        array[i] = i+1; //insering elements in array - 3rd que
    }
    for(int i=30;i<36;i++){
        array[i] = i+1; //insering elements in array - 4th que
    }
    
}

void display(){
    for(int qno=0; qno<queue_count; qno++){
        printf("Queue %d elements: ",qno);
        int start = front[qno], end = rear[qno];
        while(start != end){
            printf("%d \t",array[start]);
            start++;
        }
        printf("\n");
    }
}

//Finding max number of elements que and returning that que number
int max_elements_q(){ 
    int max = -1;
    int qno = 0;
    for(int i = 0;i<queue_count;i++){
        if(rear[i] - front[i] > max){
            max = rear[i] - front[i];
            qno = i;
        }
    }
    return qno;
}

int min_elements_q(){
    int min = max_queue_length+1;
    int qno = 0;
    for(int i = 0;i<queue_count;i++){
        if(rear[i] - front[i] < min){
            min = rear[i] - front[i];
            qno = i;
        }
    }
    return qno;
}


//inserting elements to que
int insert(int value){
    int qno = min_elements_q();
    if(rear[qno] >= (qno+1) * max_queue_length){
        printf("Queue %d overflow", qno);
        display();
        return -1;
    }
    array[rear[qno]] = value;
    rear[qno]++;
    printf("\n Queues after insertion \n");
    display();
    return 1;
    
}

int delete(){
    int qno = (int)max_elements_q();
    if(front[qno] == rear[qno]){
        printf("Queue %d underflow", qno);
        display();
        return -1;
    }
    array[front[qno]] = -1;
    front[qno]++;
    printf("\n Queues after deletion \n");
    display();
    return 1;
}
	
int main() {
	int i;
	for(i = 0; i<queue_count; i++)
	    front[i] = rear[i] = i*max_queue_length;
	question_elements();
	display();
	delete();
	delete();
	delete();
	insert(100);
	insert(102);
	delete();
	
	return 0;
}