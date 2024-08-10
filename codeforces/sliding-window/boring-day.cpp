#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> ans;

    for (int i=0; i<n; i++) {
        long long t, st, fi, h=0, sum=0, sta, fil;
        cin >> t >> st >> fi;
        sta = min(st, fi);
        fil = max(st, fi);
        vector<int> num(t+1);

        for (int a=1; a<=t; a++) {
            cin >> num[a];
        }
        
        for (int l=0, r=0; r<=t && l<=t;) {
            if (sum < sta && r<=t) {
                sum += num[r];
                r++;
            }
            while (sum > fil && l < r) {
                sum -= num[l];
                l++;
            }
            if (sum >= sta && sum <= fil) {
                h++;
                sum = 0;
                l=r;
            }
        }


        ans.push_back(h);
        
    }

    for (auto e:ans) {
        cout << e << "\n";
    }

    return 0;

}