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
	cout << "    ��1���Ƚϴ�����2���ƶ�����" << endl;
	cout << "  ð�ݣ�";
	S->Shownum();
	S->Showresult();

	S->Deinsort();
	cout << "ֱ�Ӳ��룺";
	S->Shownum();
	S->Showresult();

	S->Doubsort();
	S->Shownum();
	cout << "��·���룺";
	S->Shownum();
	S->Showresult();

	S->Halfsort();
	cout << "�۰���룺";
	S->Shownum();
	S->Showresult();

	S->Heapsort();
	cout << " ������";
	S->Shownum();
	S->Showresult();

	S->Mergesort();
	cout << "�鲢����";
	S->Shownum();
	S->Showresult();

	S->Quicksrot();
	cout << "��������";
	S->Shownum();
	S->Showresult();

	S->Selectsort();
	cout << "ѡ������";
	S->Shownum();
	S->Showresult();

	S->Shellsort();
	cout << "ϣ������";
	S->Shownum();
	S->Showresult();
	delete(S);

	return 0;
}