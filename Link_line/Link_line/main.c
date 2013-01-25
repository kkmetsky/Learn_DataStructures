//
//  main.c
//  Link_line
//
//  Created by liu yao-chun on 13/1/24.
//  Copyright (c) 2013年 liu yao-chun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1;
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

Status visit(ElemType C)
{
	printf("%d",C);
	return OK;
}

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList;

Status InitList (LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	if (!(*L))
	{
		return ERROR;
	}
	(*L)->next=NULL;
	return OK;
}

Status ListInsert(LinkList *L,int i, ElemType e)
{
	int j=1;
	LinkList p=(*L),s;
	if (!p || j>i) {
		return ERROR;
	}
	while (p && j<i) {
		p=p->next;
		++j;
	}
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListTraverse (LinkList L)
{
	LinkList p=L->next;
	while (p) {
		visit(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

Status ClearList (LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while (p) {
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;
	return OK;
}

Status ListLength (LinkList L)
{
	int i=0;
	LinkList p=L->next;
	while (p) {
		i++;
		p=p->next;
	}
	return i;
}

Status ListDelete (LinkList *L,int i,ElemType *e)
{
	int j=1;
	LinkList p=(*L),q;
	if (!(p->next) || j>i) {
		return ERROR;
	}
	while (p->next && j<i) {
		p=p->next;
		++j;
	}
	
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}
Status GetElem (LinkList L,int i,ElemType *e	){
	int j=1;
	LinkList p=L->next;
	if(!p || j>i)
		return ERROR;
	while (p && j<i) {
		p=p->next;
		j++;
	}
	*e = p->data;
	return OK;
};

Status LocateElem (LinkList L, ElemType e)
{
	int i=0;
	LinkList p=L->next;
	while (p) {
		i++;
		if(p->data==e)
			return i;
		p=p->next;
	}
	return 0;
}

void CreatListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;
	srand((unsigned)time(NULL));
	*L=(LinkList)malloc(sizeof(Node));
	r=(*L);
	
	for (i=0; i<n; i++) {
		p= (Node *)malloc(sizeof(Node));
		p->data = rand()%100/+1;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	
}

void CreatListHead (LinkList *L,int n)
{
	LinkList p;
	int i;
	srand((unsigned)time(NULL));
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for (i=0; i<n; i++) {
		p=	(LinkList)malloc(sizeof(Node));
		p->data =rand()%10+1;
		p->next=(*L)->next;
		(*L)->next=p;
	}
}

int main(int argc, const char * argv[])
{
	LinkList L;
	ElemType e;
	Status i;
	int j;
	
	i=InitList(&L);
	for (j=0; j<=5; j++) {
		i=ListInsert(&L,1,j);
	}
	ListTraverse(L);
	printf("%d\n",ListLength(L));
	i=4;
	ListDelete(&L, i,&e);
	printf("remove the %d value:%d\n",i,e);
	
	GetElem(L,4,&e);
	printf("five elem:%d\n",e);
	
	i=LocateElem(L,1);
	printf("it's locate at:%d\n",i);
	
//	ClearList(&L);
	ListTraverse(L);
	
//	CreatListTail(&L,6);
	CreatListHead(&L,8);
	ListTraverse(L);
	
    return 0;
}

