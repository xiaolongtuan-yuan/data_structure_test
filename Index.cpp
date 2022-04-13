#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
#define MAXSTRLEN 255
typedef int Status;
typedef int Element;
typedef unsigned char SString[MAXSTRLEN + 1];
void initstr(SString &T, char *ch) {
	if (strlen(ch) >= MAXSTRLEN) {
		cout << "error" << endl;
		return;
	}
	T[0] = strlen(ch);
	for (int i = 0; i < T[0]; i++) {
		T[i + 1] = ch[i];
	}
}

int Index(SString S, SString T)//Ò»°ãËã·¨£¬¸´ÔÓ¶ÈÎªO(n^2)
{
	int i = 1, j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0]) return i - T[0];
	else { 
		cout << "ËÑË÷Ê§°Ü" << endl;
		return 0; }
}
int main() {
	int a,b;
	cout << "ÇëÊäÈëÖ÷×Ö·û´®³¤¶È£º";
	cin >> a;
	char* p = new char[a];
	cin >> p;
	cout << "ÇëÊäÈëËÑË÷×Ö·û³¤¶È£º";
	cin >> b;
	char*q = new char[b];
	cin >> q;
	SString n,m;
	initstr(n, p);
	initstr(m, q);
	int pos=Index(n, m);
	if (pos)
		cout << pos;
	free(p);
	free(q);
	return 0;
}

