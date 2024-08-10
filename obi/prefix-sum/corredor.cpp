#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, sum=0, most=0;
    cin >> n;
    vector<long long> num(n);

    for (int i=0; i<n; i++) {
        cin >> num[i];
    }

    for (int i=0; i<n; i++) {
        sum = max(num[i], num[i]+sum);
        most = max(sum, most);
    }

    cout << most << "\n";

    return 0;
}