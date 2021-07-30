#include<stdio.h> 
#include<iostream>
using namespace std;

#define Initsize 50 //表长度初始定义

typedef struct {
	int *data; //指示动态分配数组的指针
	int Maxsize, length; //表最大容量，以及表中目前存在几个元素
}Sqlist;

//初始化一个顺序表
void InitList(Sqlist &L) {
	L.data = (int*)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.Maxsize = Initsize;
}

//增加动态数组的长度,增加len个
void IncreseSize(Sqlist &L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.Maxsize + len) * sizeof(int)); //申请一片新的连续区域
	for (int i = 0; i < L.length; i++) L.data[i] = p[i]; //复制
	L.Maxsize = L.Maxsize + len;
	free(p); //释放原来的空间
}

//插入，在第i个位置插入新元素e
bool ListInsert(Sqlist &L, int i, int e) {
	if (i < 1 || i > L.length) return false; //判断i的范围
	if (L.length >= L.Maxsize) return false; //此时存储空间已满，同样不可以插入
	for (int j = L.length; j >= i; j--) L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
};

//删除，删除第i个元素，并且使e等于被删除的元素
bool ListDelete(Sqlist &L, int i, int &e) {
	if (i < 1 || i > L.length) return false; //判断i的范围
	e = L.data[i - 1];
	for (int j = i; j <= L.length; j++) L.data[j - 1] = L.data[j];
	L.length--;
	return false;
}

//按值查找，找到第一个元素值为e的元素，并且返回其次序
int LocateElem(Sqlist L, int e) {
	for (int i = 0;i < L.length;i++) {
		if (L.data[i] == e) return i + 1;
	}
	return -1;
}

//按位查找，返回第i个元素的值
int GetElem(Sqlist L, int i) {
	if (i < 1 || i > L.length) return -1; //判断i的范围
	return L.data[i - 1];
}

//求表长
int Length(Sqlist L) {
	return L.length;
}

//输出所有元素
void PrintList(Sqlist L) {
	for (int i = 0; i < L.length; i++) cout << L.data[i];
}

//判空，线性表为空就返回true，否则返回false
bool Empty(Sqlist L) {
	if (L.length == 0) return true;
	return false;
}

//销毁线性表，并且释放其空间
void DestroyList(Sqlist &L) {
	free(L.data);
}

int main() {
	return 0;
}
