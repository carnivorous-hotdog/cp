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
    int a, b, x;
    cin >> a >> b >> x;

    if (x % 2 == 0){
        if (a > b){
            for (int i = 0; i < x / 2; i++) cout << "01";
            for (int i = 0; i < (b - x/2); i++) cout << '1';
            for (int i = 0; i < (a - x/2); i++) cout << '0';

        } else {
            for (int i = 0; i < x / 2; i++) cout << "10";
            for (int i = 0; i < (a - x/2); i++) cout << '0';
            for (int i = 0; i < (b - x/2); i++) cout << '1';
        }
    } else {
        if (a > b){
            for (int i = 0; i < x / 2; i++) cout << "01";
            for (int i = 0; i < (a - x/2); i++) cout << '0';
            for (int i = 0; i < (b - x/2); i++) cout << '1';
        } else {
            for (int i = 0; i < x / 2; i++) cout << "10";
            for (int i = 0; i < (b - x/2); i++) cout << '1';
            for (int i = 0; i < (a - x/2); i++) cout << '0';
        }
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


