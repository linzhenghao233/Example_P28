#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkList;

//����ѭ������
int InitCList(LinkList* L) {
	L = (LinkList*)malloc(sizeof(LinkList));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

//�ж�ѭ�������Ƿ�Ϊ��
int isempty(LinkList* L) {
	if (L->next == L)
		return true;
	else
		return false;
}

//������
int InsertCList(LinkList* L, int i, ElemType e) {
	int j;
	LinkList* temp, * node;
	temp = L->next;
	j = 1;

	while (j < i && temp != L) {
		j++;
		temp = temp->next;
	}
	if (j < i && temp->next == L)
		return false;
	node = (LinkList*)malloc(sizeof(LinkList));
	if (node == NULL)
		return false;
	node->next = temp->next;
	temp->next = node;

	return true;
}