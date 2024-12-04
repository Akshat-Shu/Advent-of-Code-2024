#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

bool is_number(const string& s) {
    return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 1;
    string bigS; string s;
    for(int i = 0; i < n_line; i++) {
        getline(cin, s);    
        bigS += s;
    }
    cout << bigS << endl;
    lli ans = 0; bool enabled = true;
    int n = bigS.size();
    for(int i = 0; i+3 < n; i++) {
        bool valid = false;
        if(i+3<n && bigS[i] == 'd' && bigS[i+1] == 'o' && bigS[i+2] == '(' && bigS[i+3] == ')') {
            enabled = true;
        } else if(i+6<n && bigS[i] == 'd' && bigS[i+1] == 'o' && bigS[i+2] == 'n' && bigS[i+3] == '\'' && bigS[i+4] == 't' && bigS[i+5] == '(' && bigS[i+6] == ')') {
            enabled = false;
        }
        if(bigS[i] == 'm' && bigS[i+1] == 'u' && bigS[i+2] == 'l' && bigS[i+3] == '(' && enabled) {
            bool ends = false, seenComma = false;
            string s1, s2;
            int j;
            for(j = i+4; j < n; j++) {
                if(bigS[j] == ')') {
                    ends = true;
                    break;
                } else if(bigS[j] == ',') {
                    seenComma = true;
                } else if(seenComma) {
                    s2 += bigS[j];
                } else {
                    s1 += bigS[j];
                }
            }
            if(!ends || !seenComma) {
                continue;
            }
            if(is_number(s1) && is_number(s2)) {
                lli a = stoll(s1), b = stoll(s2);
                ans += a*b;
            } else continue;
        }
    }
    cout << ans << endl;
    return 0;
}