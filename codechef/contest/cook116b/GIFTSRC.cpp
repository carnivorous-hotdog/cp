#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
#else
#define trace(...) 42
#endif

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
        string s;
        cin >> s;
        string tt = "";
        tt += s[0];
        int j = 0;
        for (int i = 1; i < n; i++){
            if (tt[j] == s[i]) continue;
            else {
                tt += s[i];
                j++;
            }
        }

        n = tt.size();
        int aa[n];
        for (int i = 0; i< n; i++){
            if (tt[i] == 'R' || tt[i] == 'L') {
                aa[i] = 0;
            }else aa[i] = 1;
        }

        string ss = "";
        int prev = aa[0];
        ss += tt[0];
        for (int i = 1; i < n; i++){
            if (aa[i] == prev) continue;
            else {
                prev = aa[i];
                ss += tt[i];
            }
        }

        trace(tt);
        trace(ss);

        int x, y;
        x = y = 0;
        for (auto xx: ss){
            trace(xx);
            if (xx == 'L') x--;
            if (xx == 'R') x++;
            if (xx == 'U') y++;
            if (xx == 'D') y--;
        }

        cout << x << ' ' << y << endl;
    }


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


