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

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ll n, m, u, qq;
    cin >> n >> m >> u >> qq;

    ll a[n][m], b[n][m];

    for (ll i= 0; i< n; i++){
        for (ll j = 0; j < m; j++){
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }

    while(u--){
        ll k, p, q, r, s;
        cin >> k >> p >> q >> r >> s;

        for (ll i = p; i <= r; i++){
            b[i][q] += k;
            if (s + 1 < m){
                b[i][s+1] -= k;
            }
        }
    }

    //for (ll i = 0; i < n; i++){
        //for (ll j = 0; j < m; j++){
            //cerr << b[i][j] << ' ';
        //}
        //cerr << endl;
    //}

    for (ll i = 0; i < n; i++){
        for (ll j = 1; j < m; j++){
            b[i][j] += b[i][j-1];
        }
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            a[i][j] += b[i][j];
            //cerr << b[i][j] << ' ';
        }
        //cerr << endl;
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 1; j < m; j++){
            a[i][j] += a[i][j-1];
        }
    }

    //for (ll i = 0; i < n; i++){
        //for (ll j = 0; j < m; j++){
            //cerr << a[i][j] << ' ';
        //}
        //cerr << endl;
    //}

    while(qq--){
        ll p, q, r, s;
        cin >> p >> q >> r >> s;
        ll ans = 0;

        for (ll i = p; i <= r; i++){
            if (q - 1 >= 0)
                ans += a[i][s] - a[i][q-1];
            else ans += a[i][s];
        }

        cout << ans << endl;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


