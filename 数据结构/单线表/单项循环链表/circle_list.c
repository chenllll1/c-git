#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"circle_list.h"
int Init(Node** head, Node** tail, int* len) {//初始化
	*head = (Node*)malloc(sizeof(Node));
	if (*head == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(*head, 0, sizeof(Node));
	(*head)->next = *head;
	*tail = *head;
	*len = 0;
	return true;
}

int TopInsert(Node**head,Node**tail,int*len) {//节点头插
	Node* p1 = *head;
	Node* p2 = NULL;
	p2 = (Node*)malloc(sizeof(Node));
	if (p2 == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(p2, 0, sizeof(Node));
	puts("请输入数据");
	puts("情输入学号");
	scanf("%d", &p2->item.id);
	puts("请输入姓名");
	scanf("%s", p2->item.name);
	if (p1->next == *head) {//如果头节点下一个指向自己,则没有节点
		*tail = p2;
	}
	p2->next = p1->next;
	p1->next = p2;
	(*len)++;
	puts("数据插入完毕");
	return true;
}

int EndInsert(Node**head,Node**tail,int*len) {//节点尾插
	Node* p1 = NULL, * temp = NULL;
	p1 = (Node*)malloc(sizeof(Node));
	if (p1 == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(p1, 0, sizeof(Node));
	puts("请输入数据");
	puts("请输入学号");
	scanf("%d", &p1->item.id);
	puts("请输入姓名");
	scanf("%s", p1->item.name);
	p1->next = (*tail)->next;
	(*tail)->next = p1;
	*tail = p1;
	(*len)++;
	puts("数据添加成功");
	return true;
}

int del(Node**head,Node**tail,int *len) {//删除节点
	int position = 0, i = 0;
	Node* p1 = NULL, * temp = NULL;
	flag:puts("请输入你要删除的位置");
	scanf("%d", &position);
	if (position<1 || position>=( * len) + 1) {
		puts("删除位置出错,请重新输入");
		printf("目前只支持1-%d\n", *len);
		goto flag;
	}
	for (temp = (*head), i = 0; temp->next != *head && i != position - 1; i++, temp = temp->next);
	p1 = temp->next;//temp为删除节点的前驱,p1为删除节点
	if (p1->next == (*head)) {
		*tail = temp;
	}
	temp->next = p1->next;
	p1->next = NULL;
	free(p1);
	(*len)--;
	puts("删除成功");
	return true;
}

void xg(Node*head,int len) {//修改节点
	Node* p1 = head;
	Node* temp = NULL;
	int position = 0, i = 1;
	flag:puts("请输入你要修改的位置");
	scanf("%d", &position);
	if (position<1 || position>=len + 1) {
		puts("位置输入错误,请重新输入");
		printf("目前只支持1-%d", len);
		goto flag;
	}
	for (temp = head->next, i = 1; temp->next != head && i != position; i++, temp = temp->next);
	puts("请输入修改数据");
	puts("请输入学号 姓名");
	scanf("%d %s", &temp->item.id, temp->item.name);
	puts("修改成功");
}
int cx(Node*head,int len) {
	int id = 0, i = 1;
	Node* p1 = head->next;
	puts("请输入学号查询排名");
	scanf("%d", &id);
	for (i = 1; i <= len; i++) {
		if (p1->item.id == id) {
			printf("找到了他排第%d个", i);
			return true;
		}
		p1 = p1->next;
	}
	puts("没找到");
	return false;
}

void show(Node*head,int len) {
	Node* p1 = head->next;
	printf("一共有%d个数据如下:", len);
	while (p1!=head)
	{
		printf("学号:%d 姓名:%s\n", p1->item.id, p1->item.name);
		p1 = p1->next;
	}
}

int destory(Node** head, Node** tail, int* len) {//销毁链表
	Node* p1 = *head, * temp = NULL;
	do {
		temp = p1->next;
		free(p1);
		p1 = temp;
	} while (p1!=*head);
	*head = *tail = NULL;
	*len = 0;
	puts("链表销毁完毕");
	return true;
}

void menu() {
	int num = 0;
	puts("\n\t\t\t\t*********************循环链表*********************\n");
	puts("\n\t\t\t\t***************请按键进行以下操作****************\n");
	puts("\n\t\t\t\t********************1.头插节点*********************\n");
	puts("\n\t\t\t\t********************2.尾插节点*********************\n");
	puts("\n\t\t\t\t********************3.删除节点*********************\n");
	puts("\n\t\t\t\t********************4.修改节点*********************\n");
	puts("\n\t\t\t\t********************5.查看节点*********************\n");
	puts("\n\t\t\t\t********************6.输出节点*********************\n");
	puts("\n\t\t\t\t********************7.退出程序*********************\n");
	scanf("%d", &num);
	switch (num)
	{
		case 1:TopInsert(&space.head, &space.tail, &space.len); break;
		case 2:EndInsert(&space.head, &space.tail, &space.len); break;
		case 3:del(&space.head, &space.tail, &space.len); break;
		case 4:xg(space.head, space.len); break;
		case 5:cx(space.head, space.len); break;
		case 6:show(space.head, space.len); break;
		case 7:destory(&space.head, &space.tail, &space.len); exit(0); break;
		default:puts("请按提示进行输入"); break;
	}
}

