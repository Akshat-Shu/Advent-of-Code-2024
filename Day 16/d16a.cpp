#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli minPath = INT_MAX;
vector<vector<int>> seen;
vector<vector<int>> dirn = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

// lli dfs(int x, int y, vector<string> &grid, int dir, lli path) {
//     if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') return INT_MAX;
//     if(seen[x][y] != -1) return;
//     seen[x][y] = path;
//     if(grid[x][y] == 'E') {
//         minPath = min(minPath, path);
//         return;
//     }

//     for(int k = 0; k < 4; k++) {
//         dfs(x+dirn[k][0], y+dirn[k][1], grid, k, (k == dir ? path+1 : path+1001));
//     }
// }

lli dfs(int x, int y, vector<string> &grid, int dir, lli path) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') return INT_MAX;
    if (seen[x * grid[0].size() + y][dir] != -1 && seen[x * grid[0].size() + y][dir] <= path) return INT_MAX;
    seen[x * grid[0].size() + y][dir] = path;
    if (grid[x][y] == 'E') {
        minPath = min(minPath, path);
        return path;
    }

    lli minPathLocal = INT_MAX;
    for (int k = 0; k < 4; k++) {
        lli newPath = dfs(x + dirn[k][0], y + dirn[k][1], grid, k, (k == dir ? path + 1 : path + 1001));
        minPathLocal = min(minPathLocal, newPath);
    }
    return minPathLocal;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 141, n_col = -1;
    vector<string> grid(n_line);
    pair<int, int> start, end;
    int dir = 0;
    //    1
    // 2     0
    //    3
    for(int i = 0; i < n_line; i++) {
        cin >> grid[i];
        n_col = grid[i].size();
        for(int j = 0; j < n_col; j++) {
            if(grid[i][j] == 'S') {
                start = {i, j};
            } else if(grid[i][j] == 'E') {
                end = {i, j};
            }
        }
    }
    seen.resize(n_line*n_col, vector<int>(4, -1));
    dfs(start.first, start.second, grid, 0, 0);
    cout << INT_MAX << endl;
    cout << minPath << endl;
    return 0;
}