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
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;

        int primefactors = 0;

        bool ok = false;
        int n = x;
        while(n % 2 == 0){
            n /= 2;
            primefactors++;
            if (primefactors >= k){
                ok = true;
                break;
            }
        }

        for (int i = 3; i * i <= n; i++){
            while(n % i == 0){
                n /= i;
                primefactors++;
                if (primefactors >= k){
                    ok = true;
                    break;
                }
            }
        }

        if (n != 1){
            primefactors++;
            if (primefactors >= k){
                ok = true;
            }
        }

        if (ok) cout << 1 << endl;
        else cout << 0 << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


