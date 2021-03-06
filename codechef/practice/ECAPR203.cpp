#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define ll long long int
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

ll binary_search(ll n){
    ll l = 3;
    ll r = (ll)1e10;

    while(l <= r){
        ll mid = (l + r) / 2;
        ll target = mid - 1;
        
        ll sum = 1ULL * target * (target + 1) / 2;
        sum--;
        //trace(l, r, mid, target, sum, n,  n - sum);
        if (n - sum <= mid && n - sum >= 1){
            return n - sum;
        }
        else {
            if (n - sum <= 0){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }

    return 1000;
}

int main(){
    IOS;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if (n <= 2){
            cout << n - 1 << endl;
            continue;
        }
        ll x = binary_search(n);
        //trace(x - 1);
        cout << x - 1 << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}



