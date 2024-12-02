#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_rep = 1000, count = 0;
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
        bool possible_increase = false;
        for(int i = 0; i < n_lev; i++) {
            bool possible = true;
            int prev = i==0?rep[1]:rep[0];
            for(int j = (i==0?2:1); j < n_lev; j++) {
                if(j==i) continue;
                if(rep[j]-prev>=1 && rep[j]-prev<=3) prev = rep[j];
                else {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                possible_increase = true;
                break;
            }
        }
        bool possible_decrease = false;
        for(int i = 0; i < n_lev; i++) {
            bool possible = true;
            int prev = i==0?rep[1]:rep[0];
            for(int j = (i==0?2:1); j < n_lev; j++) {
                if(j==i) continue;
                if(prev-rep[j]>=1 && prev-rep[j]<=3) prev = rep[j];
                else {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                possible_decrease = true;
                break;
            }
        }
        if(possible_increase || possible_decrease) count++;
        
    }
    cout << count << endl;
    return 0;
}