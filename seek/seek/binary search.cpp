#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*二分查找*/



/*查找关键字keyword*/
typedef int keyword;
/*查找结构体*/
typedef struct {
	keyword word;
}elemtype;
/*顺序表结构体*/
typedef struct {
	elemtype* key;
	int length;
}sstable;

/*二分查找函数1,循环*/
/*顺序表结构体，待查找表，左值，右值*/
int BinaSeek1(sstable st, int *object,int left, int right) {
	int mid = (left + right) / 2;
	while (left <= right) {
		if (object[mid] < st.key->word)left = mid + 1;
		else if (object[mid] > st.key->word)right = mid - 1;
		else return mid;
		mid = (left + right) / 2;
	}
	return 0;
}
/*二分查找函数2，递归*/
/*同上*/
int BinaSeek2(sstable st, int* object, int left, int right) {
	if (left > right)return 0;
	int mid = (left + right) / 2;
	if (object[mid] < st.key->word)BinaSeek2(st, object, mid + 1, right);
	else if (object[mid] > st.key->word)BinaSeek2(st, object, left, mid - 1);
	else return mid;
}









int mainbs() {
	/*初始顺序表*/
	sstable st1;
	sstable st2;
	/*初始查找结构体*/
	elemtype elem1;
	elemtype elem2;
	/*地址指向*/
	st1.key = &elem1;
	st2.key = &elem2;
	elem1.word = 4;
	elem2.word = 1;
	/*初始待查表*/
	int object[11] = { 0 };
	for (int i = 1; i < 11; i++) {
		object[i] = i * 2;
	}
	/*测试函数*/
	/*已找到*/
	int end1 = BinaSeek1(st1, object, 1, 10);
	printf("目标在第%d位\n", end1);
	int end2 = BinaSeek2(st1, object, 1, 10);
	printf("目标在第%d位\n", end2);
	/*未找到*/
	int end3 = BinaSeek1(st2, object, 1, 10);
	if (!end3)printf("在表里边没有这个数值\n");
	int end4 = BinaSeek2(st2, object, 1, 10);
	if (!end4)printf("还是没找到");

	return 0;
}