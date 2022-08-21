#include <bits/stdc++.h>
using namespace std;

#define pb             push_back
#define all(x)         x.begin(), x.end()
#define vi             vector<int>

vi g[100001],r_g[100001],order,ans;
bool vis[100001];
int removed[100001];

void dfs(int node) {
    vis[node] = true;

    for (auto &x: g[node])
        if (!vis[x])
            dfs(x);

    order.pb(node);
}

void r_dfs(int node,int scc_no) {
    removed[node] = scc_no;

    for (auto &x: r_g[node])
        if (removed[x] == -1)
            r_dfs(x, scc_no);

}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        g[l].pb(r);
        r_g[r].pb(l);
    }
    memset(vis, false, sizeof vis);

    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs(i);

    memset(removed, -1, sizeof removed);
    reverse(all(order));
    int scc_no = 0;
    for (auto &i: order)
        if (removed[i] == -1) {
            scc_no++;
            ans.pb(i);
            r_dfs(i, scc_no);
       }
    // cout << scc_no << endl;
    // for (int i = 0; i < n; ++i)
    //     cout << removed[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= scc_no; ++i) {// printing the scc i.e:1st line represents the first component graph
    //     cout << i << "->";
    //     for (int j = 0; j < n; ++j)
    //         if (removed[j] == i)
    //             cout << j + 1 << " ";
    //     cout << endl;
    // }
    // // checking if its possible to visit one cities from all other
    // if (scc_no == 1)
    //     cout << "YES";
    // else {// if no then it prints which one are'nt possible
    //     cout << "NO" << endl;
    //     for (int i = 0; i < ans.size() - 1; ++i)
    //         cout << ans[i]  << " " << ans[i + 1]  << endl;
    // }

}

int32_t main() {

    solve();

}
