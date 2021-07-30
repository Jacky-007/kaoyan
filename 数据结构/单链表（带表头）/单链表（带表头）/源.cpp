#include<stdio.h> 
#include<iostream>
using namespace std;

typedef struct LNode { //定义单链表的节点类型
	int data;		   //定义数据域
	struct LNode* next;   //定义指针域
}LNode, *LinkList;	   //重命名struct LNode为LNode，重命名指针struct LNode*为Linklist

LinkList List_HeadInsert(LinkList &L) { //头插法建立单链表，这样可以逆向建立
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); //建立头结点
	L->next = NULL;						 //初始为空链表，不设置会有野指针
	scanf_s("%d", &x);					 //让用户输入一个整数
	while (x != -1) {					 //x=-1 的时候就停止
		s = (LNode*)malloc(sizeof(LNode)); //创建新节点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList &L) {    //尾插法建立单链表，这样可以正向建立
	int x; 
	L = (LinkList)malloc(sizeof(LNode));   //建立头结点
	//L->next = NULL; 这里没有这一步是想在最后完成，提高效率
	LNode *s, *r = L;					   //r是表尾指针
	scanf_s("%d", &x);					   //让用户输入一个整数
	while (x != -1) {					   //x=-1 的时候就停止
		s = (LNode*)malloc(sizeof(LNode)); //创建新节点
		s->data = x;
		r->next = s;
		r = s;							   //始终让r变成表尾指针
		scanf_s("%d", &x);
	}
	r->next = NULL;						   //表尾指向NULL
	return L;
}

LNode* GetElem(LinkList L, int i) {		   //找到单链表L的第i个节点	
	if (i < 0) return NULL;				   //i的值小于0，不合法
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

LNode* LocateElem(LinkList L, int e) {    //找到值为e的第一个节点
	LNode* p = L->next;					  //从第一个开始找
	while (p->data != e && p != NULL) p = p->next;
	return p;
}

bool InsertNextNode(LNode* p, int e) {   //在p节点之后插入元素e
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;         //内存不足分配失败
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertPriorNode(LNode* p, int e) {   //在p节点之前插入元素e
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;         //内存不足分配失败
	s->data = p->data;
	s->next = p->next;
	p->next = s;
	p->data = e;
	return true;
}

bool DeleteNode(LNode* p) {	//指定删除p节点，这种方法p不能是最后一个
	if (p == NULL) return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

bool DeleteNextNode(LNode* p, int &e) {	//删除p节点后面的一个节点,返回被删除的元素e
	if (p == NULL || p->next == NULL) return false; //p为空或者p为最后一个节点都不行
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

bool ListInsert(LinkList &L, int i, int e) { //在第i的位置插入元素e
	LNode* p = GetElem(L, i);
	return InsertNextNode(p, e);
}

int ListDelete(LinkList &L, int i, int &e) { //删除第i的位置插入元素e，并返回
	LNode* p = GetElem(L, i);
	return DeleteNextNode(p, e);
}

void DestoryList(LinkList &L) {	//销毁单链表L
	LNode *p = L;
	while (p != NULL){
		LNode* r = p;
		p = p->next;
		free(r);
	}
}

LinkList ReverseList(LinkList &L) { //逆置单链表L
	LNode* p = L->next;
	L->next = NULL;
	LNode* q;
	while (p != NULL)
	{
		q = p;
		q->next = L->next;
		L->next = q;
		p = p->next;
	}
	return L;
}

int main() {
	return 0;
}