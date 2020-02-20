#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<int, int>
#define ll long long
#define pb push_back
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

vi ans;
int a, b;

bool dfs(int x, int y){
    if (x > y) return false;
    if (x == y){
        ans.pb(y);
        return true;
    }
    if (dfs(2 * x, y)){
        ans.pb(x);
        return true;
    }

    if (dfs(x * 10 + 1, y)){
        ans.pb(x);
        return true;
    }

    return false;
}

int main(){
    IOS;
    cin >> a >> b;

    if (dfs(a, b)){
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto x: ans){
            cout << x << " ";
        }
    }else{
        puts("NO");
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


