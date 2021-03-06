#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define idk ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
    idk
    #ifdef LOCAL
        freopen("input2.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ll n, m;
    cin >> n >> m;

    ll a[n+1];
    a[0] = 0;

    for (ll i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    ll x = n / m;

    ll ans = 0;
    for (ll i = 1; i <= x; i++){
        ll j = m * (i - 1) + 1;
        ll k = m * i;

        ll sum = 0;

        while(j <= k){
            sum = a[j];
            ans = (ans % MOD) +  ((sum % MOD) * (i % MOD)) % MOD;
            j++;
        }
    }

    ll sum = 0;
    for (ll i = x * m + 1; i <= n; i++){
        sum = a[i];
        ans= (ans % MOD) +  ((sum % MOD) * (x % MOD)) % MOD;
    }

    cout << ans << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


