#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*斐波那契查找*/


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
int cnt1 = 0;

/*斐波那契数列*/
int Fibonacci(int k) {
	if (k >= 0) {
		if (k == 1)return 1;
		else if (k == 0) return 0;
		else return Fibonacci(k - 1) + Fibonacci(k - 2);
	}
	return 0;
}
/*斐波那契查找*/
int Fibonacci_Search(sstable st, int* object, int left, int right) {
	/*初始化斐波那契数列*/
	int F[11] = { 0 };
	for (int i = 0; i < 11; i++) {
		F[i] = Fibonacci(i);
	}

	int mid,j, k=0;
	/*找到右边界*/
	while (st.length > F[k] - 1)k++;
	/*将数组中原右边界与F[k]-1之间的空域赋为数组的最大值*/
	for (j = st.length; j < F[k] - 1; j++) {
		object[j] = object[st.length];
	}
	/*查找主循环*/
	while (left <= right) {
			mid = left + F[k - 1] - 1;
			cnt1++;
			if (st.key->word < object[mid]) {
				right = mid - 1;
				k = k - 1;/*此时的边界长度为F[k]-1*/
			}
			else if (st.key->word > object[mid]) {
				left = mid + 1;
				k = k - 2;/*此时的边界长度为F[k]-1*/
			}
			else {
				if (mid <= st.length)return mid;
				else return st.length;
			}
		}
	return 0;
}


int main() {
	/*初始顺序表*/
	sstable st;
	st.length = 10;
	/*初始查找结构体*/
	elemtype elem;
	/*地址指向*/
	st.key = &elem;
	elem.word = 9;
	/*初始待查表*/
	int object[13] = { 0 };
	for (int i = 1; i < 11; i++) {
		object[i] = i * 3;
	}

	/*测试函数*/
	int goal = Fibonacci_Search(st, object, 1, 10);
	printf("查找位置下标为%d\n查找次数为%d次\n", goal, cnt1);

	return 0;
}