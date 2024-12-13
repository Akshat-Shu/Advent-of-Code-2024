#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_blinks = 75;
    vector<lli> a;
    int n_nums = 8;
    for(int i = 0; i < n_nums; i++) {
        lli x; cin >> x;
        a.push_back(x);
    }
    lli cnt = 0;
    for(int i = 0; i < n_nums; i++) {
        vector<lli> b({a[i]});
        for(int j = 0; j < n_blinks; j++) {
            vector<lli> newB;
            for(int k = 0; k < b.size(); k++) {
                if(b[k] == 0) newB.push_back(1);
                else if(to_string(b[k]).size() %2 ==0) {
                    string s = to_string(b[k]);
                    newB.push_back(stoll(s.substr(0, s.size()/2)));
                    newB.push_back(stoll(s.substr(s.size()/2)));
                }
                else {
                    newB.push_back(2024LL*b[k]);
                }
            }
            b = newB;
            for (lli val : b) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << b.size() << endl;
        cnt += b.size();
    }
    cout << cnt << endl;
    return 0;
}