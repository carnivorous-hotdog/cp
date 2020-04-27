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

vi adj[1000010];

int main(){
    idk
    #ifdef LOCAL
        //freopen("input2.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        memset(adj, {}, sizeof(adj));

        while(m--){
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        set<int> a, b, c;

        for (auto x: adj[1]){
            if (x == 2 || x ==1) continue;
            a.insert(x);
        }

        for (auto x: adj[2]){
            if (x == 1 || x == 2) continue;
            b.insert(x);
        }

        for (auto x: b){
            for (auto y: adj[x]){
                if (y == 2 || y == 1) continue;
                c.insert(y);
            }
        }

        set<int> d;

        set_union(b.begin(), b.end(), c.begin(), c.end(), inserter(d, d.end()));

        set<int> ans;

        set_difference(a.begin(), a.end(), d.begin(), d.end(), inserter(ans, ans.end()));

        if (ans.size() == 0) cout << -1;
        else {
            for (auto x: ans){
                cout << x << ' ';
            }
        }

        cout << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


