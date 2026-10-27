#include <iostream>
using namespace std;
#include <ctime>

#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

typedef struct lsnode
{
	elemtype data;
	struct lsnode* next;
}stacknode,*linkstack;

//初始栈
status InitLinkStack(linkstack &init) {
	init = new stacknode();
	if (!init)return error;
	return ok;
}

//栈顶指向头节点
//删除元素,返回删除元素
status DeleteElem(linkstack de,elemtype* e) {
	if (!de->next)return error;
	linkstack temp = de->next;
	de->next = temp->next;
	*e = temp->data;
	delete temp;
	temp = NULL;
	return ok;
}

//插入元素
status InsertElem(linkstack insert, elemtype e) {
	linkstack temp = new stacknode();
	temp->data = e;
	temp->next = insert->next;
	insert->next = temp;
	return ok;
}

//获取栈长
int GetLength(linkstack get) {
	linkstack temp = get;
	int length = 0;
	while (temp->next != nullptr) {
		temp = temp->next;
		length++;
	}
	return length;
}
void test00701() {
	linkstack ex=NULL;
	//初始栈
	InitLinkStack(ex);
	//随机栈长
	//int length = rand() % 2000000 + 100000;
	int length = rand() % 50 + 1;
	cout << "length = " << length << endl;
	//赋值
	for (int i = 0; i < length; i++) {
		elemtype e = rand() % 13 + 1;
		InsertElem(ex, e);
	}
	//显示栈
	linkstack print = ex;
	for (int i = 0; i < length; i++) {
		print = print->next;
		cout << print->data << " ";
	}
	cout << endl;
	//删除元素
	elemtype* e = new elemtype;
	DeleteElem(ex, e);
	cout << "deleteelem length = " << GetLength(ex) << endl;
	//显示栈
	print = ex;
	length = GetLength(ex);
	for (int i = 0; i < length; i++) {
		print = print->next;
		cout << print->data << " ";
	}
	cout << endl;
}
int main() {
	srand(time(0));
	test00701();
	system("pause");
	return 0;
}