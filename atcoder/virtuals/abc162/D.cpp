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
const int MOD=1e9+7;

//////////////////////// code starts ///////////////////////

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n;
    string s;
    cin >> n;
    cin >> s;
    vi red(n, 0), green(n, 0), blue(n, 0);

    for (int i = 0; i < n; i++){
        if (s[i] == 'R') red[i]++;
        if (s[i] == 'G') green[i]++;
        if (s[i] == 'B') blue[i]++;

        if (i != 0){
            red[i] += red[i-1];
            green[i] += green[i-1];
            blue[i] += blue[i-1];
        }
    }

    //for (int i = 0; i< n; i++){
        //trace(red[i], green[i], blue[i]);
    //}

    ll ans = 0;
    for (int i = 0; i < n; i++){
        for (int k = i + 2; k < n; k++){
            if (s[i] != s[k]){
                 if ((s[i] == 'R' && s[k] == 'G') || (s[i] == 'G' && s[k] == 'R')){
                     ans += blue[k-1] - blue[i];
                 }
                 if ((s[i] == 'R' && s[k] == 'B') || (s[i] == 'B' && s[k] == 'R')){
                     ans += green[k-1] - green[i];
                 }
                 if ((s[i] == 'B' && s[k] == 'G') || (s[i] == 'G' && s[k] == 'B')){
                     ans += red[k-1] - red[i];
                 }

                 int j = (i + k) / 2;
                 //trace(i, j, k, s[i], s[j], s[k], ans);

                 if ((2 * j == i + k) && (s[i] != s[j]) && (s[k] != s[j])){
                     ans--;
                 }
            }
        }
    }

    cout << ans << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


