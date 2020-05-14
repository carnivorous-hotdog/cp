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

    int t;
    cin >> t;
    bool targets[2001] = {0};

    for (int i = 2; i <= 1000; i++){
        if (i * i > 2000) break;
        targets[i * i] = 1;
    }

    for (int i = 2; i <= 1000; i++){
        if (i * i * i > 2000) break;
        targets[i * i * i] = 1; 
    }

    while(t--){
        int n;
        cin >> n;
        int a[n];
        unordered_map<int, int> hash;
        for (int i = 0; i< n; i++){
            cin >> a[i];
            hash[a[i]]++;
        }

        vi a_new;

        for (auto x: hash){
            a_new.pb(x.first);
        }


        int m = a_new.size();
        ll ans = 0;
        for (int i = 0; i < m; i++){

            int freq = hash[a_new[i]];
            if (freq > 1 && targets[2 * a_new[i]]){
                ans += (freq * (freq- 1)) / 2;
            }

            for (int j = i + 1; j < m; j++){
                trace(a_new[i], a_new[j], targets[a_new[i] + a_new[j]]);
                if (targets[a_new[i] + a_new[j]]){
                    ans += freq * hash[a_new[j]];
                }
            }
        }

        cout << ans << endl;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}



