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


int cc[300010][26];

int main(){
    idk
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++){
        if (s[i] < 'a') {
            s[i] = s[i] + ('a' - 'A');
        }

        cc[i][s[i] - 'a']++;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < 26; j++){
            cc[i][j] += cc[i-1][j];
        }
    }


    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;

        int ans = 0;
        for (int i = 0; i < 26; i++){
            int x;
            if (a == 0) x = cc[b][i];
            else x = cc[b][i] - cc[a-1][i];
            if (x > 0) {
                ans = x;
            }
        }

        cout << ans << endl;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


