#include<stdio.h> 
#include<iostream>
using namespace std;

#define Maxsize 50 //���Ա����󳤶ȣ�һ�����£�ʹ���в��ܸ���

typedef struct {
	int data[Maxsize]; //����һ�����������������int���͵�
	int length; //����Ŀǰ���ڼ���Ԫ��
}Sqlist;

//��ʼ��һ��˳���
void InitList(Sqlist &L) {
	L.length = 0;
	//for (int i = 0; i < Maxsize; i++) L.data[i] = 0;
	//û�и�����Ԫ�ظ��ϳ�ʼֵ����Ϊ��length�Ĵ��ڣ����ǲ������˳����л�û�е�Ԫ��
}

//���룬�ڵ�i��λ�ò�����Ԫ��e
bool ListInsert(Sqlist &L, int i, int e) {
	if (i < 1 || i > L.length) return false; //�ж�i�ķ�Χ
	if (L.length >= Maxsize) return false; //��ʱ�洢�ռ�������ͬ�������Բ���
	for (int j = L.length; j >= i; j--) L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
};

//ɾ����ɾ����i��Ԫ�أ�����ʹe���ڱ�ɾ����Ԫ��
bool ListDelete(Sqlist &L, int i, int &e) {
	if (i < 1 || i > L.length) return false; //�ж�i�ķ�Χ
	e = L.data[i - 1];
	for (int j = i; j <= L.length; j++) L.data[j - 1] = L.data[j];
	L.length--;
	return false;
}

//��ֵ���ң��ҵ���һ��Ԫ��ֵΪe��Ԫ�أ����ҷ��������
int LocateElem(Sqlist L, int e) {
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] == e) return i + 1;
	}
	return -1;
}

//��λ���ң����ص�i��Ԫ�ص�ֵ
int GetElem(Sqlist L, int i) {
	if (i < 1 || i > L.length) return -1; //�ж�i�ķ�Χ
	return L.data[i - 1];
}

//���
int Length(Sqlist L) {
	return L.length;
}

//�������Ԫ��
void PrintList(Sqlist L) {
	for (int i = 0; i < L.length; i++) cout << L.data[i];
}

//�пգ����Ա�Ϊ�վͷ���true�����򷵻�false
bool Empty(Sqlist L) {
	if (L.length == 0) return true;
	return false;
}

//�������Ա������ͷ���ռ�
void DestroyList(Sqlist &L) {
	free(L.data);
}

int main() {
	return 0;
}
