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

int main(){
    idk
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    pair<int, int> ans1 = {0, -1};
    stack<int> s;
    int start = 1;
    int mx = 0;
    int len = 0;
    int idx = -1;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 1) {
            s.push(x);
            len++;
            if ((int)s.size() > ans1.first){
                ans1.first = s.size();
                ans1.second = i;
            }
        }
        else {
            s.pop();
            if (s.size() == 0){
                if (len > mx){
                    mx = len;
                    idx = start;
                }
                start = i + 1;
                len = 0;
            }
        }
    }

    cout << ans1.first << ' ' << ans1.second << ' '<<  mx * 2 << ' ' << idx << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


