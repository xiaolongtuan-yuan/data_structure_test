#include<iostream>
#include <utility>
#include<string>
#include<map>
using namespace std;
typedef struct node {
	char data;
	node *next;
}node,*Linklist;

bool putin(map<string, string>& edges) {
	pair<string, string>edge;
	string x,y;
	cin >> edge.first >> edge.second;
	edges.insert(edge);
	int k=1;
	while (cin >> x>>y && x != "-1") {
		if (!edges.count(x)) {
//²åÈë±ß
			edge.first = x;
			edge.second = y;
			edges.insert(edge);
			k++;
		}
		else
			return false;
	}
	if (k != edges.size())
		return false;
	else
		return true;
}
bool convert(map<string,string>& M){
	map<string,string>::iterator iter;
	iter = M.begin();
	map<string, string> newM;
	while (iter != M.end()) {
		if (!newM.count(iter->second)) {
			newM.insert(make_pair(iter->second, iter->first));
			iter++;
		}
		else
			return false;
	}
	M = newM;
	return true;
}
string findbeg(map<string, string> M) {
	map<string, string>::iterator iter;
	iter = M.begin();
	while (iter != M.end()) {
		if (M.count(iter->second) == 0)
			return iter->second;
		iter++;
	}
	return "-1";
}
void print(map<string, string> M) {
	string begin = findbeg(M);
	if (begin != "-1") {
		if (convert(M)) {
			cout << begin << endl;
			for (int i = 0; i < M.size(); i++) {
				cout << M.find(begin)->second << endl;
				begin = M.find(begin)->second;
			}
		}
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
		return;
}
int main() {
	map<string,string>M;
	if (putin(M))
		print(M);
	else
		cout << "NO" << endl;
}