#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
#define ll long long
#define pb push_back
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
vi adj[30001];
bool visited[30001];

void dfs(int node){
    visited[node] = 1;

    for (auto child: adj[node]){
        if (!visited[child]){
            dfs(child);
        }
    }
}

int main(){
    IOS;
    int n, t;
    cin >> n >> t;

    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        adj[i].pb(i + x);
    }

    dfs(1);

    cout << (visited[t] == 1?"YES":"NO") << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


