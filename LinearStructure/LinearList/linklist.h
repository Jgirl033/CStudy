/*
 * linklist.h
 *
 *  Created on: 2017年3月4日
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct Node {
	int Data;
	struct Node * Next;
} LinkList;

LinkList * MakeEmptyLinkList() {
	LinkList * p = (LinkList *)malloc(sizeof(LinkList));
	p->Next=NULL;
	return p;
}

int LengthOfLinkList(LinkList * L) {
	int count=0;
	LinkList * p=L->Next;
	while(p) {
		count++;
		p=p->Next;
	}
	return count;
}

LinkList * FindKthOfLinkList(LinkList * L,int index) {

	int count=0;
	LinkList * p = L;
	while(p) {
		count++;
		if(count==index) {
			return p;
		}
		p = p->Next;
	}
	return p;
}

LinkList * FindValueInLinkList(LinkList * L,int x) {
	LinkList * p = L;
	while(p&&p->Data!=x) {
		p=p->Next;
	}
	return p;
}

LinkList * InsertIntoLinkList(LinkList * L,int index, int x){
	LinkList * p, *s;
	if(index==1){
		s = (LinkList *)malloc(sizeof(LinkList));
		s->Data=x;
		s->Next=L->Next;
		L->Next = s;
		return s;
	}

	p=FindKthOfLinkList(L,index-1);
	if(p==NULL){
		printf("%s","参数index错误");
		return NULL;
	}else{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->Data=x;
		s->Next=p->Next;
		p->Next=s;
		return L;
	}
}

LinkList * DeleteEleInLinkList(LinkList * L, int index){
	LinkList * p, *s;
	if(index ==1){
		s = L->Next;
		L->Next = s->Next;
		free(s);
		return L;
	}

	p = FindKthOfLinkList(L,index-1);
	if(p==NULL){
		printf("第%d个结点不存在",index-1);
		fflush(stdout);
		return NULL;
	}else if(p->Next==NULL){
		printf("第%d个结点不存在",index);
		fflush(stdout);
		return NULL;
	}else{
		s = p->Next;
		p->Next=NULL;
		free(s);
		return L;
	}
}


#endif /* LINKLIST_H_ */
