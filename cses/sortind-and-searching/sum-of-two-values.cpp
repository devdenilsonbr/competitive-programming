#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    long long sum;
    cin >> n >> sum;
    vector<long long> num(n);
    vector<long long> ans;
    unordered_map<long long, int> vef;

    for (int i=0; i<n; i++) {
        cin >> num[i];
    }

    for (int i=0; i<n; i++) {
        long long aux=sum-num[i];
        if (aux < 1) continue;
        if (vef.find(aux) != vef.end()) {
            ans.push_back(i);
            ans.push_back(vef[aux]);
            break;
        }
        vef[num[i]] = i;
        
    }

    if (ans.empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans[0]+1 << " " << ans[1]+1 << "\n"; 


    return 0;
}