#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*二叉排序树查找*/


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
bstree Binary_Sort_Tree(bstree b, keytype key) {
	if ((!b) || key == b->key.word)return b;
	else if (key < b->key.word) return Binary_Sort_Tree(b->lchild, key);
	else return Binary_Sort_Tree(b->rchild, key);
}/*Binary_Sort_Tree*/
/*初始化函数*/
/*开辟空间并给数据域赋值，返回空间地址*/
bstree Init_Binary_Sort_Tree(int goal) {
	bstree n = (bst*)malloc(sizeof(bst));
	n->key.word = goal;
	return n;
}

int main() {
	/*初始化二叉排序树*/
	/*固定指针*/
	bstree quite=(bst*)malloc(sizeof(bst));
	/*动态指针*/
	bstree active=quite;
	/*赋值*/
	/*左子树赋值*/
	quite->key.word = 122;
	active->lchild = Init_Binary_Sort_Tree(99);
	active = active->lchild;
	active->rchild = Init_Binary_Sort_Tree(110);
	active = active->rchild;
	active->lchild = Init_Binary_Sort_Tree(105);
	active = active->lchild;
	/*回到根节点*/
	active = quite;
	/*右子树赋值*/
	active->rchild = Init_Binary_Sort_Tree(250);
	active = active->rchild;
	active->lchild = Init_Binary_Sort_Tree(200);
	active->rchild = Init_Binary_Sort_Tree(300);
	active = active->lchild;
	active->rchild = Init_Binary_Sort_Tree(230);
	active = active->rchild;
	active->lchild = Init_Binary_Sort_Tree(216);
	/*回到根节点*/
	active = quite;
	/*算法查找*/
	keytype key = 105;/*目标值*/
	bstree end = Binary_Sort_Tree(quite, key);
	if (!end)printf("没找着");
	else printf("找到了，地址是%p\n", end);
	return 0;
}