#include <iostream>

#define int long long

using namespace std;

int32_t main() {
    int n; cin >> n;

    int a = 1, sum=0, cont=0;

    while (true) {
        sum = a * 5;
        if (sum > n) break;
        cont += n/sum;
        a = sum;
    }

    cout << cont << "\n";
}
