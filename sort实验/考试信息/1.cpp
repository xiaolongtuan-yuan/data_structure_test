#include<iostream>
#include <cstdlib>
#include<string>
#include <iomanip>
#define stunum 10
#define subject 3
using namespace std;
struct student {
	string name;
	int rank;
	int number;
	int score[subject];
	int allscore;
}stu[stunum];
void init(student stus[]) {
	for (int i = 0; i < stunum; i++) {
		cin >> stus[i].name;
		stus[i].number = i;
		for (int j = 0; j < subject; j++) {
			cin >> stus[i].score[j];
			stus[i].allscore += stus[i].score[j];
		}
	}
	return;
}//初始化信息
void getrank(student stu[]) {
	student temp;
	int i, j, min;
	for (i = 0; i < stunum; i++) {
		min = i;
		for (j = i + 1; j < stunum; j++) {
			if (stu[min].allscore < stu[j].allscore) {
				min = j;
			}
		}
		if (i != min) {
				temp = stu[i];
				stu[i] = stu[min];
				stu[min] = temp;
			}
	}
	j = 1;
	stu[0].rank = j;
	for (i = 1; i < stunum; i++) {
		if (stu[i].allscore != stu[i - 1].allscore) {
			stu[i].rank = ++j;
		}
		else {
			stu[i].rank = j;
		}
	}
}
void main() {
	init(stu);
	getrank(stu);
	cout << "rank";
	cout << setw(10) << "学号";
	cout << setw(10) << "name";
	cout << setw(10) << "总分";
	cout << setw(10) << "英语";
	cout << setw(10) << "数学";
	cout << setw(10) << "语文" << endl;
	for (int i = 0; i < stunum; i++) {
		cout <<setw(4)<< stu[i].rank;
		cout << setw(10) << stu[i].number;
		cout << setw(10) << stu[i].name;
		cout << setw(10) << stu[i].allscore;
		cout << setw(10) << stu[i].score[0];
		cout << setw(10) << stu[i].score[1];
		cout << setw(10) << stu[i].score[2] << endl;
	}
	return;
}
//章
//12 55 65
//刘
//15 56 55
//方
//68 88 98
//茶
//15 47 89
//陈
//36 45 56
//行
//15 16 89
//缠
//15 16 89
//彬
//15 48 89
//次
//33 66 44
//流
//15 65 56