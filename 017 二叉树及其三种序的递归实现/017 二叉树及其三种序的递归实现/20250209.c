#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* lchild, * rchild;
}TreeNode, *TreeList;

TreeList InitBTree() {
	TreeList T = (TreeNode*)malloc(sizeof(TreeNode));
	if (!T) {
		return NULL;
	}
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

TreeList CreatBTree(TreeList T) {
	if (!T) {
		return NULL;
	}
	char data = 0;
	scanf("%c", &data);
	if (data == '#') {
		return NULL;
	}
	else {
		T->data = data;
	}
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	T->lchild = CreatBTree(p);
	TreeNode* q = (TreeNode*)malloc(sizeof(TreeNode));
	T->rchild = CreatBTree(q);
	return T;
}

void PreBTreeTraverse(TreeList T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreBTreeTraverse(T->lchild);
	PreBTreeTraverse(T->rchild);
}

void InBTreeTraverse(TreeList T) {
	if (T == NULL) {
		return;
	}
	InBTreeTraverse(T->lchild);
	printf("%c ", T->data);
	InBTreeTraverse(T->rchild);
}

void PostBTreeTraverse(TreeList T) {
	if (!T) {
		return;
	}
	PostBTreeTraverse(T->lchild);
	PostBTreeTraverse(T->rchild);
	printf("%c ", T->data);
}

int main() {
	TreeList T;
	T = InitBTree();
	printf("构造二叉树，请输入:>");
	//637##4##21##9##
	T = CreatBTree(T);
	printf("\n----------------------- 先序遍历二叉树 -----------------------\n");
	PreBTreeTraverse(T);
	printf("\n----------------------- 中序遍历二叉树 -----------------------\n");
	InBTreeTraverse(T);
	printf("\n----------------------- 后序遍历二叉树 -----------------------\n");
	PostBTreeTraverse(T);
	return 0;
}