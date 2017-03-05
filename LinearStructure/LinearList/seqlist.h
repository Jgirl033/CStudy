/*
 * seqlist.h
 *
 *  Created on: 2017��3��4��
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#ifndef SEQLIST_H_
#define SEQLIST_H_

typedef struct {
	int Data[MAXSIZE];
	int Last;
} SeqList;

SeqList * MakeEmptySeqList() {
	SeqList * PtrL;
	PtrL = (SeqList * )malloc(sizeof(SeqList));
	PtrL -> Last = -1;//��ʼ�����Ա�Ϊ��
	return PtrL;
}

void InsertIntoSeqList(SeqList * PtrL, int index, int x) {
	int j;
	if(PtrL -> Last == MAXSIZE-1) {
		printf("%s","��������");
		return;
	}
	if(index<0||index>MAXSIZE-1) {
		printf("%s","����λ�ò��Ϸ�");
	}
	for(j=PtrL->Last+1; j>index; j--) {
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL ->Data[index] =x;
	PtrL ->Last = PtrL ->Last+1;
	return;
}

int FindValueInSeqList(SeqList * PtrL, int x) {
	int i;
	if(PtrL ->Last==-1) {
		printf("%s\n","��Ϊ��");
		return -1;
	}
	for(i=0; i<=PtrL ->Last; i++) {
		if(PtrL ->Data[i]==x) {
			return i;
		}
	}
	printf("%s\n","�Ҳ���Ԫ��");
	return -1;
}

void DeleteEleInSeqList(SeqList * PtrL, int index) {
	int j;
	for(j=index; j<=PtrL->Last; j++) {
		PtrL ->Data[j-1] = PtrL ->Data[j];
	}
	PtrL ->Last--;
}


#endif /* SEQLIST_H_ */
