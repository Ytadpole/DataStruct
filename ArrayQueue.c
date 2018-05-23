#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 10

typedef struct Queue{
	int data[MAX_SIZE];//元素
	int front;//队头 
	int rear; //队尾 
}QQueue, *Queue; 

Queue createNewQueue(){
	Queue q ;
	q = (Queue)malloc(sizeof(QQueue));
	q->front=0;
	q->rear=0;
}

int isEmpty(Queue q){
	return q->front == q->rear;
}

int isFull(Queue q){
	return (q->rear + 1) % MAX_SIZE == q->front;
}

void add(Queue q, int x){
	if((q->rear + 1) % MAX_SIZE == q->front){
		printf("队列空间已满");
		return;
	}
	
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAX_SIZE;			
}

//命名remove有冲突 
int removeD(Queue q){
	int tmp;
	
	if(q->rear == q->front){
		printf("队列为空，无法出队");
		return; 
	}
	
	tmp = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	
	return tmp;	
}

void printData(Queue q){
	int i;
	
	printf("结果:");
	for(i = q->front; i % MAX_SIZE < q->rear; i = (i+1) % MAX_SIZE ){
		printf(" %i", q->data[i]);
	}	
	printf("\n");
}

int main(){
	Queue q = createNewQueue();	
	add(q, 1);
	add(q, 2);
	add(q, 3);
	printData(q);
	
	removeD(q);
	printData(q);
	return;
}
