#include <iostream>
using namespace std;
#include <ctime>

#define error -1
#define ok 0
typedef int status;
typedef int elemtype;

//递归实现
long long fabonacci(int num) {
	if (num == 1 || num == 0)return num;
	return fabonacci(num - 1) + fabonacci(num - 2);
}

//循环实现
void fabonacci(int* nums, int length) {
	nums[0] = 0;
	nums[1] = 1;
	for (int i = 2; i < length; i++) {
		nums[i] = nums[i - 1] + nums[i - 2];
	}
}

//斐波那契数列从1开始
//斐波那契数列第89位，数太大了，换23
void test00801() {
	cout << "fabonacci(23) = " << fabonacci(23) << endl;
}

//打印斐波那契数列前34位
void test00802() {
	int nums[40];
	fabonacci(nums, 40);
	for (int i = 1; i < 35; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
int main008() {
	srand(time(0));
	test00801();
	test00802();
	system("pause");
	return 0;
}