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

const int MAX = 1010;
bool vis[MAX][MAX];

vi di = {1, 0, -1, 0};
vi dj = {0, 1, 0, -1};

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int a[n+1][n+1];

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }

        vii queries(q);
        for (int i = 0; i < q; i++){
            cin >> queries[i].first;
            queries[i].second = i;
        }

        sort(queries.begin(), queries.end());

        for (int i = 0; i < q; i++){
            trace(queries[i].first, queries[i].second);
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pr;

        memset(vis, 0, sizeof(vis));

        pr.push(mp(a[1][1], mp(1, 1)));
        vis[1][1] = 1;

        vi ansarray(q);
        int ans = 0;

        for (auto x: queries){
            int query = x.first;

            while(pr.size() > 0 && pr.top().first < query){
                int nodei = pr.top().second.first;
                int nodej = pr.top().second.second;
                pr.pop();
                ans++;
                trace(query, pr.top().first, nodei, nodej); 
                for (int i = 0; i < 4; i++){
                    int pi = nodei + di[i];
                    int pj = nodej + dj[i];
                    trace(pi, pj, vis[pi][pj]);
                    if (pi <= n && pi >= 1 && pj <= n && pj >= 1 && vis[pi][pj] == 0){
                        pr.push(mp(a[pi][pj], mp(pi, pj)));
                        vis[pi][pj] = 1;
                        trace("pushed", a[pi][pj]);
                    }
                }
            }
            //cout << endl;

            ansarray[x.second] = ans;
        }

        for (int i = 0; i < q; i++){
            cout << ansarray[i] << endl;
        }
    }


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


