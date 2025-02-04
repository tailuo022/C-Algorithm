#define  _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdio.h>

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
} //��������������ֵ

int* randomArray(int arrSize, int max) {
	if (max == 0) {
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		arr[i] = rand() % max + 1;
	}
	return arr;
} //�����������

int* copyArray(int* arr, int arrSize) {
	if (arrSize == 0) {
		return NULL;
	}
	int* carr = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		carr[i] = arr[i];
	}
	return carr;
} //��������

void insertionSort(int* arr, int size) {
	if (size < 2) {
		return;
	}
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
} //��������

bool findNumber(int* arr, int arrSize, int target) {
	if (!arr || arrSize == 0) {
		return false;
	}
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;
	while (left <= right) {
		mid = left + ((right - left) >> 1);// ��ֹ���
		if (arr[mid] == target) {
			return true;
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
} //���ֲ���

bool findNumber_turing(int* arr, int arrSize, int target) {
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == target) {
			return true;
		}
	}
	return false;
} //���β���

int findFistBigger(int* arr, int arrSize, int target) {
	int ans = -1;
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (arr[mid] >= target) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
} //���ص�һ�����ڵ���Ŀ��ֵ������Ԫ�ص��±� -> ���ַ�

int findFirstBigger_turing(int* arr, int arrSize, int target) {
	int ans = -1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] >= target) {
			ans = i;
			return ans;
		}
	}
	return ans;
} //���ص�һ�����ڵ���Ŀ��ֵ������Ԫ�ص��±� -> ���β���

int findLastSmaller(int* arr, int arrSize, int target) {
	int ans = -1;
	int left = 0, right = arrSize - 1, mid = 0;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (arr[mid] <= target) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
} //�������һ��С�ڵ���Ŀ��ֵ������Ԫ�ص��±� -> ���ַ�

int findLastSmaller_turing(int* arr, int arrSize, int target) {
	int ans = -1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] <= target) {
			ans = i;
		}
		else {
			break;
		}
	}
	return ans;
} //�������һ��С�ڵ���Ŀ��ֵ������Ԫ�ص��±�-> ���β��� 

int findPeakElem(int* arr, int arrSize) {
	if (arrSize == 1) {
		return 0;
	}
	if (arr[0] > arr[1]) {
		return 0;
	}
	if (arr[arrSize - 1] > arr[arrSize - 2]) {
		return arrSize - 1;
	}
	int ans = -1;
	int left = 1, right = arrSize - 2, mid = 0;
	while(left <= right) {
		mid = left + ((right - left) >> 1);
		if (arr[mid - 1] > arr[mid]) {
			right = mid - 1;
		}
		else if (arr[mid] < arr[mid + 1]) {
			left = mid + 1;
		}
		else {
			ans = mid;
			return ans;
		}
	 }
	return ans;
} //����һ����ֵ���±� -> ���ֲ���

int findPeakElem_turing(int* arr, int peak) {
	int ans = peak;
	if (arr[peak - 1] < arr[peak] && arr[peak] > arr[peak + 1]) {
		return ans;
	}
	else {
		return -1;
	}
} //��֤peak�Ƿ��Ƿ�ֵ

int main() {
	srand((unsigned)time(NULL));
	int N = 100; //��������С
	int V = 500; //����Ԫ�����ֵ
	int testTimes = 200; //���Դ���
	printf("��ʼ����:>���ֲ���arr�������Ƿ����Ŀ����ֵtarget\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //�����С��0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findNumber(arr2, arrSize, target) == findNumber_turing(arr1, arrSize, target)) {
			printf("���Գɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			Sleep(1000);
			printf("����Ϊ��");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n����ͨ��\n");

	printf("��ʼ����:>���ַ��ص�һ�����ڵ���Ŀ��ֵtarget������Ԫ�ص��±�\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //�����С��0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findFistBigger(arr2, arrSize, target) == findFirstBigger_turing(arr1, arrSize, target)) {
			printf("���Գɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			Sleep(1000);
			printf("����Ϊ��");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n����ͨ��\n");

	printf("��ʼ����:>���ַ������һ��С�ڵ���Ŀ��ֵtarget������Ԫ�ص��±�\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //�����С��0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findLastSmaller(arr2, arrSize, target) == findLastSmaller_turing(arr1, arrSize, target)) {
			printf("���Գɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			Sleep(1000);
			printf("����Ϊ��");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n����ͨ��\n");

	printf("��ʼ����:>���ֲ�������һ������");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1);
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		int peak = findPeakElem(arr, arrSize);
		int peak_turing = findPeakElem_turing(arr, peak);
		if (peak == peak_turing) {
			printf("���Գɹ�\n");
		}
		else {
			printf("����ʧ��\n");
			printf("ʧ�ܵ�������:\n");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			Sleep(2000);
			return -1;
		}
	}
	Sleep(2000);
	printf("\n����ͨ��\n");
		
	return 0;
}