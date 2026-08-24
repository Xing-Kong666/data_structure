#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int keytype;/*关键字类型*/
#define maxsize 10/*数组最大长度*/
typedef struct {
	keytype key;
	char* otherinfo;
}sortkey;/*排序结构体*/
typedef struct {
	sortkey array[maxsize+1];
	int length;
}sqlist;/*排序表*/

void Insert_Sort(sqlist& goal) {/*直接插入排序无哨兵*/
	for (int i = 1; i < maxsize + 1; i++) {
		sortkey x;
		x.key = goal.array[i].key;
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (x.key < goal.array[j].key)goal.array[j + 1].key = goal.array[j].key;
			else break;
		}
		/*
		for (int k = i - 1; k >= 0 && x < goal.array[k]; k--) {
			goal.array[k + 1].key = goal.array[k].key;
		}
		*/
		goal.array[j + 1].key = x.key;
	}
}
void Insert_Sort_Sentry(sqlist& goal) {/*直接插入有哨兵*/
	for (int i = 2; i < maxsize + 1; i++) {
		if (goal.array[i].key < goal.array[i - 1].key) {
			goal.array[0].key = goal.array[i].key;
		}
		int j;
		for (j = i - 1; goal.array[j].key > goal.array[0].key; j--) {
			goal.array[j + 1].key = goal.array[j].key;
		}
		goal.array[j + 1].key = goal.array[0].key;
	}
}
int main() {
	sqlist goal;
	/*无哨兵算法测试*/
	for (int i = 0; i < maxsize + 1; i++) {
		scanf("%d", &goal.array[i].key);
	}
	printf("乱序： ");
	for (int i = 0; i < maxsize + 1; i++) {
		printf("%d ", goal.array[i].key);
	}
	printf("\n");
	Insert_Sort(goal);
	printf("正序： ");
	for (int i = 0; i < maxsize + 1; i++) {
		printf("%d ", goal.array[i].key);
	}
	printf("\n");
	/*有哨兵算法测试*/
	goal.array[0].key = 0;
	for (int i = 1; i < maxsize + 1; i++) {
		scanf("%d", &goal.array[i].key);
	}
	printf("乱序： ");
	for (int i = 0; i < maxsize + 1; i++) {
		printf("%d ", goal.array[i].key);
	}
	printf("\n");
	Insert_Sort(goal);
	printf("正序： ");
	for (int i = 0; i < maxsize + 1; i++) {
		printf("%d ", goal.array[i].key);
	}
	printf("\n");
	return 0;
}