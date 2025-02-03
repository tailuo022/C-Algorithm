#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//选择排序一句话：i~n - 1范围上，找到最小值并放在i位置(交换)，然后i + 1~n - 1范围上继续
void selectionSort(int arr[], int size) {
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
void bubbleSort(int arr[], int size) {
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
void insertionSort(int arr[], int size) {
	if (size < 2) {
		return;
	}
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
}


int main() {
	printf("-------------选择排序--------------\n");
	int arr1[10] = { 0, 3, 2, 7, 8, 1, 9, 4, 6, 5 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	selectionSort(arr1, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	// right

	printf("-------------冒泡排序--------------\n");
	int arr2[10] = { 0, 3, 2, 7, 8, 1, 9, 4, 6, 5 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	bubbleSort(arr2, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	// right

	printf("-------------插入排序--------------\n");
	int arr3[10] = { 0, 3, 2, 7, 8, 1, 9, 4, 6, 5 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr3[i]);
	printf("\n");
	insertionSort(arr3, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr3[i]);
	printf("\n");
	// right
	return 0;
}