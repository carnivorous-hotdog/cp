#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
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
int cat[100010];
vi adj[100010];
int n, m;

int dfs(int node, int parent, int c){
    if (cat[node]) c++;
    else c = 0;
    if (c > m) {
        return 0;
    }

    bool leaf = true;
    int ans = 0;
    for (auto child: adj[node]){
        if (child != parent){
            leaf = false;
            ans += dfs(child, node, c);
        }
    }

    if (leaf) return 1;
    return ans;
}

int32_t main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cat[i];

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }


    cout << dfs(1, -1, 0) << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


