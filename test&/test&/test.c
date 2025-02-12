#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSSIZE 100

typedef char TElem, Elem; // 树节点的信息的数据类型

typedef struct BiNode {
	TElem data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree; //二叉树节点的定义

typedef struct {
	BiNode* top;
	BiNode* base;
	int stackSize;
}Stack; //栈的定义


void InitStack(Stack* S) {
	S->base = (BiNode*)malloc(sizeof(BiNode) * MAXSSIZE);
	if (!S) {
		printf("栈创建失败\n");
		return;
	}
	S->top = S->base;
	S->stackSize = MAXSSIZE;
} //栈的初始化

void Push(Stack* S, BiNode* T) {
	if (S->top - S->base == S->stackSize) {
		printf("栈满\n");
		return;
	}
	S->top = T;
	(S->top)++;
} //入栈

void Pop(Stack* S, BiNode** T) {
	if (S->base == S->top) {
		printf("栈空\n");
		return;
	}
	*T = S->top - 1;
	(S->top)--;
} //出栈

void Peek(Stack* S, BiNode** T) {
	if (S->base == S->top) {
		printf("栈空\n");
		return;
	}
	*T = (S->top - 1);
} //取出栈顶

int StackEmpty(Stack* S) {
	if (S->top == S->base) {
		return 1;
	}
	else {
		return 0;
	}
} //判断栈空

void InitBiTree(BiTree T) {
	if (!T) {
		return;
	}
	T->lchild = T->rchild = NULL;
} //初始化二叉树

BiNode* CreatBiTree(BiTree T) {
	if (!T) {
		return NULL;
	}
	char ch = 0;
	//printf("请输入节点信息，为负数时返回空指针:>");
	scanf("%c", &ch);
	if (ch != '#') {
		T->data = ch;
	}
	else {
		return NULL;
	}
	//printf("进入%d的左孩子\n", T->data);
	BiNode* p = (BiNode*)malloc(sizeof(BiNode));
	T->lchild = CreatBiTree(p);
	//printf("进入%d的右孩子\n", T->data);
	BiNode* q = (BiNode*)malloc(sizeof(BiNode));
	T->rchild = CreatBiTree(q);
	return T;
} //创建二叉树

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
} //后序遍历非递归算法(一个栈)
int main() {
	BiTree T;
	T = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(T);
	printf("输入数的结构，#表示空:>");
	//642##1##57##8##
	T = CreatBiTree(T);
	printf("\n--------后序遍历非递归算法(一个栈)----------\n");
	PostOrderTraverseByStack1(T);
	return 0;
}
