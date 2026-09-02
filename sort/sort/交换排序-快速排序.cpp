#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*对每一个枢轴左右进行划分*/
int Partition(int* arr, int left, int right) {
	arr[0] = arr[left];
	int pivot = arr[left];
	while (left < right) {
		while (left < right && pivot <= arr[right])--right;
		arr[left] = arr[right];
		while (left < right && pivot >= arr[left])++left;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	return left;
}
/*快速排序，对每一个枢轴排序，直到只剩枢轴自身为止*/
/*最小时间复杂度:o(n*logn)
最大时间复杂度:o(n*n)
平均时间复杂度:o(n*logn)
最小空间复杂度:o(logn)
最大空间复杂度:o(n)
平均空间复杂度:o(logn)
不稳定排序*/
void Quick_Sort(int* arr, int left,int right) {
	if (left < right) {
		int pivot = Partition(arr, left, right);
		Quick_Sort(arr, left, pivot - 1);
		Quick_Sort(arr, pivot + 1, right);
	}
}
int mainqs() {
	int arr[11];
	arr[0] = 0;
	for (int i = 1; i < 11; i++) {
		scanf("%d", &arr[i]);
	}

	printf("快速排序排序前\t");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	Quick_Sort(arr, 1, 10);
	printf("快速排序排序后\t");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}