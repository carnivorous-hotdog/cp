#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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

    string s;
    cin >> s;

    int n = s.size();

    vi u(n, 0), l(n, 0);

    for(int i = 1; i < n; i++){
        l[i] = l[i-1];
        if (s[i-1] >= 'a'){
            l[i]++;
        }
    }

    for (int i = n - 2; i >= 0; i--){
        u[i] = u[i+1];

        if (s[i+1] <= 'Z'){
            u[i]++;
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        trace(i, s[i], l[i], u[i], l[i] + u[i]);
        ans = min(ans, l[i] + u[i]);
    }
    cout << ans << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


