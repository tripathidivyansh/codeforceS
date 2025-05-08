#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(x + 1, 1e8);
    dp[0] = 0;

    for (int coin : arr) {
        for (int j = coin; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    cout << (dp[x] >= 1e8 ? -1 : dp[x]) << endl;
    return 0;
}
