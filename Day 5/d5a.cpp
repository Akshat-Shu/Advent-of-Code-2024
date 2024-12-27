#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_const = 1176, n_update = 192;
    // int n_const = 21, n_update = 6;
    
    map<int, vector<int>> before;
    for(int i = 0; i < n_const; i++) {
        int x, y; char c;
        cin >> x >> c >> y;
        before[y].push_back(x);
    }
    string update;
    lli ans = 0;
    for(int i = 0; i < n_update; i++) {
        cin >> update;
        vector<int> update_values;
        stringstream ss(update);
        string temp;
        while (getline(ss, temp, ',')) {
            update_values.push_back(stoi(temp));
        }
        bool valid = true;
        for(int i = 0; i < update_values.size(); i++) {
            for(int j = i+1; j < update_values.size(); j++) {
                if (find(before[update_values[i]].begin(), before[update_values[i]].end(), update_values[j]) != before[update_values[i]].end()) {
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(valid) ans += update_values[update_values.size()/2];
    }
    cout << ans << endl;
    return 0;
}