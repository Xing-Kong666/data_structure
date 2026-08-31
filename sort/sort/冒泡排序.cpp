#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Bubble_Sort(int* arr,int length) {//冒泡排序版本1.0.0
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < length - i + 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
/*改进判定条件，减少时间复杂度，当其中一轮循环没有发生交换时，则该序列已经有序，无需再做后续比较
最小时间复杂度为o(1)
最大时间复杂度为o(n*n)
平均时间复杂度为o(n*n)
空间复杂度为o(1)
具有稳定性
适用于小规模的无序数据排序
优点：不会改变元素的相对位置，并且每一次循环都能够使元素更接近自己的最终位置，排序的比较次数随着循环而逐渐减少，在添加了flag判断时
进一步减少了后续的无用比较
缺点：不适用于大规模的数据排序，相对于希尔排序比较耗时
*/
void Bubble_Sort_Change(int* arr, int length) {//冒泡排序1.1.0
	int flag = 0;//判定交换与否
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 1;
			}
		}
		if (!flag)break;
	}
}

int main() {
	int arr[11];
	arr[0] = 0;
	for (int i = 1; i < 11; i++) {
		scanf("%d", &arr[i]);
	}

	printf("1.0.0版本排序前 ");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	Bubble_Sort(arr, 10);
	printf("1.0.0版本排序后 ");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	int array[11];
	for (int i = 0; i < 11; i++) {
		scanf("%d", &array[i]);
	}

	printf("1.1.0版本排序前 ");
	for (int i = 0; i < 11; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	Bubble_Sort_Change(array, 11);
	printf("1.1.0版本排序后 ");
	for (int i = 0; i < 11; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}