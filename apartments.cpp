#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> desired(n), available(m);
    for(int i = 0; i < n; i++){
        cin >> desired[i];
    }
    for(int i = 0; i < m; i++){
        cin >> available[i];
    }
    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());
    int count = 0;
    for(int i = 0, j = 0; i < m && j < n;){
        if(available[i] < desired[j] - k) i++;
        else if(available[i] > desired[j] + k) j++;
        else {i++; j++; count++;}
    }
    cout << count << endl;
}