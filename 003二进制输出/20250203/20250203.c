#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 7;
	printf("%d\n", a);
	printf("%d\n", (a << 1));
	printf("%d\n", (a << 2));
	printf("%d\n", (a << 3));
	//7 14 28 56
	int b = -7;
	printf("%d\n", b);
	printf("%d\n", (b >> 1));
	printf("%d\n", (b >> 2));
	// 打印二进制
	printf("%d\n", sizeof(int)); // 4
	for (int i = 31; i >= 0; i--) {
		printf("%d", (a & (1 << i)) == 0 ? 0 : 1);
	}
	printf("\n");
	for (int i = 31; i >= 0; i--) {
		printf("%d", (b & (1 << i)) == 0 ? 0 : 1);
	}
	printf("\n");

	// 改变类型
	long long c = 15;
	printf("%d\n", sizeof(long long)); // 8
	for (int i = 63; i >= 0; i--) {
		printf("%d", (c & (1 << i)) == 0 ? 0 : 1);
	}
	//0000000000000000000000000000111100000000000000000000000000001111
	// error
	printf("\n");
	for (int i = 63; i >= 0; i--) {
		printf("%d", (c & ((long long)1 << i)) == 0 ? 0 : 1);
	}
	//0000000000000000000000000000000000000000000000000000000000001111
	// right

	return 0;
}