//
//  main.c
//  1-0
//
//  Created by liu yao-chun on 13/1/22.
//  Copyright (c) 2013年 liu yao-chun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Header.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;


typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}sqList;


Status visit (ElemType c)
{
	printf("%d",c);
	return OK;
}

Status InitList (sqList *L)
{
	L->length=0;
	return OK;
}

Status ListEmpt (sqList *L)
{
	if(L->length==0)
		return TRUE;
	else
		return FLASE;
}

Status ClearList (sqList *L)
{
	L->length=0;
	return OK;
}

int ListLength(sqList L)
{
	return L.length;
}

Status GetElem(sqList L,int i,ElemType *e)
{
	if (L.length==0 || i<1 || i>L.length)
	{
		return ERROR;
	}
	*e=L.data[i-1];
	
	return OK;
}

int LocateElem(sqList L,ElemType e)
{
	int i;
	if(L.length==0)
		return 0;
	for (i=0; i<L.length; i++) {
		if(L.data[i]==e)
			break;
	}
	if (i>=L.length) {
		return 0;
	}
	return i+1;
}

Status ListInsert(sqList *L,int i,ElemType e)
{
	int k;
	if ((L->length==MAXFLOAT)|| i<1 || i>L->length+1) {
		return ERROR;
	}
	if (i<=L->length) {
		for (k=L->length-1; k>=i-1; k--) {
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}

Status ListDelete(sqList *L,int i ,ElemType *e)
{
	int k;
	if((L->length==0)||(i<1)||(i>L->length))
	{
		return ERROR;
	}
	*e=L->data[i-1];
	if (i<L->length)
	{
		for (k=1; k<L->length; k++)
		{
			L->data[k-1]=L->data[k];
		}
	}
	L->length--;
	return OK;
}

Status ListTraverse (sqList L)
{
	int i;
	for (i=0; i< L.length ;i++) {
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}

void unionL(sqList *La,sqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;
	
	La_len =ListLength(*La);
	Lb_len =ListLength(Lb);
	
	for (i=1; i< Lb_len;i++) {
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e))
		{
			ListInsert(La,++La_len,e);
		}
	}
}

int main ()
{
	sqList L;
	ElemType e;
	Status i;
	int j,k;
	
	i=InitList(&L);
	
	printf("[init]L.length=%d\n",L.length);
	for (j=1; j<=5; j++) {
		i=ListInsert(&L, 1, j);
	}
	printf("[insert]L.data=");
	ListTraverse(L);
	
	printf("L.length=%d\n",L.length);
	
	i=ListEmpt(&L);
	printf("is L empty:%d\n",i);
	
	i=ClearList(&L);
	printf("[clear]L.length=%d\n",L.length);
	
	i=ListEmpt(&L);
	printf("is L empty:%d\n",i);
	
	//---------------------------
	for(j=1;j<=10;j++)
		ListInsert(&L,j,j);
    printf("在L的表尾依次插入1∼10後：L.data=");
    ListTraverse(L);
	
    printf("L.length=%d \n",L.length);
	
    ListInsert(&L,1,0);
    printf("在L的表頭插入0後：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);
	
    GetElem(L,5,&e);
    printf("第5個元素的值為：%d\n",e);
    for(j=3;j<=4;j++)
    {
		k=LocateElem(L,j);
		if(k)
			printf("第%d個元素的值為%d\n",k,j);
		else
			printf("沒有值為%d的元素\n",j);
    }
    
	
    k=ListLength(L); /* k為表長 */
    for(j=k+1;j>=k;j--)
    {
		i=ListDelete(&L,j,&e); /* 刪除第j個資料 */
		if(i==ERROR)
			printf("刪除第%d個資料失敗\n",j);
		else
			printf("刪除第%d個的元素值為：%d\n",j,e);
    }
    printf("依次輸出L的元素：");
    ListTraverse(L);
	
    j=5;
    ListDelete(&L,j,&e); /* 刪除第5個資料 */
    printf("刪除第%d個的元素值為：%d\n",j,e);
	
    printf("依次輸出L的元素：");
    ListTraverse(L);
	
	//構造一個有10個數的Lb
	sqList Lb;
    i=InitList(&Lb);
    for(j=6;j<=15;j++)
		i=ListInsert(&Lb,1,j);
	
    unionL(&L,Lb);
    printf("依次輸出合併了Lb的L的元素：");
    ListTraverse(L);
    return 0;
}