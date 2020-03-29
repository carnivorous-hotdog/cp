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
    int n, r;
    cin >> n >> r;

    int a[n+1];

    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++){
        trace(a[i]);
        if (a[i] == 1){
            int l = max(i - r + 1, 1);
            int rr = min(n, i + r - 1);

            trace(l, rr);
            int ok = false;
            while(l <= rr){
                //trace(l);
                if (a[l] == 1){
                    l++;
                    continue;
                }
                if (a[l] != 2) {
                    a[l] = 2;
                    ok = true;
                }
                l++;
            }
            if (ok) ans++;
        }
    }

    cout << (ans == 0 ? -1 : ans) << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


