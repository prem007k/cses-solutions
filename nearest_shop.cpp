#include <bits/stdc++.h>
using namespace std;

int main() {
    // https://cses.fi/problemset/task/3303
    int n, m, k;
    cin >> n >> m >> k;
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(3, INT_MAX));
    vector<vector<int>> shop(n, vector<int>(3, -1));
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < k; i++) {
        int v; 
        cin >> v;
        v--;
        dist[v][1] = 0;
        shop[v][1] = v;
        q.push({v, 1});
    }
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    while(!q.empty()) {
        auto [v, level] = q.front();
        q.pop();
        
        if(level == 1) {
            for(int u : adj[v]) {
                if(dist[u][1] == INT_MAX) {
                    dist[u][1] = dist[v][1] + 1;
                    shop[u][1] = shop[v][1];
                    q.push({u, 1});
                }
                else if(dist[u][2] == INT_MAX && dist[u][1] != INT_MAX && shop[u][1] != shop[v][1]) {
                    dist[u][2] = dist[v][1] + 1;
                    shop[u][2] = shop[v][1];
                    q.push({u, 2});
                }
            }
        }
        else { 
            for(int u : adj[v]) {
                if(dist[u][2] == INT_MAX) {
                    dist[u][2] = dist[v][2] + 1;
                    shop[u][2] = shop[v][2];
                    q.push({u, 2});
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(shop[i][1] != i && dist[i][1] != INT_MAX) {
            cout << dist[i][1];
        } else if(dist[i][2] != INT_MAX) {
            cout << dist[i][2];
        } else {
            cout << -1;
        }
        cout << " ";
        }
    
    return 0;
}