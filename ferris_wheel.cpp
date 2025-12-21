#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int i = 0, j = n - 1, rides = 0;
    while(i < j){
        if(weights[i] + weights[j] <= x){
            i++;
        }
        j--;
        rides++;
    }
    cout << rides + (i == j) << endl;
    return 0;
}