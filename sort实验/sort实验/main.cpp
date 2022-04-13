#include"sortlist.h"
#define max 150
int main() {
	vector<int>T;
	for (int i = 0; i < max; i++) {
		T.push_back(rand() % max);
	}
	sortlist *S;
	S = new sortlist(T);
	S->Bubblesort();
	cout << "    （1）比较次数（2）移动次数" << endl;
	cout << "  冒泡：";
	S->Shownum();
	S->Showresult();

	S->Deinsort();
	cout << "直接插入：";
	S->Shownum();
	S->Showresult();

	S->Doubsort();
	S->Shownum();
	cout << "二路插入：";
	S->Shownum();
	S->Showresult();

	S->Halfsort();
	cout << "折半插入：";
	S->Shownum();
	S->Showresult();

	S->Heapsort();
	cout << " 堆排序：";
	S->Shownum();
	S->Showresult();

	S->Mergesort();
	cout << "归并排序：";
	S->Shownum();
	S->Showresult();

	S->Quicksrot();
	cout << "快速排序：";
	S->Shownum();
	S->Showresult();

	S->Selectsort();
	cout << "选择排序：";
	S->Shownum();
	S->Showresult();

	S->Shellsort();
	cout << "希尔排序：";
	S->Shownum();
	S->Showresult();
	delete(S);

	return 0;
}