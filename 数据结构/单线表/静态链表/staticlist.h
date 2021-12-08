//静态链表的接口
#ifndef STATICLIST_H_
#define STATICLIST_H_
#define max 20
#define true 1
#define false 0
typedef struct student
{	
	int id;
	int name[20];
}Item;
typedef struct node {
	Item item;
	int cur;
}Node,staticlist[max];
staticlist space;
int InitList(staticlist space);//初始化静态链表

int GetLength(staticlist space);//获取数据长度

int malloc_staticlist(staticlist space);//为数据分配空间

void free_staticlist(staticlist space, int index);//释放节点

int Insetlist(staticlist space);//添加节点

int dellist(staticlist space);//删除节点

int xiugailist(staticlist space);//修改节点

int searchlist(staticlist space);//查找节点

void printlist(staticlist space);//输出节点

void menu();//菜单栏
#endif // !STATICLIST_H_
