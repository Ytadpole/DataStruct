#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;//ÔªËØ
 	struct Node *next; 
}*Node;

typedef struct Queue{
	struct Node *front;
	struct Node *rear;
} *Queue;

void add(Queue queue, int x){
	Node n ;
	n = (Node) malloc(sizeof(struct Node));
	
	n->data = x;
	n->next=NULL;
	
	queue->rear->next=n;
	queue->rear = n;	
}

void remv(Queue q){
	Node n;
	n = q->front;
	
	q->front = q->front->next;
	free(n);
}

void printData(Queue q){
	Node n = q->front->next;
	printf("Êý¾Ý:");
	while(n){
		printf(" %i", n->data);
		n = n->next;
	}
	printf("\n");
}

Queue createNewQueue(){
	Queue q;
	Node n;
	
	q = (Queue)malloc(sizeof(struct Queue));
	n = (Node)malloc(sizeof(struct Node));
	
	q->front=n;
	q->rear=n;
	q->rear->next = NULL;
	return q;
}

int isEmpty(Queue q){
	return q->front == q->rear;
}

int main(){
	Queue q ;
	int i;
	
	q = createNewQueue();
	add(q, 1);
	i = isEmpty(q);
	printf("%i",i);
	add(q, 2);
	printData(q);
		
	remv(q);
	printData(q);
	
	return;
}
