#include <stdio.h>
#include <stdlib.h>

typedef struct Stack PStack, *Stack; 
struct Stack{
	int data;//Ԫ��
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
	//��ʽ���ÿ�������
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct Stack));
	tmp->data = x;
	//ͷ�巨 
	tmp->next = s->next;
	s->next= tmp;	
}

int pop(Stack s){
	Stack tmp; 
	int val;
	
	if(isEmpty(s)){
		printf("ջΪ�գ��޷���ջ\n");
		return; 
	}
	
	//�������� 
	tmp = s->next;
	val = tmp->data;
	
	//ɾ��
	s->next = tmp->next;
 	free(tmp);
	return val;
}

//ջ��������� 
void printData(Stack s){
	Stack p = s;
	printf("\n ��ǰջԪ�� ��");
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
