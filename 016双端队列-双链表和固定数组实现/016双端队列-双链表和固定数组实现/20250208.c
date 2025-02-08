#define  _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdlib.h>

// ---------------------------------- ˼·һ��˫������ -------------------------------------

typedef struct Node {
	int data;
	struct Node* prior, * next;
}LNode; //�ڵ㹹��

typedef struct {
	LNode* node;
	LNode* head, * tail;
	int count;
	int maxsum;
} MyCircularDeque; //˫�˶��й���

MyCircularDeque* myCircularDequeCreate(int k) {
	MyCircularDeque* L = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
	L->node = (LNode*)malloc(sizeof(LNode)); // ���ٿռ�
	L->node->next = NULL;
	L->node->prior = NULL;
	L->head = L->tail = L->node;
	L->count = 0;
	L->maxsum = k;
	return L;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
	if (obj->count == obj->maxsum) {
		return false;
	}
	if (obj->head->next == NULL) { // ��һ��Ԫ�صĵĴ洢
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node->data = value;
		obj->head->next = node;
		node->prior = obj->head;
		node->next = NULL;
		obj->tail = node;
		obj->count++;
	}
	else {
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node->data = value;
		node->next = obj->head->next;
		obj->head->next = node;
		node->next->prior = node;
		node->prior = obj->head;
		obj->count++;
	}
	return true;
} //��һ��Ԫ����ӵ�˫�˶���ͷ����

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
	if (obj->count == obj->maxsum) {
		return false;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->data = value;
	node->next = NULL;
	obj->tail->next = node;
	node->prior = obj->tail;
	obj->tail = node;
	obj->count++;
	return true;
} //��һ��Ԫ����ӵ�˫�˶���β����

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
	if (obj->count == 0) {
		return false;
	}
	if (obj->count == 1) { // ��һ��Ԫ�ص�ɾ��
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node = obj->head->next;
		obj->tail = obj->head;
		obj->head->next = NULL;
		obj->count--;
		free(node);
	}
	else {
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node = obj->head->next;
		obj->head->next = node->next;
		node->next->prior = obj->head;
		free(node);
		obj->count--;
	}
	return true;
} //��˫�˶���ͷ��ɾ��һ��Ԫ�ء�

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
	if (obj->count == 0) {
		return false;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node = obj->tail;
	obj->tail = node->prior;
	obj->tail->next = NULL;
	free(node);
	obj->count--;
	return true;
} //��˫�˶���β��ɾ��һ��Ԫ�ء�

int myCircularDequeGetFront(MyCircularDeque* obj) {
	if (obj->count == 0) {
		return -1;
	}
	return obj->head->next->data;
} //��˫�˶���ͷ�����һ��Ԫ�ء�

int myCircularDequeGetRear(MyCircularDeque* obj) {
	if (obj->count == 0) {
		return -1;
	}
	return obj->tail->data;
} //���˫�˶��е����һ��Ԫ�ء�

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
	if (obj->count == 0) {
		return true;
	}
	return false;
} //˫�˶���Ϊ��

bool myCircularDequeIsFull(MyCircularDeque* obj) {
	if (obj->count == obj->maxsum) {
		return true;
	}
	return false;
} //˫�˶�����

void myCircularDequeFree(MyCircularDeque* obj) {
	obj->count = 0;
	obj->maxsum = 0;
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node = obj->head->next;
	obj->head = obj->tail;
	obj->head->next = NULL;
	obj->head->prior = NULL;
	while (node) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		p = node->next;
		free(node);
		node = p;
	}
} //˫�˶��е�����

// ---------------------------------- ˼·����ѭ������ -------------------------------------
typedef struct {
	int* arr;
	int l, r, size;
	int max;
} MyCircularDeque2; // ѭ�����н��


MyCircularDeque2* myCircularDequeCreate(int k) {
	MyCircularDeque2* L = (MyCircularDeque2*)malloc(sizeof(MyCircularDeque2));
	L->arr = (int*)malloc(sizeof(int) * k);
	L->l = 0;
	L->r = 0;
	L->size = 0;
	L->max = k;
	return L;
} // ���캯��,˫�˶������Ϊ k ��

bool myCircularDequeInsertFront(MyCircularDeque2* obj, int value) {
	if (obj->size == obj->max) {
		return false;
	}
	if (obj->size == 0) {
		obj->l = obj->r = 0;
		obj->arr[0] = value;
	}
	else {
		obj->l = obj->l == 0 ? (obj->max - 1) : obj->l - 1;
		obj->arr[obj->l] = value;
	}
	obj->size++;
	return true;
} // ��һ��Ԫ����ӵ�˫�˶���ͷ����

bool myCircularDequeInsertLast(MyCircularDeque2* obj, int value) {
	if (obj->size == obj->max) {
		return false;
	}
	if (obj->size == 0) {
		obj->l = obj->r = 0;
		obj->arr[0] = value;
	}
	else {
		obj->r = obj->r == (obj->max - 1) ? 0 : obj->r + 1;
		obj->arr[obj->r] = value;
	}
	obj->size++;
	return true;
} // ��һ��Ԫ����ӵ�˫�˶���β����

bool myCircularDequeDeleteFront(MyCircularDeque2* obj) {
	if (obj->size == 0) {
		return false;
	}
	obj->l = obj->l == (obj->max - 1) ? 0 : obj->l + 1;
	obj->size--;
	return true;
} // ��˫�˶���ͷ��ɾ��һ��Ԫ�ء�

bool myCircularDequeDeleteLast(MyCircularDeque2* obj) {
	if (0 == obj->size) {
		return false;
	}
	obj->r = obj->r == 0 ? obj->max - 1 : obj->r - 1;
	obj->size--;
	return true;
} // ��˫�˶���β��ɾ��һ��Ԫ�ء�

int myCircularDequeGetFront(MyCircularDeque2* obj) {
	if (obj->size == 0) {
		return -1;
	}
	return obj->arr[obj->l];
} // ��˫�˶���ͷ�����һ��Ԫ�ء����˫�˶���Ϊ�գ����� -1 ��

int myCircularDequeGetRear(MyCircularDeque2* obj) {
	if (0 == obj->size) {
		return -1;
	}
	return obj->arr[obj->r];
} // ���˫�˶��е����һ��Ԫ�ء� ���˫�˶���Ϊ�գ����� -1 ��

bool myCircularDequeIsEmpty(MyCircularDeque2* obj) {
	return obj->size == 0;
} //��˫�˶���Ϊ�գ��򷵻� true �����򷵻� false  ��

bool myCircularDequeIsFull(MyCircularDeque2* obj) {
	return obj->size == obj->max;
} // ��˫�˶������ˣ��򷵻� true �����򷵻� false ��

void myCircularDequeFree(MyCircularDeque2* obj) {
	free(obj->arr);
	obj->l = obj->r = obj->size = obj->max = 0;
} // ����