#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

vector<int> nums;
int n;

int coins(int a) {
    if (a == 0) return 0;
    if (a < 0) return inf;

    int best = inf;

    for (auto e:nums) {
        //int remainder = a - e;
        best = min(best, coins(a - e)+1);
    }

    return best;

}  

int main() {
    int sum;
    cin >> n >> sum;

    for (int i=0; i<n; i++) {
        int v; cin >> v;
        nums.push_back(v);
    }


    cout << coins(sum) << "\n";

    return 0;
}