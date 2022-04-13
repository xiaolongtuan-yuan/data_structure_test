#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	short v = 0x1234;
	char* p = (char*)&v;
	printf("%x\n", *p);
	return 0;
}