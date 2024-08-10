#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int num, sum=0; cin >> num;
        while (num > 0) {
            sum += num % 10;
            num = num/10;
        }

        cout << sum << "\n";
    }


    return 0;
}
