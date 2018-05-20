#include <stdio.h>
#define MAX_SIZE 10

typedef struct Stack{
	int data[MAX_SIZE];//元素
	int top; 
} PStack, *Stack;

Stack createNewStack(){
	Stack s ;
	s = (Stack)malloc(sizeof(PStack));
	s->top = -1;
	return s;	
}

//出栈 
int pop(Stack s){
	if(s->top < 0){
		printf("栈中无数据，无法出栈"); 
		return;
	}	
	return s->data[s->top--]; 
}

//入栈 
void push(Stack s, int x){ 
	if(s->top + 1 >= MAX_SIZE){
		printf("栈空间已满，无法加入");
		return; 
	} 
	
	s->data[++(s->top)] = x;	
} 

//返回值 1-为空 0-不为空 
int isEmpty(Stack s){
	if( s->top < 0) return 1;
	else return 0;	
}

void printData(Stack s){
	int i = 0; 
	printf("当前栈中元素： ");
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
