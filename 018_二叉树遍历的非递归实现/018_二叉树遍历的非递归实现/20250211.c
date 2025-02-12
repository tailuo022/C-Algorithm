#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define arrSize 15
#define arrMAX 10
#define testTime 2500
#define StackSize 100
#define QueueSize 100

typedef struct BiTree {
	char data;
	struct BiTree* left, * right;
}BiTreeNode, * BiTree; //二叉树结点定义

typedef struct Stack {
	BiTreeNode** num;
	int top, base;
}Stack; // 栈的定义

typedef struct Queue {
	BiTreeNode** num;
	int base, top;
}Queue; // 队列的定义

void InitStack(Stack* S) {
	if (!S) {
		return;
	}
	S->num = (BiTreeNode*)malloc(sizeof(BiTreeNode) * StackSize);
	S->base = S->top = 0;
} //栈的初始化

void Push(Stack* S, BiTreeNode* p) {
	if (StackSize == S->top) {
		return;
	}
	S->num[(S->top)++] = p;
} // 入栈

BiTreeNode* Pop(Stack* S) {
	if (S->top == S->base) {
		return NULL;
	}
	return S->num[--(S->top)];
} // 出栈

int StackEmpty(Stack* S) {
	if (S->base == S->top) {
		return 1;
	}
	return 0;
} // 判断栈空

void InitQueue(Queue* Q) {
	if (!Q) {
		return;
	}
	Q->num = (BiTreeNode*)malloc(sizeof(BiTreeNode) * QueueSize);
	if (!Q->num) {
		return;
	}
	Q->base = Q->top = 0;
} // 初始化队列

int QueueEmpty(Queue* Q) {
	if (Q->base == Q->top) {
		return 1;
	}
	return 0;
} // 判断队空

void EnQueue(Queue* Q, BiTreeNode* T) {
	if ((Q->top + 1) % QueueSize == Q->base) {
		return;
	}
	Q->num[Q->top] = T;
	Q->top = (Q->top + 1) % QueueSize;
} // 入队

BiTreeNode* DeQueue(Queue* Q) {
	if (QueueEmpty(Q)) {
		return NULL;
	}
	int i = Q->base;
	Q->base = (Q->base + 1) % QueueSize;
	return &Q->num[i];
} // 出队

void InitBiTree(BiTree T) {
	if (!T) {
		return;
	}
	T->left = T->right = NULL;
} // 初始化二叉树

BiTree CreatBiTree(BiTree T, char* arr, int* num) {
	if (!T) {
		return NULL;
	}
	Queue Q;
	InitQueue(&Q);
	EnQueue(&Q, T);
	while (!QueueEmpty(&Q)) {
		BiTreeNode* p = DeQueue(&Q);
		char ch = arr[(*num)++];
		if (ch != '#') {
 			p->data = ch;
			BiTreeNode* p1 = (BiTreeNode*)malloc(sizeof(BiTreeNode));
			if (!p1) {
				return NULL;
			}
			BiTreeNode* p2 = (BiTreeNode*)malloc(sizeof(BiTreeNode));
			if (!p2) {
				return NULL;
			}
			p->left = p1;
			p->right = p2;
			EnQueue(&Q, p1);
			EnQueue(&Q, p2);
		}
		else {
			p = NULL;
		}
	}
	return T;
} // 层次遍历思想建立二叉树

char* CopyArray(char arr[], int size) {
	char* copyarr = (int*)malloc(sizeof(char));
	for (int i = 0; i < size; i++) {
		copyarr[i] = arr[i];
	}
	return copyarr;
} // 复制数组

//void PreOrderTraverse(BiTree T, char* copyarr, int* num) {
//	if (!T) {
//		(*num)++;
//		return;
//	}
//	if (*num < arrSize) {
//		copyarr[(*num)++] = T->data;
//		PreOrderTraverse(T->left, copyarr, num);
//		PreOrderTraverse(T->right, copyarr, num);
//	}
//} // 先序遍历二叉树

void Traverse(BiTree T) {
	if (!T) {
		return;
	}
	printf("%c ", T->data);
	Traverse(T->left);
	Traverse(T->right);
}

void LevelTraverse(BiTree T) {
	Queue Q; InitQueue(&Q);  
	BiTreeNode* p = T;
	EnQueue(&Q, p);
	while (!QueueEmpty(&Q)) {
		BiTreeNode* q = DeQueue(&Q);
		printf("%c ", q->data);
 		if (q->left) {
			EnQueue(&Q, q->right);
		}
		if (q->right) {
			EnQueue(&Q, q->right);
		}
	}
} //层次遍历二叉树

void InOrderTraverse(BiTree T) {
	if (!T) {
		return;
	}
	InOrderTraverse(T->left);
	printf("%c ", T->data);
	InOrderTraverse(T->right);
} // 中序遍历二叉树

void PostOrderTraverse(BiTree T) {
	if (!T) {
		return;
	}
	PostOrderTraverse(T->left);
	PostOrderTraverse(T->right);
	printf("%c ", T->data);
} // 后序遍历二叉树

int main() {
	BiTree T = (BiTree)malloc(sizeof(BiTreeNode));
	InitBiTree(T);
	printf("构造二叉树，请输入:>");
	srand((unsigned)time(NULL));

	printf("\n-------------两种先序遍历的比较---------------------\n");
	printf("开始测试\n");
//	Sleep(2000);
	//for (int i = 0; i < testTime; i++) {
		char* arr = (char*)malloc(sizeof(char));
	for (int j = 0; j < 15; j++) { // 创建数组(生成树序列)
		if (j < 7 ? 1 : 0) {
			arr[j] = rand() % arrMAX + '0';
		}
		else {
			arr[j] = '#';
		}
	}
	for (int i = 0; i < arrSize; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	int num = 0;
	T = CreatBiTree(T, arr, &num);
	//LevelTraverse(T);
	Traverse(T);
	printf("\n");


	num = 0;
	char* arr1 = (char*)malloc(sizeof(char) * arrSize);
	//PreOrderTraverse(T, arr1, &num);
	for (int i = 0; i < arrSize; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < arrSize; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
	//}

	//printf("\n-------------------------中序遍历二叉树-------------------------\n");
	//InOrderTraverse(T);
	//printf("\n-------------------------后序遍历二叉树-------------------------\n");
	//PostOrderTraverse(T);
	return 0;
}