#ifndef DOUBLELIST_H_//此处为双向链表接口
#define DOUBLELIST_H_
#define true 1
#define false 0
typedef struct item {
	int id;
	char name[20];
}Item;
typedef struct node {
	Item item;
	struct node* pre;
	struct node* next;
}Node;
typedef struct list {//head为头指针，tail为尾指针，len为数据长度
	Node* head;
	Node* tail;
	int len;
}List;
List space;
int Init(Node**head,Node**tail,int*len);//初始化链表

int TopInsert(Node**head,Node**tail,int*len);//头插

int EndInsert(Node**head,Node**tail,int*len);//尾插

int del(Node**head,Node**tail,int*len);//删除节点

int xg(Node*head,int len);//修改节点

int cx(Node* head, int len);//查询节点

void show(Node* head, int len);//输出节点

int destory(Node** head, Node** tail, int* len);//销毁节点

void menu();//操作菜单
#endif // !DOUBLELIST_H_
