#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*散列表*/


/*函数状态*/
typedef int status;
typedef struct hashnode{
	int data;
	hashnode* next;
}hashnode,*hashptr;
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
void Hash_Graph_Init_Link(int* a,hashptr* &head,int length) {/*a为关键字数组，end用于接收返回值，length为a的数组长度*/
	head = (hashptr*)calloc(length, sizeof(hashptr));/*指针数组存放指针指向变量的地址，链地址法*/
	if (!head)return;
	for (int i = 0; i < length; i++) {
		int remain = a[i] % length;
		hashptr node = (hashptr)calloc(1, sizeof(hashnode));
		if (head[remain]) {
			node->next = head[remain];/*头插法*/
			head[remain] = node;
			node->data = a[i];
		}
		else {
			head[remain] = node;
			node->data = a[i];
		}
	}
}
void Free_Link(hashptr* &head,int length) {
	for (int i = 0; i < length; i++) {
		if (!head[i])continue;
		else {
			hashptr end = head[i]->next;
			while (head[i]) {
				if (end) {
					free(head[i]);
					head[i] = end;
					end = end->next;
				}
				else {
					free(head[i]);
					head[i] = NULL;
				}
			}
		}
	}
	free(head);
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
	printf("开放定址法：");
	for (int i = 0; i < 11; i++) {
		printf("%d ", hash[i]);
	}
	printf("\n");

	hashptr *head;
	Hash_Graph_Init_Link(a, head, 11);
	printf("链地址法：");
	printf("\n");
	for (int i = 0; i < 11; i++) {
		hashptr active = head[i];
		printf("第%d行： ",i);
		while (active) {
			printf("%d ", active->data);
			active = active->next;
		}
		printf("\n");
	}
	/*释放内存*/
	free(hash);
	Free_Link(head,11);
	return 0;
}