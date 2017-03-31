#include <bits/stdc++.h>
using namespace std;

#define MAXN 31

int n, m, pid, tc = 0;
string nome[MAXN], aux;
unordered_map<string, int> id;
vector<int> adj[MAXN], ts;
int vis[MAXN];

int visit(int u) {
    if (vis[u] == 1) return 0; // temporary mark found, not a DAG
    if (!vis[u]) {
        vis[u] = 1;
        for (int i = 0; i < adj[u].size(); i++)
            if (!visit(adj[u][i])) return 0;
        vis[u] = 2;
        ts.push_back(u);
    }
    return 1;
}

int toposort() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (!vis[i]) if (!visit(i)) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> n && n) {
        for (int i = 0; i <= n; i++) adj[i].clear();
        ts.clear();
        cout << "Teste " << ++tc << '\n';
        for (int i = 1; i <= n; i++) {
            cin >> nome[i];
            id[nome[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> aux;
            pid = id[aux];
            cin >> m;
            while (m--) {
                cin >> aux;
                adj[pid].push_back(id[aux]);
            }
        }
        if (!toposort()) cout << "impossivel";
        else for (int i = 0; i < ts.size(); i++) {
            if (i) cout << ' ';
            cout << nome[ts[i]];
        }
        cout << "\n\n";
    }
    return 0;
}
