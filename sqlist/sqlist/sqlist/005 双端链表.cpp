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
	if(t->next!=nullptr)t->next->prior = t->prior;
	*e = t->data;
	delete t;
	t = NULL;
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
	int length = GetLength(p);
	for (int i = 0; i < length; i++) {
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
//合并两个链表,并将新链表设为循环双端链表，头指针设为尾指针
status MergeTwoLinkList(doublelinklist& a, doublelinklist& b) {
	if (!(a->next) || !(b->next))return error;
	//1.第一个链表尾连接第二个链表头
	doublelinklist ex1 = a;
	while (ex1->next!=nullptr) {
		ex1 = ex1->next;
	}
	cout << ex1->data << " ";
	ex1->next = b->next;
	b->next->prior = ex1;
	cout << ex1->next->data;
	//2.第二个链表表尾连接第一个链表头节点
	doublelinklist ex2 = b->next;
	while (ex2->next != nullptr) {
		ex2 = ex2->next;
	}
	ex2->next = a;
	a->prior = ex2;
	//3.更改头指针为尾指针
	a = ex2;
	delete b;
	b = nullptr;
	return ok;
}
void test00501() {
	doublelinklist ex1 = NULL;
	InitDoubleLinkList(ex1);
	//链表长度为1-25随机值
	int length = rand() % 25 + 1;
	cout << length << endl;
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
	delete re;
	re = NULL;
}
void test00502() {
	//合并两链表
	doublelinklist ex2 = NULL;
	doublelinklist ex3 = NULL;

	InitDoubleLinkList(ex2);
	InitDoubleLinkList(ex3);
	int length = rand() % 25 + 1;
	cout << length << endl;
	for (int i = 0; i < length; i++)
	{
		elemtype e = i+1;
		InsertElem(ex2, e);
	}
	cout << "ex2: ";
	print(ex2);


	length = rand() % 15 + 1;
	cout << length << endl;
	for (int i = 0; i < length; i++)
	{
		elemtype e = i+2;
		InsertElem(ex3, e);
	}
	cout << "ex3: ";
	print(ex3);

	MergeTwoLinkList(ex2, ex3);
	cout <<endl<< "merge ex2+ex3 :";
	doublelinklist temp = ex2->next;
	while (temp != ex2) {
		temp = temp->next;
		cout << temp->data << " ";
	}
	cout << endl;

}
int main() {
	srand(time(0));
	test00501();
	test00502();
	system("pause");
	return 0;
}