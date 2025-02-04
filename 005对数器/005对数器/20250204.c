#define  _CRT_SECURE_NO_WARNINGS

#include "sort.cpp"

int main() {
	srand((unsigned)time(NULL));
	int N = 100; //数组最大大小
	int V = 10000; //元素最大值
	int testTimes = 50000; //测试次数
	
	printf("测试开始\n\n");
	Sleep(2000);
	for (int test = 0; test < testTimes; test++) {
		int arrnum = rand() % (N + 1); //数组大小：0 - N
		int* arr = (int*)malloc(sizeof(int) * arrnum);
		arr = randomArray(arrnum, V);
		int* arr1 = copyArray(arr, arrnum);
		int* arr2 = copyArray(arr, arrnum);
		int* arr3 = copyArray(arr, arrnum);
		selectionSort(arr1, arrnum);
		bubbleSort(arr2, arrnum);
		insertionSort(arr3, arrnum);
		if (isSameArray(arr1, arr2, arrnum) && isSameArray(arr2, arr3, arrnum)) {
			printf("测试成功\n");
		}
		else {
			printf("测试出错\n");
			printf("原数组:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			printf("选择排序结果:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr1[i]);
			}
			printf("\n");
			printf("冒泡排序结果:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr2[i]);
			}
			printf("\n");
			printf("插入排序结果:\n");
			for (int i = 0; i < arrnum; i++) {
				printf("%d ", arr3[i]);
			}
			printf("\n");
			Sleep(2000);
			printf("\n测试结束\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n测试结束\n");
	return 0;
}