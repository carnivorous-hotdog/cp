#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
vector<set<int>> v(26);

int main(){
    IOS;
    freopen("input.txt", "r", stdin);
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++){
        v[s[i] - 'a'].insert(i+1);
    }

    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if (a == 2){
            int l, r;
            cin >> l >> r;
            int unq = 0;

            // does not give TLE
            //for (int i = 0; i < 26; i++){
                //cerr << "hello" << endl;
                //auto it = v[i].lower_bound(l);
                //if (it != v[i].end() && *it <= r){
                    //unq++;
                //}
            //}

            // gives TLE
            for (auto x: v){
                cerr << "hello" << endl;
                auto it = x.lower_bound(l);
                if (it != x.end() && *it <= r){
                    unq++;
                }
            }

            cout << unq << endl;

        } else {
            int pos;
            char c;
            cin >> pos >> c;

            v[s[pos-1] - 'a'].erase(pos);
            s[pos-1]=c;
            v[c-'a'].insert(pos);
        }
    }

    return 0;
}

