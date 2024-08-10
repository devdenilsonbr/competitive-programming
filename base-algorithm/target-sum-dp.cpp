#include <bits/stdc++.h>

using namespace std;

bool dp[50000]={0};
int vis[50000]={0};

//uma tree onde a cada son é a quantidade de nums - mas ainda uma tree

bool targetSum (int target, vector<int> nums) {
    if (vis[target]) return dp[target]; //vef se ja foi visitado
    if (target == 0) return 1; // então tem a soma no conjunto de numeros
    if (target < 0) return 0; // não tem a soma, está na raiz da arvores

    for (auto e:nums) {
        int tree = target - e;
        if (targetSum(tree, nums)) { //vai ficar subtraindo elementos ate as c.
            dp[tree] = 1; 
            vis[tree] = 1;
            return 1;
        }
    }
    dp[target] = 0; // se nenhuma vez o retornou true para o target
    vis[target] = 1;
    return 0;

}

int main() {

    cout << targetSum(7, {2, 4, 6, 8}) << "\n";
    cout << targetSum(6, {2, 4, 6}) << "\n";
    cout << targetSum(300, {7, 14}) << "\n";

    return 0;
}