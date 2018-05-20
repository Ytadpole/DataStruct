#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct LNode{
	int data[MAX_SIZE];
	int last;//按数组下标计 
} LNode, *List;

//建立空的线性表 
List createNewList(){
	List p;
	p = (List)malloc(sizeof(LNode));
	p -> last = -1;
	return p;
}

//查找某个元素第一次出现的下标 
int find(int x, List l){
	int i = 0;
	while(i <= l->last && x != l -> data[i]){
		i++;
	}
	if(i > l->last) return -1;
	else return i;
}

//插入元素，队列末尾 
//void insert(int x, list l){
//	if(l->last > MAZ_SIZE - 1){
//		printf("线性表空间不足");
//		return ; 
//	} 
	
	
//}

//插入数据， x-》插入元素  pos-》插入位置  l-》线性表 
void insert(int x, int pos, List l){
	int i ;

	printf("添加元素%i, 位置%i\n", x, pos);
	
	if(l->last >= MAX_SIZE - 1){
		printf("线性表容量已用完，无法插入新内容\n");
		return ;
	}
		
	if( pos < 1 || pos > MAX_SIZE) {
		printf("插入位置大于最大容量或者小于1\n");
		return; 
	}
	
	//后移 
	for(i = l->last; i >= pos - 1 ; i-- ){
		l->data[i+1] = l->data[i];
	}

	//插入数据	
	l->last = l->last + 1;
	l->data[pos - 1] = x;	
}

//删除位置为pos的元素  pos-》待删除元素位置，  
void deleteData(int pos, List l){
	int i;
	
	if(l->last <0){
		printf("线性表无元素，无法删除");
		return; 
	} 
	
	if(pos < 1 || pos > (l->last+1)){
		printf("需要删除元素 位置不存在");
		return ;
	}
	
	for(i = pos - 1; i < l->last; i++){
		l->data[i] = l->data[i + 1];
	}
	
	l->last--;
} 

//打印类容 
void printData(List l){
	int i;
	printf("线性表元素：");
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
	
	printf("第二个位置插入4，理想结果 1，4，2，3\n");
	insert(4, 2, list);
	printf("实际结果：");
	printData(list); 
	
	printf("\n"); 
	printf("删除第二个位置的元素，理想结果1，2,3\n");
	deleteData(2, list);
	printf("实际结果：");
	printData(list); 
}
