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
template <typename Arg1>void __f(const char* name, Arg1&& arg1){cout<<name<<" : "<<arg1<<"\n";}
template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
{const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);} 
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

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            a[i] = (x == 'H' ? 1 : 0);
        }

        int count = 0;
        int tofind = 1;
        for (int i = n - 1; i >= n - k; i--){
            if (a[i] == tofind){
                tofind = !tofind;
                count++;
            }
        }

        tofind = (count&1 ? 0 : 1);

        int ans = 0;
        for (int i = 0; i <= n - k - 1; i++){
            if (a[i] == tofind) ans++;
        }

        cout << ans << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


