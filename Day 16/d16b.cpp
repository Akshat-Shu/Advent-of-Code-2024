#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;


vector<vector<vector<int>>> seen2;
vector<vector<pair<int, int>>> allMinPaths;
lli minPath = INT_MAX;
vector<vector<int>> dirn = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void dfs2(int x, int y, vector<string> &grid, int dir, lli path, vector<pair<int, int>> currentPath) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') return;
    currentPath.push_back({x, y});
    if (grid[x][y] == 'E') {
        vector<string> newGrid = grid;
        cout << "path: " << path << endl;
        for(auto pt: currentPath) {
            newGrid[pt.first][pt.second] = 'O';
        }
        for(auto row: newGrid) {
            cout << row << endl;
        }
        if (path < minPath) {
            minPath = path;
            allMinPaths.clear();
            allMinPaths.push_back(currentPath);
        } else if (path == minPath) {
            allMinPaths.push_back(currentPath);
        }
        return;
    }

    seen2[x][y][dir] = path;

    for (int k = 0; k < 4; k++) {
        int nx = x + dirn[k][0];
        int ny = y + dirn[k][1];
        if (k == dir) {
            if (seen2[nx][ny][k] == -1 || seen2[nx][ny][k] > path + 1) {
                dfs2(nx, ny, grid, k, path + 1, currentPath);
            }
        } else {
            if (seen2[nx][ny][k] == -1 || seen2[nx][ny][k] > path + 1001) {
                dfs2(nx, ny, grid, k, path + 1001, currentPath);
            }
        }
    }

    currentPath.pop_back();
}

// lli minPath = INT_MAX;
// vector<vector<int>> seen;
// vector<vector<int>> seen2;
// vector<vector<int>> dirn = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
// vector<vector<int>> points;


// lli dfs(int x, int y, vector<string> &grid, int dir, lli path) {
//     if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') return INT_MAX;
//     if (seen[x * grid[0].size() + y][dir] != -1 && seen[x * grid[0].size() + y][dir] <= path) return INT_MAX;
//     seen[x * grid[0].size() + y][dir] = path;
//     if (grid[x][y] == 'E') {
//         minPath = min(minPath, path);
//         return path;
//     }

//     lli minPathLocal = INT_MAX;
//     for (int k = 0; k < 4; k++) {
//         lli newPath = dfs(x + dirn[k][0], y + dirn[k][1], grid, k, (k == dir ? path + 1 : path + 1001));
//         minPathLocal = min(minPathLocal, newPath);
//     }
//     return minPathLocal;
// }

// lli dfs2(int x, int y, vector<string> &grid, int dir, lli path, vector<pair<int, int>> currentPath) {
//     if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '#') return INT_MAX;
//     if (seen2[x * grid[0].size() + y][dir] != -1 && seen2[x * grid[0].size() + y][dir] <= path) return INT_MAX;
//     seen2[x * grid[0].size() + y][dir] = path;
//     currentPath.push_back({x, y});
//     if (grid[x][y] == 'E') {
//         cout << path << endl;
//         if(path == minPath) {
//             for (auto &p : currentPath) {
//                 cout << "(" << p.first << ", " << p.second << ") ";
//             }
//             cout << endl;
//             for(auto &pt: currentPath) {
//                 points[pt.first][pt.second]++;
//             }
//         }
//         return path;
//     }

//     lli minPathLocal = INT_MAX;
//     for (int k = 0; k < 4; k++) {
//         lli newPath = dfs2(x + dirn[k][0], y + dirn[k][1], grid, k, (k == dir ? path + 1 : path + 1001), currentPath);
//         minPathLocal = min(minPathLocal, newPath);
//     }
//     return minPathLocal;
// }



int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 17, n_col = -1;
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
    // seen.resize(n_line*n_col, vector<int>(4, -1));
    seen2.resize(n_line, vector<vector<int>>(n_col, vector<int>(4, -1)));
    // dfs(start.first, start.second, grid, 0, 0);
    // points.resize(n_line, vector<int>(n_col, 0));
    dfs2(start.first, start.second, grid, 0, 0, {{start.first, start.second}});
    cout << minPath << endl;
    int cnt = 0;
    // for(int i = 0; i < n_line; i++) {
    //     for(int j = 0; j < n_col; j++) {
    //         if(points[i][j] > 0) {
    //             cout << "O";
    //             cnt++;
    //         } else cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    for(auto minPathDir: allMinPaths) {
        for(auto pt: minPathDir) {
            if(grid[pt.first][pt.second] == '.') {
                grid[pt.first][pt.second] = 'O';
                cnt++;
            }
        }
    }
    for (int i = 0; i < n_line; i++) {
        for (int j = 0; j < n_col; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}