#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct student {//创建学生结构体
	int id;
	char name[15];
	struct score {
		float chinese;
		float math;
		float english;
		float sum;
		float average;
	}score;
	struct student* next;
}stu;
int i = 0;//为数据人数(最后写入数据时变为总人数)
int n = 0;//为添加的人数
void node_scanf(stu* p);
stu* sort(stu* h);
stu* create_node(stu*h) {//用于添加学生信息
	stu* p1=NULL,*p2=h;//p1为新节点，p2为尾节点
	p1 = (stu*)malloc(sizeof(stu));
	if (p1 == NULL) {
		printf("无法分配空间\n");
		exit(-1);
	}
	memset(p1, 0, sizeof(p1));
	if (n!=0)//判断是否有添加人数
	{
		node_scanf(p1);
	}
	if (h == NULL) {
		h = p1;
		p1->next = NULL;
	}	
	else {
		while (p2->next!=NULL)//查找最后一个节点
		{
			p2 = p2->next;
		}
		p2->next = p1;
		p1->next = NULL;
	}
	return h;
}
void node_scanf(stu*p) {//用于输入学生信息
	printf("学号\t姓名\t语文\t数学\t英语\t\n");
	scanf("%d%s%f%f%f", &p->id, p->name, &p->score.chinese,&p->score.math,&p->score.english);
	p->score.sum = p->score.chinese + p->score.math + p->score.english;
	p->score.average = p->score.sum / 3;
}
void search(stu*h) {//用于查询学生信息
	int n;//此处n为局部变量
	int flag = 1;//判断用户是否继续输入(局部变量)
	stu* p = h;
	char m = 'n';//检查是否找到元素(局部变量)
	printf("请选择你的查询方式(目前支持俩种)\n");
	while (flag)
	{
		printf("1.按学号查询\t2.按姓名查询\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:{
			int id;//复合语句中的局部变量
			printf("请输入学号\n");
			scanf("%d", &id);
			p = h;//再次要p指向头节点便于多次循环
			while (p != NULL) {
				if (p->id == id) {
					m = 'y';
					printf("学号\t姓名\t语文\t数学\t英语\t总分\t平均分\t\n");
					printf("%-4d\t%-2s\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t\n", p->id, p->name, p->score.chinese, p->score.math, p->score.english, p->score.sum, p->score.average);
				}
				p = p->next;
			}
			flag = 0;
			if (m == 'n') {
				printf("没有找到\n");
				flag = 1;
			}
			 break; 
		}
		case 2: {
			char name[15];//复合语句中的局部变量
			printf("请输入你的姓名\n");
			scanf("%s", name);
			p = h;//再次要p指向头节点便于多次循环
			while (p!=NULL)
			{
				if (strcmp(p->name,name)==0)
				{
					m = 'y';
					printf("学号\t姓名\t语文\t数学\t英语\t总分\t平均分\t\n");
					printf("%-4d\t%-2s\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t\n", p->id, p->name, p->score.chinese, p->score.math, p->score.english, p->score.sum, p->score.average);
				}
				p = p->next;
			}
			flag = 0;
			if (m == 'n') {
				printf("没有找到\n");
				flag = 1;
			}
			 break;
		}
		default:printf("请按提示输入\n"); flag = 1;break;
		}
	}
}
stu* del(stu*h) {//用于删除学生信息
	int num;//此处为局部变量
	int flag = 1;//用于判断用户是否继续输入(局部变量)
	char m = 'n';//判断是否找到(局部变量)
	//p为当前节点，pre为前驱节点，r为要删除的节点
	stu* p = h;
	stu* pre=h, * r;
	printf("请选择\n");
	while (flag)
	{
		printf("1.按姓名删除2.按学号删除\n");
		scanf("%d", &num);
		switch (num)
		{
			case 1: {
				char name[15];//局部变量
				printf("请输入你要删除的学生姓名\n");
				scanf("%s", name);
				p = h;//再次要p指向头节点便于多次循环
				while (p!=NULL)
				{
					if (strcmp(p->name, name) == 0) {
						m = 'y';
						i--;
						if (p==h)
						{
							h = p->next;
							r = p;
							p = pre = h;
						}
						else
						{
							pre->next = p->next;
							r = p;
							p = pre->next;
						}
						r->next = NULL;
						free(r);
						printf("删除学生信息成功\n");
					}
					else
					{
						pre = p;
						p = p->next;
					}
				}
				flag = 0;
				if (m == 'n') {
					printf("\n\n没有此人,请重新输入\n\n");
					flag = 1;
				}
				break;
			}
			case 2: {
				int id;//局部变量
				printf("请输入学号\n");
				scanf("%d", &id);
				p = h;//再次要p指向头节点便于多次循环
				while (p != NULL)
				{
					if (p->id==id) {
						m = 'y';
						i--;
						if (p == h)
						{
							h = p->next;
							r = p;
							p = pre = h;
						}
						else
						{
							pre->next = p->next;
							r = p;
							p = pre->next;
						}
						r->next = NULL;
						free(r);
						printf("删除学生信息成功\n");
					}
					else
					{
						pre = p;
						p = p->next;
					}
				}
				flag = 0;
				if (m == 'n') {
					printf("\n\n没有此人,请重新输入\n\n");
					flag = 1;
				}
				break;
			}
			default:printf("请按提示进行输入\n"); flag = 1; break;
		}
	}
	return h;
}
void xiugai(stu*h) {//用于修改学生信息
	stu* p=h;
	int n;
	int flag = 1;
	char m = 'n';
	printf("请选择修改项目\n");
	while (flag)
	{
		printf("1.修改学号2.修改姓名3.修改学生成绩4.退出此程序\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: {
			char name[15];
			printf("请输入你的姓名\n");
			scanf("%s", name);
			p = h;
			while (p != NULL)
			{
				if (strcmp(p->name, name) == 0) {
					m = 'y';
					printf("请输入修改后的学号\n");
					scanf("%d",&p->id);
					printf("修改成功\n");
				}
				p = p->next;
			}
			flag = 0;
			if (m=='n')
			{
				printf("\n\n没有此人,请重新输入\n\n");
				flag = 1;
			}
			break;
		}
		case 2: {
			int id;
			printf("请输入你的学号\n");
			scanf("%d", &id);
			p = h;
			while (p!=NULL)
			{
				if (p->id == id) {
					m = 'y';
					printf("请输入修改后的名字\n");
					scanf("%s", p->name);
					printf("修改成功\n");
				}
				p = p->next;
			}
			flag = 0;
			if (m == 'n') {
				printf("\n\n没有此人,请重新输入\n\n");
				flag = 1;
			}
			break;
		}
		case 3: {
			int num, num1;//num用于最外层switch，num1用于里面的switch；
			printf("请选择\n");
			printf("1.按学号查找并修改2.按姓名查找并修改\n");
			scanf("%d", &num);
			switch (num)
			{
				case 1: {
							int id;
							printf("请输入学号\n");
							scanf("%d", &id);
							p = h;
							while (p!=NULL)
							{
								if (p->id == id) {
									m = 'y';
									printf("请选择你要修改的学科\n");
									printf("1.语文2.数学3.英语\n");
									scanf("%d", &num1);
									switch (num1)
									{
										case 1: {
											printf("请输入修改后的语文成绩\n");
											scanf("%f", &p->score.chinese);
											printf("成绩修改成功\n");
											break;
											}
										case 2: {
											printf("请输入修改后的数学成绩\n");
											scanf("%f", &p->score.math);
											printf("成绩修改成功\n");
											break;
											}
										case 3: {
											printf("请输入修改后的英语成绩\n");
											scanf("%f", &p->score.english);
											printf("成绩修改成功\n");
											break;
											}
										default:printf("请按提示进行输入\n"); break;
									}
								}
								p = p->next;
							}
							flag = 0;
							if (m == 'n') {
								printf("\n\n没有此人,请重新输入\n\n");
								flag = 1;
							}
							break;
						}
				case 2: {
					char name[15];
					printf("请输入姓名\n");
					scanf("%s", name);
					p = h;
					while (p!=NULL)
					{
						if (strcmp(p->name,name)==0) {
							m = 'y';
							printf("请输入你要修改的学科\n");
							printf("1.语文2.数学3.英语\n");
							scanf("%d", &num1);
							switch (num1)
							{
								case 1: {
									printf("请输入修改后的语文成绩\n");
									scanf("%f", &p->score.chinese);
									printf("成绩修改成功\n");
									break;
								}
								case 2: {
									printf("请输入修改后的数学成绩\n");
									scanf("%f", &p->score.math);
									printf("成绩修改成功\n");
									break;
								}
								case 3: {
									printf("请输入修改后的英语成绩\n");
									scanf("%f", &p->score.english);
									printf("成绩修改成功\n");
									break;
								}
								default:printf("请按提示进行输入\n"); break;
							}
						}
						p = p->next;
					}
					flag = 0;
					if (m=='n')
					{
						printf("\n\n没有此人,请重新输入\n\n");
						flag = 1;
					}
					break;
				}
				default:printf("请按提示进行输入\n");flag=1; break;
			}
			break;
		}
		case 4: {
			printf("退出程序成功感谢你的使用\n");
			flag = 0;
			break;
		}
		default:printf("请按提示进行输入\n"); flag = 1; break;
		}
	}
}
stu* node_printf(stu*h) {//用于展示学生信息
	h=sort(h);
	stu* p = h;
	if (p == NULL) {
		printf("这不是一个链表\n");
		return;
	}
	printf("学号\t姓名\t语文\t数学\t英语\t总分\t平均分\t\n");
	while (p!=NULL)
	{
		printf("%-4d\t%-2s\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t\n", p->id, p->name, p->score.chinese, p->score.math, p->score.english, p->score.sum, p->score.average);
		p = p->next;
	}
	return h;
}
stu* sort(stu*h) {//用于学生按学号进行排序
	stu* p1 = h, * p2, * k;
	stu* pre1=h, * pre2=p1;
	stu* huan;
	while (p1!=NULL)
	{
		k = p1;
		pre2 = p1;
		p2 = p1->next;
		while (p2!=NULL)//寻找小的节点
		{	
			if (p2->id < k->id)
				k = p2;
				p2 = p2->next;
		}
		//查找最小节点的前节点
		p2 = p1->next;
		while (p2!=NULL)
		{
			if (k == p2)break;
			pre2 = pre2->next;
			p2 = p2->next;
		}
		if (k!=p1)
		{
			if (p1==h)
			{
				if (pre2 == p1) {
					p1->next = k->next;
					k->next = p1;
					h = p1 = k;
				}
				else {
					huan = p1->next;
					p1->next = k->next;
					k->next = huan;
					pre2->next = p1;
					h = p1 = k;
				}
			}
			else
			{
				if (pre2==p1) {
					p1->next = k->next;
					k->next = p1;
					pre1->next = k;
					p1 = k;
				}
				else {
					huan = p1->next;
					p1->next = k->next;
					k->next = huan;
					//前后节点交换
					huan = pre1->next;
					pre1->next = pre2->next;
					pre2->next = huan;
					p1 = k;
					//printf("6");
				}
			}
		}
		pre1 = p1;
		p1 = p1->next;
	 }
	return h;
}
void save(stu*h) {//用于保存学生信息
	stu* p=h;
	FILE* fp;
	if ((fp=fopen("C:\\Users\\Lenovo\\Desktop\\2.txt","w+")) == NULL)
	{
		printf("不能打开文件\n");
		exit(1);
	}
	i = n + i;
	fprintf(fp, "%d\n", i);
	while (p!=NULL)
	{
		fprintf(fp, "%-4d\t%-2s\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t%-4.1f\t\n", p->id, p->name, p->score.chinese, p->score.math, p->score.english, p->score.sum, p->score.average);
		p = p->next;
	}
	printf("文件写入完毕\n");
	fclose(fp);
}
stu* load(stu*h) {//从文件中读取数据
	FILE* fp;
	stu* p = h;
	int n;
	if ((fp = fopen("C:\\Users\\Lenovo\\Desktop\\2.txt", "r")) == NULL) {
		printf("无法打开文件\n");
		exit(-1);
	}
	fscanf(fp,"%d", &i);
	for (n = 0; n < i; n++) {
		h = create_node(h);
	}
	p = h;
	while (p != NULL)
	{
		fscanf(fp,"%d%s%f%f%f%f%f",&p->id,p->name,&p->score.chinese,&p->score.math,&p->score.english,&p->score.sum,&p->score.average);
		p = p->next;
	}
	printf("数据更新完毕\n");
	if (fclose(fp)) {
		printf("不能关闭文件\n");
		exit(1);
	}
	return h;
}
stu* destruct(stu*h) {//用于销毁链表
	stu* p, * q;
	p = h;
	while (p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	h = NULL;
	return h;
}
int main() {
	stu* h=NULL;
	int i=0;
	h=load(h);
	printf("-------------------文件更新完毕,请稍后-------------------\n");
	printf("请输入你要添加学生的个数\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		h = create_node(h);
	}
	h=node_printf(h);
	h=del(h);
	save(h);
	h = destruct(h);
	printf("文件销毁完毕，程序结束\n");
	return 0;
}