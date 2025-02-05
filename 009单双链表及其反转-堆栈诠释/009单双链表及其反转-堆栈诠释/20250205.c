#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct ALinkNode {
	Elem data;
	struct ALinkNode* next;
}ALinkNode, *ALinkList;

typedef struct DLinkNode {
	Elem data;
	struct DLinkNode* prior, * next;
}DLinkNode, *DLinkList;

void CreatALinkList(ALinkList AL) {
	ALinkNode* p = AL;
	ALinkNode* q = p;
	printf("输入链表元素，空格间隔，负数表示结束(链表必须有元素):>");
	int a0 = 0;
	do {
		scanf("%d", &a0);
		if (a0 < 0) {
			q->next = NULL;
			return;
		}
		p->data = a0;
		ALinkNode* al = (ALinkNode*)malloc(sizeof(ALinkNode));
		p->next = al;
		q = p;
		p = p->next;
	} while (1);
} //创建单链表

void ALinkListTraverse(ALinkList AL) {
	if (!AL) {
		printf("链表中不含元素\n");
		return;
	}
	ALinkNode* p = AL;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
} //遍历单链表

ALinkList raversalALinkList(ALinkList AL) {
	ALinkNode* p = AL, * head = p;
	ALinkNode* first = (ALinkNode*)malloc(sizeof(ALinkNode));
	first->data = p->data;
	first->next = NULL;
	p = p->next;
	free(head);
	ALinkNode* pp = first;
	while (p) {
		ALinkNode* tmp = (ALinkNode*)malloc(sizeof(ALinkNode));
		tmp->data = p->data;
		tmp->next = pp;
		pp = tmp;
		head = p;
		p = p->next;
		free(head);
	}
	return pp;
} //反转单链表 -> 方法一：重复复制链表

ALinkList RaversalALinkList(ALinkList AL) {
	ALinkList next = NULL;
	ALinkList pre = NULL;
	while (AL) {
		next = AL->next;
		AL->next = pre;
		pre = AL;
		AL = next;
	}
	return pre;
} //反转单链表 -> 方法二：不使用辅助空间

int main() {
	ALinkList AL;
	AL = (ALinkList)malloc(sizeof(ALinkNode));
	if (!AL) {
		return -1;
	}
	CreatALinkList(AL);
	ALinkListTraverse(AL);
	ALinkList p = raversalALinkList(AL);
	ALinkListTraverse(p);
	AL = NULL;
	ALinkListTraverse(AL);

	printf("\n\n-------------------------另一种方法----------------------------\n");
	ALinkList AL2;
	AL2 = (ALinkList)malloc(sizeof(ALinkNode));
	if (!AL2) {
		return -1;
	}
	CreatALinkList(AL2);
	ALinkListTraverse(AL2);
	ALinkList p2 = raversalALinkList(AL2);
	ALinkListTraverse(p2);
	AL2 = NULL;
	ALinkListTraverse(AL2);


	return 0;
}