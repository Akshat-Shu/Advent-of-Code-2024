#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 130, n_char = -1;
    // int n_line = 10, n_char = -2;
    vector<vector<char>> lines(n_line);
    vector<vector<char>> path(n_line);
    int i = -1, j = -1, chance = 0;
    for(int k = 0; k < n_line; k++) {
        string s; cin >> s;
        n_char = s.size();
        for(auto x: s) {
            lines[k].push_back(x);
            path[k].push_back(x);
            if(x == '^') {
                i = k; j = lines[k].size()-1;
            }
        }
    }
    path[i][j] = 'X';
    while(1) {
        pair<int, int> pos = {i, j};
        pair<int, int> newPos = {i, j};
        if(chance == 0) {
            newPos.first--;
        } else if(chance == 1) {
            newPos.second++;
        } else if(chance == 2) {
            newPos.first++;
        } else {
            newPos.second--;
        }
        if(newPos.first < 0 || newPos.first >= n_line || newPos.second < 0 || newPos.second >= n_char) {
            break;
        }
        if(lines[newPos.first][newPos.second] == '#') {
            chance = (chance+1)%4;
        } else {
            i = newPos.first;
            j = newPos.second;
            path[i][j] = 'X';
        }
    }
    int count = 0;
    for(int k = 0; k < n_line; k++) {
        for(int l = 0; l < n_char; l++) {
            count += (path[k][l] == 'X');
        }
    }
    cout << count << endl;
    return 0;
}