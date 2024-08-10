#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long sum=0, allsum=0;

    for (int i=0; i<n-1; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    for (int i=1; i<=n; i++) {
        allsum+=i;
    }

    cout << allsum - sum << "\n";


    return 0;
}