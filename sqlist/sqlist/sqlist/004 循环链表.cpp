#include <iostream>
using namespace std;
#include <ctime>

typedef int status;
typedef int elemtype;
#define ok 0
#define error -1
//节点类型，节点指针
typedef struct node{
	elemtype data;
	struct node* next;
}node,*looplinklist;

//初始化循环链表
status InitLoopLinkList(looplinklist &init) {
	init = new node();
	if (!init)return error;
	init->next = init;
	return ok;
}

//尾插法插入元素,头指针在循环链表中更换为尾指针
status InsertElem(looplinklist &insert, elemtype e) {
	looplinklist temp = new node();
	if (!temp)return error;
	temp->data = e;
	temp->next = insert->next;
	insert->next = temp;
	insert = temp;
	return ok;
}

//获取链表长度
int GetLength(looplinklist get) {
	int length = 0;
	looplinklist temp = get->next;
	while (temp != get) {
		temp = temp->next;
		length++;
	}
	return length;
}
//删除第i个元素
status DeleteElem(looplinklist &de,int i, elemtype* e) {
	if (i<1 || i>GetLength(de))return error;
	looplinklist temp = de->next;
	for (int j = 1; j <= i - 1; j++) {
		temp = temp->next;
	}
	if (i == GetLength(de))de = temp;
	looplinklist p = temp->next;
	*e = p->data;
	temp->next = p->next;
	delete p;
	return ok;
}

int main() {
	looplinklist ex=nullptr;
	InitLoopLinkList(ex);
	//为链表赋值
	srand(time(0));
	for (int i = 0; i < 20; i++) {
		elemtype e = rand() % 400 + 1;
		InsertElem(ex, e);
	}
	//打印链表
	looplinklist ac = ex->next;
	for (int i = 0; i < GetLength(ex); i++) {
		ac = ac->next;
		cout << ac->data << " ";
	}
	cout << endl;
	//cout << ex->data << endl;
	//删除第9个元素
	elemtype *e=new elemtype();
	DeleteElem(ex, 9, e);
	//打印链表
	ac = ex->next;
	for (int i = 0; i < GetLength(ex); i++) {
		ac = ac->next;
		cout << ac->data << " ";
	}
	cout << endl;
	//打印删除元素值
	cout << "删除的元素 = " << *e << endl;
	system("pause");
	return 0;
}