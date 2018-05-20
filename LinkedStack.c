#include <stdio.h>
#include <stdlib.h>

typedef struct Stack PStack, *Stack; 
struct Stack{
	int data;//元素
 	Stack next;
};

Stack createNewStack(){
	Stack s;
	s = (Stack) malloc(sizeof(struct Stack));
	s->next = NULL;
	return s;
}

int isEmpty(Stack s){
	return s->next == NULL;
}

void push(Stack s, int x){
	//链式不用考虑容量
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct Stack));
	tmp->data = x;
	//头插法 
	tmp->next = s->next;
	s->next= tmp;	
}

int pop(Stack s){
	Stack tmp; 
	int val;
	
	if(isEmpty(s)){
		printf("栈为空，无法出栈\n");
		return; 
	}
	
	//保存数据 
	tmp = s->next;
	val = tmp->data;
	
	//删除
	s->next = tmp->next;
 	free(tmp);
	return val;
}

//栈顶往下输出 
void printData(Stack s){
	Stack p = s;
	printf("\n 当前栈元素 ：");
	while(p->next != NULL){
		printf(" %i", p->next->data);	
		p = p->next;
	}
}

int main(){
	Stack s = createNewStack();
	push(s, 1); 
	push(s, 2); 
	push(s, 3); 
	push(s, 4); 
	printData(s);
	
	pop(s);
	pop(s); 
	printData(s);
} 
