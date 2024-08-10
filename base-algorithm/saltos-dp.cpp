#include <iostream>

using namespace std;

long long dp[500000];
bool vis[500000];

long long saltos (int n) {
    if (n <= 1) return 1;

    if (vis[n]) return dp[n];
    vis[n] = 1;

    dp[n] = saltos(n-1) + saltos(n-2);
    return dp[n];
}

int main() {

    cout << saltos(3) << "\n";
    cout << saltos(4) << "\n";
    cout << saltos(100) << "\n";
    cout << saltos(1) << "\n";
    cout << saltos(25) << "\n";
    cout << saltos(2) << "\n";



    return 0;
}