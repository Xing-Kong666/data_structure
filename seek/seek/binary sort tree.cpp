#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*二叉排序树查找*/




#define ok 0
#define error 1
typedef int keytype;
/*二叉排序树数值类型*/
typedef struct {
	keytype word;
	char* other;
}elemtype;
/*二叉排序树节点类型*/
typedef struct bst {
	elemtype key;/*查找关键字结构体*/
	bst* lchild, * rchild;/*树的左右孩子*/
}bst,*bstree;/*查找表和根节点*/





/*递归查找函数*/
bstree Binary_Sort_Tree_Search(bstree b, keytype key) {
	if ((!b) || key == b->key.word)
		return b;
	else if (key < b->key.word) 
		return Binary_Sort_Tree_Search(b->lchild, key);
	else 
		return Binary_Sort_Tree_Search(b->rchild, key);
}/*Binary_Sort_Tree_Search*/

/*初始化节点*/
/*开辟空间并给数据域赋值，返回空间地址*/
void Init_Binary_Sort_Tree(bstree &active,int goal) {
	active = (bst*)calloc(1,sizeof(bst));
	if (!active)return;
	active->key.word = goal;
}/*Init_Binary_Sort_Tree*/

/*二叉排序树的插入*/
int Binary_Sort_Tree_Insert(bstree &b, keytype key) {
	if (!b) {
		b = (bst*)calloc(1,sizeof(bst));
		if (!b)return -1;
		b->key.word = key;
		return ok;
	}
	else if (key > b->key.word)
		Binary_Sort_Tree_Insert(b->rchild, key);
	else if (key < b->key.word)
		Binary_Sort_Tree_Insert(b->lchild, key);
	else return ok;
}/*Binary_Sort_Tree_Insert*/

/*二叉排序树的生成*/
int Binary_Sort_Tree_Init(bstree &b, int* keys,int keyslength) {
	b = (bst*)calloc(1,sizeof(bst));
	if (!b)return -1;
	bstree root = b;
	b->key.word = keys[0];
	for (int i = 1; i < keyslength; i++) {/*对每一个关键字数值进行从根节点的路径比较*/
		while (b) {
			if (keys[i] < b->key.word) {/*小*/
				if (b->lchild) b = b->lchild;/*后面有就继续比较*/
				else {/*后面没有就开辟空间填入结束*/
					b->lchild = (bst*)calloc(1,sizeof(bst));
					b = b->lchild;
					b->key.word = keys[i];
					break;
				}
			}
			else if (keys[i] > b->key.word) {/*大*/
				if (b->rchild) b = b->rchild;/*后面有继续比较*/
				else {/*没有就填入*/
					b->rchild = (bst*)calloc(1,sizeof(bst));
					b = b->rchild;
					b->key.word = keys[i];
					break;
				}
			}
			else continue;
		}
		b = root;/*地址重置进行下一个关键字数值的循环*/
	}
	return ok;
}/*Binary_Sort_Tree_Init*/
/*释放内存*/
void Free_Tree(bstree b) {
	if (!b)return;
	Free_Tree(b->lchild);
	Free_Tree(b->rchild);
	free(b);
}
/*中序打印二叉树*/
void Print_Tree(bstree b) {
	if (!b)return;
	Print_Tree(b->lchild);
	printf("%d ", b->key.word);
	Print_Tree(b->rchild);
}




int main() {
	/*初始化二叉排序树*/
	bstree quite=(bst*)malloc(sizeof(bst));/*固定指针*/
	bstree active=quite;/*动态指针*/
	if (!quite)return -1;
	/*赋值*/
	quite->key.word = 122;/*左子树赋值*/
	Init_Binary_Sort_Tree(active->lchild,99);
	active = active->lchild;
	Init_Binary_Sort_Tree(active->rchild,110);
	active = active->rchild;
	Init_Binary_Sort_Tree(active->lchild, 105);
	active = active->lchild;
	active = quite;/*回到根节点*/
	Init_Binary_Sort_Tree(active->rchild, 250);/*右子树赋值*/
	active = active->rchild;
	Init_Binary_Sort_Tree(active->lchild, 200);
	Init_Binary_Sort_Tree(active->rchild, 300);
	bstree active2 = active->rchild;
	active = active->lchild;
	Init_Binary_Sort_Tree(active->rchild, 230);
	active = active->rchild;
	Init_Binary_Sort_Tree(active->lchild, 216);
	active = active->lchild;
	active = quite;/*回到根节点*/
	/*算法查找*/
	keytype key1 = 105;/*目标值*/
	bstree end = Binary_Sort_Tree_Search(active, key1);
	if (!end)printf("没找着");
	else printf("找到了，地址是%p,内容是%d\n", end,end->key.word);
	printf("显示查找的二叉排序树: ");
	Print_Tree(active);
	printf("\n");
	/*算法插入*/
	keytype key2 = 100;
	Binary_Sort_Tree_Insert(active, key2);
	printf("插入100: ");
	Print_Tree(active);
	printf("\n");
	/*释放当前额外内存*/
	Free_Tree(active);
	active = NULL;
	quite = NULL;
	/*算法生成*/
	keytype keys[7] = { 55,11,23,42,25,256,253 };
	bstree b = (bst*)calloc(1,sizeof(bst));
	if (!b)return -1;
	Binary_Sort_Tree_Init(b, keys, 7);
	printf("生成二叉排序树: ");
	Print_Tree(b);
	/*释放内存*/
	Free_Tree(b);
	b = NULL;

	return 0;
}