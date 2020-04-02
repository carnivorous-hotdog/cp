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

vector<int> adj[200020];
int componentno[200020];

void dfs(int node, int &len, int no){
    componentno[node] = no;
    len++;

    for (auto child: adj[node]){
        if (!componentno[child]){
            dfs(child, len, no);
        }
    }
}

int main(){
    IOS;
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        memset(componentno, 0, sizeof(componentno));
        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            x--;
            adj[i].pb(x);
        }

        map<int, int> m;

        int no = 1;
        for (int i = 0; i < n; i++){
            int len = 0;
            if (!componentno[i]){
                dfs(i, len, no);
            }
            m[no] = len;
            no++;
        }

        for (int i = 0; i < n; i++){
            cout << m[componentno[i]] << ' ';
        }
        cout << endl;
    }



    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


