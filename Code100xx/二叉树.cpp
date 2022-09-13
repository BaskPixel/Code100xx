#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
enum TraverType
{
	pre = 0,
	in = 1,
	post = 2,
};
typedef struct Tree
{
	struct Tree* lchild;
	struct Tree* rchild;
	int data;
};

Tree* BuildTree(int data[])
{
	Tree* n0 = new Tree();
	n0->data = data[0];

	Tree* n1 = new Tree();
	n1->data = data[1];

	Tree* n2 = new Tree();
	n2->data = data[2];

	Tree* n3 = new Tree();
	n3->data = data[3];

	Tree* n4 = new Tree();
	n4->data = data[4];

	Tree* n5 = new Tree();
	n5->data = data[5];

	Tree* n6 = new Tree();
	n6->data = data[6];

	Tree* n7 = new Tree();
	n7->data = data[7];

	n0->lchild = n1;
	n0->rchild = n2;

	n1->lchild = n3;
	n1->rchild = n4;

	n2->lchild = NULL;
	n2->rchild = n5;

	n3->lchild = n6;
	n3->rchild = n7;

	n4->lchild = NULL;
	n4->rchild = NULL;

	n5->lchild = NULL;
	n5->rchild = NULL;

	n6->lchild = NULL;
	n6->rchild = NULL;

	n7->lchild = NULL;
	n7->rchild = NULL;

	return n0;
}
Tree* BuildSearchTree(int data[])
{
	Tree* n0 = new Tree();
	n0->data = data[0];//6

	Tree* n1 = new Tree();
	n1->data = data[1];//2

	Tree* n2 = new Tree();
	n2->data = data[2];//8

	Tree* n3 = new Tree();
	n3->data = data[3];//1

	Tree* n4 = new Tree();
	n4->data = data[4];//4

	Tree* n5 = new Tree();
	n5->data = data[5];//5

	n0->lchild = n1;
	n0->rchild = n2;

	n1->lchild = n3;
	n1->rchild = n4;

	n2->lchild = NULL;
	n2->rchild = NULL;

	n3->lchild = NULL;
	n3->rchild = NULL;

	n4->lchild = n5;
	n4->rchild = NULL;

	n5->lchild = NULL;
	n5->rchild = NULL;

	return n0;
}
//遍历
void PreTraver(Tree* root, TraverType type)
{
	switch (type)
	{
	case pre:
		if (root)
		{
			cout << root->data << " ";
			PreTraver(root->lchild, pre);
			PreTraver(root->rchild, pre);
		}
		break;
	case in:
		if (root)
		{
			PreTraver(root->lchild, in);
			cout << root->data << " ";
			PreTraver(root->rchild, in);
		}
		break;
	case post:
		if (root)
		{
			PreTraver(root->lchild, post);
			PreTraver(root->rchild, post);
			cout << root->data << " ";
		}
		break;
	default:
		break;
	}

}
//获取树的高度
int Height(Tree* root)
{
	int l, r;
	if (root)
	{
		l = Height(root->lchild);
		r = Height(root->rchild);
		return l > r ? l + 1 : r + 1;
	}
	return 0;
}
//求最大宽度
int num = 0;
void Pre(Tree* root, int k)
{
	k--;
	if (root)
	{
		if (k == 0)num++;
		Pre(root->lchild, k);
		Pre(root->rchild, k);
	}
	else
	{
		return;
	}
}
int MaxWidth(Tree* root)
{
	if (root == NULL)return 0;
	if (root->lchild == NULL && root->rchild == NULL)return 1;
	int hei = Height(root);
	if (hei == 1)return 1;
	int maxSize = 0;
	for (int i = 2; i <= hei; i++)
	{
		num = 0;
		Pre(root, i);
		if (num >= maxSize)
			maxSize = num;
	}
	return maxSize;
}
//前序打印结点及结点的层次
void InputLevelTree(Tree* root, int k = 0)
{
	k++;
	if (root)
	{
		cout << "Tree: " << root->data << ",Level: " << k << endl;
		InputLevelTree(root->lchild, k);
		InputLevelTree(root->rchild, k);
	}
}
//打印指定结点的层次
void TreeLevel(Tree* root, int c, int k = 0)
{
	k++;
	if (root)
	{
		if (root->data == c)
		{
			cout << k << endl;
			return;
		}
		TreeLevel(root->lchild, c, k);
		TreeLevel(root->rchild, c, k);
	}
}
//打印前k层的所有结点
void PrintKLevel(Tree* root, int k)
{
	if (k == 0)return;
	if (k > Height(root))return;
	k--;
	if (root)
	{
		cout << root->data << " ";
		if (k == 0) { return; }
		PrintKLevel(root->lchild, k);
		PrintKLevel(root->rchild, k);
	}
}
//打印第k层的所有结点
void PrintNumKLevel(Tree* root, int k)
{
	if (k<0 || k>Height(root))return;
	k--;
	if (root)
	{
		if (k == 0) {
			cout << root->data << " ";
			return;
		}
		PrintNumKLevel(root->lchild, k);
		PrintNumKLevel(root->rchild, k);
	}
}
//打印偶数层次的结点
void PrintEventLevelTree(Tree* root, int k = 0)
{
	k--;
	if (root)
	{
		if (k == 0)
		{
			cout << root->data << " ";
		}
		PrintEventLevelTree(root->lchild, k);
		PrintEventLevelTree(root->rchild, k);
	}
}
void Solve(Tree* root)
{
	for (int i = 1; i <= Height(root); i++)
	{
		if (i % 2 != 0)
		{
			PrintEventLevelTree(root, i);
		}
	}
}
//白页纸题
//2
bool TwoSame(Tree* t1, Tree* t2)
{
	if (t1 == NULL && t2 == NULL)return true;
	else if (t1 == NULL || t2 == NULL)return false;
	else if (t1->data != t2->data)return false;
	else
	{
		return TwoSame(t1->lchild, t2->lchild) &&
			TwoSame(t1->rchild, t2->rchild);
	}
}
//3
bool Check(Tree* p, Tree* q)
{
	if (!p && !q)return true;
	if (p == NULL || q == NULL)return false;
	return p->data == q->data && Check(p->lchild, q->rchild) && Check(p->rchild, q->lchild);
}
bool IsSymmetric(Tree* root)
{
	return Check(root->lchild, root->rchild);
}
//4
int maxDepth(Tree* root)
{
	int l, r;
	if (!root)return 0;
	l = maxDepth(root->lchild);
	r = maxDepth(root->rchild);
	if (l > r)
	{
		return l + 1;
	}
	else
	{
		return r + 1;
	}
}
//5
Tree* helper(int nums[], int left, int right)
{
	if (left > right)return NULL;
	int m = (left + right) / 2;
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->data = nums[m];
	node->lchild = helper(nums, left, m - 1);
	node->rchild = helper(nums, m + 1, right);
	return node;
}
Tree* sortedArrayToBST(int nums[], int numSize)
{
	return helper(nums, 0, numSize - 1);
}
//6
bool BlanceTree(Tree* root)
{
	if (root == NULL)return 0;
	if (root)
	{
		int l = Height(root->lchild);
		int r = Height(root->rchild);
		if (l - r > 1 || l - r < -1)return false;
		BlanceTree(root->lchild);
		BlanceTree(root->rchild);
		return true;
	}
}
//11
void ConstructPath(Tree* root, int sta[], int top)
{
	if (root != NULL)
	{
		if (root->lchild == NULL && root->rchild == NULL)
		{
			sta[top++] = root->data;
			for (int i = 0; i < top; i++)
			{
				cout << sta[i] << " ";
			}
			cout << endl;
		}
		else
		{
			sta[top++] = root->data;
			ConstructPath(root->lchild, sta, top);
			ConstructPath(root->rchild, sta, top);
		}
	}
}
void AllTreePath(Tree* root)
{
	int sta[1024];
	ConstructPath(root, sta, 0);
}
//12
bool helper8(Tree* root, int target)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		return target == root->data;
	}
	bool l = helper8(root->lchild, target - root->data);
	bool r = helper8(root->rchild, target - root->data);
	return l || r;
}
//12
int ls = 0;
bool isLeafTree(Tree* Tree)
{
	if (Tree->rchild == NULL && Tree->lchild == NULL)return true;
	else return false;
}
int dfsTree(Tree* root)
{
	int ans = 0;
	if (root->lchild)
	{
		if (isLeafTree(root->lchild))
		{
			ans += root->lchild->data;
		}
		else
		{
			ans += dfsTree(root->lchild);
		}
	}
	//如果是右节点但右节点不是叶子节点
	if (root->rchild && isLeafTree(root->rchild) == false)
	{
		if (isLeafTree(root->rchild))
		{
			ans += root->rchild->data;
		}
		else
		{
			ans += dfsTree(root->rchild);
		}
	}
	return ans;
}
int LeftSum(Tree* root)
{
	return root ? dfsTree(root) : 0;
}
//15
int ans = 0;
int depth(Tree* root)
{
	if (root == NULL)return 0;
	int L = depth(root->lchild);
	int R = depth(root->rchild);
	ans = ans > (L + R + 1) ? ans : (L + R + 1);
	return L > R ? L + 1 : R + 1;
}
int diameterOfBinaryTree(Tree* root)
{
	ans = 1;
	depth(root);
	return ans - 1;
}
//16
int tnn = 0;
int dfs16(Tree* root)
{
	if (root == NULL) return 0;
	int L = dfs16(root->lchild);
	int R = dfs16(root->rchild);
	tnn += abs(L - R);
	return L + R + root->data;
}
int find(Tree* root)
{
	dfs16(root);
	return tnn;
}
//非递归不适用栈返回二叉树的前序遍历的最后一个结点
Tree* PreLastNode(Tree* root)
{
	Tree* p = root;
	while (1)
	{
		if (p->rchild)
		{
			p = p->rchild;
		}
		else if (p->lchild)
		{
			p = p->lchild;
		}
		else
			break;
	}
	return p;
}
//两个结点之和
int dyy[100];
int ii = 0;
void Pre(Tree* root)
{
	if (root)
	{
		dyy[ii++] = root->data;
		Pre(root->lchild);
		Pre(root->rchild);
	}
}
bool Dyy(Tree* root, int k, int n)
{
	if (!root)return false;
	Pre(root);
	for (int j = 0; j < n; j++)
	{
		int d = k - dyy[j];
		for (int k = j; k < n; k++)
		{
			if (d == dyy[k])
				return true;
		}
	}
	return false;
}
//反转二叉树
Tree* Rve(Tree* root)
{
	if (root == NULL)return NULL;
	Tree* l = Rve(root->lchild);
	Tree* r = Rve(root->rchild);
	root->lchild = r;
	root->rchild = l;
	return root;
}
//是否是平衡二叉树
bool IsBlance(Tree* root)
{
	if (root == NULL)return true;
	if (root)
	{
		int l = Height(root->lchild);
		int r = Height(root->rchild);
		if (l - r < -1 || l - r>1)return false;
		return IsBlance(root->lchild) &&
			IsBlance(root->rchild);
	}
}
/*找出二叉排序树的最大节点和最小节点的各自的层次*/
int* b;
int topa;
void Prea(Tree* root)
{
	if (root == NULL)return;
	Prea(root->lchild);
	b[topa++] = root->data;
	Prea(root->rchild);
}
//求指定结点的层次
void NodeLevel(Tree* root, int c, int k)
{
	k++;
	if (root)
	{
		if (root->data == c)
		{
			cout << k << endl;
			return;
		}
		TreeLevel(root->lchild, c, k);
		TreeLevel(root->rchild, c, k);
	}
}
void Solvea(Tree* root)
{
	if (!root)return;
	b = (int*)malloc(sizeof(int) * 100);
	topa = 0;
	Prea(root);
	cout << "最小：" << b[0] << "层次：";
	NodeLevel(root, b[0], 0);
	cout << "最大：" << b[topa - 1] << "层次：";
	NodeLevel(root, b[topa - 1], 0);
}

