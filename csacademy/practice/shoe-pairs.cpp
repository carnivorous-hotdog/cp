#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
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
bool check[1010];
vector<pair<int, char>> a(1010);

int main(){
    idk
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        cin >> a[i].second;
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        if (check[i] == 1) continue;
        for (int j = i + 1; j < n; j++){
            if (a[i].first == a[j].first && a[i].second != a[j].second && check[j] != 1){
                ans++;
                check[j] = 1;
                break;
            }
        }
    }

    cout << ans << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}

