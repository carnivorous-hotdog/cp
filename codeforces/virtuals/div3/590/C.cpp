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
    set<int> first;
    set<int> second;
    first.insert(1);
    first.insert(2);
    second.insert(3);
    second.insert(4);
    second.insert(5);
    second.insert(6);

    while(t--){
        int n;
        cin >> n;
        string x, y;
        cin >> x >> y;
        int a[3][n+1];

        for (int i = 0; i < n; i++){
            a[1][i+1] = x[i] - '0';
        }

        for (int i = 0; i < n; i++){
            a[2][i+1] = y[i] - '0';
        }

        int row = 1;

        bool ok = true;
        for (int i = 1; i <= n; i++){
            int curr = a[row][i];
            if (second.count(curr)){
                row = (row == 1 ? 2: 1);

                if (!second.count(a[row][i])){
                    ok = false;
                    cout << "NO" << endl;
                }
            }
            if (!ok) break;
        }

        if (!ok) continue;

        if (row == 2) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}

