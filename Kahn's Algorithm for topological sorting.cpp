#include <bits/stdc++.h>
using namespace std;

#define pb             push_back
#define vi             vector<int>
vi edges[100001],ans;
queue<int>q;
int n,m,indeg[100001];

void solve(){

    memset(indeg,0,sizeof(indeg));

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;

        edges[x].pb(y);
        indeg[y]++;
    }
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        ans.pb(node);
        q.pop();
        for(auto &x:edges[node])
        {
            indeg[x]--;
            if(indeg[x]==0){
                q.push(x);
            }
        }


    }
    if(ans.size()!=n)
        cout<<"IMPOSSIBLE";// cycle exists
    else{
        for(auto &c:ans)
            cout<<c<<" ";
    }


}

int32_t main() {

    solve();

}
