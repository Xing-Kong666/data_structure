#include <iostream>
using namespace std;


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
int main() {
	
	system("pause");
	return 0;
}