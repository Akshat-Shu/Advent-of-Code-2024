#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 50, n_col = -1;
    int n_input_line = 20;
    vector<string> grid(n_line);
    pair<int, int> rob = {0, 0};
    for(int i = 0; i < n_line; i++) {
        cin >> grid[i];
        n_col = grid[i].size();
        for(int j = 0; j < n_col; j++) {
            if(grid[i][j] == '@') rob = {i, j};
        }
    }
    string s; cin >> s;
    for(int i = 0; i < n_input_line; i++) {
        string t; cin >> t;
        s+=t;
    }
    for(int k = 0; k < s.size(); k++) {
        pair<int, int> dir = {0, 0};
        if(s[k] == '<') {
            dir = {0, -1};
        } else if(s[k] == '>') {
            dir = {0, 1};
        } else if(s[k] == '^') {
            dir = {-1, 0};
        } else if(s[k] == 'v') {
            dir = {1, 0};
        }

        pair<int, int> pos = rob;
        pair<int, int> free = {-1, -1};
        while(pos.first >= 0 && pos.first < n_line && pos.second >= 0 && pos.second < n_col) {
            if(grid[pos.first][pos.second] == '#') {
                break;
            }
            if(grid[pos.first][pos.second] == '.') {
                free = pos;
                break;
            }
            pos.first += dir.first;
            pos.second += dir.second;
        }
        pos = {rob.first + dir.first, rob.second + dir.second};
        if(free.first != -1) {
            while(pos != free) {
                grid[pos.first][pos.second] = 'O';
                pos.first += dir.first;
                pos.second += dir.second;   
            }
            grid[free.first][free.second] = 'O';
            grid[rob.first][rob.second] = '.';
            rob.first += dir.first;
            rob.second += dir.second;
            grid[rob.first][rob.second] = '@';
        }
    }
    lli ans = 0;
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_col; j++) {
            if(grid[i][j] == 'O') ans += 100*i+j;
        }
    }
    cout << ans << endl;
    return 0;
}