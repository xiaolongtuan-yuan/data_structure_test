#include "sortlist.h"
void sortlist::swap(int x, int y) {
	int temp = L.r[x];
	L.r[x] = L.r[y];
	L.r[y] = temp;
	movenum = movenum + 3;
	return;
}//交换，算三次移动数
bool sortlist::compare(int x, int y) {
	if (L.r[x] > L.r[y]) {
		compnum++;
		return true;
	}
	else {
		compnum++;
		return false;
	}
}//x值大于y值返回true，小于等于返回false，比较次数加1

void sortlist::Deinsort() {
	copy();
	movenum = 0;
	compnum = 0;
	int i, j;
	for (i = 2; i < L.length; i++) {
		this->L.r[0] = L.r[i];
		if (compare(i-1 , i)) {
			for (j = i; compare(j-1, 0); j--) {
				L.r[j] = L.r[j - 1];
				movenum++;
			}
			swap(0, j);
		}
	}
}//直接插入
void sortlist::Halfsort(){
	copy();
	movenum = 0;
	compnum = 0;
	int i, j,low,high;
	for (i = 2; i < L.length; i++) {
		L.r[0] = L.r[i];
		low = 1, high = i-1; int m = 0;
		while (low <= high) {
			m = (low + high) / 2;
			if (compare(m, 0))//插入点在高半区
				high = m - 1;
			else
				low = m + 1;
		}
		for (j = i - 1; j >= high + 1; j--) {
			L.r[j + 1] = L.r[j];
			movenum++;
		}
		L.r[high+1] = L.r[0];
		movenum++;
	}
}//折半插入
void sortlist::Doubsort(){
	copy();
	movenum = 0;
	compnum = 0;
	int first, last,temp;
	first = last = 0;
	int b[150];
	b[0] = L.r[1];
	for (int i = 2; i <= L.length; i++) {
		temp = L.r[i];
		if (temp < b[first] && ++compnum) {
			first = (first - 1 + L.length) % L.length;
			b[first] = temp;
			movenum++;
		}
		else if(temp > b[last] && ++compnum)
		{
			last = (last + 1) % L.length;
			b[last] = temp;
			movenum++;
		}
		else {//在中间位置用直接插入
			int j;
			for (j = (last+1)%L.length; b[(j-1+L.length)%L.length] >= temp && ++compnum; j=(j-1+L.length)%L.length){
				b[j] = b[(j - 1+L.length) % L.length];
				movenum++;
			}
			b[j] = L.r[i];
			last=(last+1)%L.length;
			movenum++;
		}
	}
	int k = first;
	for (int i = 1; i <= L.length; i++) {
		cout << b[k] << " ";
		k = (k + 1) % L.length;
	}//L排序
	for (int i = 1; i <= L.length; i++) {
		L.r[i] = b[k];
		k = (k + 1) % L.length;
	}//L排序
	return;
	delete(b);
}//二路插入


void sortlist::Shellsort(){
	copy();
	movenum = 0;
	compnum = 0;
	int i, j;
	int increment = L.length;
	do {
		increment = increment / 3 + 1;
		for (i = increment +1; i <= L.length; i+= increment) {
			L.r[0] = L.r[i];
			if (compare(i - increment,i )) {
				for (j = i - increment; j>0&&compare(j,0); j-= increment) {
					L.r[j + increment] = L.r[j];
					movenum++;
				}
				L.r[j + increment] = L.r[0];
				movenum++;
			}
		}
	} while (increment > 1);
	return;
}//希尔插入
void sortlist::Bubblesort(){
	copy();
	movenum = 0;
	compnum = 0;
	int i, j;
	bool flag = true;
	for (i = 1; i < L.length-1&&flag; i++) {//若flag为false则序列已排好
		flag = false;
		for (j = L.length - 1; j >= i; j--) {
			if (compare(j, j + 1)) {
				swap(j, j + 1);
				flag = true;
			}
		}
	}
	return;
}//冒泡优化
int sortlist::Partion(int low, int high){
	L.r[0] = L.r[low];
	while (low < high)
	{
		while (low < high&&L.r[high]>=L.r[0]&&++compnum)
			high--;
		swap(low, high);
		while (low < high&&L.r[0]>=L.r[low]&&++compnum)
			low++;
		swap(low, high);
	}
	return low;
}
void sortlist::Sort(int low, int high){
	int pivot;
	if (low < high) {
		pivot = Partion(low, high);
		Sort(low, pivot - 1);
		Sort(pivot + 1, high);
	}
	return;
}

void sortlist::Quicksrot(){
	copy();
	movenum = 0;
	compnum = 0;
	Sort(1, L.length);
	return;
}//快速排序
void sortlist::Selectsort(){
	copy();
	movenum = 0;
	compnum = 0;
	int i, j, min;
	for (i = 1; i < L.length; i++) {
		min = i;
		for (j = i + 1; j < L.length; j++) {
			if (compare(min,j)) {
				min = j;
			}
			if (i != min)
				swap(i, min);
		}
	}
	return;
}//选择排序
void sortlist::Heapadjust(int s,int m){
	int i, j;
	L.r[0] = L.r[s];
	for (j = s * 2; j <= m; j *= 2) {
		if (j < m&&compare(j + 1, j))
			j++;
		if (compare(0, j))
			break;
		L.r[s] = L.r[j];
		movenum++;
		s = j;
	}L.r[s] = L.r[0];
	return;
}
void sortlist::Heapsort(){
	copy();
	movenum = 0;
	compnum = 0;
	int i;
	for (i = (1+L.length )/ 2; i > 0 ; i--)
		Heapadjust(i, L.length);
	for (i = L.length; i > 1; i--) {
		swap(1, i);
		Heapadjust(1, i - 1);
	}
	return;
}//堆排序

void sortlist::Msort(vector<int> &SR, vector<int>&TR, int s,int t){
	int m ;

	if(s<t){
		m = (s + t) / 2;
		Msort(SR, TR, s, m);
		Msort(SR, TR, m + 1, t);
		Merge(SR, TR, s, m, t);
	}
	return;
}
void sortlist::Merge(vector<int> &SR, vector<int> &TR , int start, int mid ,int end){
	int i=start,j=mid+1,k=start;//k记录前半序列的指针，j记录后半序列的指针
	while (i <= mid && j <= end) {
		if (SR[i] > SR[j] && ++compnum) {
			TR[k++] = SR[j++];
			movenum++;
		}
		else {
			TR[k++] = SR[i++];
			movenum++;
		}
	}
	while (i <= mid ) {
		TR[k++] = SR[i++];
		movenum++;
	}
	while (j <= end ) {
		TR[k++] = SR[j++];
		movenum++;
	}
	for (i = start; i <= end; i++) {
		SR[i] = TR[i];
		movenum++;
	}
	
	return;
}
void sortlist::Mergesort(){
	copy();
	movenum = 0;
	compnum = 0;
	vector<int> TmpA;

	for (int i = 0; i <= L.length; i++) {
		TmpA.push_back(0);
	}
	Msort(L.r,TmpA, 1, L.length);
	for (int i = 1; i < L.length; i++) {
		L.r[i] = TmpA[i];
	}
}//归并
void sortlist::Showresult(){
	for (int i = 1; i <= L.length; i++)
		cout<<L.r[i]<<" ";
	cout << endl;
	return;
};
void sortlist::Shownum() {
	cout << compnum << "        " << movenum << endl;
}