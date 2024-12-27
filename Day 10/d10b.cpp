#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void checkValue(int i, int j, int val, vector<string> &s, int n_line, int n_char, set<pair<int, int>> &found, int &count) {
    if(i<0||i>=n_line || j<0||j>=n_char) return;
    if(val == 9 && s[i][j] == '9') {
        found.insert({i, j});
        count ++;
        return;
    }
    if(s[i][j] - '0' != val) return;
    {
        checkValue(i-1, j, val+1, s, n_line, n_char, found, count);
        checkValue(i+1, j, val+1, s, n_line, n_char, found, count);
        checkValue(i, j-1, val+1, s, n_line, n_char, found, count);
        checkValue(i, j+1, val+1, s, n_line, n_char, found, count);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 8, n_char = -1;
    vector<string> s(n_line);
    vector<pair<int, int>> nines;
    vector<pair<int, int>> zeroes;
    for(int i = 0; i < n_line; i++) {
        cin >> s[i];
        n_char = s[i].size();
        for(int j = 0; j < n_char; j++) {
            if(s[i][j] == '0') zeroes.push_back({i, j});
            else if(s[i][j] == '0') nines.push_back({i, j});
        }
    }
    lli ans = 0;
    for(auto zero: zeroes) {
        set<pair<int, int>> found;
        int count = 0;
        checkValue(zero.first, zero.second, 0, s, n_line, n_char, found, count);
        ans += count;
        // if(found.size()) {
        //     cout << "i: " << zero.first << " j: " << zero.second <<endl;
        //     cout << "found: ";
        //     for(auto x: found) cout << "{" << x.first << ", " << x.second << "} ";
        //     cout << endl;
        // }
    }

    cout << ans << endl;

    return 0;
}