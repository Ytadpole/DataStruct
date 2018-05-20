#include <stdio.h>
#define MAX_SIZE 10

typedef struct Stack{
	int data[MAX_SIZE];//Ԫ��
	int top; 
} PStack, *Stack;

Stack createNewStack(){
	Stack s ;
	s = (Stack)malloc(sizeof(PStack));
	s->top = -1;
	return s;	
}

//��ջ 
int pop(Stack s){
	if(s->top < 0){
		printf("ջ�������ݣ��޷���ջ"); 
		return;
	}	
	return s->data[s->top--]; 
}

//��ջ 
void push(Stack s, int x){ 
	if(s->top + 1 >= MAX_SIZE){
		printf("ջ�ռ��������޷�����");
		return; 
	} 
	
	s->data[++(s->top)] = x;	
} 

//����ֵ 1-Ϊ�� 0-��Ϊ�� 
int isEmpty(Stack s){
	if( s->top < 0) return 1;
	else return 0;	
}

void printData(Stack s){
	int i = 0; 
	printf("��ǰջ��Ԫ�أ� ");
	for(; i<= s->top; i++){
		printf(" %i", s->data[i]);
	}
}

int main(){
	Stack s = createNewStack();
	push(s, 1);
	push(s, 2);
	push(s, 3);
	
	printData(s);
	push(s, 3);
	push(s, 1);
	printData(s);
	
	pop(s);
	pop(s);
	pop(s);
	printData(s);
	//pop(s);
	//pop(s);
	//pop(s);
	//pop(s);
	//pop(s);
	//pop(s);
} 
