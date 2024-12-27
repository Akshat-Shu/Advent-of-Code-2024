#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

map<string, bool> memo;

bool findMatch(string s, vector<string> &tows) {
    if(s=="") return true;
    if(memo.find(s) != memo.end()) return memo[s];
    bool ans = false;
    for(string tow: tows) {
        if(s.size() >= tow.size() && s.substr(0, tow.size()) == tow) {
            cout << "checking " << s.substr(tow.size()) << endl;
            ans = ans || findMatch(s.substr(tow.size()), tows);
        }
    }
    memo[s] = ans;
    return ans;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    vector<string> tows;
    string s; getline(cin, s);
    stringstream ss(s);
    string item;
    while (getline(ss, item, ',')) {
        tows.push_back(item);
    }
    int n_patt = 400;
    // int n_patt = 8;
    int cnt = 0;
    for(int _ = 0; _ < n_patt; _++) {
        cout << "processing " << _ << endl;
        string s; cin >> s;
        bool isMatch = findMatch(s, tows);
        cnt += (isMatch ? 1 : 0);
        cout << "string " << s << " is " << (isMatch ? "matched" : "not matched") << endl;
    }
    cout << cnt << endl;
    return 0;
}