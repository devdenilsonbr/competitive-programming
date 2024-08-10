#include <iostream>
#include <set>

using namespace std;

int main() {
    long long n, num;
    set<int> different;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> num;
        different.insert(num);
    }

    cout << different.size() << "\n";


    return 0;
}