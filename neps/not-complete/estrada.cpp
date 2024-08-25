#include <bits/stdc++.h>

using namespace std;

int main() {
    int lim, n; cin >> lim >> n;

    vector<int> nums;

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        nums.push_back(a);
    }

    if (n == 1) {
        cout << lim << "\n";
        return 0;
    }

    vector<double> vz;

    sort(nums.begin(), nums.end());

    vz.push_back(nums[0]+((nums[1]-nums[0])/2.0));

    for(int i=1; i<n-1; i++) {
        double vizh = (nums[i]-nums[i-1]+nums[i+1]-nums[i]) / 2.0;
        vz.push_back(vizh);
    }

    double fi = (lim-nums[n-1]) + ((nums[n-1]-nums[n-2])/2.0);
    vz.push_back(fi);

    sort(vz.begin(), vz.end());

    cout << fixed << setprecision(2) << vz[0] << "\n";

    return 0;
}
