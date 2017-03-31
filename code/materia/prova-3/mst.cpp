// N is the maximum number of vertices
// u.first is the vertex index
// u.second is the edge weight
// store weight as negative value!!! pqueue is maxheap

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int N = 1001;

// adjacency list
vector<pair<int, int> > adj[N];
vector<pair<int, int> > mst[N];
char vis[N];

// r is the root
// the mst is stored in mst[] with pos weight
void runmst(int r) {
    for (int i=0; i<N; i++) mst[i].clear();
    memset(vis, 0, sizeof(vis));
    // priority queue
    priority_queue<pair<int, pair<int, int> > > q;
    for (auto u:adj[r]) {
        q.push(mp(u.second, mp(r, u.first)));
    }
    while (!q.empty()) {
        int v = q.top().second.second;
        int p = q.top().second.first;
        int d = q.top().first;
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        // this edge is in the MST
        // do something
        mst[p].pb(mp(v, -d));
        for (auto u:adj[v]) {
            q.push(mp(u.second, mp(v, u.first)));
        }
    }
}

// add edge to the graph with neg weight
void addedge(int x, int y, int d) {
    adj[x].pb(mp(y, -d));
    // if digraph remove this line
    adj[y].pb(mp(x, -d));
}

int main() {

    return 0;
}
