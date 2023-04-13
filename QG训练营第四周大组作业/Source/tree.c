#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

BinarySortTreePtr BST_init() {
	BinarySortTreePtr a = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	if (a == NULL) {
		printf("树的创建失败！请检查系统环境");
		exit(-1);
	}
	a->root = NULL;
	return a;
}

Status BST_insert(BinarySortTreePtr a, ElemType num) {
	BinarySortTreePtr b = malloc(sizeof(BinarySortTree));
	BinarySortTreePtr c = malloc(sizeof(BinarySortTree));
	BinarySortTreePtr d = malloc(sizeof(BinarySortTree));
	b = BST_init();
	c = BST_init();
	d = BST_init();
	c->root = malloc(sizeof(Node));
	c->root->value = num;
	c->root->left = NULL;
	c->root->right = NULL;
	if (a->root == NULL){
		a->root = (NodePtr)malloc(sizeof(Node));
		a->root = c->root;
		return 1;
	}
	else {
		b->root = a->root;
		while (b->root != NULL)
		{
			d->root = b->root;
			if (b->root->value >num) {
				b->root = b->root->left;
			}
			else if (b->root->value < num) {
				b->root = b->root->right;
			}
			else if (b->root->value == num)	return 0;
		}
		if (d->root->value > num) {
			d->root->left =c->root;
		}
		else if (d->root->value < num) {
			d->root->right = c->root;
		}
		return 1;
	}
}

Status BST_delete(BinarySortTreePtr a, ElemType num) {
	if (a->root == NULL) {
		printf("二叉树为空！");
		return 0;
	}
	if (a->root->value ==num) {
		a->root = NULL;
	}
	BinarySortTreePtr b = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	BinarySortTreePtr c = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	b = BST_init();
	c = BST_init();
	b->root = a->root;
	c->root = b->root;
	int count = 0;
	while(b->root!=NULL)
	{
		c->root = b->root;
		if (num < b->root->value) {
			b->root = b->root->left;
			count = 1;
		}
		else if (num > b->root->value) {
			b->root = b->root->right;
			count = 2;
		}
		if (num == b->root->value ) {
			if (b->root->left != NULL&&count == 1) {
				c->root->left = b->root->left;
				return 1;
			}
			else if (b->root->right != NULL && count == 2) {
				c->root->right = b->root->right;
				return 1;
			}
			else {
				if (count == 1) {
					c->root->left = NULL;
					free(b);
					return 1;
				}
				else if (count == 2) {
					c->root->right = NULL;
					free(b);
					return 1;
				}
			}
		}
	}
}

Status BST_search(BinarySortTreePtr a, ElemType num) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	p->root = a->root;
	while (p->root != NULL)
	{
		if (p->root->value > num)	p->root = p->root->left;
		else if (p->root->value < num)	p->root = p->root->right;
		else if (p->root->value == num) {
			printf("二叉树中有该数字！\n");
			return 1;
		}
	}
	printf("二叉树中没有该数字！\n");
	return 0;
}

Status BST_preorderI(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(p);
	pushLStack(p, a);
	while (!isEmptyLStack(p)) 
	{
		NodePtr T  = malloc(sizeof(Node));
		popLStack(p, &T);
		visit(T);
		if (T->right)	pushLStack(p, T->right);
		if (T->left)	pushLStack(p, T->left);
	}
	return 1;
}

//Status BST_preorderI(NodePtr a, void (*visit)(NodePtr)) {
//	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
//	initLStack(p);
//	NodePtr t;
//	t = a;
//	while (t||!isEmptyLStack(p)) 
//	{
//		if (t) {
//			visit(t);
//			pushLStack(p, t);
//			t = t->left;
//		}
//		else {
//			popLStack(p, &t);		//出栈会有问题
//			t = t->right;
//		}
//	}
//}

Status BST_preorderR(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		return 0;
	}
	visit(a);
	BST_preorderR(a->left,Printf_tree);
	BST_preorderR(a->right, Printf_tree);
	return 1;
}

Status BST_inorderI(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(p);
	pushLStack(p, a);
	while (!isEmptyLStack(p))
	{
		NodePtr T = malloc(sizeof(Node));
		getTopLStack(p,&T);
		if (T->left&&p->top->site == 0) {
			p->top->site = 1;		//标记法，防止死循环
			pushLStack(p, T->left);
		}
		else if (T->right) {
			popLStack(p, &T);
			visit(T);
			pushLStack(p, T->right);
		}
		else{
			popLStack(p, &T);
			visit(T);
		}
	}
	return 1;
}

Status BST_inorderR(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	BST_inorderR(a->left, Printf_tree);
	visit(a);
	BST_inorderR(a->right, Printf_tree);
	return 1;
}

Status BST_postorderI(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(p);
	pushLStack(p, a);
	while (!isEmptyLStack(p))
	{
		NodePtr T = malloc(sizeof(Node));
		getTopLStack(p, &T);
		if (T->left && p->top->site == 0) {
			p->top->site = 1;		//标记法，防止死循环
			pushLStack(p, T->left);
		}
		else if (p->top->site == 2) {
			popLStack(p, &T);
			visit(T);
		}
		else if (T->right) {
			p->top->site = 2;
			pushLStack(p, T->right);
		}
		else {
			popLStack(p, &T);
			visit(T);
		}
	}
	return 1;
}

Status BST_postorderR(NodePtr a, void (*visit)(NodePtr)) {
	if (a == NULL) {
		printf("二叉树为空！\n");
		return 0;
	}
	BST_postorderR(a->left, Printf_tree);
	BST_postorderR(a->right, Printf_tree);
	visit(a);
	return 1;
}

void Printf_tree(NodePtr a) {		//打印树的结点数值
	printf("%d\n", a->value);
}