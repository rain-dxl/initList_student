#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OVERFLOW  -1	//用于错误退出系统
#define OK 1			//用于返回函数执行是否成功
#define ERROR 0			//返回错误

typedef int Status;

typedef struct LNode
{
	 char name[10];
	 char XH[10];
	 int CJ;
	 struct LNode *next;
}LNode,*LinkList;		//节点信息

//初始化链表
Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	if(!(L->next))
		printf("\n初始化成功！\n");
	else
	{
		printf("\n初始化失败!!!\n");
		exit(OVERFLOW);
	}

	return OK;
}

//添加输入学生数据
Status addStudent(LinkList &L)
{
	LinkList p=L;
	int N,n=0;
	printf("\n请输入需要添加的学生信息个数：\n");
	scanf("%d",&n);
	N=n;				//用于显示添加学生位数
	while(p->next)
		p=p->next;
	while(n>0)
	{
		LinkList s;
		s=new LNode;
		s->next=NULL;
		printf("\n--当前添加第%d位同学--\n",N+1-n);
		printf("\n输入该学生姓名："); scanf("%s",s->name);
		printf("\n输入该学生学号："); scanf("%s",s->XH);
		printf("\n输入该学生成绩："); scanf("%d",&s->CJ);
		//printf("成绩输入成功！\n");
		p->next=s;
		//printf("节点添加成功!\n");
		p=p->next;
		//printf("为下个节点做准备\n");
		n--;
	}
	return OK;
}

Status Insert(LinkList &L)
{
	LinkList p=L;
	LinkList s;
	s=new LNode;
	int i,j=0;
	printf("\n输入需要插入的位置：");
	scanf("%d",&i);
	while(p&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1) return ERROR;
	printf("\n输入该学生姓名："); scanf("%s",s->name);
	printf("\n输入该学生学号："); scanf("%s",s->XH);
	printf("\n输入该学生成绩："); scanf("%d",&s->CJ);
	s->next=p->next;
	p->next=s;
	return OK;
}

Status LocateElem(LinkList &L)
{
	LinkList p=L;
	char xm[10];
	int i=1;
	printf("\n输入同学姓名："); scanf("%s",&xm);
	while(p)
	{
		p=p->next;
		if(strcmp(p->name,xm)==0)
		{
			printf("\n该同学在第%d位！\n",i);
			break;
		}
		i++;
	}
	return OK;
}

Status ListDelete(LinkList &L)
{
	int i,j=0;
	LinkList p=L;
	printf("\n输入需要删除的序号:\n");
	scanf("%d",&i);
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1))
	{
		printf("输入数据有误！");
		return ERROR;
	}
	printf("\n正在删除！\n");
	p->next=p->next->next;
	printf("\n删除成功！\n");
	return OK;
}

void print(LinkList &L)
{
	LinkList p=L;
	int n=1;
	while(p=p->next)
	{
		printf("%d:%s\t%s\t%d\n",n,p->name,p->XH,p->CJ);
		n++;
	}
}

void main(void)
{
	LinkList L;
	InitList(L);
	printf("表格已初始化!\n**************rain的学生数据结构成绩系统*************\n");
	printf("功能0：退出系统\n");
	printf("功能1：添加学生信息\n");
	printf("功能2：插入学生信息\n");
	printf("功能3：删除学生信息\n");
	printf("功能4：查找学生信息\n");
	printf("功能5：统计当前表格学生信息\n\n");
	int choose;
	while(1)
	{
		printf("请输入你要选择的功能序号：");
		scanf("%d",&choose);
		if(choose==0) break;
		if(choose==1) addStudent(L);	//初次输入
		if(choose==2) Insert(L);		//插入数据
		if(choose==3) ListDelete(L);	//删除数据
		if(choose==4) LocateElem(L);	//查找信息
		if(choose==5) print(L);			//查看当前表

	}
}
