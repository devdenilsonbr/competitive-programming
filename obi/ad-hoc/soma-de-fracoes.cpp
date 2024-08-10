#include <bits/stdc++.h>

#define int long long

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int aux = b;
		b = a%b;
		a = aux;
	}
	return a;
}

int lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int32_t main() {
	long long t1, b1, t2, b2, answert, answerb;
	cin >> t1 >> b1 >> t2 >> b2;
	if (b1 == b2) {
		answert = t1+t2;
		answerb = b1;
	}
	else {
		answerb = lcm(b1, b2);
		answert = (answerb / b1) * t1 + (answerb/b2) * t2;
	}
	
	cout << answert / gcd(answert, answerb) << " " << answerb / gcd(answert, answerb) << "\n";
	
	return 0;
}