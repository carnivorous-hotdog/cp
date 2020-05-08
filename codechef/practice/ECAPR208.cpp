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
vi adj[100010];
int color[100010];
map<int, pair<ll, ll>> comp_sums;
int strength[100010];
int c_no = 1;

bool dfs(int node, int par){

    if (color[par] == 1){
        color[node] = 2;
        comp_sums[c_no].second += strength[node];
    }
    else {
        color[node] = 1; 
        comp_sums[c_no].first += strength[node];
    }

    for (auto child: adj[node]){
        if (color[child] == 0){
            if (dfs(child, node) == false){
                return false;
            }
        }
        else if (color[child] == color[node]){
            return false;
        }
    }
    return true;
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        for (int i = 1; i <= n; i++) cin >> strength[i];

        if (m == 0){
            cout << "NOT POSSIBLE" << endl;
            continue;
        }

        memset(adj, {}, sizeof(adj));
        memset(color, 0, sizeof(color));
        comp_sums.clear();
        c_no = 1;

        while(m--){
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        color[0] = 1;

        bool ok;
        for (int i = 1; i <= n; i++){
            if (color[i] == 0){
                comp_sums[c_no].first = 0;
                comp_sums[c_no].second = 0;
                ok = dfs(i, 0);
            }
            c_no++;
            if (!ok){
                break;
            }
        }
        if (!ok){
            cout << "NOT POSSIBLE" << endl;
        }
        else {
            ll color1 = 0;

            for (auto x: comp_sums){
                color1 += max(x.second.first, x.second.second);
            }

            cout << "YES" << endl << color1 << endl;
        }

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


