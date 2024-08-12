#include <iostream>

using namespace std;

int main() {
    int n, pos, hands; cin >> n >> pos >> hands;
    
    for (int i=0; i<hands; i++) {
        pos = (pos + 1)%n;
    }

    if (pos == 0) pos = n;

    cout << pos << "\n";

    return 0;
}