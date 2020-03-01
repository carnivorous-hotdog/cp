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

vector<vector<int>> adj(2020);
bool visited[2020], color[2020];

bool dfs(int node, int c){
    visited[node] = 1;
    color[node] = c;

    for (auto child: adj[node]){
        if (!visited[child]){
            if (dfs(child, !c) == false) return false;
        }
        else {
            if (color[node] == color[child]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++){
        int n, m;
        cin >> n >> m;

        adj.clear();
        adj.resize(2020);
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));

        while(m--){
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        bool ok = true;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                if (!dfs(i, 1)){
                    ok = false;
                    break;
                }
            }
        }

        cout << "Scenario #" << j << ":" << endl;
        if (ok) {
            cout << "No suspicious bugs found!";
        }else{
            cout << "Suspicious bugs found!";
        }
        cout << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


