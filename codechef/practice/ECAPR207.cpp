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

vector<pair<int, int>> adj[10010];
bool vis[10010];

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n, k, m, aa;
    cin >> n >> k >> m >> aa;

    int a[aa];
    for (int i = 0; i < aa; i++){
        cin >> a[i];
    }

    while(m--){
        int aaa, b, w;
        cin >> aaa >> b >> w; 
        adj[aaa].pb(mp(b, w));
        adj[b].pb(mp(aaa, w));
    }

    bool ok = true;
    for (int i = 0; i < aa; i++){
        //trace(a[i]);

        vector<int> dist(n+1, INT_MAX);
        memset(vis, 0, sizeof(vis));
        dist[a[i]] = 0;


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bag;

        bag.push({0, a[i]});

        while(!bag.empty()){
            pair<int, int> node = bag.top();
            bag.pop();

            //if (node.first != dist[node.second]) continue;
            if (vis[node.second]) continue;
            vis[node.second] = true;

            for (auto child: adj[node.second]){
                int edgeweight = child.second;

                if (edgeweight + node.first < dist[child.first]){
                    dist[child.first] = edgeweight + node.first;
                    bag.push({dist[child.first], child.first});
                }
            }

        }

        //for (int jj = 1; jj <= n; jj++){
            //cout << dist[jj] << ' ';
        //}
        //cout << endl;

        for (int j = 0; j < aa; j++){
            if (i == j) continue;

            //trace(a[j], dist[a[j]], k);
            if (dist[a[j]] < k){
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }

    cout << (ok ? "PASS" : "FAIL") << endl;



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


