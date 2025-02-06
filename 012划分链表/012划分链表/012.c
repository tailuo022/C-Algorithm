#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//给你一个链表的头节点?head?和一个特定值?x?
//请你对链表进行分隔，使得所有?小于?x?的节点都出现在?大于或等于?x?的节点之前
//你应当?保留?两个分区中每个节点的初始相对位置


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