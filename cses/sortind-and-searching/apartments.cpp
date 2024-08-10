#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long a, s, count=0, lim;
    cin >> a >> s >> lim;
    vector<long long> ap(a);
    vector<long long> av(s);

    for (int i=0; i<a; i++) {
        cin >> ap[i];
    }
    for (int i=0; i<s; i++) {
        cin >> av[i];
    }
    sort(ap.begin(), ap.end());
    sort(av.begin(), av.end());

    for (int la=0, lv=0; lv < s && la < a; lv++) {
        while (av[lv]-lim > ap[la] && la < a-1) {
            la++;
        }
        if (av[lv] >= ap[la]-lim && av[lv] <= ap[la]+lim) {
            count++;
            la++;
        }
    } 
    
    cout << count << "\n";

    return 0;
}