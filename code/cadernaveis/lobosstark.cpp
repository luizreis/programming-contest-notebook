/*
function stableMatching {
    Initialize all men and women to free
    while there is a free man m who still has a woman w to propose to {
       w = first woman on m list to whom m has not yet proposed
       if w is free
         (m, w) become engaged
       else some pair (m1, w) already exists
         if w prefers m to m1
            m1 becomes free
           (m, w) become engaged 
         else
           (m1, w) remain engaged
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

int n, cid = 1, wid = 1, cc, cw;
list<int> pc[201];
int pw[201][201];
string str;
unordered_map<string, int> c, w;
string nc[201], nw[201];
vector<pair<int, int> > marriage;

void stable_marriage() {
    marriage.clear();
    int m[201];
    list<int> fc; // free children
    memset(m, 0, sizeof(m)); // matches (wolf -> child)
    for (int i = 1; i <= n; i++) fc.push_back(i); // mark every child as free
    while (fc.size() > 0) { // while there is a free child
        int _c = fc.front(); fc.pop_front();
        int _w = pc[_c].front(); pc[_c].pop_front(); // best match in child list
        if (!m[_w]) {
            m[_w] = _c; // if wolf is free match them
        } else {
            if (pw[_w][_c] < pw[_w][m[_w]]) { // wolf prefers current child
                fc.push_back(m[_w]); // set other child as free
                m[_w] = _c; // match wolf and current child
            } else {
                fc.push_front(_c); // c remains free
            }
        }
    }
    for (int i = 1; i <= n; i++)
        marriage.push_back(make_pair(m[i], i));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (!c[str]) {
            cc = c[str] = cid++;
            nc[cc] = str;
        }
        else cc = c[str];
        for (int j = 0; j < n; j++) {
            cin >> str;
            if (!w[str]) {
                cw = w[str] = wid++;
                nw[cw] = str;
            }
            else cw = w[str];
            pc[cc].push_back(cw);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (!w[str]) {
            cw = w[str] = wid++;
            nw[cw] = str;
        }
        else cw = w[str];
        for (int j = 0; j < n; j++) {
            cin >> str;
            if (!c[str]) {
                cc = c[str] = cid++;
                nc[cc] = str;
            }
            else cc = c[str];
            pw[cw][cc] = j;
        }
    }
    stable_marriage();
    sort(marriage.begin(), marriage.end());
    for (int i = 0; i < marriage.size(); i++)
        cout << nc[marriage[i].first] << ' ' << nw[marriage[i].second] << '\n';
    return 0;
}
