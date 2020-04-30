#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1){cerr<<name<<" : "<<arg1<<"\n";}
template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
{const char* comma=strchr(names+1,',');cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);} 
#define traceloop(x,a) { cerr<<#a<<": "; for(ll ix=0;ix<x;ix++) cerr<<a[ix]<<" "; cerr<<endl; }

#else
#define trace(...) 42
#define traceloop(...) 42
#endif
const int MOD=1e9+7;

//////////////////////// code starts ///////////////////////
vi adj[100010];
bool vis[100010];
int level[100010], parent[100010];

void dfs(int node, int par){
    vis[node] = 1;

    parent[node] = par;

    if (par == -1) level[node] = 1;
    else level[node] = level[par] + 1;

    for (auto child: adj[node]){
        if (!vis[child]){
            dfs(child, node);
        }
    }
}

int getlca(int u, int v){
    while(level[u] != level[v]){
        if (level[u] < level[v]) swap(u, v);
        u = parent[u];
    }

    while(u != v){
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int p;
        cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }

    dfs(0, -1);

    int m;
    cin >> m;
    vi a(m);

    for (int i = 0; i < m; i++){
        cin >> a[i];
    }

    int locallca = getlca(a[0], a[1]);

    for (int i = 2; i < m; i++){
        locallca = getlca(locallca, a[i]);
    }

    cout << locallca << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


