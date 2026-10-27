#include <iostream>
using namespace std;
#include <ctime>

#define max 120
#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

typedef struct sqst {
	elemtype sq[max];//顺序栈栈数组
	int top;//栈顶指针
}sqstack;
//初始顺序栈
status InitSqStack(sqstack init) {
	for (int i = 0; i < max; i++) {
		init.sq[i] = 0;
	}
	init.top = -1;
	return ok;
}
//添加元素
status InsertElem(sqstack& insert,elemtype e) {
	if (insert.top >= max - 1)return error;
	insert.sq[++insert.top] = e;
	return ok;
}
//删除元素
status DeleteElem(sqstack& de, elemtype* e) {
	if (de.top <= -1)return error;
	*e = de.sq[de.top];
	de.top--;
	return ok;
}
//获取栈长
int GetLength(sqstack get) {
	return get.top + 1;
}
//清空栈(逻辑清空)
status ClearStack(sqstack &clear) {
	clear.top = -1;
	return ok;
}
//赋值(空栈)
status Assignment(sqstack& ass) {
	//栈长
	int length = rand() % 20 + 1;
	for (int i = 0; i < length; i++) {
		elemtype e = rand() % 34 + 53;
		ass.sq[++ass.top] = e;
	}
	return ok;
}
void print(sqstack p) {
	cout << "栈元素：";
	if (p.top == -1)cout << "栈空";
	for (int i = 0; i <= p.top; i++) {
		cout << p.sq[i] << " ";
	}
	cout << endl;
}
void test006() {
	sqstack ex;
	ex.top = -1;
	InitSqStack(ex);
	cout << "初始栈长为 = " << GetLength(ex) << endl;
	print(ex);
	Assignment(ex);
	cout << "赋值栈长为 = " << GetLength(ex) << endl;
	print(ex);
	InsertElem(ex, 23);
	cout << "插入元素栈长为 = " << GetLength(ex) << endl;
	print(ex);
	elemtype* e = new elemtype;
	DeleteElem(ex, e);
	cout << "*e = " << *e << endl;
	cout << "删除元素栈长为 = " << GetLength(ex) << endl;
	print(ex);
	ClearStack(ex);
	cout << "清空栈长为 = " << GetLength(ex) << endl;
	print(ex);
	delete e;
	e = NULL;
}
int main006() {
	srand(time(0));
	test006();
	system("pause");
	return 0;
}