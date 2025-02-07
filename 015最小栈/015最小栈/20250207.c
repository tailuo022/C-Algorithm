#define  _CRT_SECURE_NO_WARNINGS

// 多一个min栈，stack[]压入的数字<= min[top], min中压入stack
// stack[]压入的数字<= min[top], min中压入min[top]
// 起始都为空，同步压入

typedef struct {
	int stack[100000];
	int topS;
	int min[100000];
	int topM;
} MinStack;


MinStack* minStackCreate() {
	MinStack* S = (MinStack*)malloc(sizeof(MinStack));
	S->topS = S->topM = 0;
	return S;
}

void minStackPush(MinStack* obj, int val) {
	obj->stack[obj->topS++] = val;
	if (obj->topM == 0 || val <= obj->min[obj->topM - 1]) {
		obj->min[obj->topM++] = val;
	}
	else {
		int x = obj->min[obj->topM - 1];
		obj->min[obj->topM++] = x;
	}
}

void minStackPop(MinStack* obj) {
	obj->topM--;
	obj->topS--;
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->topS - 1];
}

int minStackGetMin(MinStack* obj) {
	if (obj->topM == 0) {
		return -1;
	}
	return obj->min[obj->topM - 1];
}

void minStackFree(MinStack* obj) {
	obj->topM = obj->topS = 0;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
