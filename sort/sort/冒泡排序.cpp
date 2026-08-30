#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Bubble_Sort(int* arr,int length) {//√∞≈›≈≈–Ú∞Ê±æ1.0.0
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

int main() {
	int arr[11];
	arr[0] = 0;
	for (int i = 1; i < 11; i++) {
		scanf("%d", &arr[i]);
	}

	printf("≈≈–Ú«∞");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	Bubble_Sort(arr, 10);
	printf("≈≈–Ú∫Û");
	for (int i = 0; i < 11; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}