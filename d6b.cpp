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
        for(int p =0; p < n_char; p++) {
            char x = s[p];
            lines[k].push_back(x);
            path[k].push_back(x);
            if(x == '^') {
                i = k; j = p;
            }
        }
    }


    int cnt = 0;
    for(int m = 0; m < n_line; m++) {
        for(int n = 0; n < n_char; n++) {
            if(lines[m][n] != '.' ) continue;
            lines[m][n] = '#';
            vector<set<int>> visited(n_line*n_char, set<int>());

            path[i][j] = 'X';
            bool loops = false;
            chance = 0;
            pair<int, int> pos = {i, j};
            while(1) {
                pair<int, int> newPos = {pos.first, pos.second}; 
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
                    pos = newPos;
                    if(visited[pos.first*n_char+pos.second].count(chance)) {
                        loops = true;
                        break;
                    }
                    visited[pos.first*n_char+pos.second].insert(chance);
                }
            }
            // if (loops) {
            //     cout << "loops for " << m << " " << n << endl;
            //     for (int h = 0; h < n_line; h++) {
            //         for (int k = 0; k < n_char; k++) {
            //             cout << path[h][k];
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            cnt += (loops ? 1: 0);
            lines[m][n] = '.';  
        }
    }
    cout << cnt << endl;
    return 0;
}