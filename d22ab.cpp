#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli mix(lli a, lli b) {
    return a^b;
}
 
lli prune(lli a) {
    return a%16777216;
}
 
lli nextSecret(lli a) {
    lli first = prune(mix(64*a, a));
    lli second = prune(mix(first, first/32));
    return prune(mix(2048*second, second));
}

lli finalSecret(lli a, int n_sim) {
    lli curr = a;
    for(int i = 0; i < n_sim; i++) {
        curr = nextSecret(curr);
        int dig = curr%10;
        cout << (dig<0?"": " ") << dig << " ";
    }
    cout << endl;
    return curr;
}

vector<lli> finalAnswer(lli a, int n_sim) {
    vector<lli> ans;
    lli curr = a;
    for(int i = 0; i < n_sim; i++) {
        lli temp = curr;
        curr = nextSecret(curr);
        int dig = curr%10;
        ans.push_back(dig);
    }
    return ans;
}

lli findSubArray(vector<lli> &changes, vector<lli> sub, vector<lli> &ans) {
    int n = changes.size(), m = sub.size();
    for(int i = 0; i+m <= n; i++) {
        bool found = true;
        for(int j = 0; j < m; j++) {
            if(changes[i+j] != sub[j]) {
                found = false;
                break;
            }
        }
        if(found) return ans[i+m-1];
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n_line = 1767, n_sim = 2000;
    
    vector<vector<lli>> changes(n_line);
    vector<vector<lli>> answers(n_line);
    set<vector<lli>> fourPairs;
    for(int i = 0; i < n_line; i++) {
        int x; cin >> x;
        vector<lli> ans = finalAnswer(x, n_sim);
        vector<lli> change = {-200};
        for(int j = 1; j < n_sim; j++) {
            change.push_back(ans[j] - ans[j-1]);
        }
        for(int i = 0; i +3<change.size(); i++) {
            fourPairs.insert({change[i], change[i+1], change[i+2], change[i+3]});
        }
        answers[i] = ans;
        changes[i] = change;
    }
    lli fin = 0;
    vector<lli> config = {};
    for(auto p: fourPairs) {
        lli i = p[0], j = p[1], k = p[2], l = p[3];
        lli sum = 0;
        for(int m = 0; m < n_line; m++) {
            lli ans = findSubArray(changes[m], {i, j, k, l}, answers[m]);
            if(i==-2 && j ==1 &&k==-1&&l==3) {
                cout << m << " " << ans << endl;
            }
            // cout << "ok" << endl;
            if(ans != -1) {
                sum += ans;
            }
        }
        if(sum > fin) {
            fin = sum;
            cout << "fin: " << fin << endl;
            config = {i, j, k, l};
        }
    }

    cout << fin << endl;
    for(auto c: config) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}