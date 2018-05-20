#include <stdio.h>
#include <stdlib.h>

typedef struct Node PNode, *List;

struct Node{
	int data;//元素
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

//查找第k个元素 
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

//插入元素 x-元素 pos-位置  链表不用考虑容量问题
List insertData(int x, int pos , List l){
	
	List list ;
	//新元素 
	List newNode ;
	
	printf("向第%i个位置 插入元素%i\n", x, pos);
	
	if(pos == 1){
		//第一个元素
		newNode = (List) malloc(sizeof(PNode));
		newNode->data = x;
		newNode->next = l;
		return newNode;
		 
	} else{
		//先找到pos-1的元素，使用findKth方法
		list = l;
		List p = findKth(pos - 1, list);
		if(p==NULL){
			printf("插入位置错误");
			return;
		}
		
		newNode = (List) malloc(sizeof(PNode));
		newNode->data = x;	 
		
		//next指针修改
		newNode->next = p->next;
		p->next = newNode;	
		return l;
	}
}


List deleteData(int pos, List l){
	List list = l;
	List temp;
	
	//第一个节点特殊处理
	if(pos == 1){
		l = list->next;
		free(list);
		return l;
	}else{
		
		//找到前面一个元素 
		List p = findKth(pos - 1, list);
		if(NULL == p){
			printf("待删除位置错误");
			return;
		}
		
		temp = p->next;//需要删除的元素
		p->next = p->next->next;
		free(temp); 
		return l;
	}
}

void printData(List l){
	List p = l;
	printf("链表内容：");
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
	
	printf("当前元素");
	printData(list); 
	
	printf("\n");
	printf("向第二个位置插入4，理想结果 1，4，2，3\n");
	list =insertData(4, 2, list);
 	printf("实际结果 ");
 	printData(list); 
 	
 	printf("\n");
 	printf("删除第二个位置的元素，理想结果 1，2，3\n");
	list = deleteData(2, list);
 	printf("实际结果 ");
 	printData(list); 
}
