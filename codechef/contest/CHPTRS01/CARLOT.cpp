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
    while(t--){
        int m, n;
        cin >> m >> n;
        char a[m][n];

        int lastfloor = -1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                if (a[i][j] == 'P'){
                    lastfloor = i;
                }
            }
        }

        trace(lastfloor);

        vector<pair<int, pair<int, int>>> floors;

        bool gl = false;
        int size = 0;
        for (int i = 0; i < m; i++){
            bool l = false;
            int left = -1;
            int right = -1;
            for (int j = 0; j < n; j++){
                if (a[i][j] == 'P'){
                    gl = true;
                    if (!l){
                        left = j;
                        l = true;
                    } 
                    right = j;
                }
            }
            if (left != -1){
                floors.pb({i, {left, right}});
                size++;
            } else{
                if (gl){
                    if (i < lastfloor){
                        size++;
                        floors.pb({i, {-1, -1}});
                    }
                    else break;
                }
            }
        }

        trace(floors.size());
        int ans = max(size - 1, 0);

        if (floors.size() == 0){
            cout << ans << endl;
            continue;
        }

        trace("floors");
        for (int i = 0; i < (int)floors.size(); i++){
            auto x = floors[i];
            trace(i, x.second.first, x.second.second);
        }
        trace("floors");


        //int x, y;
        //x = floors[0].second.first;
        //y = floors[0].second.second;
        int pos;
        if (floors[0].first % 2 == 0) pos = floors[0].second.first;
        else pos = floors[0].second.second;

        for (int i = 0; i < (int)floors.size(); i++){
            int npos = -1;
            if (i != (int)floors.size() - 1){
                if (floors[i].first % 2 == 0){
                    if (floors[i+1].second.second != -1){
                        if (floors[i].second.second != -1){
                            //y = max(floors[i].second.second, floors[i+1].second.second);
                            npos = max(floors[i].second.second, floors[i+1].second.second);
                            ans += abs(pos - npos);
                            pos = npos;
                        } else {
                            //y = floors[i+1].second.second;
                            npos = floors[i+1].second.second;
                            ans += abs(npos - pos);
                            pos = npos;
                        }
                    } else {
                        if (floors[i].second.second != -1){
                            //y = floors[i].second.second;
                            npos = floors[i].second.second;
                            ans += abs(npos - pos);
                            pos = npos;
                        } else {
                            trace("continued");
                            continue;
                        }
                    }
                } else {
                    if (floors[i+1].second.second != -1){
                        if (floors[i].second.second != -1){
                            //x = min(floors[i].second.first, floors[i+1].second.first);
                            npos = min(floors[i].second.first, floors[i+1].second.first);
                            ans += abs(npos - pos);
                            pos = npos;
                        } else {
                            //x = floors[i+1].second.first;
                            npos = floors[i+1].second.first;
                            ans += abs(npos - pos);
                            pos = npos;
                        }
                    } else {
                        if (floors[i].second.second != -1){
                            //x = floors[i].second.first;
                            npos = floors[i].second.first;
                            ans += abs(npos - pos);
                            pos = npos;
                        } else {
                            trace("continued");
                            continue;
                        }
                    }
                    //if (floors[i+1].second.second != -1){
                        //x = min(floors[i].second.first, floors[i+1].second.first);
                    //} else {
                        //x = floors[i].second.first;
                    //}
                }
            } else {
                if (floors[i].first % 2 == 0){
                    //y = floors[i].second.second;
                    //pos += floors[i].second.second;
                    npos = floors[i].second.second;
                    ans += abs(pos - npos);
                    pos = npos;
                } else {
                    //x = floors[i].second.first;
                    npos = floors[i].second.first;
                    ans += abs(pos - npos);
                    pos = npos;
                }
            }
            //ans += abs(x - y);
            //trace(i, x, y, ans);
            trace(i, ans, pos);
        }

        cout << ans << endl;

    }

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}


