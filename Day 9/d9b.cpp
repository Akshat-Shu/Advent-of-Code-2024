#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    vector<lli> a;
    lli ctr = 0;
    map<lli, bool> seen;
    map<lli, lli> freq;
    vector<pair<int, int>> gaps;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < s[i]-'0'; j++) {
                a.push_back(ctr);
                freq[ctr]++;
            }
            ctr++;
        }  else {
            if(s[i]>'0')gaps.push_back({a.size(), a.size()+s[i]-'0'-1});
            for(int j = 0; j < s[i]-'0'; j++) {
                a.push_back(-1);
            }
        }
    }


    
    for(int i = a.size()-1; i >= 0; i--) {
        if(a[i] == -1) continue;
        if(seen[a[i]]) continue;
        int f = freq[a[i]];
        seen[a[i]] = true;
        int end = i;
        int start = i-f+1;
        bool found = false; int j;
        for(j = 0; j < gaps.size(); j++) {
            if(gaps[j].first > end) break;
            if(gaps[j].second-gaps[j].first+1>=f) {
                found = true;
                break;
            }
        }
        if(found) {
            for(int k = gaps[j].first; k< gaps[j].first+f; k++) {
                a[k] = a[i];
            }
            for(int j = start; j<=end; j++) {
                a[j] = -1;
            }
            gaps[j].first += f;
        }
        i=start;
    }

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    lli ans = 0;
    for(lli i = 0; i < a.size(); i++) {
        if(a[i] == -1) continue;
        lli x = a[i];
        ans += i*x;
    }
    cout << ans << endl;

    return 0;
}