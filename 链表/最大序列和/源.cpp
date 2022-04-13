#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int Max = *nums.begin();
	for (auto index1 = nums.begin(); index1 != nums.end(); ++index1)
	{
		int Sum = 0;
		for (auto index2 = index1; index2 != nums.end(); ++index2)
		{
			Sum += *index2;
			if (Sum > Max)
				Max = Sum;
		}
	}
	return Max;
}
int main() {
	int x,y;
	cin >> x;
	vector<int> M;
	while (x > 0) {
		cin >> y;
		M.push_back(y);
		x--;
	}
	cout << maxSubArray(M)<< endl;
	return 0;
}
