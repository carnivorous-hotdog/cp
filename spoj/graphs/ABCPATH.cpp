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


bool visited[52][52];
char grid[52][52];
int longest = 0;

void dfs(int first, int second, int locallong){
    visited[first][second] = 1;
    char orig = grid[first][second];
    trace(orig);
    longest = max(locallong, longest);

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            char curr = grid[first + i][second + j];
            if (curr - orig == 1 && visited[first+i][second+j] == 0){
                dfs(first+i, second+j, locallong+1);
            }
        }
    }
}


int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int c = 1;
    while(1){
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        memset(visited, 0, sizeof(visited));
        memset(grid, 0, sizeof(grid));
        longest = 0;

        vector<pair<int, int>> as;
        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                char x;
                cin >> x;
                if (x == 'A') as.pb({i, j});
                grid[i][j] = x;
            }
        }

        for (int i = 0; i < w + 2; i++){
            grid[0][i] = '-';
            grid[h+1][i] = '-';
        }

        for (int i = 0; i < h + 2; i++){
            grid[i][0] = '-';
            grid[i][w+1] = '-';
        }

        for (auto x: as){
            dfs(x.first, x.second, 1);
        }

        cout << "Case " << c << ": " << longest << endl;
        c++;
    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


