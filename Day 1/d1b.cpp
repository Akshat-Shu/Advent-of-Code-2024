#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n = 6;
    vector<lli> a(n);
    map<lli, lli> freq;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; lli x; cin >> x;
        freq[x]++;
    }
    lli ans = 0;
    for(int i = 0; i < n; i++) {
        ans += freq[a[i]]*a[i]*1LL;
    }
    cout << ans << endl;
    return 0;
}