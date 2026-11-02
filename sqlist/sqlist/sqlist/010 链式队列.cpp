#include <iostream>
using namespace std;
#include <ctime>

#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

typedef struct linkqu {
	elemtype data;
	struct linkqu* next;
}queuenode,*linkqueue;

typedef struct pr {
	linkqueue front;
	linkqueue back;
	int length;
}pr;
//初始化链队,初始为空，front与back指向相同
status InitQueue(pr &init) {
	init.front = new queuenode();
	init.back = init.front;
	init.length = 0;
	return ok;
}

//添加元素
status InsertElem(pr &insert, elemtype e) {
	linkqueue temp = new queuenode();
	if (!temp)return error;
	temp->data = e;
	insert.back->next = temp;
	insert.back = temp;
	insert.length++;
	return ok;
}

//删除元素
status DeleteElem(pr& de, elemtype* e) {
	if (de.front == de.back)return error;
	linkqueue temp = de.front->next;
	de.front->next = temp->next;
	*e = temp->data;
	if (temp == de.back) {
		de.back = de.front;
	}
	free(temp);
	temp = NULL;
	de.length--;
	return ok;
}

//获取队头元素
status GetHeadElem(pr get, elemtype* e) {
	if (get.front == get.back)return error;
	*e = get.front->next->data;
	return ok;
}

//获取队尾元素
status GetRearElem(pr get, elemtype* e) {
	if (get.front == get.back)return error;
	*e = get.back->data;
	return ok;
}

//清空队列
status ClearQueue(pr& clear) {
	if (!clear.length)return error;
	linkqueue head = clear.front->next;
	linkqueue rear = clear.front;
	while (rear != NULL) {
		free(rear);
		rear = head;
		if(head)head = head->next;
	}
	clear.front = NULL;
	clear.back = NULL;
	clear.length = 0;
	return ok;
}

//打印链队
status PrintQueue(pr p) {
	if (!p.length)return error;
	linkqueue temp = p.front->next;
	for (int i = 1; i <= p.length; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return ok;
}
void test010() {
	pr ex;
	ex.front = NULL;
	ex.back = NULL;
	//初始化
	InitQueue(ex);
	int length = rand() % 12 + 2;
	cout << "length == " << length << endl;
	//初始化链队元素
	for (int i = 0; i < length; i++) {
		elemtype e = rand() % 23 + 1;
		InsertElem(ex, e);
	}
	PrintQueue(ex);
	

	cout << "删除元素" << endl;
	elemtype* e = new elemtype();
	DeleteElem(ex, e);
	PrintQueue(ex);
	cout << "删除的元素为 = " << *e << endl;


	GetHeadElem(ex, e);
	cout << "队头元素为 = " << *e << endl;


	GetRearElem(ex, e);
	cout << "队尾元素为 = " << *e << endl;

	cout << "清空链队" << endl;
	ClearQueue(ex);
	cout << "队长为 = " << ex.length << endl;
}
int main() {
	srand(time(0));
	test010();
	system("pause");
	return 0;
}