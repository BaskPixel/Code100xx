#include<stdlib.h>
#include<stdio.h>
#include<iostream>
typedef struct LinkNode
{
	struct LinkNode* next;
	int data;
}LinkNode;
void BuildLinkNode(LinkNode* head, int a[], int n)
{
	head->next = NULL;
	LinkNode* rear = head;
	for (int i = 0; i < n; i++)
	{
		LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = a[i];
		node->next = rear->next;
		rear->next = node;
		rear = node;
	}
}
void Build2(LinkNode* headA, LinkNode* headB)
{

}
// 求平均数
float Arrange(LinkNode* head)
{
	LinkNode* p = head->next;
	int i = 0;
	int j = 0;
	while (p != NULL)
	{
		i += p->data;
		p = p->next;
		j++;
	}
	return i / j;
}
//返回倒数第k个元素，有表头结点
LinkNode* Find(LinkNode* head, int k)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	if (k <= 0)return NULL;
	LinkNode* p = head->next;
	while (p && k > 1)
	{
		p = p->next;
		k--;
	}
	if (p)return p;
	return NULL;
}

int LinkLength(LinkNode* head)
{
	int i = 0;
	LinkNode* p = head->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//相交链表
LinkNode* getIntersectionNode(LinkNode* headA, LinkNode* headB)
{
	int lA = LinkLength(headA);
	int lB = LinkLength(headB);
	int Db = 0;
	LinkNode* longer, * shorter;
	if (lA > lB)
	{
		longer = headA->next;
		shorter = headB->next;
		Db = lA - lB;
	}
	else
	{
		longer = headB->next;
		shorter = headA->next;
		Db = lB - lA;
	}
	while (Db--)
	{
		longer = longer->next;
	}
	while (longer != NULL)
	{
		if (longer == shorter)
			return longer;
		longer = longer->next;
		shorter = shorter->next;
	}
	return NULL;
}
LinkNode* MediumNode(LinkNode* head)
{
	LinkNode* p = head->next;
	LinkNode* a = (LinkNode*)malloc(sizeof(LinkNode) * 100);
	int top = 0;
	while (p)
	{
		a[top++] = *p;
		p = p->next;
	}
	return &a[top / 2];
}

LinkNode* Mergelist(LinkNode* l1, LinkNode* l2)
{
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;
	LinkNode* l3 = (LinkNode*)malloc(sizeof(LinkNode));
	l3->next = NULL;
	LinkNode* r = l3;
	LinkNode* q = NULL;
	LinkNode* p1 = l1->next;
	LinkNode* p2 = l2->next;
	while (p1 && p2)
	{
		if (p1->data <= p2->data)
		{
			q = p1;
			p1 = p1->next;

			q->next = r->next;
			r->next = q;
			r = q;

		}
		else
		{
			q = p2;
			p2 = p2->next;
			q->next = r->next;
			r->next = q;
			r = q;
		}
	}
	if (p1)
	{
		r->next = p1;
	}
	else
	{
		r->next = p2;
	}
	return l3;
}

bool HuiWenList(LinkNode* head)
{
	int* a = (int*)malloc(sizeof(int)*100);
	int top = 0;
	LinkNode* p = head->next;
	while (p)
	{
		a[top++] = p->data;
		p = p->next;
	}
	for (int i = 0; i < top; i++)
	{
		if (a[i] != a[top - 1 - i])
			return false;
	}
	return true;
}
/*
*/
/*
int main()
{
	LinkNode* l1 = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* l2 = (LinkNode*)malloc(sizeof(LinkNode));
	int a[] = {1,2,3,2,1};
	int b[] = {2,4,5,6,7};
	BuildLinkNode(l1, a, 5);
	BuildLinkNode(l2, b, 5);
	//std::cout<<Arrange(head);
	//std::cout << Find(head, 5)->data;
	//std::cout << LinkLength(head);
	//LinkNode* r = MediumNode(head);
	//std::cout << r->data;
	return 0;
}
*/