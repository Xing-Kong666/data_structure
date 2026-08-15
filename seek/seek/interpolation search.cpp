#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*插值查找*/


/*查找关键字keyword*/
typedef int keyword;
/*查找对象结构体*/
typedef struct {
	keyword word;
}elemtype;
/*顺序表结构体*/
typedef struct {
	elemtype* key;
	int length;
}sstable;
/*计算查次数*/
int cnt = 0;


/*插值查找，与二分查找类似*/
int Interpolation_Search(sstable st,int *object,int left,int right) {
	while (left <= right) {
		/*插值查找公式，可以减少查找次数，比二分更快，但是适用于数值分布比较均匀的查找表[1,2,3，...]，不适用于[1,12,100,999,...]*/
		int mid = left + (st.key->word - object[left]) / (object[right] - object[left]) * (right - left);
		cnt++;
		if (st.key->word > object[mid])left = mid + 1;
		else if (st.key->word < object[mid])right = mid - 1;
		else return mid;
	}
	return 0;
}



int mainis() {
	/*初始顺序表*/
	sstable st;
	/*初始查找结构体*/
	elemtype elem;
	/*地址指向*/
	st.key = &elem;
	elem.word = 4;
	/*初始待查表*/
	int object[11] = { 0 };
	for (int i = 1; i < 11; i++) {
		object[i] = i * 2;
	}

	/*得出下标位置和查找次数*/
	int goal = Interpolation_Search(st, object, 1, 10);
	printf("查找位于第%d位，该位查找次数为%d次\n", goal, cnt);

	return 0;
}