#include<stdio.h> 
#include<iostream>
using namespace std;

typedef struct LNode { //���嵥����Ľڵ�����
	int data;		   //����������
	struct LNode* next;   //����ָ����
}LNode, *LinkList;	   //������struct LNodeΪLNode��������ָ��struct LNode*ΪLinklist

LinkList List_HeadInsert(LinkList &L) { //ͷ�巨������������������������
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
	L->next = NULL;						 //��ʼΪ�����������û���Ұָ��
	scanf_s("%d", &x);					 //���û�����һ������
	while (x != -1) {					 //x=-1 ��ʱ���ֹͣ
		s = (LNode*)malloc(sizeof(LNode)); //�����½ڵ�
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList &L) {    //β�巨������������������������
	int x; 
	L = (LinkList)malloc(sizeof(LNode));   //����ͷ���
	//L->next = NULL; ����û����һ�������������ɣ����Ч��
	LNode *s, *r = L;					   //r�Ǳ�βָ��
	scanf_s("%d", &x);					   //���û�����һ������
	while (x != -1) {					   //x=-1 ��ʱ���ֹͣ
		s = (LNode*)malloc(sizeof(LNode)); //�����½ڵ�
		s->data = x;
		r->next = s;
		r = s;							   //ʼ����r��ɱ�βָ��
		scanf_s("%d", &x);
	}
	r->next = NULL;						   //��βָ��NULL
	return L;
}

LNode* GetElem(LinkList L, int i) {		   //�ҵ�������L�ĵ�i���ڵ�	
	if (i < 0) return NULL;				   //i��ֵС��0�����Ϸ�
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

LNode* LocateElem(LinkList L, int e) {    //�ҵ�ֵΪe�ĵ�һ���ڵ�
	LNode* p = L->next;					  //�ӵ�һ����ʼ��
	while (p->data != e && p != NULL) p = p->next;
	return p;
}

bool InsertNextNode(LNode* p, int e) {   //��p�ڵ�֮�����Ԫ��e
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;         //�ڴ治�����ʧ��
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertPriorNode(LNode* p, int e) {   //��p�ڵ�֮ǰ����Ԫ��e
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;         //�ڴ治�����ʧ��
	s->data = p->data;
	s->next = p->next;
	p->next = s;
	p->data = e;
	return true;
}

bool DeleteNode(LNode* p) {	//ָ��ɾ��p�ڵ㣬���ַ���p���������һ��
	if (p == NULL) return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

bool DeleteNextNode(LNode* p, int &e) {	//ɾ��p�ڵ�����һ���ڵ�,���ر�ɾ����Ԫ��e
	if (p == NULL || p->next == NULL) return false; //pΪ�ջ���pΪ���һ���ڵ㶼����
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

bool ListInsert(LinkList &L, int i, int e) { //�ڵ�i��λ�ò���Ԫ��e
	LNode* p = GetElem(L, i);
	return InsertNextNode(p, e);
}

int ListDelete(LinkList &L, int i, int &e) { //ɾ����i��λ�ò���Ԫ��e��������
	LNode* p = GetElem(L, i);
	return DeleteNextNode(p, e);
}

void DestoryList(LinkList &L) {	//���ٵ�����L
	LNode *p = L;
	while (p != NULL){
		LNode* r = p;
		p = p->next;
		free(r);
	}
}

LinkList ReverseList(LinkList &L) { //���õ�����L
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