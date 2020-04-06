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

bool boolprime[90000005];
vector<int> primes;

void seive(){
    int n = 90000001;

    for (int i = 3; i * i <= n; i += 2){
        if (boolprime[i] == 0){
            for (ll j = 1L * i * i; j <= n; j += i){
                boolprime[j] = 1;
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= n; i += 2){
        if (!boolprime[i]) primes.pb(i);
    }
}

int main(){

    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    seive();
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << primes[n-1] << endl;
    }
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


