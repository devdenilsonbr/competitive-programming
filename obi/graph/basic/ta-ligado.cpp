#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

vector<int> m[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    int n, con;
    vector<int> res;

    cin >> n >> con;

    for (int i=0; i<con; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bool sit=false;
        if (a == 0) { 
            for (auto& v:m[b]) {
                if (v == c) {
                    sit = true;
                    break;
                }
            }
            res.push_back(sit);
        }
        else {
            m[b].push_back(c);
            m[c].push_back(b);
        }
    }

    for (auto& e:res) {
        cout << e << "\n";
    }

    return 0;
}