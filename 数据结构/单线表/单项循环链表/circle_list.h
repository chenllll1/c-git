#ifndef CIRCLE_LIST_H_//单项循环链表
#define	CIRCLE_LIST_H_
#define true 1
#define false 0
typedef struct item {
	int id;
	char name[20];
}Item;
typedef struct node {
	Item item;
	struct node* next;
}Node;
typedef struct list {//head为头指针，tail为尾指针，len为链表数据长度
	Node* head;
	Node* tail;
	int len;
}List;
List space;
int Init(Node**head,Node**tail,int*len);//初始化

int TopInsert(Node**head,Node**tail,int*len);//头插节点

int EndInsert(Node** head, Node** tail, int* len);//尾插节点

int del(Node** head, Node** tail, int* len);//删除节点

void xg(Node* head,int len);//修改节点

int cx(Node* head, int len);//查询节点

void show(Node* head, int len);//输出节点

int destory(Node** head, Node** tail, int* len);//销毁全部节点

void menu();//菜单
#endif // !CIRCLE_LIST_H_
