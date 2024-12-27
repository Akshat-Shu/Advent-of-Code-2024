#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n_line = 3450;
    vector<pair<int, int>> inst(n_line);
    for(int i = 0; i < n_line; i++) {
        int a, b; char c;
        cin >> a >> c >> b;
        inst[i] = {a, b};
    }
    int ctr = 1024;        
    vector<vector<char>> grid(71, vector<char>(71, '.'));
    for(int i = 0; i < ctr; i++) {
        int a = inst[i].first, b = inst[i].second;
        grid[a][b] = '#';
    }
    while(1) {

        grid[inst[ctr].first][inst[ctr].second] = '#';
        vector<vector<int>> dist(71, vector<int>(71, INT_MAX));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < 71 && ny >= 0 && ny < 71 && grid[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        if(dist[70][70] == INT_MAX) {
            cout << inst[ctr].first << " " << inst[ctr].second << endl;
            break;
        } else ctr++;
    }
    return 0;
}