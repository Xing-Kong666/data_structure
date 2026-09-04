#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*最小时间复杂度:o(n*n)
最大时间复杂度:o(n*n)
平均时间复杂度:o(n*n)
空间复杂度:o(1)
不稳定排序*/
void Select_Sort_1(int* arr, int length) {//1.0.0
	for (int i = 0; i < length - 1; ++i) {
		for (int j = i + 1; j < length; ++j) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void Select_Sort_2(int* arr, int length) {//1.0.1
	for (int i = 0; i < length - 1; ++i) {
		int k = i;
		for (int j = i + 1; j < length; ++j) {
			if (arr[k] > arr[j])k = j;
		}
		if(k!=i){/*对正序数列来说有时间优势*/
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}
int mainess() {
	int arr[15];
	int a[11];
	printf("选择排序前:\n");
	for (int i = 0; i < 15; i++) {
		scanf("%d", &arr[i]);
	}
	getchar();
	for (int i = 0; i < 11; i++) {
		scanf("%d", &a[i]);
	}
	printf("选择排序后:\n");

	printf("选择排序1:\n");
	Select_Sort_1(arr, 15);
	for (int i = 0; i < 15; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("选择排序2:\n");
	Select_Sort_2(a, 11);
	for (int i = 0; i < 11; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}