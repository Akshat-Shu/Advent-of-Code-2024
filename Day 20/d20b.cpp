#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;



int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 141, n_char = -1;
    pair<int, int> start, end;
    vector<string> grid(n_line);
    for(int i = 0; i < n_line; i++) {
        cin >> grid[i];
        n_char = grid[i].size();
        for(int j = 0; j < n_char; j++) {
            if(grid[i][j] == 'S') start = {i, j};
            if(grid[i][j] == 'E') end = {i, j};
        }
    }
    vector<vector<int>> distToEnd(n_line, vector<int>(n_char, INT_MAX));
    queue<pair<int, int>> q;
    q.push({end.first, end.second});
    distToEnd[end.first][end.second] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(abs(i)+abs(j) != 1) continue;
                int new_x = x+i, new_y = y+j;
                if(new_x >= 0 && new_x < n_line && new_y >= 0 && new_y < n_char && grid[new_x][new_y] != '#' && distToEnd[new_x][new_y] == INT_MAX) {
                    distToEnd[new_x][new_y] = distToEnd[x][y]+1;
                    q.push({new_x, new_y});
                }
            }
        }
    }
    cout << "Distance from end to start: " << distToEnd[start.first][start.second] << endl;
    vector<pair<int, int>> path;
    if (distToEnd[start.first][start.second] != INT_MAX) {
        pair<int, int> current = start;
        while (current != end) {
            path.push_back(current);
            int x = current.first, y = current.second;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) != 1) continue;
                    int new_x = x + i, new_y = y + j;
                    if (new_x >= 0 && new_x < n_line && new_y >= 0 && new_y < n_char && distToEnd[new_x][new_y] == distToEnd[x][y] - 1) {
                        current = {new_x, new_y};
                        break;
                    }
                }
                if (current != path.back()) break;
            }
        }
        path.push_back(end);
    }
    cout << distToEnd[7][7] << " hi" << endl;
    map<int, int> reduced;
    int minCheatPath = INT_MAX;
    map<pair<int, int>, int> dp;
    function <void(int, int, int, int, int)> check = [&](int x1, int y1, int x, int y, int time) {
        if(time == 20) return;
        time++;
        for(int i = -1; i<= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(abs(i)+abs(j) != 1) continue;
                int new_x = x+i, new_y = y+j;
                check(x1, y1, new_x, new_y, time);
                if(new_x >= 0 && new_x < n_line && new_y >= 0 && new_y < n_char && grid[new_x][new_y] != '#') {
                    reduced[distToEnd[x1][y1] - time - distToEnd[new_x][new_y]]++;
                }
            }
        }
    };
    for(auto point: path) {
        int x = point.first, y = point.second;
        // for(int time = 0; time<20; time++) {
        //     for(int i = -1; i<= 1; i++) {
        //         for(int j = -1; j <= 1; j++) {
        //             if(abs(i)+abs(j) != 1) continue;
        //             int new_x = x+i, new_y = y+j;
        //             if(new_x >= 0 && new_x < n_line && new_y >= 0 && new_y < n_char && grid[new_x][new_y] != '#') {
                        
        //             }
        //         }
        //     }
        // }
        for(int i = max(0, x-20); i < min(n_line, x+21); i++) {
            for(int j = max(0, y-20); j < min(n_char, y+21); j++) {
                if(grid[i][j] != '#') {
                    int minTime = abs(x-i)+abs(y-j);
                    if(minTime <= 20) {
                        reduced[distToEnd[x][y]-minTime-distToEnd[i][j]]++;
                    }
                }
            }
        }
    }
    int savingCheats = 0;
    cout << "Minimum cheat path: " << minCheatPath << endl;
    for(auto p: reduced) {
        cout << p.first << " " << p.second << endl;
        if(p.first>=100) savingCheats += p.second;
    }
    cout << savingCheats << endl;
    


    return 0;
}