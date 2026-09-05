#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void Heap_Ajust_Max(int* arr, int root, int end) {/*大根堆调整*/
	int temp = arr[root];
	for (int i = root * 2; i <= end; i *= 2) { 
		if (i < end && arr[i] < arr[i + 1])++i;
		if (temp >= arr[i])break;
		arr[root] = arr[i];
		root = i;
	}
	arr[root] = temp;
}
void Heap_Ajust_Min(int* arr, int root, int end) {/*小根堆调整*/
	int temp = arr[root];
	for (int i = root * 2; i <= end; i *= 2) {
		if (i < end && arr[i] > arr[i + 1])++i;
		if (temp <= arr[i])break;
		arr[root] = arr[i];
		root = i;
	}
	arr[root] = temp;
}
void Swap(int* front, int* back) {/*交换函数*/
	int temp = *front;
	*front = *back;
	*back = temp;
}
/*时间复杂度均为o(n*logn)
空间复杂度为o(1)*/
void Heap_Sort_Max(int* arr,int end) {/*大根堆初始化并筛选排序*/
	for (int i = end / 2; i >= 1; --i)/*o(n/2)*/
		Heap_Ajust_Max(arr, i, end);
	for (int i = end; i > 1; i--) {/*n*logn*/
		Swap(&arr[1], &arr[i]);/*交换数值，便于做边界处理,o(1)*/
		Heap_Ajust_Max(arr, 1, i - 1);
	}/*用正序打印为小根堆*/
}
void Heap_Sort_Min(int* arr, int end) {/*小根堆初始化并筛选排序*/
	for (int i = end / 2; i >= 1; --i)
		Heap_Ajust_Min(arr, i, end);
	for (int i = end; i > 1; i--) {
		Swap(&arr[1], &arr[i]);
		Heap_Ajust_Min(arr, 1, i - 1);
	}/*用正序打印为大根堆*/
}
int mainhs() {
	int arr1[14];
	arr1[0] = 0;
	printf("请输入13个数据:");
	for (int i = 1; i <= 13; i++) {
		scanf("%d", &arr1[i]);
	}

	printf("大根堆排序正序小根堆:\n");
	Heap_Sort_Max(arr1, 13);
	for (int i = 1; i <= 13; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr2[20];
	arr2[0] = 0;
	printf("请输入19个数据:");
	for (int i = 1; i <= 19; i++) {
		scanf("%d", &arr2[i]);
	}

	printf("小跟堆排序正序大根堆:\n");
	Heap_Sort_Min(arr2, 19);
	for (int i = 1; i <= 19; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}