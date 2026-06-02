#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    queue<int> q;
    vector<char> removed(n, 0);
    for (int i = 0; i < n; ++i)
        if (deg[i] <= 5) q.push(i);

    vector<int> order;
    order.reserve(n);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (removed[v]) continue;
        removed[v] = 1;
        order.push_back(v);
        for (int to : adj[v]) {
            if (!removed[to]) {
                if (--deg[to] <= 5)
                    q.push(to);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        if (!removed[i]) order.push_back(i);

    vector<int> color(n, -1);
    for (int idx = n - 1; idx >= 0; --idx) {
        int v = order[idx];
        bool used[7] = {false};
        for (int to : adj[v])
            if (color[to] != -1)
                used[color[to]] = true;

        for (int c = 1; c <= 6; ++c) {
            if (!used[c]) {
                color[v] = c;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << color[i] << " \n"[i + 1 == n];
    return 0;
}