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
	printf("��������Ԫ�أ��ո�����������ʾ����(���������Ԫ��):>");
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
} //����������

void ALinkListTraverse(ALinkList AL) {
	if (!AL) {
		printf("�����в���Ԫ��\n");
		return;
	}
	ALinkNode* p = AL;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
} //����������

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
} //��ת������ -> ����һ���ظ���������

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
} //��ת������ -> ����������ʹ�ø����ռ�

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

	printf("\n\n-------------------------��һ�ַ���----------------------------\n");
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