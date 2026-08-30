#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Shell_Sort(int* arr,int length) {
	for (int gap = length / 2; gap > 0; gap /= 2) {
		for (int i = gap + 1; i <= length; i++) {
			if (arr[i] < arr[i - gap]) {
				arr[0] = arr[i];
				int j;
				for (j = i - gap; j > 0 && arr[j] > arr[0]; j -= gap) {
					arr[j + gap] = arr[j];
				}
				arr[j + gap] = arr[0];
			}
		}
	}
}
void Print_Arr(int* arr,int length) {
	printf("打印数组结果\n");
	for (int i = 0; i <= length; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[11];
	arr[0] = 0;
	for (int i = 1; i < 11; i++) {
		scanf("%d", &arr[i]);
	}

	printf("未排序\n");
	Print_Arr(arr, 10);
	printf("\n");

	printf("已排序\n");
	Shell_Sort(arr, 10);
	Print_Arr(arr, 10);
	return 0;
}