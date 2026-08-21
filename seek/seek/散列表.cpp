#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*散列表*/


/*函数状态*/
typedef int status;
/*各种状态*/
#define ok 0
#define error -1


/*函数设置*/
int* Hash_Graph_Init(int *a,int length) {/*开放定址法*/
	int *hash = (int*)calloc(length,sizeof(int));
	if (!hash)return NULL;
	for (int i = 0; i < length; i++) {
		int j = 0;
		while (j < length) {
			int remain = (a[i] + j) % length;/*线性探测法寻找新的位置*/
			if (hash[remain]) {
				j++;
				continue;
			}
			else {
				hash[remain] = a[i];
				break;
			}
		}
	}
	return hash;
}



int main() {
	/*接收关键字列表*/
	int a[11] = {0};
	printf("请输入11位数字：");
	for (int i = 0; i < 11; i++) {
		scanf("%d", &a[i]);
	}
	/*测试初始化函数*/
	int* hash = Hash_Graph_Init(a,11);
	for (int i = 0; i < 11; i++) {
		printf("%d ", hash[i]);
	}
	printf("\n");
	/*释放内存*/
	free(hash);
	return 0;
}