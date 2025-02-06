#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����һ�������ͷ�ڵ�?head?��һ���ض�ֵ?x?
//�����������зָ���ʹ������?С��?x?�Ľڵ㶼������?���ڻ����?x?�Ľڵ�֮ǰ
//��Ӧ��?����?����������ÿ���ڵ�ĳ�ʼ���λ��


struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* L, * Lmin, * Lbig;
	L = (struct ListNode*)malloc(sizeof(struct ListNode));
	Lmin = (struct ListNode*)malloc(sizeof(struct ListNode));
	Lbig = (struct ListNode*)malloc(sizeof(struct ListNode));
	Lmin->next = NULL;
	Lbig->next = NULL;
	L->next = NULL;
	struct ListNode* p, * q;
	p = Lmin;
	q = Lbig;
	while (head) {
		if (head->val < x) {
			p->next = head;
			head = head->next;
			p = p->next;
		}
		else {
			q->next = head;
			head = head->next;
			q = q->next;
		}
	}
	p->next = NULL;
	q->next = NULL;
	if (Lmin->next == NULL) {
		return Lbig->next;
	}
	if (Lbig->next == NULL) {
		return Lmin->next;
	}
	L->next = Lmin->next;
	p->next = Lbig->next;
	return L->next;
}