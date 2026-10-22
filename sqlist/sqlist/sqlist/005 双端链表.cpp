#include <iostream>
using namespace std;
#include <ctime>

#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

typedef struct dll {
	elemtype data;
	struct dll* prior;
	struct dll* next;
	struct dll() {
		data = 0;
		prior = NULL;
		next = NULL;
	}
	struct dll(elemtype a,struct dll* b,struct dll *c) {
		data = a;
		prior = b;
		next = c;
	}
}node,*doublelinklist;

//初始化双端链表
status InitDoubleLinkList(doublelinklist &init) {
	init = new node();
	if (!init)return error;
	return ok;
}
//获取双端链表的长度
int GetLength(doublelinklist get) {
	doublelinklist t=get->next;
	int length = 0;
	while (t != nullptr) {
		length++;
		t = t->next;
	}
	return length;
}
//删除第i个节点
status DeleteElem(doublelinklist de, int i, elemtype* e) {
	doublelinklist t=de;
	if (i<1 || i>GetLength(de))return error;
	//因为为双端，可以直接移动到第i个节点
	for (int j = 1; j <= i; j++) {
		t = t->next;
	}
	//交代完事情就释放
	t->prior->next = t->next;
	t->next->prior = t->prior;
	*e = t->data;
	delete t;
	return ok;
}
//头插法插入节点
status InsertElem(doublelinklist insert, elemtype e) {
	doublelinklist t = new node(e,NULL,NULL);
	if (!t)return error;
	t->next = insert->next;
	t->prior = insert;
	insert->next = t;
	//要注意第一次插入时只有头节点，后一个节点为空，不能非法访问
	if(t->next!=nullptr)t->next->prior = t;
	return ok;
}
void print(doublelinklist p) {
	for (int i = 0; i < GetLength(p); i++) {
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
void test00501() {
	doublelinklist ex1 = NULL;
	srand(time(0));
	InitDoubleLinkList(ex1);
	//链表长度为1-25随机值
	int length = rand() % 25 + 1;
	for (int i = 0; i < length; i++)
	{
		elemtype e = rand() % 200 + 1;
		InsertElem(ex1, e);
	}
	print(ex1);

	elemtype* re = new elemtype();
	DeleteElem(ex1, 3, re);
	print(ex1);
	cout << "删除的元素是 = " << *re << endl;
}
int main() {
	test00501();
	system("pause");
	return 0;
}