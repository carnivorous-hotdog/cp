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
vi adj[1010];
bool visited[1010];
int dist[1010];

void dfs(int node, int parent){
    visited[node] = 1;
    dist[node] = dist[parent] + 1;

    for (auto child: adj[node]){
        if (!visited[child]){
            dfs(child, node);
        }
    }
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dist[0] = -1;
    dfs(1, 0);

    int q;
    cin >> q;
    dist[0] = n + 1;
    int ans = 0;

    while(q--){
        int g;
        cin >> g;
        if (dist[g] == dist[ans] && g < ans){
            ans = g;
        }
        if (dist[g] < dist[ans]){
            ans = g;
        }
    }

    cout << ans << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


