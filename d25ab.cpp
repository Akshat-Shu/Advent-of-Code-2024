#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;



int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n_input = 500;
    vector<vector<int>> locks, keys;
    for(int i = 0; i <n_input; i++) {
        vector<string> ss;
        for(int i = 0; i < 8; i++) {
            string s; getline(cin, s);
            if(i!=7) ss.push_back(s);
        }
        vector<int> cnt(5);
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 7; j++) {
                cnt[i] += (ss[j][i] == '#');
            }
        }
        if(ss[0] == "#####") locks.push_back(cnt);
        else keys.push_back(cnt);
        cout << "cnt: ";
        for(int i = 0; i < 5; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
    int cnt = 0;
    for(auto lock: locks) {
        for(auto key: keys) {
            bool possible = true;
            for(int i = 0; i < 5; i++) {
                if(lock[i]+key[i] >7) {
                    possible = false;
                    break;
                }
            }
            if(possible) cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}