#include <bits/stdc++.h>
using namespace std;

int main() {
    // https://cses.fi/problemset/task/1671
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n+1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n+1, LLONG_MAX);
    
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        

        if(d > dist[node]) continue;
        
        for(auto [neighbor, weight] : adj[node]) {
            long long newDist = dist[node] + weight;
            
            if(newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}