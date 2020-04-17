#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
int Rank[100010], parent[100010];
bool mark[100010];


int Find(int x){
    if (parent[x] == x) return x;

    return parent[x] = Find(parent[x]);
}


void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if (x != y){
        if (Rank[x] > Rank[y]) swap(x, y);
        parent[x] = y;
        Rank[y] += Rank[x];
    }
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n, m1, m2;
    cin >> n >> m1;

    for (int i = 0; i <= n; i++){
        Rank[i] = 1;
        parent[i] = i;
        mark[i] = 1;
    }

    while(m1--){
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    cin >> m2;
    while(m2--){
        int x, y;
        cin >> x >> y;
        x = Find(x);
        y = Find(y);

        if (x == y){
            mark[x] = false;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        trace(i, parent[i], Rank[i], mark[i]);
        if ((i == parent[i]) && mark[i] && (Rank[i] > ans)){
            ans = Rank[i];
        }
    }

    cout << ans << endl;


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


