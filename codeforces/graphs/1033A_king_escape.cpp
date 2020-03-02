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

vector<pair<int, int>> adj[1010][1010];
bool visited[1010][1010];
bool qat[1010][1010];

void dfs(int f, int s){
    visited[f][s] = 1;

    for (auto child: adj[f][s]){
        if (!visited[child.first][child.second]){
            dfs(child.first, child.second);
        }
    }
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int n, ax, ay, bx, by, cx, cy;
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    for (int i = 1; i <= n; i++){
        qat[ax][i] = 1;
        qat[i][ay] = 1;
    }

    for (int i = 1; i <= n; i++){
        if (ax + i <= n && ay + i <= n){
            qat[ax+i][ay+i] = 1;
        }
        if (ax + i <= n && ay - i >= 1){
            qat[ax+i][ay-i] = 1;
        }
        if (ax - i >= 1 && ay + i <= n){
            qat[ax-i][ay+i] = 1;
        }
        if (ax - i >= 1 && ay - i >= 1){
            qat[ax-i][ay-i] = 1;
        }
    }

    //for (int i = 1; i <= n; i++){
        //for (int j = 1; j <= n; j++){
            //cout << qat[i][j];
        //}
        //cout << endl;
    //}

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int p = -1; p <= 1; p++){
                for (int q = -1; q <= 1; q++){

                    if (p == q && p == 0) continue;
                    if (p == -1 && i == 1) continue;
                    if (q == -1 && j == 1) continue;
                    if (p == 1 && i == n) continue;
                    if (q == 1 && j == n) continue;

                    int nx = i + p;
                    int ny = j + q;
                    if (qat[nx][ny] == 0 && qat[i][j] == 0){
                        adj[i][j].pb({i+p, j+q});
                    }
                }
            }
        }
    }

    dfs(bx, by);
    if (visited[cx][cy]) cout << "YES" << endl;
    else cout << "NO" << endl;


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


