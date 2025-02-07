#define  _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// 栈实现队列 -> 两个栈

// 两个栈 in 和 out 
// out为空才能倒入数据
// in倒数据必须要倒完

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

// 思路优化，Push进入in的前提是in是空的
// Pop的时候把in的所有数据倒入out里面
// 不必每次Pop之后都把out里的数据倒回去
// 每次Push都只需要在in里面加数据
// Pop的时候不为空就可以了
// “队列”为空的条件改为out和in都为空
// 分摊下来，时间为O(1)。



// 队列实现栈

// 放进去的是第n个数，把前面n - 1个数依次出队再入队
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