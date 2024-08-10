#include <bits/stdc++.h>

using namespace std;

int main() {
    string word, end="";
    vector<char> vog={'a', 'e', 'i', 'o', 'u'};

    cin >> word;

    for (int i=0; i<word.size(); i++) {
        end.push_back(word[i]);
        
        if (find(vog.begin(), vog.end(), word[i]) != vog.end()) {
            continue;
        }


        bool vef = false;
        int small=100000;
        for (int j=0; j<5;j++) {
            int r;
            r = abs(vog[j] - word[i]);
            small = min(small, r);
        }
        if (find(vog.begin(), vog.end(), word[i]-small) != vog.end()) {
            end.push_back(word[i]-small);
        }
        else {
            end.push_back(word[i]+small);
        }

        if (word[i] == 'z') {
            end.push_back('z');
            continue;
        }

        if (find(vog.begin(), vog.end(), word[i]+1) != vog.end()) {
            if (word[i]+2 == 'w') {
                end.push_back('x');
            }
            else if (word[i]+2 == 'y') {
                end.push_back('z');
            }
            else {
                end.push_back(word[i]+2);
            }
        }
        else {
            if (word[i]+1 == 'w') {
                end.push_back('x');
            }
            else if (word[i]+1 == 'y') {
                end.push_back('z');
            }
            else {
                end.push_back(word[i]+1);
            }
        }

    }

    cout << end << "\n";

    return 0;
}