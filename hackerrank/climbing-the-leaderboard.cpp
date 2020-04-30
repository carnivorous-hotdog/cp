#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    IOS;

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> unq(n); // extra array to store unique values

    for (int i = 0;i < n; i++){
        cin >> a[i];
        unq[i] = a[i];
    }

    // map to store the score : rank pairs
    map<int, int> mp;

    // to get unique values
    unq.erase(unique(unq.begin(), unq.end()), unq.end());

    // populating the map
    for (int i = 0; i < (int)unq.size(); i++){
        mp[unq[i]] = i+1;
    }

    
    int m;
    cin >> m;
    // reversing to easily do binary search
    reverse(a.begin(), a.end());

    while(m--){
        int x;
        cin >> x;
        // if score of alice is found in map, then just print the corresponding rank
        if (mp.count(x)){
            cout << mp[x] << endl;
        }
        else {
            // getting the index of the score that is just greater than alice score
            int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            // if idx == n, it means that alice's score is the heighest
            if (idx == n) cout << 1 << endl;
            // else, the rank will be 1 more than the element at idx as alice score will be 1 below in table
            else cout << mp[a[idx]] + 1 << endl;
        }
    }

    return 0;
}


