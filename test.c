#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkList;

//创建循环链表
int InitCList(LinkList* L) {
	L = (LinkList*)malloc(sizeof(LinkList));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

//判断循环链表是否为空
int isempty(LinkList* L) {
	if (L->next == L)
		return true;
	else
		return false;
}

//插入结点
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

//删除结点
int DelCList(LinkList* L, int i) {
	int j;
	LinkList* t1, * t2;
	j = 1;
	t1 = L->next;
	t2 = L;
	while (j < i && t1 != L) {
		j++;
		t1 = t1->next;
		t2 = t2->next;
	}
	if (j > i)
		return false;
	t2->next = t1->next;
	free(1);

	return true;
}