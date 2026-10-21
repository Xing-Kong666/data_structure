#include <iostream>
using namespace std;
#include <ctime>

#define ok 0
#define error -1
#define maxsize 100
typedef int elemtype;
typedef int status;

typedef struct {
	elemtype data;//数据
	int cur;//游标
}node,staticlinklist[maxsize];//后者为一个数组类型，数组内的元素为node类型

//静态链表初始化
status InitStaticLinkList(staticlinklist init) {
	init[maxsize - 1].cur = 0;
	for (int i = 0; i < maxsize - 1; i++) {
		init[i].cur = i + 1;
	}
	return ok;
}
//获取静态链表表长
int GetLength(const staticlinklist get) {
	int length = 0;
	int i = get[maxsize-1].cur;
	while (i) {
		length++;
		i = get[i].cur;
	}
	return length;
}
//模拟节点开辟
int MallocNode(staticlinklist m) {
	int j = m[0].cur;
	if (j) {
		m[0].cur = m[j].cur;
		return j;
	}
	return error;
}
//静态链表第i个位置插入元素
status InsertElem(staticlinklist insert,int i,elemtype e) {
	int j;
	int k = maxsize - 1;
	if (i<1 || i>GetLength(insert) + 1)return error;
	for (int l = 1; l < i; l++) {
		k = insert[k].cur;
	}
	j = MallocNode(insert);
	insert[j].data = e;
	insert[j].cur = insert[k].cur;
	insert[k].cur = j;
	return ok;
}
//模拟内存释放第i个节点
status FreeNode(staticlinklist f,int i) {
	f[i].cur = f[0].cur;
	f[0].cur = i;
	return ok;
}
//删除第i个节点
status DeleteStaticLinkList(staticlinklist de,int i) {
	int k = maxsize - 1;
	int j;
	if (i<1 || i>GetLength(de))return error;
	for (int l = 1; l < i; l++) {
		k = de[k].cur;
	}
	j = de[k].cur;
	de[k].cur = de[j].cur;
	FreeNode(de, j);
	return ok;
}

int main003() {
	staticlinklist ex;
	InitStaticLinkList(ex);

	//为链表赋值
	srand(time(0));
	for (int i = 1; i < 23; i++) {
		elemtype e = rand() % 100 + 1;
		InsertElem(ex, i, e);
	}
	//最后一个元素的cur为空
	ex[22].cur = 0;
	//指向第一个元素
	int temp = ex[maxsize - 1].cur;
	for (int i = 1; i < 23; i++) {
		cout << ex[temp].data;
		cout << " ";
		temp = ex[temp].cur;
	}
	cout << endl;

	//删除第4个节点
	DeleteStaticLinkList(ex, 4);
	temp = ex[maxsize - 1].cur;
	for (int i = 1; i <=GetLength(ex); i++) {
		cout << ex[temp].data;
		cout << " ";
		temp = ex[temp].cur;
	}
	cout << endl;
	system("pause");
	return 0;

}