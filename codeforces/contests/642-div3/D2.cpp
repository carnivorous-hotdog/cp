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
// using set with custom comparator function

#define pp pair<int, pair<int, int>>

struct cmp {
    bool operator() (pp a, pp b){
        if (a.first == b.first){
            return a.second.first < b.second.first;
        }

        return a.first > b.first;
    }
};

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
        set<pp, cmp> storage;
        storage.insert({n, {1, n}});

        int count = 1;
        int a[n+1] = {0};
        while(storage.size()){
            pp target = *storage.begin();
            storage.erase(storage.begin());
            int l = target.second.first;
            int r = target.second.second;

            int m = (l + r) / 2;

            a[m] = count++;
            if (l <= m - 1) {
                storage.insert({m - l, {l, m - 1}});
            }
            if (m + 1 <= r){
                storage.insert({r - m, {m + 1, r}});
            }
        }

        for (int i = 1; i <= n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;

    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


