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
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n+1];
        pair<ll, ll> l[n+1];

        ll mn = 1e9 + 10;
        ll idx = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < mn){
                idx = i;
                mn = a[i];
            }

            l[i] = {mn, idx};
        }

        for (ll i = 1; i <= n; i++){
            trace(a[i], l[i].first, l[i].second);
        }

        ll ans = 0;
        idx = n;
        ll val = 0;

        while(1){
            trace("hello");
            trace(idx, l[idx].first, val, idx * (l[idx].first - val));
            ans += idx * (l[idx].first - val);
            val += (l[idx].first - val);
            idx = l[idx].second - 1;
            if (idx < 1) break;
            trace(ans);
        }

        cout << ans << endl;
        //trace(ans);

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


