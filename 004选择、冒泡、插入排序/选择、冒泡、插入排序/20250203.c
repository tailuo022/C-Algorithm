#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//ѡ������һ�仰��i~n - 1��Χ�ϣ��ҵ���Сֵ������iλ��(����)��Ȼ��i + 1~n - 1��Χ�ϼ���
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


//ð������һ�仰��0~i��Χ�ϣ�����λ�ýϴ��������ȥ(����)�����ֵ��������iλ�ã�Ȼ��0~i - 1��Χ�ϼ���
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


//��������һ�仰��0~i��Χ���Ѿ����������������ҵ��󻬵�����С��λ�ò���(����)��Ȼ�����
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
	printf("-------------ѡ������--------------\n");
	int arr1[10] = { 0, 3, 2, 7, 8, 1, 9, 4, 6, 5 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	selectionSort(arr1, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	// right

	printf("-------------ð������--------------\n");
	int arr2[10] = { 0, 3, 2, 7, 8, 1, 9, 4, 6, 5 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	bubbleSort(arr2, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	// right

	printf("-------------��������--------------\n");
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