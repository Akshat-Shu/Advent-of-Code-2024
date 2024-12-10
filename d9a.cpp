#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    vector<int> a;
    lli ctr = 0;
    vector<int> gaps;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < s[i]-'0'; j++) {
                a.push_back(ctr);
            }
            ctr++;
        }  else {
            for(int j = 0; j < s[i]-'0'; j++) {
                gaps.push_back(a.size());
                a.push_back(-1);
            }
        }
    }
    sort(gaps.begin(), gaps.end(), greater<int>());
    for(int i = a.size()-1; i >= 0; i--) {
        if(gaps.back()>i) break;
        if(a[i] != -1) {
            a[gaps.back()] = a[i];
            a[i] = -1;
            gaps.pop_back();
        }
    }

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    lli ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == -1) continue;
        lli x = a[i];
        ans += i*x;
    }
    cout << ans << endl;

    return 0;
}