#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int keytype;/*关键字类型*/
#define maxsize 10/*数组最大长度*/
typedef struct {
	keytype key;
	char* otherinfo;
}sortkey;/*排序结构体*/
typedef struct {
	sortkey array[maxsize + 1];
	int length;
}sqlist;/*排序表*/

void Binary_sort(sqlist& end) {//折半插入
	for (int i = 2; i < maxsize + 1; i++) {
		int left = 1, right = i - 1;
		int mid = 0;
		end.array[0].key = end.array[i].key;//哨兵
		while (left <= right) {
			mid = left + (right - left) / 2;//防越界
			if (end.array[mid].key > end.array[0].key)right = mid - 1;
			else if (end.array[mid].key < end.array[0].key)left = mid + 1;
		}//插入位置为left,也就是right+1
		for (int j = i - 1; j > right; --j) {
			end.array[j + 1].key = end.array[j].key;
		}//移位
		end.array[right + 1].key = end.array[0].key;//插入
	}
}
int mainbis() {
	sqlist end;//初始化
	end.length = 11;
	for (int i = 1; i < maxsize + 1; i++)
		scanf("%d", &end.array[i].key);//输入测试用例
	Binary_sort(end);//测试
	printf("[");
	for (int i = 0; i < maxsize + 1; i++) {//打印
		printf("%d ", end.array[i].key);
	}
	printf("]");
	return 0;
}