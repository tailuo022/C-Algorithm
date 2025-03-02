

// µ›πÈ∞Ê

//void merge(int* nums, int* help, int left, int mid, int right) {
//	int i = left;
//	int a = left;
//	int b = mid + 1;
//	while (a <= mid && b <= right) {
//		help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
//	}
//	while (a <= mid) {
//		help[i++] = nums[a++];
//	}
//	while (b <= right) {
//		help[i++] = nums[b++];
//	}
//	for (i = left; i <= right; i++) {
//		nums[i] = help[i];
//	}
//}
//
//void SORT(int* nums, int* help, int left, int right) {
//	if (left == right) {
//		return;
//	}
//	int mid = left + ((right - left) >> 1);
//	SORT(nums, help, left, mid);
//	SORT(nums, help, mid + 1, right);
//	merge(nums, help, left, mid, right);
//}
//
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	int* help = (int*)malloc(sizeof(int) * numsSize);
//	SORT(nums, help, 0, numsSize - 1);
//	*returnSize = numsSize;
//	return nums;
//}


// ∑«µ›πÈ∞Ê

//int cmp(int a, int b) {
//	return a < b ? a : b;
//}
//
//void merge(int* nums, int* help, int left, int mid, int right) {
//	int i = left;
//	int a = left;
//	int b = mid + 1;
//	while (a <= mid && b <= right) {
//		help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
//	}
//	while (a <= mid) {
//		help[i++] = nums[a++];
//	}
//	while (b <= right) {
//		help[i++] = nums[b++];
//	}
//	for (i = left; i <= right; i++) {
//		nums[i] = help[i];
//	}
//}
//
//
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	int* help = (int*)malloc(sizeof(int) * numsSize);
//	int step, left, mid, right;
//	for (step = 1; step < numsSize; step <<= 1) {
//		left = 0;
//		while (left < numsSize) {
//			mid = left + step - 1;
//			if (mid + 1 >= numsSize) { // ‘ΩΩÁ√ª”–”“≤‡
//				break;
//			}
//			right = cmp(left + (step << 1) - 1, numsSize - 1);// ”–”“≤‡
//			merge(nums, help, left, mid, right);
//			left = right + 1;
//		}
//	}
//	*returnSize = numsSize;
//	return nums;
//}