#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
/*算法1函数*/
int SequSeek1(sstable st, int* object);
/*算法2函数*/
int SequSeek2(sstable st, int* object);
/*算法3函数*/
int SequSeek3(sstable st, int* object);

int main() {
	/*定义顺序表类型*/
	sstable st;
	elemtype exam;
	/*初始化查找对象和顺序表*/
	int object[11] = {0};
	for (int i = 1; i < 11; i++) {
		int x = i * 2;
		object[i] += x;
	}
	st.length = 10;
	st.key = &exam;
	st.key->word = 18;
	/*算法测试*/
	/*fa1*/
	int goal1=SequSeek1(st, object);
	printf("算法1: 关键字位于第%d位\n", goal1);
	/*fa2*/
	int goal2 = SequSeek2(st, object);
	printf("算法2: 关键字位于第%d位\n", goal2);
	/*fa3*/
	object[0] = st.key->word;
	object[9] = 0;
	int goal3 = SequSeek3(st, object);
	printf("算法3: 关键字位于第%d位\n", goal3);
	if (goal3 == 0)printf("未找到目标数值");

	return 0;
}
/*进行查找操作，设计算法*/


/*算法1*/
int SequSeek1(sstable st,int *object) {
	int i;
	for (i = st.length; i > 0; i--)
		if (object[i] == st.key->word)return i;
	return 0;
}
/*算法2*/
int SequSeek2(sstable st, int* object) {
	int i;
	for (i = st.length; object[i] != st.key->word && i > 0; i--);
	/*或者用一个if语句判断i是否小于等于0*/
	return i;
}
/*算法3*/
int SequSeek3(sstable st, int* object) {
	int i;
	for (i = st.length; object[i] != st.key->word; i--);
	return i;
}