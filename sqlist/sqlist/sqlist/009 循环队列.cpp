#include <iostream>
using namespace std;
#include <ctime>

#define max 10
#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

/*
顺序队列
front=back为空
(back+1)%max==front 为满
*/

/*数据类型*/
typedef struct sqq {
	elemtype q[max];
	int front;
	int back;
}sqqueue,*sq;

//初始化循环队列
status InitQueue(sq init) {
	init->front = 0;
	init->back = 0;
	return ok;
}

//插入元素
status InsertElem(sq insert, elemtype e) {
	//判满
	if ((insert->back + 1) % max == insert->front)return error;
	insert->q[insert->back] = e;
	insert->back = (insert->back + 1) % max;
	return ok;
}

//删除元素
status DeleteElem(sq de, elemtype* e) {
	//判空
	if (de->front == de->back)return error;
	*e = de->q[de->front];
	de->front = (de->front + 1) % max;
	return ok;
}

//获取队长
int GetLength(sq get) {
	return (get->back - get->front + max) % max;
}

////查找队列第i个元素
//status SearchElem(sq search,int i, elemtype* e) {
//	if (i<1 || i>GetLength(search))return error;
//	*e = search->q[search->front + i - 1];
//	return ok;
//}

//返回队列队头元素
status ReturnElem(sq re, elemtype* e) {
	if (re->front == re->back)return error;
	*e = re->q[re->front];
	return ok;
}

//清空队列
status ClearQueue(sq clear) {
	clear->front = clear->back;
	return ok;
}

//队列打印
status print(sq ex) {
	if (ex->front == ex->back)cout << "队列为空" << endl;
	if (ex->front < ex->back) {
		for (int i = ex->front; i < ex->back; i++) {
			cout << ex->q[i] << " ";
		}
		cout << endl;
	}
	else if(ex->front>ex->back){
		for (int i = ex->front; i < max; i++) {
			cout << ex->q[i] << " ";
		}

		for (int i = 0; i < ex->back; i++) {
			cout << ex->q[i] << " ";
		}
		cout << endl;
	}
	return ok;
}

void test009() {
	sq ex=new sqqueue();
	InitQueue(ex);
	int length = rand() % 8 + 1;
	cout << "length = " << length << endl;
	while (length--) {
		elemtype e = rand() % 234 + 1;
		InsertElem(ex, e);
	}


	cout << "初始队列" << " ";
	print(ex);
	cout << "当前队长:" << " ";
	cout << GetLength(ex) << endl;


	elemtype* e=new elemtype();
	DeleteElem(ex, e);
	cout << "队尾元素为：" << *e << endl;


	cout << "获取队头元素" << endl;
	ReturnElem(ex, e);
	cout << "队头元素为：" <<*e<< endl;


	cout << "删除队尾元素" << " ";
	print(ex);
	cout << "当前队长:" << " ";
	cout << GetLength(ex) << endl;


	cout << "清空队列" << " ";
	ClearQueue(ex);
	print(ex);
	cout << "当前队长:" << " ";
	cout << GetLength(ex) << endl;

}
int main() {
	srand(time(0));
	test009();
	system("pause");
	return 0;
}