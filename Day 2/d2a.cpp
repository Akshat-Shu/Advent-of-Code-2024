#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_rep = 6, count = 0;
    vector<int> rep(30);
    for(int i = 0; i < n_rep; i++) {
        int n_lev = 0;
        string line;
        getline(cin, line);
        istringstream iss(line);
        int val;
        while(iss >> val) {
            rep[n_lev++] = val;
        }
        bool possible_increase = true;
        for(int j = 1; j < n_lev; j++) {
            if(rep[j]-rep[j-1]>=1 && rep[j]-rep[j-1]<=3) continue;
            else {
                possible_increase = false;
                break;
            }
        }
        bool possible_decrease = true;
        for(int j = 1; j < n_lev; j++) {
            if(rep[j-1]-rep[j]>=1 && rep[j-1]-rep[j]<=3) continue;
            else {
                possible_decrease = false;
                break;
            }
        }
        if(possible_increase || possible_decrease) count++;
    }
    cout << count << endl;
    return 0;
}