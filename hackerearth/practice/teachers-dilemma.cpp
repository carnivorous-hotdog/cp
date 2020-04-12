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
const int MOD=1e9+7;

//////////////////////// code starts ///////////////////////
int parent[100010];

int Find(int n){
    if (parent[n] < 0){
        return n;
    }
    return parent[n] = Find(parent[n]);
}

void Union(int x, int y){
    parent[x] += parent[y];
    parent[y] = x;
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    memset(parent, -1, sizeof(parent));

    while(m--){
        int x, y;
        cin >> x >> y;

        x = Find(x);
        y = Find(y);

        if (x != y) Union(x, y);
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++){
        if (parent[i] < 0){
            ans = ((ans % MOD) * (parent[i] % MOD))%MOD;
        }
    }

    cout << abs(ans) << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


