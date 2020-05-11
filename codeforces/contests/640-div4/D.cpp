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
    while(t--){
        int n;
        cin >> n;
        int a[n+1];

        for (int i =1; i <= n; i++) cin >> a[i];

        int alice = a[1];
        int bob = 0;
        int i = 2;
        int j = n;
        int totalalice = a[1];
        int totalbob = 0;
        int chances = 1;

        int chance = 0;
        while(i <= j) {
            trace(i, j, totalalice, totalbob, chances);
            if (chance){
                trace("starting alice");
                chances++;
                alice = 0;
                while(1){
                    trace("eating", a[i]);
                    alice += a[i];
                    totalalice += a[i];
                    i++;
                    //trace(alice, bob, i, j);
                    if (alice > bob) break;
                    if (i > j) break;
                }
                chance = !chance;
            }
            else {
                trace("starting bob");
                chances++;
                bob = 0;
                while(1){
                    trace("eating", a[j]);
                    bob += a[j];
                    totalbob += a[j];
                    j--;
                    //trace(alice, bob, i, j);
                    if (bob > alice) break;
                    if (j < i) break;
                }
                chance = !chance;
                trace("bob exit", i, j, bob, alice);
            }
        }

        cout << chances <<  ' ' << totalalice << ' ' << totalbob << endl;

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


