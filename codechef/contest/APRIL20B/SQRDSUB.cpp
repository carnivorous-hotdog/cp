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

int main(){
    IOS;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];

        for (ll i = 0; i < n; i++) cin >> a[i];

        ll p[n];

        for (ll i = 0; i < n; i++){
            if (a[i]&1) p[i] = 0;
            else {
                if (a[i] % 4 == 0) p[i] = 2;
                else p[i] = 1;
            }
        }

        for (ll i = 0; i < n; i++){
            trace(p[i]);
        }

        ll notgood = 0;
        ll countodd = 0;
        for (ll i = 0; i < n; i++){
            trace("begin", notgood, p[i], countodd);
            if (p[i] == 2){
                countodd = 0;
                continue;
            }
            else if (p[i] == 1){
                ll j = i + 1;
                for (; j < n; j++){
                    if (p[j] != 0){
                        break;
                    }
                }
                ll notgooddist = j - i;
                notgood += j - i;
                notgood += (countodd) * notgooddist;
                trace(countodd, notgooddist);
                countodd = 0;
            }
            else {
                countodd += 1;
            }
            trace("end", notgood);
        }

        cout << ((n * (n+1)) / 2) - notgood << endl;
    }


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


