#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void prim(vector<vector<pii>> g) {
    int src = 0, total_weight = 0;
    vector<bool> vis(g.size(), false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vis[src] = true;
    for(auto p: g[src]) {
        pq.push(p);
    }
    for(int i = 0; i < g.size() - 1; i ++) {
        total_weight += pq.top().first;
        src = pq.top().second;
        vis[src] = true;
        pq.pop();
        for(auto p: g[src]) {
            if(!vis[p.second]) {
                pq.push(p);
            }
        }
        while(!pq.empty() && vis[pq.top().second]) {
            pq.pop();
        }
    }
    cout << total_weight << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    prim(g);
}