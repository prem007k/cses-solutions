#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, c, Max = 1e6 + 1;
    cin >> n >> x;
    vector<int> dp(x + 1, Max);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &c);
        for(int j = 0; j <= x-c; j++)
            if(dp[j] != Max)
                dp[j+c] = min(dp[j+c], dp[j]+1);
    }
    (dp[x] == Max) ? cout << "-1" : cout << dp[x] ;
}