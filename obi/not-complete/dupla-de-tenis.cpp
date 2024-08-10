#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> players;

    for (int i=0; i<4; i++) {
        int a; cin >> a;
        players.push_back(a);
    }

    sort(players.begin(), players.end());

    cout <<  abs((players[0]+players[3]) - (players[1]+players[2])) << "\n";

    return 0;
}
