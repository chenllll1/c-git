#include<stdio.h>//实现双向链表接口
#include<stdlib.h>
#include<string.h>
#include"doublelist.h"

int Init(Node**head,Node**tail,int*len) {
	*head = (Node*)malloc(sizeof(Node));
	if (*head == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(*head, 0, sizeof(Node));
	(*head)->next = NULL;
	(*head)->pre = NULL;
	*tail = *head;
	(*len) = 0;
}

int TopInsert(Node**head,Node**tail,int *len) {//头插
	Node* p1 = NULL;
	p1 = (Node*)malloc(sizeof(Node));
	if (p1 == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(p1, 0, sizeof(Node));
	puts("请输入数据(学号 姓名)");
	scanf("%d %s", &p1->item.id, p1->item.name);
	if ((*head)->next == NULL) {
		*tail = p1;
	}
	else {
		(*head)->next->pre = p1;
	}
	p1->next = (*head)->next;
	p1->pre = *head;
	(*head)->next = p1;
	(*len)++;
	puts("数据添加成功");
	return true;
}

int EndInsert(Node**head,Node**tail,int*len) {
	Node* p1 = NULL;
	p1 = (Node*)malloc(sizeof(Node));
	if (p1 == NULL) {
		fprintf(stderr, "无法分配空间");
		exit(0);
	}
	memset(p1, 0, sizeof(Node));
	puts("请输入数据(学号 姓名)");
	scanf("%d %s", &p1->item.id, p1->item.name);
	p1->next = (*tail)->next;
	p1->pre = (*tail);
	(*tail)->next = p1;
	*tail = p1;
	puts("数据添加成功");
	(*len)++;
	return true;
}

int del(Node**head,Node**tail,int*len) {
	if ((*head)->next == NULL) {
		puts("链表为空,没有数据可删除");
		return false;
	}
	int position = 0, i = 1;
	Node* p1 = (*head)->next;
	flag:puts("请输入你要删除的位置");
	scanf("%d", &position);
	if (position < 1 || position >= (*len) + 1) {
		puts("删除位置有误,请重新输入");
		printf("**目前只支持1-%d**\n", *len);
		goto flag;
	}
	for (i = 1; i < position; i++) {
		p1 = p1->next;
	}
	if (p1->next != NULL) {
		p1->next->pre = p1->pre;
	}
	p1->pre->next = p1->next;
	p1->pre = p1->next = NULL;
	free(p1);
	(*len)--;
	puts("删除成功");
	return true;
}
int xg(Node*head,int len) {
	int position = 0, i = 1;
	Node* p1 = head->next;
	flag:puts("请输入你要修改的位置");
	scanf("%d", &position);
	if (position < 1 || position >= len + 1) {
		puts("位置有误,请重新输入");
		printf("**目前只支持1-%d**\n", len);
		goto flag;
	}
	for (i = 1; i < position; i++) {
		p1 = p1->next;
	}
	puts("请输入修改的数据(学号 姓名)");
	scanf("%d %s", &p1->item.id, p1->item.name);
	puts("修改成功");
	return true;
}
int cx(Node*head,int len) {
	int id = 0, i = 0;
	Node* p1 = head->next;
	puts("请输入学号,查询排名");
	scanf("%d", &id);
	while (p1!=NULL)
	{
		i++;
		if (p1->item.id == id) {
			printf("找到了他是第%d个", i);
			return true;
		}
		p1 = p1->next;
	}
	puts("没找到");
	return false;
}
void show(Node*head,int len) {
	Node* p1 = head->next;
	while (p1!=NULL)
	{
		printf("学号:%d 姓名:%s", p1->item.id, p1->item.name);
		p1 = p1->next;
	}
}
int destory(Node**head,Node**tail,int*len) {
	Node* p1 = *head, * temp = NULL;
	while (p1!=NULL)
	{
		temp = p1->next;
		free(p1);
		p1 = temp;
	}
	*head = *tail = NULL;
	*len = 0;
	puts("链表销毁完毕");
	return true;
}
void menu() {
	int num = 0;
	puts("\n\t\t\t\t*****************双向循环链表*********************\n");
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
	case 7:destory(&space.head, &space.tail, &space.len); exit(0);
	default:puts("请按提示进行输入"); break;
	}
}