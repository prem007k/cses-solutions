#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    const int mod = 1e9 + 7;

    cin >> n >> x;
    vector<int> coins(n);
    vector<long long> dp(x + 1, 0);

    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n && coins[j] <= i; j++) {
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }

    cout << dp[x];
}
