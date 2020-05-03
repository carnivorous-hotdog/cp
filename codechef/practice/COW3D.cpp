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
vi adj[200010];
int level[200010], jump_parent[200010];
const int maxN = log2(200010);
int lca[200010][maxN+1];

void dfs(int node, int par){
    level[node] = level[par] + 1;
    lca[node][0] = par;

    for (auto child: adj[node]){
        if (child != par){
            dfs(child, node);
        }
    }
}

int getlca(int u, int v){
    if (level[u] < level[v]) swap(u, v);
    int d = level[u] - level[v];

    while(d){
        int x = log2(d);
        u = lca[u][x];
        d -= (1 << x);
    }

    if (u == v) return u;

    for (int i = maxN; i >= 0; i--){
        if (lca[u][i] != 0 && (lca[u][i] != lca[v][i])){
            u = lca[u][i];
            v = lca[v][i];
        }
    }

    return lca[u][0];
}

void init(){
    level[0] = -1;
    dfs(1, 0);

    for (int j = 1; j <= maxN; j++){
        for (int i = 0; i <= 200000; i++){
            if (lca[i][j-1] != 0){
                int par = lca[i][j-1];
                lca[i][j] = lca[par][j-1];
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

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    init();

    while(q--){
        int k;
        cin >> k;
        int a[k];
        set<int> st;

        for (int i = 0; i < k; i++){
            cin >> a[i];
            st.insert(a[i]);
        }

        if (k == 1) {
            cout << a[0] << endl;
            continue;
        }

        int llca = getlca(a[0], a[1]);

        for (int i = 2; i < k; i++){
            llca = getlca(llca, a[i]);
        }

        if (st.count(llca)){
            cout << llca << endl;
        } else {
            cout << -1 << endl;
        }

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


