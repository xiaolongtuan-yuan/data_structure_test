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
	int movenum;//��¼�㷨�ƶ�����;
	int compnum;//��¼�㷨�Ƚϴ�����
	sortlist() = default;
	sortlist(vector<int> T) {
		Lreal.r.push_back(0);//����r[0]Ϊ�ڱ�,��ʼ��Ϊ0
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
	void Halfsort();//�۰����
	void Doubsort();//��·����
	void Deinsort();//ֱ�Ӳ���
	void Shellsort();//ϣ������
	void Bubblesort();//ð��
	void Quicksrot();//��������
	void Sort(int low,int high);
	int Partion(int low,int high);
	void Selectsort();//ѡ������
	void Heapadjust(int s,int m);
	void Heapsort();//������
	void Msort(vector<int> &SR, vector<int>&Tr, int s,int t);
	void Merge(vector<int> &SR, vector<int>&Tr, int i,int m,int n);
	void Mergesort();//�鲢
	void Showresult();
	void Shownum();
};

