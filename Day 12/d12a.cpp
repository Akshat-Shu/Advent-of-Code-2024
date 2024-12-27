#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct DSU {
    vector<int> parent, rank;
    int n_char;
    DSU(int n, int ch) : parent(n), rank(n, 0) {
        n_char = ch;
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    int find(pair<int, int> x) {
        return find(x.first*n_char+x.second);
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    void unite(pair<int, int> x, pair<int, int> y) {
        unite(x.first*n_char + x.second, y.first*n_char+y.second);
    }
};

int val(pair<int, int> p, int ch) {
    return ch*p.first+p.second;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 140, n_char = -1;
    vector<string> s(n_line);
    for(int i = 0; i < n_line; i++) {
        cin >> s[i];
        n_char = s[i].size();
    }

    DSU dsu(n_line*n_char, n_char);
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_char; j++) {
            if(i-1>=0 && s[i-1][j] == s[i][j]) dsu.unite(i*n_char+j, (i-1)*n_char+j);
            if(i+1<n_line && s[i+1][j] == s[i][j]) dsu.unite(i*n_char+j, (i+1)*n_char+j);
            if(j-1>=0 && s[i][j-1] == s[i][j]) dsu.unite(i*n_char+j, i*n_char+j-1);
            if(j+1<n_char && s[i][j+1] == s[i][j]) dsu.unite(i*n_char+j, i*n_char+j+1);

        }
    }
    cout << "ok" << endl;

    map<int, set<int>> regions;
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_char; j++) {
            auto found = dsu.find(i*n_char+j);
            regions[found].insert(i*n_char+j);
            regions[found].insert(found);
        }
    }
    cout << regions.size() << " regions";

    lli ans = 0;
    for(auto region: regions) {
        lli area = region.second.size();
        lli perimeter = 0;
        vector<vector<vector<int>>> sides(n_line, vector<vector<int>>(n_char, vector<int>(4, 0)));
        for(auto y: region.second) {
            pair<int, int> x = {y/n_char, y%n_char};
            if(x.second-1<0||region.second.find(val({x.first, x.second-1}, n_char)) == region.second.end()) {
                if(sides[x.first][x.second][0] == 0) {
                    perimeter++;
                    // cout << "perimeter L for " << x.first << " " << x.second << endl;
                
                }
                int cnt = x.first;
                while(region.second.find(val({cnt, x.second}, n_char)) != region.second.end()) {
                    if(x.second>=0 && region.second.find(val({cnt, x.second-1}, n_char)) != region.second.end()) break;
                    sides[cnt][x.second][0] = 1;
                    cnt--;
                }
                cnt = x.first+1;
                while(region.second.find(val({cnt, x.second}, n_char)) != region.second.end()) {
                    if(x.second>=0 && region.second.find(val({cnt, x.second-1}, n_char)) != region.second.end()) break;
                    sides[cnt][x.second][0] = 1;
                    cnt++;
                }
            }
                
            if(x.second+1>=n_char||region.second.find(val({x.first, x.second+1}, n_char)) == region.second.end()) {
                if(sides[x.first][x.second][1] == 0) {
                    perimeter++;
                    // cout << "perimeter R for " << x.first << " " << x.second << endl;
                }
                int cnt = x.first;
                while(region.second.find(val({cnt, x.second}, n_char)) != region.second.end()) {
                    if(x.second+1<n_char && region.second.find(val({cnt, x.second+1}, n_char)) != region.second.end()) break;
                    sides[cnt][x.second][1] = 1;
                    cnt--;
                }
                cnt = x.first+1;
                while(region.second.find(val({cnt, x.second}, n_char)) != region.second.end()) {
                    if(x.second+1<n_char && region.second.find(val({cnt, x.second+1}, n_char)) != region.second.end()) break;
                    sides[cnt][x.second][1] = 1;
                    cnt++;
                }
            }
            if(x.first-1<0||region.second.find(val({x.first-1, x.second}, n_char)) == region.second.end()) {
                if(sides[x.first][x.second][2] == 0) {
                    perimeter++;
                    // cout << "perimeter U for " << x.first << " " << x.second << endl;
                }
                int cnt = x.second;
                while(region.second.find(val({x.first, cnt}, n_char)) != region.second.end()) {
                    if(x.first>=0 && region.second.find(val({x.first-1, cnt}, n_char)) != region.second.end()) break;
                    sides[x.first][cnt][2] = 1;
                    cnt--;
                }
                cnt = x.second+1;
                while(region.second.find(val({x.first, cnt}, n_char)) != region.second.end()) {
                    if(x.first>=0 && region.second.find(val({x.first-1, cnt}, n_char)) != region.second.end()) break;
                    sides[x.first][cnt][2] = 1;
                    cnt++;
                }
            }
            if(x.first+1>=n_line||region.second.find(val({x.first+1, x.second}, n_char)) == region.second.end()) {
                if(sides[x.first][x.second][3] == 0) {
                    perimeter++;
                    // cout << "perimeter D for " << x.first << " " << x.second << endl;
                }
                int cnt = x.second;
                while(region.second.find(val({x.first, cnt}, n_char)) != region.second.end()) {
                    if(x.first+1<n_line && region.second.find(val({x.first+1, cnt}, n_char)) != region.second.end()) break;
                    sides[x.first][cnt][3] = 1;
                    cnt--;
                }
                cnt = x.second+1;
                while(region.second.find(val({x.first, cnt}, n_char)) != region.second.end()) {
                    if(x.first+1<n_line && region.second.find(val({x.first+1, cnt}, n_char)) != region.second.end()) break;
                    sides[x.first][cnt][3] = 1;
                    cnt++;
                }
            }
        }
        cout << "area: " << area << " perimeter: " << perimeter << endl;
        ans += area*perimeter;
    }
    cout << ans << endl;
    return 0;
}