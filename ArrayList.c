#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct LNode{
	int data[MAX_SIZE];
	int last;//�������±�� 
} LNode, *List;

//�����յ����Ա� 
List createNewList(){
	List p;
	p = (List)malloc(sizeof(LNode));
	p -> last = -1;
	return p;
}

//����ĳ��Ԫ�ص�һ�γ��ֵ��±� 
int find(int x, List l){
	int i = 0;
	while(i <= l->last && x != l -> data[i]){
		i++;
	}
	if(i > l->last) return -1;
	else return i;
}

//����Ԫ�أ�����ĩβ 
//void insert(int x, list l){
//	if(l->last > MAZ_SIZE - 1){
//		printf("���Ա�ռ䲻��");
//		return ; 
//	} 
	
	
//}

//�������ݣ� x-������Ԫ��  pos-������λ��  l-�����Ա� 
void insert(int x, int pos, List l){
	int i ;

	printf("���Ԫ��%i, λ��%i\n", x, pos);
	
	if(l->last >= MAX_SIZE - 1){
		printf("���Ա����������꣬�޷�����������\n");
		return ;
	}
		
	if( pos < 1 || pos > MAX_SIZE) {
		printf("����λ�ô��������������С��1\n");
		return; 
	}
	
	//���� 
	for(i = l->last; i >= pos - 1 ; i-- ){
		l->data[i+1] = l->data[i];
	}

	//��������	
	l->last = l->last + 1;
	l->data[pos - 1] = x;	
}

//ɾ��λ��Ϊpos��Ԫ��  pos-����ɾ��Ԫ��λ�ã�  
void deleteData(int pos, List l){
	int i;
	
	if(l->last <0){
		printf("���Ա���Ԫ�أ��޷�ɾ��");
		return; 
	} 
	
	if(pos < 1 || pos > (l->last+1)){
		printf("��Ҫɾ��Ԫ�� λ�ò�����");
		return ;
	}
	
	for(i = pos - 1; i < l->last; i++){
		l->data[i] = l->data[i + 1];
	}
	
	l->last--;
} 

//��ӡ���� 
void printData(List l){
	int i;
	printf("���Ա�Ԫ�أ�");
	for(i = 0; i <= l->last; i++){
		printf(" %i", l->data[i]);	
	}
	printf("\n"); 
}

int main(){
	List list ;
	list = createNewList();
	insert(1, 1, list);
	insert(2, 2, list);
	insert(3, 3, list);
	printData(list);
	
	printf("�ڶ���λ�ò���4�������� 1��4��2��3\n");
	insert(4, 2, list);
	printf("ʵ�ʽ����");
	printData(list); 
	
	printf("\n"); 
	printf("ɾ���ڶ���λ�õ�Ԫ�أ�������1��2,3\n");
	deleteData(2, list);
	printf("ʵ�ʽ����");
	printData(list); 
}
