#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge_sortz(int* temp,int *end,int left,int mid,int right) {/*分治思想，治*/
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (temp[i] <= temp[j]) end[k++] = temp[i++];
		else end[k++] = temp[j++];
	}
	while (j <=right)end[k++] = temp[j++];
	while (i <= mid)end[k++] = temp[i++];
}
void MergeSortf(int* arr, int* end,int left, int right) {/*分治思想，分+治*/
	int temp[15] = { 0 };
	if (left == right)end[left] = arr[left];
	else {
		/*求中值将区间分为两部分*/
		int mid = (left + right) / 2;
		/*对left-mid左半部分进行归并*/
		MergeSortf(arr, temp, left, mid);
		/*对mid+1-right右半部分归并*/
		MergeSortf(arr, temp, mid + 1, right);
		/*将两个各自有序的序列进行归并并存入新的数组中，temp数组相当于原来的两个连续但不有序的数组
		经过归并算法从left左边界开始填入新的数组end之中，temp起了一个临时存放的作用
		*/
		merge_sortz(temp, end, left, mid, right);
	}
}

int mainms() {
	int arr[9];
	printf("请输入9个数据:\n");
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	int end[15] = { 0 };
	MergeSortf(arr, end, 0, 8);
	printf("归并排序:\n");
	printf("原数组为：");
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("归并数组为：");
	for (int i = 0; i < 9; i++) {
		printf("%d ", end[i]);
	}
	printf("\n");

	return 0;
}