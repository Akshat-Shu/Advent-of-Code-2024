#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

bool push(vector<string> &grid, pair<int, int> pos, pair<int, int> dir) {
    pair<int, int> newPos = {pos.first + dir.first, pos.second + dir.second};
    if(grid[newPos.first][newPos.second] == '#') return false;
    else if(grid[newPos.first][newPos.second] = '.') return true;
    else if(dir.second == 0) {
        if(grid[newPos.first][newPos.second] == ']')
            return push(grid, newPos, dir) && push(grid, {newPos.first, newPos.second-1}, dir);
        else return push(grid, newPos, dir) && push(grid, {newPos.first, newPos.second+1}, dir);
    } else if(dir.second == 1) {
        if(grid[newPos.first][newPos.second] == '[')
            return push(grid, {newPos.first, newPos.second+1}, dir);
    } else if(dir.second == -1) {
        if(grid[newPos.first][newPos.second] == ']')
            return push(grid, {newPos.first, newPos.second-1}, dir);
    }
}

void change(vector<string> &grid, pair<int, int> pos, pair<int, int> dir) {
    pair<int, int> newPos = {pos.first + dir.first, pos.second + dir.second};
    if(grid[newPos.first][newPos.second] == '#') return;
    else if(grid[newPos.first][newPos.second] == '.') {
        swap(grid[pos.first][pos.second], grid[newPos.first][newPos.second]);
    } else if(dir.second == -1) {
        if(grid[newPos.first][newPos.second] == ']') {
            change(grid, {newPos.first, newPos.second-1}, dir);
            grid[newPos.first][newPos.second] = '[';
            grid[newPos.first][newPos.second-1] = grid[pos.first][pos.second];
            grid[pos.first][pos.second] = ']';
        }
    } else if(dir.second == 1) {
        if(grid[newPos.first][newPos.second] == '[') {
            change(grid, {newPos.first, newPos.second+1}, dir);
            grid[newPos.first][newPos.second] = ']';
            grid[newPos.first][newPos.second+1] = grid[pos.first][pos.second];
            grid[pos.first][pos.second] = '[';
        }
    } else if(dir.second == 0) {
        if(grid[newPos.first][newPos.second] == ']') {
            change(grid, {newPos.first, newPos.second-1}, dir);
            change(grid, {newPos.first, newPos.second}, dir);
            swap(grid[newPos.first][newPos.second], grid[pos.second][pos.first]);
        } else if(grid[newPos.first][newPos.second] == '[') {
            change(grid, {newPos.first, newPos.second+1}, dir);
            change(grid, {newPos.first, newPos.second}, dir);
            swap(grid[newPos.first][newPos.second], grid[pos.second][pos.first]);
        }
    }
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 10, n_col = -1;
    int n_input_line = 10;
    vector<string> g(n_line);
    vector<string> grid(n_line);
    pair<int, int> rob = {0, 0};
    for(int i = 0; i < n_line; i++) {
        cin >> g[i];
        n_col = g[i].size();
        string sa;
        for(int j = 0; j < n_col; j++) {
            if(g[i][j] == '#') {
                sa += "##";
            } else if(g[i][j] == '.') {
                sa += "..";
            } else if(g[i][j] == 'O') {
                sa += "[]";
            }
            else if(g[i][j] == '@') {
                sa += "@.";
            }
        }
        grid[i] = sa;
    }
    n_col = grid[0].size();
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_col; j++) {
            if(grid[i][j] == '@') rob = {i, j};
        }
    }
    for(auto &row : grid) {
        cout << row << endl;
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
        if(push(grid, rob, dir)) {
            change(grid, rob, dir);
            rob.first += dir.first;
            rob.second += dir.second;
        }
        cout << "move: " << s[k] << endl;
        for (const auto& row : grid) {
            cout << row << endl;
        }
    }

    lli ans = 0;
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_col; j++) {
            if(grid[i][j] == '[') ans += 100*i+j;
        }
    }
    cout << ans << endl;
    return 0;
}