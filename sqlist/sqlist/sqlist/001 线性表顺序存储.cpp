#include <iostream>
using namespace std;

//定义数组长度
#define max 100
//定义返回结果
#define error -1
#define ok 0
//定义元素类型
typedef int elemtype;
//定义顺序线性表
typedef struct {
	elemtype elems[max];//元素数组
	int length;//线性表实际长度
}sqlist;

/*01初始化线性表*/
void InitSqlist(sqlist* init) {
	init->length = 0;
}
/*02判定线性表是否为空*/
int SqlistEmpty(sqlist empty) {
	if (!empty.length)return 0;
}
/*03清空线性表*/
//逻辑清空
void EmptySqlist(sqlist* empty) {
	empty->length = 0;
}
/*04获取线性表长度*/
//eee额,链式存储情况另说，没有设置length用循环统计
int GetLength(sqlist length) {
	return length.length;
}
/*05插入元素*/
//pos为位序
//插入元素值e至位序为pos的位置
int InsertElem(sqlist* insert,int pos,elemtype e) {
	if (pos > insert->length + 1 || insert->length==max)return error;
	if (pos == insert->length + 1)insert->elems[pos - 1] = e;
	else {
		for (int i = insert->length - 1; i >= pos - 1; i--) {
			insert->elems[i + 1] = insert->elems[i];
		}
		insert->elems[pos-1] = e;
	}
	insert->length++;
	return ok;
}
/*06删除元素*/
//删除数组中为val的值(无重复元素)
int DeleteElem(sqlist* dele, elemtype val) {
	if (!dele->length)return error;
	int pos = 0;//val的位序
	int flag = 0;//是否找到val，0为未找到，1为已找到
	for (int i = 0; i < dele->length; i++) {
		if (dele->elems[i] == val) {
			pos = i + 1;
			flag = 1;
			break;
		}
	}
	if (!flag)return error;
	for (int i = pos; i < dele->length; i++) {
		dele->elems[i - 1] = dele->elems[i];
	}
	dele->length--;
	return ok;
}
/*07修改元素的值*/
//修改位序为pos元素的值为e
void ChangeElem(sqlist* change, int pos,elemtype e) {
	change->elems[pos - 1] = e;
}
/*08查找元素*/
//返回位序,否则error
int SearchElem(sqlist search,elemtype val) {
	if (!search.length)return error;
	int flag = 0;//0为未找到，1为找到了
	int pos = 0;//位序存储
	for (int i = 0; i < search.length; i++) {
		if (search.elems[i] == val) {
			pos = i + 1;
			flag = 1;
			break;
		}
	}
	if (!flag)return error;
	else return pos;
}
int main001() {
	sqlist exam;
	//初始化线性表
	InitSqlist(&exam);

	//插入元素
	cout << "请输入5个元素" << endl;
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		cin >> temp;
		InsertElem(&exam, i + 1, temp);
	}

	//得到线性表长度
	int length=GetLength(exam);
	cout << "线性表表长 = " << length << endl<<endl;

	//查找元素
	int pos = SearchElem(exam, 12);
	if (pos > 0)cout << "12的位序 = " << pos << endl;

	//修改元素
	cout << endl << "线性表修改第三位序前 = {";
	for (int i = 0; i < exam.length; i++) {
		cout << exam.elems[i] << ", ";
	}
	cout << "}" << endl;
	ChangeElem(&exam, 3, 48);
	cout << endl << "线性表修改第三位序后 = {";
	for (int i = 0; i < exam.length; i++) {
		cout << exam.elems[i] << ", ";
	}
	cout << "}" << endl;

	//删除元素
	cout << endl << "线性表删除34前 = {";
	for (int i = 0; i < exam.length; i++) {
		cout << exam.elems[i] << ", ";
	}
	cout << "}" << endl;
	DeleteElem(&exam, 34);
	cout << endl << "线性表删除34后 = {";
	for (int i = 0; i < exam.length; i++) {
		cout << exam.elems[i] << ", ";
	}
	cout << "}" << endl;

	//线性判空
	cout << endl;
	int empty = SqlistEmpty(exam);
	if (!empty)cout << "线性表为空" << endl;
	else cout << "线性表不为空" << endl;

	//线性表清空
	cout << endl;
	EmptySqlist(&exam);
	int emp = SqlistEmpty(exam);
	if (!emp)cout << "线性表为空" << endl;
	else cout << "线性表不为空" << endl;
	cout << endl;
	system("pause");
	return 0;
}