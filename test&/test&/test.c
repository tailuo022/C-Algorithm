#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSSIZE 100

typedef char TElem, Elem; // ���ڵ����Ϣ����������

typedef struct BiNode {
	TElem data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree; //�������ڵ�Ķ���

typedef struct {
	BiNode* top;
	BiNode* base;
	int stackSize;
}Stack; //ջ�Ķ���


void InitStack(Stack* S) {
	S->base = (BiNode*)malloc(sizeof(BiNode) * MAXSSIZE);
	if (!S) {
		printf("ջ����ʧ��\n");
		return;
	}
	S->top = S->base;
	S->stackSize = MAXSSIZE;
} //ջ�ĳ�ʼ��

void Push(Stack* S, BiNode* T) {
	if (S->top - S->base == S->stackSize) {
		printf("ջ��\n");
		return;
	}
	S->top = T;
	(S->top)++;
} //��ջ

void Pop(Stack* S, BiNode** T) {
	if (S->base == S->top) {
		printf("ջ��\n");
		return;
	}
	*T = S->top - 1;
	(S->top)--;
} //��ջ

void Peek(Stack* S, BiNode** T) {
	if (S->base == S->top) {
		printf("ջ��\n");
		return;
	}
	*T = (S->top - 1);
} //ȡ��ջ��

int StackEmpty(Stack* S) {
	if (S->top == S->base) {
		return 1;
	}
	else {
		return 0;
	}
} //�ж�ջ��

void InitBiTree(BiTree T) {
	if (!T) {
		return;
	}
	T->lchild = T->rchild = NULL;
} //��ʼ��������

BiNode* CreatBiTree(BiTree T) {
	if (!T) {
		return NULL;
	}
	char ch = 0;
	//printf("������ڵ���Ϣ��Ϊ����ʱ���ؿ�ָ��:>");
	scanf("%c", &ch);
	if (ch != '#') {
		T->data = ch;
	}
	else {
		return NULL;
	}
	//printf("����%d������\n", T->data);
	BiNode* p = (BiNode*)malloc(sizeof(BiNode));
	T->lchild = CreatBiTree(p);
	//printf("����%d���Һ���\n", T->data);
	BiNode* q = (BiNode*)malloc(sizeof(BiNode));
	T->rchild = CreatBiTree(q);
	return T;
} //����������

void PostOrderTraverseByStack1(BiTree T) {
	BiNode* h = T;
	if (T) {
		Stack S; InitStack(&S);
		Push(&S, h);
		while (!StackEmpty(&S)) {
			BiNode* p = (BiNode*)malloc(sizeof(BiNode));
			Peek(&S, &p);
			if (p->lchild != NULL && h != p->lchild && h != p->rchild) {
				Push(&S, p->lchild);
			}
			else if (p->rchild != NULL && h != p->rchild) {
				Push(&S, p->rchild);
			}
			else {
				printf("%c ", p->data);
				Pop(&S, &h);
			}
		}
	}
	else {
		return;
	}
} //��������ǵݹ��㷨(һ��ջ)
int main() {
	BiTree T;
	T = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(T);
	printf("�������Ľṹ��#��ʾ��:>");
	//642##1##57##8##
	T = CreatBiTree(T);
	printf("\n--------��������ǵݹ��㷨(һ��ջ)----------\n");
	PostOrderTraverseByStack1(T);
	return 0;
}
