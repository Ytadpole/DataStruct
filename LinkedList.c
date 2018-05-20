#include <stdio.h>
#include <stdlib.h>

typedef struct Node PNode, *List;

struct Node{
	int data;//Ԫ��
 	List next;
};

int length(List l){
	List p = l;
	int len = 0;
	while(p){
		len ++;
		p = p->next;
	}
	return len;
} 

//���ҵ�k��Ԫ�� 
List findKth(int k, List l){
	List p = l;
	int i = 1;
	while(i < k && p){
		i++;
		p = p->next;
	}	
	if(i == k) return p; 
	else return NULL;
}

//����Ԫ�� x-Ԫ�� pos-λ��  �����ÿ�����������
List insertData(int x, int pos , List l){
	
	List list ;
	//��Ԫ�� 
	List newNode ;
	
	printf("���%i��λ�� ����Ԫ��%i\n", x, pos);
	
	if(pos == 1){
		//��һ��Ԫ��
		newNode = (List) malloc(sizeof(PNode));
		newNode->data = x;
		newNode->next = l;
		return newNode;
		 
	} else{
		//���ҵ�pos-1��Ԫ�أ�ʹ��findKth����
		list = l;
		List p = findKth(pos - 1, list);
		if(p==NULL){
			printf("����λ�ô���");
			return;
		}
		
		newNode = (List) malloc(sizeof(PNode));
		newNode->data = x;	 
		
		//nextָ���޸�
		newNode->next = p->next;
		p->next = newNode;	
		return l;
	}
}


List deleteData(int pos, List l){
	List list = l;
	List temp;
	
	//��һ���ڵ����⴦��
	if(pos == 1){
		l = list->next;
		free(list);
		return l;
	}else{
		
		//�ҵ�ǰ��һ��Ԫ�� 
		List p = findKth(pos - 1, list);
		if(NULL == p){
			printf("��ɾ��λ�ô���");
			return;
		}
		
		temp = p->next;//��Ҫɾ����Ԫ��
		p->next = p->next->next;
		free(temp); 
		return l;
	}
}

void printData(List l){
	List p = l;
	printf("�������ݣ�");
	while(p){
		printf(" %i", p->data);
		p = p->next; 
	}
	printf("\n");
}

int main(){

	List list = NULL;//= (List) malloc(sizeof(PNode));
	list = insertData(1, 1, list);
	list =insertData(2, 2, list);
	list =insertData(3, 3, list);
	
	printf("��ǰԪ��");
	printData(list); 
	
	printf("\n");
	printf("��ڶ���λ�ò���4�������� 1��4��2��3\n");
	list =insertData(4, 2, list);
 	printf("ʵ�ʽ�� ");
 	printData(list); 
 	
 	printf("\n");
 	printf("ɾ���ڶ���λ�õ�Ԫ�أ������� 1��2��3\n");
	list = deleteData(2, list);
 	printf("ʵ�ʽ�� ");
 	printData(list); 
}
