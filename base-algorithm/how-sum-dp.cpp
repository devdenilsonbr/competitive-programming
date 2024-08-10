#include <bits/stdc++.h>

using namespace std;

vector<int> dp[5000];
int vis[5000];


vector<int> howSum(int target, vector<int> nums) {
    if (vis[target]) return dp[target];//vetor armazenado
    if (target <= 0) return {};//caso base

    for (auto num:nums) {
        int rest = target - num;
        vector<int> result =  howSum(rest, nums);//chamada recursiva

        if (!result.empty() || rest == 0) {// adicionar os numeros a partir do caso base
            result.push_back(num);
            vis[rest] = 1;
            dp[rest].push_back(num);//adicionando os numeros que fazem a soma
            return result;
        }
    }

    dp[target] = {};
    vis[target] = 1;
    return {};

}

int main() {
    vector<int> test={4, 6, 2, 1};
    int num = 15;

    vector<int> ans = howSum(num, test);
    if (ans.empty()) cout << -1 << "\n";

    for (int e:ans) {
        cout << e << " ";
    }
    cout << "\n";

    for (int i=0; i<=15; i++) {
        if (dp[i].empty()) continue;
        for (auto e : dp[i]) {
            cout << e;
        }
    }
    


    return 0;
}