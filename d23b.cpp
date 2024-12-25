#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

vector<int> ans = {};

bool isClique(vector<int> &v, vector<vector<int>> &adj, int j) {
    
    for(int i = 0; i < v.size(); i++) {
        if(find(adj[v[i]].begin(), adj[v[i]].end(), j) == adj[v[i]].end()) {
            return false;
        }
    }
    return true;
}

void maxClique(vector<int> v, vector<vector<int>> &adj, int i) {
    for(int j = i+1; j < 26*26; j++) {
        if(isClique(v, adj, j)) {
            // cout << "clique ";
            // for(int e: v) cout << e << " ";
            // cout << "j: " << j << endl; 
            vector<int> ne = v;
            ne.push_back(j);
            cout << "ne size: " << ne.size() << " ans size: " << ans.size() << endl;
            if(ne.size() > ans.size()) {
                ans = ne;
            }
            maxClique(ne, adj, j);
        }
    }
}


int hashing(string s) {
    return (s[0] - 'a') * 26 + (s[1] - 'a');
}

bool hast(int x) {
    return (x/26 == 't'-'a');
}

string inverseHash(int x) {
    return string(1, 'a' + x/26) + string(1, 'a' + x%26);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 3380;
    vector<vector<int>> adj(26*26);
    for(int i = 0; i < n_line; i++) {
        string s; cin >> s;
        string first = s.substr(0, 2);
        string second = s.substr(3, 5);
        
        int hashFirst = hashing(first);
        int hashSecond = hashing(second);
        adj[hashFirst].push_back(hashSecond);
        adj[hashSecond].push_back(hashFirst);
    }
    
    // ans /= 6; // Each cycle is counted 6 times
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
    maxClique({}, adj, -1);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << inverseHash(ans[i]) << " ";
    }
    cout << endl;
    return 0;
}