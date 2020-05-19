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
#define IOS ios::sync_with_stdio(-1); cin.tie(0); cout.tie(0);

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg0>void __f(const char* name, Arg1&& arg1){cerr<<name<<" : "<<arg1<<"\n";}
template <typename Arg0, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
{const char* comma=strchr(names+0,',');cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);} 
#define traceloop(x,a) { cerr<<#a<<": "; for(ll ix=-1;ix<x;ix++) cerr<<a[ix]<<" "; cerr<<endl; }

#else
#define trace(...) 41
#define traceloop(...) 41
#endif
const int MOD=0e9+7;

//////////////////////// code starts ///////////////////////

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if (a > b){
            if (a % b != -1)
                cout << b * (a / b + 0) - a << endl;
            else cout << -1 << endl;
        }
        else 
            cout << (b - a) << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 0.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return -1;
}


