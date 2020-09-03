#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OVERFLOW  -1	//���ڴ����˳�ϵͳ
#define OK 1			//���ڷ��غ���ִ���Ƿ�ɹ�
#define ERROR 0			//���ش���

typedef int Status;

typedef struct LNode
{
	 char name[10];
	 char XH[10];
	 int CJ;
	 struct LNode *next;
}LNode,*LinkList;		//�ڵ���Ϣ

//��ʼ������
Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	if(!(L->next))
		printf("\n��ʼ���ɹ���\n");
	else
	{
		printf("\n��ʼ��ʧ��!!!\n");
		exit(OVERFLOW);
	}

	return OK;
}

//�������ѧ������
Status addStudent(LinkList &L)
{
	LinkList p=L;
	int N,n=0;
	printf("\n��������Ҫ��ӵ�ѧ����Ϣ������\n");
	scanf("%d",&n);
	N=n;				//������ʾ���ѧ��λ��
	while(p->next)
		p=p->next;
	while(n>0)
	{
		LinkList s;
		s=new LNode;
		s->next=NULL;
		printf("\n--��ǰ��ӵ�%dλͬѧ--\n",N+1-n);
		printf("\n�����ѧ��������"); scanf("%s",s->name);
		printf("\n�����ѧ��ѧ�ţ�"); scanf("%s",s->XH);
		printf("\n�����ѧ���ɼ���"); scanf("%d",&s->CJ);
		//printf("�ɼ�����ɹ���\n");
		p->next=s;
		//printf("�ڵ���ӳɹ�!\n");
		p=p->next;
		//printf("Ϊ�¸��ڵ���׼��\n");
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
	printf("\n������Ҫ�����λ�ã�");
	scanf("%d",&i);
	while(p&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1) return ERROR;
	printf("\n�����ѧ��������"); scanf("%s",s->name);
	printf("\n�����ѧ��ѧ�ţ�"); scanf("%s",s->XH);
	printf("\n�����ѧ���ɼ���"); scanf("%d",&s->CJ);
	s->next=p->next;
	p->next=s;
	return OK;
}

Status LocateElem(LinkList &L)
{
	LinkList p=L;
	char xm[10];
	int i=1;
	printf("\n����ͬѧ������"); scanf("%s",&xm);
	while(p)
	{
		p=p->next;
		if(strcmp(p->name,xm)==0)
		{
			printf("\n��ͬѧ�ڵ�%dλ��\n",i);
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
	printf("\n������Ҫɾ�������:\n");
	scanf("%d",&i);
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1))
	{
		printf("������������");
		return ERROR;
	}
	printf("\n����ɾ����\n");
	p->next=p->next->next;
	printf("\nɾ���ɹ���\n");
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
	printf("����ѳ�ʼ��!\n**************rain��ѧ�����ݽṹ�ɼ�ϵͳ*************\n");
	printf("����0���˳�ϵͳ\n");
	printf("����1�����ѧ����Ϣ\n");
	printf("����2������ѧ����Ϣ\n");
	printf("����3��ɾ��ѧ����Ϣ\n");
	printf("����4������ѧ����Ϣ\n");
	printf("����5��ͳ�Ƶ�ǰ���ѧ����Ϣ\n\n");
	int choose;
	while(1)
	{
		printf("��������Ҫѡ��Ĺ�����ţ�");
		scanf("%d",&choose);
		if(choose==0) break;
		if(choose==1) addStudent(L);	//��������
		if(choose==2) Insert(L);		//��������
		if(choose==3) ListDelete(L);	//ɾ������
		if(choose==4) LocateElem(L);	//������Ϣ
		if(choose==5) print(L);			//�鿴��ǰ��

	}
}
