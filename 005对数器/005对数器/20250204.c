#define  _CRT_SECURE_NO_WARNINGS

#include "sort.cpp"

int main() {
	srand((unsigned)time(NULL));
	int N = 100; //��������С
	int V = 10000; //Ԫ�����ֵ
	int testTimes = 50000; //���Դ���
	
	printf("���Կ�ʼ\n\n");
	Sleep(2000);
	for (int test = 0; test < testTimes; test++) {
		int arrnum = rand() % (N + 1); //�����С��0 - N
		int* arr = (int*)malloc(sizeof(int) * arrnum);
		arr = randomArray(arrnum, V);
		int* arr1 = copyArray(arr, arrnum);
		int* arr2 = copyArray(arr, arrnum);
		int* arr3 = copyArray(arr, arrnum);
		selectionSort(arr1, arrnum);
		bubbleSort(arr2, arrnum);
		insertionSort(arr3, arrnum);
		if (isSameArray(arr1, arr2, arrnum) && isSameArray(arr2, arr3, arrnum)) {
			printf("���Գɹ�\n");
		}
		else {
			printf("���Գ���\n");
			printf("ԭ����:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			printf("ѡ��������:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr1[i]);
			}
			printf("\n");
			printf("ð��������:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr2[i]);
			}
			printf("\n");
			printf("����������:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr3[i]);
			}
			printf("\n");
			Sleep(2000);
			printf("\n���Խ���\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n���Խ���\n");
	return 0;
}