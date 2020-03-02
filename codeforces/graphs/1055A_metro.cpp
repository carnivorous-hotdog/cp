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
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n, s;
    cin >> n >> s;

    bool f = true;
    int last = -1;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x){
            if (f) {
                f = false;
                last = i;
            }
            else{
                adj[last].pb(i);
                last = i;
            }
        }
    }
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    f = true;
    for (int i = n; i >= 1; i--){
        if (a[i]){
            if (f){
                last = i;
                f = false;
            }
            else{
                adj[last].pb(i);
                last = i;
            }
        }
    }

    dfs(1);

    if (visited[s]) cout << "YES" << endl;
    else cout << "NO" << endl;




    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


