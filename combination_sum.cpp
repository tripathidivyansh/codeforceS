#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = -1e9; 

int solve(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
    if (target == 0) return 0;
    if (i >= (int)arr.size() || target < 0) return INF;

    if (dp[i][target] != -1) {
        return dp[i][target];
    }

    int take = INF;
    if (target >= arr[i]) {
        int res = solve(i, arr, target - arr[i], dp);
        if (res != INF) take = (arr[i] + res) % MOD;
    }

    int not_take = solve(i + 1, arr, target, dp);

    return dp[i][target] = max(take, not_take);
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    int result = solve(0, arr, target, dp);
    
    if (result < 0) cout << 0 << endl;
    else cout << result << endl;
    
    return 0;
}