//求最大宽度
int counta = 0;
void Pre0(Tree* root, int d)
{
	d--;
	if (root)
	{
		if (d == 0)counta++;
		Pre0(root->lchild, d);
		Pre0(root->rchild, d);
	}
}
int MaxWidth2(Tree* root)
{
	if (root == NULL)return 0;
	int h = Height(root);
	int max = 0;
	for (int i = 1; i <= h; i++)
	{
		Pre0(root, i);
		if (counta >= max)
		{
			max = counta;
			counta = 0;
		}
	}
	return max;
}

#pragma region 输出二叉排序树中的最大和最小的结点以及各自的层次
void WanQuanCengCi(Tree* root)
{
	if (root == NULL)return;
	int ln = 1, rn = 1;
	Tree* l = root, * r = root;
	while (l->lchild)
	{
		l = l->lchild;
		ln++;
	}
	while (r->rchild)
	{
		r = r->rchild;
		rn++;
	}
	cout << "Max:" << r->data << "Level:" << rn << endl;
	cout << "Min:" << l->data << "Level:" << ln << endl;
}
#pragma endregion
#pragma region 1从大到小输出二叉排序树中所有值不小于k的关键字
int B[1024];
int b0;
void InOrder1(Tree* root)
{
	if (root)
	{
		InOrder1(root->lchild);
		B[b0++] = root->data;
		InOrder1(root->rchild);
	}
}
void Solver4(Tree* root, int k, int c)
{
	if (root == NULL)return;
	b0 = 0;
	InOrder1(root);
	for (int i = c - 1; i >= 0; i--)
	{
		if (B[i] >= k)
		{
			cout << B[i] << " ";
		}
	}
}
#pragma endregion
#pragma region 2在二叉排序中查找第k小的元素
Tree C[1024];
int c0 = 0;
void InOrder2(Tree* root)
{
	if (root)
	{
		InOrder2(root->lchild);
		C[c0++] = *root;
		InOrder2(root->rchild);
	}
}
Tree* Solver2(Tree* root, int k, int n)
{
	if (k <= 0 || k > n)return NULL;
	InOrder2(root);
	return &C[k - 1];
}
#pragma endregion
#pragma region 1根节点为t的后跟遍历最后一个结点
Tree* Post1(Tree* root)
{
	if (root)
	{
		Post1(root->lchild);
		Post1(root->rchild);
		return root;
	}
}
#pragma endregion
#pragma region 完全二叉树存储在数组中，求先序遍历
void Pre5(Tree* root)
{
	if (root)
	{
		cout << root->data << " ";
		Pre5(root->lchild);
		Pre5(root->rchild);
	}
}
Tree* Creat5(int d[], int s, int n)
{
	if (s <= n)
	{
		Tree* curr = (Tree*)malloc(sizeof(Tree));
		curr->data = d[s];
		curr->lchild = Creat5(d, 2 * s, n);
		curr->rchild = Creat5(d, 2 * s + 1, n);
		return curr;
	}
	else
	{
		return NULL;
	}
}
void Solver5(int d[], int s, int n)
{
	Tree* t = Creat5(d, s, n);
	Pre5(t);
	PreTraver(t, in);
}
#pragma endregion

/* 构建树结构如下：

			  1
			 / \
			2   3
		   / \   \
		  4   5   6
		 / \
		7   8
二叉查找树：
			  6
			 / \
			2   8
		   / \
		  1   4
		   \
			3
*/
/*
int main()
{
	int data1[8] = { 1,2,3,4,5,6,7,8 };
	int data2[8] = { 1,2,3,4,5,6,7,8 };
	int data3[6] = { 6,2,8,1,4,3 };
	Tree* root = BuildTree(data1);
	Tree* root2 = BuildTree(data2);
	Tree* searchTree = BuildSearchTree(data3);
	return 0;
}
*/
