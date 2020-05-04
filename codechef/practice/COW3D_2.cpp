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

vi adj[200020];
bool vis[200020];
int intime[200020], outtime[200020];
int timer = 1;

void dfs(int node){
    vis[node] = 1;
    intime[node] = timer++;

    for (auto child: adj[node]){
        if (!vis[child]){
            dfs(child);
        }
    }

    outtime[node] = timer++;
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;
    int nn = n;
    for (int i = 0; i< nn - 1; i++){
        int a, b;
        cin>> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);


    while(q--){
        int k;
        cin >> k;

        int a[k];
        for (int i = 0; i < k; i++) cin >> a[i];

        int mn = INT_MAX;
        int mx = INT_MIN;
        int mnidx = 0;
        int mxidx = 0;

        for (int i = 0; i < k; i++){
            if (mn > intime[a[i]]){
                mn = intime[a[i]];
                mnidx = a[i];
            }

            if (mx < outtime[a[i]]){
                mx = outtime[a[i]];
                mxidx = a[i];
            }
        }

        cout << (mnidx == mxidx ? mnidx : -1) << endl;
    }


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


