#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include <cstdlib>
using namespace std;

typedef struct Sqlist {
	int length = 0;
	vector<int> r;
}Sqlist;

class sortlist
{
public:
	Sqlist L;
	Sqlist Lreal;
	int movenum;//记录算法移动次数;
	int compnum;//记录算法比较次数；
	sortlist() = default;
	sortlist(vector<int> T) {
		Lreal.r.push_back(0);//其中r[0]为哨兵,初始化为0
		for (int i = 0; i < T.size(); i++) {
			Lreal.r.push_back(T[i]);
		}
		Lreal.length = T.size();
		movenum = 0;
		compnum = 0;
	}
	void copy() {
		L.length = Lreal.length;
		L.r.assign(Lreal.r.begin(), Lreal.r.end());
	}
	void swap(int x, int y);
	bool compare(int x, int y);
	void Halfsort();//折半插入
	void Doubsort();//二路插入
	void Deinsort();//直接插入
	void Shellsort();//希尔插入
	void Bubblesort();//冒泡
	void Quicksrot();//快速排序
	void Sort(int low,int high);
	int Partion(int low,int high);
	void Selectsort();//选择排序
	void Heapadjust(int s,int m);
	void Heapsort();//堆排序
	void Msort(vector<int> &SR, vector<int>&Tr, int s,int t);
	void Merge(vector<int> &SR, vector<int>&Tr, int i,int m,int n);
	void Mergesort();//归并
	void Showresult();
	void Shownum();
};

