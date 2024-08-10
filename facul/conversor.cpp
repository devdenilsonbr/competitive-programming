#include <bits/stdc++.h>

using namespace std;

string bin(int a) {
    string ans="";
    while (a > 0) {
        if (a % 2 == 0) ans.push_back('0');
        else ans.push_back('1');
        a = a/2;
    }
    string ans2="";
    for (int i=(int)ans.size()-1; i>=0; i--) {
        ans2.push_back(ans[i]);
    }
    return ans2;
}

string octalorhex(string num, char t) {
    int base, exp;
    string ans="";
    if (t == 'h') {
        base = 4; exp = 8;
    }
    else {
        base = 3; exp = 4;
    }

    int cont=1, dig=0;

    for (int i=0; i<(int)num.size(); i+=base) {
        if (num[i] == '1') {
            dig += exp;
        }
        if (num[i+1] == '1') {
            dig += exp/2;
        }
        if (num[i+2] == '1') {
            dig += exp/4;
        }
        if (exp == 8) {
            if (num[i+3] == '1') {
                dig += exp/8;
            }
        }
        
        ans.push_back()
    }
}

int main() {
    int n; cin >> n;

    cout << bin(n) << "\n";


    return 0;
}