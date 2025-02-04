#define  _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//选择排序一句话：i~n - 1范围上，找到最小值并放在i位置(交换)，然后i + 1~n - 1范围上继续
void selectionSort(int* arr, int size) {
	if (size == 0 || size == 1) {
		return;
	}
	int min = 0;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr, i, min);
	}
}


//冒泡排序一句话：0~i范围上，相邻位置较大的数滚下去(右移)，最大值最终来到i位置，然后0~i - 1范围上继续
void bubbleSort(int* arr, int size) {
	if (size == 0 || size == 1) {
		return;
	}
	for (int end = size - 1; end > 0; end--) {
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i + 1])
				swap(arr, i, i + 1);
		}
	}
}


//插入排序一句话：0~i范围上已经有序，新来的数从右到左滑到不再小的位置插入(左移)，然后继续
void insertionSort(int* arr, int size) {
	if (size < 2) {
		return;
	}
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
}

int* randomArray(int n, int max) {
	int* arr = (int*)malloc(sizeof(n) * n);
	if (max == 0) {
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % max + 1;
	}
	return arr;
}

int* copyArray(int* arr, int size) {
	int* carr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		carr[i] = arr[i];
	}
	return carr;
}

bool isSameArray(int* a, int* b, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}