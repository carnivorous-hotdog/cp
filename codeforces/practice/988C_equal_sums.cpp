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
    int k;
    cin >> k;
    vector<int> sums(k+1);
    vector<vector<int>> orig(k+1);
    vector<vector<int>> newsum(k+1);
    vector<pair<int, pair<int, int>>> final;

    for (int i = 0; i < k; i++){
        int n;
        cin >> n;
        int sum = 0;
        while(n--){
            int x;
            cin >> x;
            sum += x;
            orig[i+1].pb(x);
        }
        sums[i+1] = sum;
    }


    for (int i = 1; i <= k; i++){
        for (auto x: orig[i]){
            newsum[i].pb(sums[i] - x);
        }
    }

    for (int i = 1; i <= k; i++){
        for (int j = 0; j < (int)newsum[i].size(); j++){
            final.pb(mp(newsum[i][j], mp(i, j+1)));
        }
    }

    sort(final.begin(), final.end());

    bool ok = false;
    for (int i = 0; i < final.size() - 1; i++){
        if (final[i].first == final[i+1].first && final[i].second.first != final[i+1].second.first){
            ok = true;
            cout << "YES" << endl;
            cout << final[i].second.first << " " << final[i].second.second << endl;
            cout << final[i+1].second.first << " " << final[i+1].second.second << endl;
        }
        if (ok) break;
    }

    if (!ok) cout << "NO" << endl;

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


