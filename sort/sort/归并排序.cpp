#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge_sortz(int* arr,int *end,int left,int mid,int right) {/*分治思想，治*/
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) end[k++] = arr[i++];
		else end[k++] = arr[j++];
	}
	while (j <=right)end[k++] = arr[j++];
	while (i <= mid)end[k++] = arr[i++];
	for (int a = left; a < right + 1; a++) {
		arr[a] = end[a];
	}
}
void MergeSortf(int* arr, int* end,int left, int right) {/*分治思想，分+治*/
	if (left >= right)return;
	int mid = (left + right) / 2;
	MergeSortf(arr, end,left, mid);
	MergeSortf(arr, end,mid + 1, right);
	merge_sortz(arr, end,left, mid, right);
}

int main() {
	int arr[9];
	printf("请输入9个数据:\n");
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	int end[15] = { 0 };
	MergeSortf(arr, end, 0, 8);
	printf("归并排序:\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", end[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}