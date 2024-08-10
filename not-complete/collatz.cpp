#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
    int n; cin >> n;
    vector<int> ans;

    for (int i=0; i<n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        for (int i=0; i<c; i++) {
            int aux=1, in=b;
            a++;
            while (a%b == 0) {
                aux = b;
                b += in;

            }
            a = a/aux;
        }
        ans.push_back(a);
    }
    
    for (auto e:ans) {
    	cout << e << "\n";
	}


    return 0;
}