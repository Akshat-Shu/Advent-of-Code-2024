#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int getSize(int x) {
        return size[find(x)];
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

int hashing(string s) {
    return (s[0] - 'a') * 26 + (s[1] - 'a');
}

bool hast(int x) {
    return (x/26 == 't'-'a');
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 3380;
    DSU dsu(26*26);
    vector<vector<int>> adj(26*26);
    for(int i = 0; i < n_line; i++) {
        string s; cin >> s;
        string first = s.substr(0, 2);
        string second = s.substr(3, 5);
        
        int hashFirst = hashing(first);
        int hashSecond = hashing(second);
        dsu.unite(hashFirst, hashSecond);
        adj[hashFirst].push_back(hashSecond);
        adj[hashSecond].push_back(hashFirst);
    }
    int ans = 0;
    for(int i = 0; i < 26*26; i++) {
        for(auto first: adj[i]) {
            for(auto second: adj[i]) {
                if(find(adj[second].begin(), adj[second].end(), first) != adj[second].end()) {
                    if(hast(i) || hast(first) || hast(second)) {
                        ans++;
                    }
                }
            }
        }
    }
    ans /= 6; // Each cycle is counted 6 times
    // vector<bool> seen(26*26);
    // for(int i = 0; i < 26*26; i++) {
        // if(!seen[i] && dsu.getSize(i) == 3) {
    //         if(adj[i].size() != 2) continue;
    //         int first = adj[i][0];
    //         int second = adj[i][1];
    //         if(adj[first].size() != 2 || adj[second].size() != 2) continue;
    //         if(hast(first) || hast(second) || hast(i)) {
    //             ans++;
    //         }
    //         seen[first] = seen[second] = seen[i] = true;
    //     }

    // }
    cout << ans << endl;
    return 0;
}