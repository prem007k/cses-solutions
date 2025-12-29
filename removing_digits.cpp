#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, N;
    cin >> n;
    vector<int>dp(n+1, 1e6 + 1);
    dp[n] = 0;
    for(int i = n; i >=0; i--) {
        if(dp[i] != 1e6 + 1) {
            N = i;
            while(N) {
                dp[i - N%10] = min(dp[i] + 1, dp[i - N%10]);
                N /= 10;
            }
        }
    }
    cout << dp[0] <<endl;
}