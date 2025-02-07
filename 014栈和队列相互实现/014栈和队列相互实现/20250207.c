#define  _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// ջʵ�ֶ��� -> ����ջ

// ����ջ in �� out 
// outΪ�ղ��ܵ�������
// in�����ݱ���Ҫ����

typedef struct {
	int in[10000];
	int out[10000];
	int intop;
	int outtop;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* Q = (MyQueue*)malloc(sizeof(MyQueue));
	Q->intop = Q->outtop = 0;
	return Q;
}

bool myQueueEmpty(MyQueue* obj) {
	if (obj->intop == 0) {
		return 1;
	}
	return 0;
}

void myQueuePush(MyQueue* obj, int x) {
	if (obj->intop == 10000) {
		return;
	}
	obj->in[obj->intop++] = x;
}

int myQueuePop(MyQueue* obj) {
	if (myQueueEmpty(obj)) {
		return -1;
	}
	while (obj->intop) {
		obj->out[obj->outtop++] = obj->in[--obj->intop];
	}
	int x = obj->out[--obj->outtop];
	while (obj->outtop) {
		obj->in[obj->intop++] = obj->out[--obj->outtop];
	}
	return x;
}

int myQueuePeek(MyQueue* obj) {
	if (myQueueEmpty(obj)) {
		return -1;
	}
	while (obj->intop) {
		obj->out[obj->outtop++] = obj->in[--obj->intop];
	}
	int x = obj->out[--obj->outtop];
	obj->outtop++;
	while (obj->outtop) {
		obj->in[obj->intop++] = obj->out[--obj->outtop];
	}
	return x;
}

void myQueueFree(MyQueue* obj) {
	obj->intop = obj->outtop = 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

// ˼·�Ż���Push����in��ǰ����in�ǿյ�
// Pop��ʱ���in���������ݵ���out����
// ����ÿ��Pop֮�󶼰�out������ݵ���ȥ
// ÿ��Push��ֻ��Ҫ��in���������
// Pop��ʱ��Ϊ�վͿ�����
// �����С�Ϊ�յ�������Ϊout��in��Ϊ��
// ��̯������ʱ��ΪO(1)��



// ����ʵ��ջ

// �Ž�ȥ���ǵ�n��������ǰ��n - 1�������γ��������
typedef struct {
	int L[10000];
	int base, top;
	int size;
} MyStack;

MyStack* myStackCreate() {
	MyStack* L = (MyStack*)malloc(sizeof(MyStack));
	L->base = L->top = L->size = 0;
	return L;
}

int myStackPop(MyStack* obj) {
	int x = obj->L[obj->base++];
	obj->size--;
	return x;
}

void LPush(MyStack* obj, int x) {
	obj->L[obj->top++] = x;
	obj->size++;
}

void myStackPush(MyStack* obj, int x) {
	obj->L[obj->top++] = x;
	obj->size++;
	int n = obj->size;
	for (int i = 0; i < n - 1; i++) {
		int x = myStackPop(obj);
		LPush(obj, x);
	}
	int left = 0;
	for (int i = 0; i < n; i++) {
		obj->L[left++] = obj->L[obj->base++];
	}
	obj->base = 0;
	obj->top = obj->size;
}

bool myStackEmpty(MyStack* obj) {
	if (obj->size == 0) {
		return 1;
	}
	return 0;
}

int myStackTop(MyStack* obj) {
	return obj->L[obj->base];
}

void myStackFree(MyStack* obj) {
	obj->base = obj->size = obj->top = 0;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/