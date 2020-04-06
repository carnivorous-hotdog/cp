#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
#else
#define trace(...) 42
#endif

#define mod 1000000007

vector<int> adj[100010];
bool visited[100010];
vector<int> lengths;

void dfs(int node, int &len){
    visited[node] = 1;
    len++;
    trace(len);

    for (auto child: adj[node]){
        if (!visited[child]){
            dfs(child, len);
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
    while(t--){
        memset(adj, {}, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        lengths.clear();

        int n, m;
        cin >> n >> m;
        while(m--){
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        int cc = 0;

        for (int i = 1; i <= n; i++){
            int len = 0;
            if (!visited[i]){
                dfs(i, len);
                trace("len here", len);
                cc++;
                lengths.pb(len);
            }
        }

        ll ans = 1;
        for (auto x: lengths){
            ans = (ans * x) % mod;
        }

        cout << cc << ' ' << ans << endl;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


