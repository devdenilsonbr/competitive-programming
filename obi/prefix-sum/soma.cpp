#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, sum;
	cin >> N >> sum;
	vector<int> number(N);
	
	for (int i=0; i<N; i++) {
		cin >> number[i];
	}
	
	long long sum_prefix=0, cont=0;
	map<long long, long long> sum_open;
	sum_open[0] = 1;
	
	for (int i=0; i<N; i++) {
		sum_prefix+=number[i];
		cont += sum_open[sum_prefix-sum];
		sum_open[sum_prefix]++;
	}
	
	cout << cont << "\n";
	
	
	return 0;
}
