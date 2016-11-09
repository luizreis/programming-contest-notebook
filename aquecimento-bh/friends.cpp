#include <bits/stdc++.h>
using namespace std;

int p[100010], r[100010], s[100010];
int t, f, id;
unordered_map<string, int> name;
string n1, n2;

void create_set(int x) { p[x] = x; r[x] = 0; s[x] = 1; }
int find_set(int x) { if (x != p[x]) p[x] = find_set(p[x]); return p[x]; }
void merge_sets(int x, int y) {
    int px = find_set(x);
    int py = find_set(y);
    if (px == py) return; // do not merge same set
    if (r[px] > r[py]) { p[py] = px; s[px] += s[py]; }
    else { p[px] = py; s[py] += s[px]; }
    if (r[px] == r[py]) r[py]++;
}

int main() {
    cin >> t;
    while (t--) {
        id = 1; name.clear();
        cin >> f;
        while (f--) {
            cin >> n1 >> n2;
            if (name.find(n1) == name.end()) {
                name[n1] = id;
                create_set(id++);
            }
            if (name.find(n2) == name.end()) {
                name[n2] = id;
                create_set(id++);
            }
            merge_sets(name[n1], name[n2]);
            printf("%d\n", s[find_set(name[n1])]);
        }
    }
    return 0;
}
