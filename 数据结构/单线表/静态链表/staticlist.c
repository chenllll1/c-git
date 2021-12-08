//静态链表接口的实现
#include<stdio.h>
#include<string.h>
#include "staticlist.h"
int InitList(staticlist space) {//初始化
	int i;
	for (i = 0; i < max - 1; i++) {
		space[i].cur = i + 1;
	}
	space[max - 1].cur = 0;
	//puts("静态链表初始化完成");
	return true;
}
int GetLength(staticlist space) {//获取数据长度
	int len = 0;
	int index = space[max - 1].cur;
	while (index)
	{
		len++;
		index = space[index].cur;
	}
	return len;
}
int malloc_staticlist(staticlist space) {//分配节点
	int index = space[0].cur;
	if (index) {
		space[0].cur = space[index].cur;
		return index;
	}
	puts("移动失败");
	return false;
}
void free_staticlist(staticlist space, int index) {//释放节点
	space[index].cur = space[0].cur;
	space[0].cur = index;
}
int Insetlist(staticlist space) {//添加节点
	int freeIndex, validIndex, i;
	int position;
	puts("请输入要插入的位置");
	scanf("%d", &position);
	if (position<1 || position>GetLength(space) + 1) {
		puts("插入位置错误");
		return false;
	}
	validIndex = max - 1;
	freeIndex = malloc_staticlist(space);
	if (freeIndex) {
		rewind(stdin);
		puts("请输入学号");
		scanf("%d", &space[freeIndex].item.id);
		puts("请输入姓名");
		scanf("%s", space[freeIndex].item.name);
		for (i = 1; i <= position - 1; i++) {
			validIndex = space[validIndex].cur;
		}
		space[freeIndex].cur = space[validIndex].cur;
		space[validIndex].cur = freeIndex;
		puts("插入成功");
		return true;
	}
	else {
		puts("插入失败");
		return false;
	}

}
int dellist(staticlist space) {//删除节点
	int freeindex, validindex, i;
	int position;
	puts("请输入你要删除的位置");
	scanf("%d", &position);
	if (position<1 || position>GetLength(space) + 1) {
		puts("删除数据位置出错");
		return false;
	}
	validindex = max - 1;
	for (i = 1; i <= position-1; i++) {
		validindex = space[validindex].cur;
	}
	freeindex = space[validindex].cur;
	space[validindex].cur = space[freeindex].cur;
	free_staticlist(space, freeindex);
	puts("删除数据成功");
	return true;
}
int xiugailist(staticlist space) {//修改节点
	int index;
	puts("请输入你要修改的位置");
	flag:scanf("%d", &index);
	if (index<1 || index>GetLength(space) + 1) {
		puts("修改位置有误,请重新输入");
		goto flag;
	}
	//puts("请输入你要修改的学号");
	puts("请输入你要修改的姓名");
	scanf("%s", space[index].item.name);
	//scanf(" %c", &space[index].ch);
	puts("修改数据成功");
	return true;
}
int searchlist(staticlist space) {//查看节点
	int index; int ch1;
	puts("请输入数据");
	scanf("%d", &ch1);
	index = space[max - 1].cur;
	while (index)
	{
		if (space[index].item.id == ch1) {
			printf("找到了他是第%d个", index);
			return true;
		}
		index = space[index].cur;
	}
	puts("没有找到");
	return false;
}
void printlist(staticlist space) {
	int index = space[max - 1].cur;
	puts("数据为");
	while (index)
	{
		printf("学号:%d,姓名:%s",space[index].item.id,space[index].item.name);
		index = space[index].cur;
	}
}
void menu() {//实现菜单
	int num;
	puts("\n--------------------------------------静态链表系统--------------------------------------\n");
	puts("\n--------------------------------------请按键选择操作--------------------------------------\n");
	puts("\n--------------------------------------1.添加节点--------------------------------------\n");
	puts("\n--------------------------------------2.删除节点--------------------------------------\n");
	puts("\n--------------------------------------3.查找节点--------------------------------------\n");
	puts("\n--------------------------------------4.修改节点--------------------------------------\n");
	puts("\n--------------------------------------5.输出节点--------------------------------------\n");
	puts("\n--------------------------------------6.退出系统--------------------------------------\n");
	puts("请输入:");
	scanf("%d", &num);
	switch (num)
	{
	case 1:Insetlist(space); break;
	case 2:dellist(space); break;
	case 3:searchlist(space); break;
	case 4:xiugailist(space); break;
	case 5:printlist(space); break;
	case 6:puts("程序结束"); exit(0); break;
	default:puts("请按提示进行操作"); break;
	}
}