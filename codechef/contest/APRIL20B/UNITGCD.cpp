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

int main(){
    IOS;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if (n == 1){
            //cout << 1 << endl << 1 << ' ' << 1 << endl;
            printf("1\n1 1\n");
            continue;
        }

        printf("%d\n", n/2);
        if (n&1){
            //cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << n << endl;
            printf("3 1 2 %d\n", n);
        } else {
            //cout << 2 << ' ' << 1 << ' ' << 2 << endl;
            printf("2 1 2\n");
        }

        for (int i = 3; i + 1 <= n; i+= 2){
            //cout << 2 << ' ' <<  i << ' ' << i + 1;
            printf("2 %d %d\n", i, i+1);
            //cout << endl;
        }
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


