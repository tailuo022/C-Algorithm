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
} //交换数组中两个值

int* randomArray(int arrSize, int max) {
	if (max == 0) {
		return NULL;
	}
	int* arr = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		arr[i] = rand() % max + 1;
	}
	return arr;
} //随机数组内容

int* copyArray(int* arr, int arrSize) {
	if (arrSize == 0) {
		return NULL;
	}
	int* carr = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		carr[i] = arr[i];
	}
	return carr;
} //拷贝数组

void insertionSort(int* arr, int size) {
	if (size < 2) {
		return;
	}
	for (int i = 1; i < size; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
} //插入排序

bool findNumber(int* arr, int arrSize, int target) {
	if (!arr || arrSize == 0) {
		return false;
	}
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;
	while (left <= right) {
		mid = left + ((right - left) >> 1);// 防止溢出
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
} //二分查找

bool findNumber_turing(int* arr, int arrSize, int target) {
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == target) {
			return true;
		}
	}
	return false;
} //依次查找

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
} //返回第一个大于等于目标值的数组元素的下标 -> 二分法

int findFirstBigger_turing(int* arr, int arrSize, int target) {
	int ans = -1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] >= target) {
			ans = i;
			return ans;
		}
	}
	return ans;
} //返回第一个大于等于目标值的数组元素的下标 -> 依次查找

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
} //返回最后一个小于等于目标值的数组元素的下标 -> 二分法

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
} //返回最后一个小于等于目标值的数组元素的下标-> 依次查找 

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
} //返回一个峰值的下标 -> 二分查找

int findPeakElem_turing(int* arr, int peak) {
	int ans = peak;
	if (arr[peak - 1] < arr[peak] && arr[peak] > arr[peak + 1]) {
		return ans;
	}
	else {
		return -1;
	}
} //验证peak是否是峰值

int main() {
	srand((unsigned)time(NULL));
	int N = 100; //数组最大大小
	int V = 500; //数组元素最大值
	int testTimes = 200; //测试次数
	printf("开始测试:>二分查找arr数组中是否存在目标数值target\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //数组大小：0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findNumber(arr2, arrSize, target) == findNumber_turing(arr1, arrSize, target)) {
			printf("测试成功\n");
		}
		else {
			printf("测试失败\n");
			Sleep(1000);
			printf("数组为：");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n测试通过\n");

	printf("开始测试:>二分返回第一个大于等于目标值target的数组元素的下标\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //数组大小：0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findFistBigger(arr2, arrSize, target) == findFirstBigger_turing(arr1, arrSize, target)) {
			printf("测试成功\n");
		}
		else {
			printf("测试失败\n");
			Sleep(1000);
			printf("数组为：");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n测试通过\n");

	printf("开始测试:>二分返回最后一个小于等于目标值target的数组元素的下标\n\n");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1); //数组大小：0 - N
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		insertionSort(arr, arrSize);
		int* arr1 = copyArray(arr, arrSize);
		int* arr2 = copyArray(arr, arrSize);
		int target = rand() % V + 1;
		if (findLastSmaller(arr2, arrSize, target) == findLastSmaller_turing(arr1, arrSize, target)) {
			printf("测试成功\n");
		}
		else {
			printf("测试失败\n");
			Sleep(1000);
			printf("数组为：");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr1[j]);
			}
			printf("\n");
			return -1;
		}
	}
	Sleep(2000);
	printf("\n测试通过\n");

	printf("开始测试:>二分查找任意一个波峰");
	Sleep(2000);
	for (int i = 0; i < testTimes; i++) {
		int arrSize = rand() % (N + 1);
		int* arr = (int*)malloc(sizeof(int) * arrSize);
		arr = randomArray(arrSize, V);
		int peak = findPeakElem(arr, arrSize);
		int peak_turing = findPeakElem_turing(arr, peak);
		if (peak == peak_turing) {
			printf("测试成功\n");
		}
		else {
			printf("测试失败\n");
			printf("失败的数组是:\n");
			for (int j = 0; j < arrSize; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			Sleep(2000);
			return -1;
		}
	}
	Sleep(2000);
	printf("\n测试通过\n");
		
	return 0;
}