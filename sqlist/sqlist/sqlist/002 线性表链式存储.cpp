#include <iostream>
using namespace std;
#include <ctime>

typedef int elemtype;
//定义头指针和节点，头节点与普通节点类型相同
typedef struct lnode {
	elemtype data;
	struct lnode* next;
}node;
typedef node* linklist;

#define ok 0
#define error -1

//在第i个位置插入元素
int InsertElem(linklist in, int i, elemtype e) {
	linklist p = in;
	int j = 1;
	//循环让p到达i-1的位置
	while (p && j < i) {
		p = p->next;
		j++;
	}
	//排除错误i值和p为空情况
	if (!p || j > i)return error;
	//插入节点
	linklist s = new node();
	s->data = e;
	s->next = p->next;
	p->next = s;
	return ok;
}

//删除第i个位置的元素
int DeleteElem(linklist de, int i, elemtype &e) {
	linklist p = de;
	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i)return error;
	//节点删除交代事情
	linklist s = p->next;
	p->next = s->next;
	e = s->data;
	delete s;
	return ok;
}
//查找第i个元素
int GetElem(linklist ge, int i, elemtype& e) {
	linklist p = ge->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)return error;
	e = p->data;
	return ok;
}
//获取链表长度
int GetLength(linklist ge) {
	int length = 0;
	linklist p = ge;
	while (p->next) {
		p = p->next;
		length++;
	}
	return length;
}
//单链表整表创建
void CreateLinkList(linklist cr,int num) {
	srand(time(0));
	for (int i = 0; i < num; i++) {
		linklist p = new node();
		p->data = rand() % 100 + 1;
		p->next = cr->next;
		cr->next = p;
	}
	return;
}
//单链表的整表删除
void DeleteLinkList(linklist de) {
	if (!(de->next))return;
	linklist f, b;
	f = de->next;
	b = f;
	while (b) {
		f = f->next;
		delete b;
		b = f;
	}
	//释放完之后要把头结点的指针域置空，否则影响后续打印
	de->next = nullptr;
	return;
}
//单链表整表打印
void PrintLinkList(linklist pr) {
	if (!(pr->next))cout << "链表为空" << endl;
	else {
		linklist p = pr->next;
		cout << "链表为： ";
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
	}
	return;
}
int main002() {
	linklist ex=new node();
	cout << "测试一：整表创建" << endl << endl;
	CreateLinkList(ex, 10);
	cout << "测试：创建后整表打印" << endl << endl;
	PrintLinkList(ex);
	cout << endl << endl;
	cout << "测试二：第5个位置插入元素" << endl << endl;
	InsertElem(ex, 5, 2324555);
	cout << "测试：插入元素后打印" << endl;
	PrintLinkList(ex);
	cout << endl << endl;
	cout << "测试三：获取链表长度" << endl << endl;
	int length=GetLength(ex);
	cout << "测试：打印长度" << endl << endl;
	cout << "链表长度为： " << length << endl << endl;
	cout << "测试四：删除第8个位置的元素" << endl << endl;
	elemtype e;
	DeleteElem(ex, 8, e);
	cout << "测试：删除元素后打印" << endl << endl;
	PrintLinkList(ex);
	cout << endl << endl;
	cout << "测试五：查找第4个位置的元素" << endl << endl;
	elemtype s;
	GetElem(ex, 4, s);
	cout << "测试：打印第四个元素" << endl << endl;
	cout << "第四个元素 = " << s << endl << endl;
	cout << "测试六：整表删除" << endl << endl;
	DeleteLinkList(ex);
	cout << "测试：删除后打印" << endl << endl;
	PrintLinkList(ex);
	cout << endl;

	system("pause");
	return 0;
}