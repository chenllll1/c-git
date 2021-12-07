#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>
#define maxname 10
struct student
{
	int id;
	char name[maxname];
};
typedef struct student Item;
typedef struct node
{
	Item item;
	struct node* next;
}Node;
typedef Node *List;
void InitializeList(List* plist);

bool ListIsEmpty(const List* plist);

bool ListIsFull(const List* plist);

unsigned int ListItemCount(const List* plist);

bool AddItem(Item item, List* plist);

void Traverse(const List* plist, void(*pfun)(Item item));

void EmptyTheList(List* plist);
#endif