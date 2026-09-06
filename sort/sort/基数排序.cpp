#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct d {
	int num;
	struct d* head;
}*data,dnode;
int GetDigit(int num, int d) {/*得到数字某一位上的值*/
	int i;
	for (i = 1; i < d; i++) {
		i /= 10;
	}
	return i % 10;
}
int GetMaxDigit(int* arr,int length) {/*得到最大数的位数*/
	int cnt = 0;
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] > max) max = arr[i];
	}
	while (max) {
		max /= 10;
		cnt++;
	}
	return cnt;
}
void RedixSort(int* arr, int length,int max) {
	int digit = 1;
	for (int i = 1; i <= max; i++) {
		struct d* temp[10];
		for (int i = 0; i < 10; i++) temp[i]->head = NULL;/*初始化*/
		for (int j = 0; j < length; j++) {/*填值*/
			int end=GetDigit(arr[j], digit);
			data node = (data)calloc(1, sizeof(dnode));
			node->num = arr[j];
			node->head = temp[end]->head;
			temp[end]->head = node;
		}
		int idx = 0;
		for (int i = 0; i < length; i++) {
			while (!temp[idx])idx++;
			arr[i] = temp[idx]->num;
			temp[idx] = temp[idx]->head;
			if (!temp[idx])idx++;
		}
		digit++;
	}
}
int main() {
	return 0;
}