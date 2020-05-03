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
vi adj[10010];
int level[10010];
const int maxN = log2(10010);
int LCA[10010][maxN+1];

void dfs(int node, int par){
    LCA[node][0] = par;
    level[node] = level[par] + 1;

    for (auto child: adj[node]){
        if (child != par){
            dfs(child, node);
        }
    }
}

int getlca(int u, int v){
    if (level[u] < level[v]) swap(u, v);

    int d = level[u] - level[v];

    while(d > 0){
        int x = log2(d);
        u = LCA[u][x];
        d -= (1 << x);
    }

    if (u == v) return u;

    for (int i = maxN; i >= 0; i--){
        if (LCA[u][i] != 0 && (LCA[u][i] != LCA[v][i])){
            u = LCA[u][i];
            v = LCA[v][i];
        }
    }

    return LCA[u][0];
}

void init(){
    level[0] =1;
    dfs(1, 0);

    for (int j = 1; j <= maxN; j++){
        for (int i = 1; i < 10010; i++){
            if (LCA[i][j-1] != 0){
                int par = LCA[i][j-1];
                LCA[i][j] = LCA[par][j-1];
            }
        }
    }
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for (int test = 1; test <= t; test++){
        int n;
        cin >> n;
        memset(adj, {}, sizeof(adj));
        memset(LCA, 0, sizeof(LCA));
        memset(level, 0, sizeof(level));

        for (int i= 1; i <= n; i++){
            int m;
            cin >> m;
            if (m == 0) continue;
            while(m--){
                int x;
                cin >> x;
                adj[x].pb(i);
                adj[i].pb(x);
            }
        }
        init();

        int q;
        cin >> q;
        cout << "Case " << test << ":" << endl;
        while(q--){
            int u, v;
            cin >> u >> v;

            //trace(lca(u, v));
            cout << getlca(u, v) << endl;
        }

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


