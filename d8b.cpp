#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line =50, n_char = -1;
    // int n_line = 12, n_char = -1;
    vector<string> graph(n_line);
    map<char, vector<pair<int, int>>> freq;
    for(int i = 0; i < n_line; i++) {
        cin >> graph[i];
        n_char = graph[i].size();
        for(int j = 0; j < n_char; j++) {
            if(graph[i][j] != '.') {
                freq[graph[i][j]].push_back({i, j});
            }
        }
    }
    vector<vector<bool>> antinode(n_line, vector<bool>(n_char, false));
    for(auto x: freq) {
        for(auto p1: x.second) {
            for(auto p2: x.second) {
                if(p2==p1) continue;
                int ctr =0;
                while(1) {
                    pair<int, int> first = {(ctr+1)*p1.first-ctr*p2.first, (ctr+1)*p1.second-ctr*p2.second};
                    if(first.first>=0 && first.first<n_line && first.second>=0 && first.second<n_char) {
                        antinode[first.first][first.second] = true;
                    } else {
                        break;
                    }
                    ctr++;
                }
                ctr = 0;
                while(1) {
                    pair<int, int> second = {(ctr+1)*p2.first-ctr*p1.first, (ctr+1)*p2.second-ctr*p1.second};
                    if(second.first>=0 && second.first<n_line && second.second>=0 && second.second<n_char) {
                        antinode[second.first][second.second] = true;
                    } else {
                        break;
                    }
                    ctr++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_char; j++) {
            ans += antinode[i][j] ? 1 : 0;
        }
    }
    for(int i = 0; i < n_line; i++) {
        cout << graph[i] << endl;
    }
    cout << ans << endl;
    return 0;
}