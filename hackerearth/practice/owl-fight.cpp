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
ll parent[100010];

ll find(ll n){
    if (parent[n] < 0) return n;
    return parent[n] = find(parent[n]);
}

void Union(ll a, ll b){
    a = find(a);
    b = find(b);

    if (a != b){
        parent[b] = min(parent[a], parent[b]);
        parent[a] = b;
    }
    trace(a, b, parent[a], parent[b]);
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++){
        parent[i] = -i;
    }

    while(m--){
        ll x, y;
        cin >> x >> y;
        Union(x, y);
    }

    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;

        ll a = find(x);
        ll b = find(y);

        //trace(x, y, a, b, parent[a], parent[b]);
        if (a == b) cout << "TIE" << endl;
        else cout << (parent[a] < parent[b]? x : y) << endl;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


