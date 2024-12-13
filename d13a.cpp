#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 1280;
    vector<vector<pair<int, int>>> moves(n_line/4, vector<pair<int, int>>(2, {0, 0})); 
    vector<pair<int, int>> prize (n_line/4, {0, 0});
    for(int i = 0; i < n_line; i++) {
        if(i%4 == 0 || i%4==1) {
            string s;
            getline(cin, s);
            string input = s.substr(12);
            int comma_pos = input.find(',');
            int num1 = stoi(input.substr(0, comma_pos));
            int plus_pos = input.find('+');
            int num2 = stoi(input.substr(plus_pos+1));
            moves[i/4][i%4] = {num1, num2};
        } else if(i%4 == 2) {
            string s;
            getline(cin, s);
            string input = s.substr(9);
            int comma_pos = input.find(',');
            int num1 = stoi(input.substr(0, comma_pos));
            int equal_pos = input.find('=');
            int num2 = stoi(input.substr(equal_pos+1));
            prize[i/4] = {num1, num2};
        } else {
            string s;
            getline(cin, s);
        }
    }
    int ans = 0;
    for(int i = 0; i < moves.size(); i++) {
        vector<pair<int, int>> move = moves[i];
        pair<int, int> pr = prize[i];
        int possible = true;
        int denom = move[1].first*move[0].second - move[1].second*move[0].first;
        int num = pr.first*move[0].second - pr.second*move[0].first;
        if(denom == 0 || num%denom != 0) {
            possible = false;
            continue;
        }
        int b = num/denom;
        denom = move[0].first*move[1].second - move[0].second*move[1].first;
        num = pr.first*move[1].second - pr.second*move[1].first;
        if(denom == 0 || num%denom != 0) {
            possible = false;
            continue;
        }
        int a = num/denom;
        // if(a>100||b>100) possible = false;
        // move[0].first *a + move[1].first *b = pr.first
        // move[0].second *a + move[1].second *b = pr.second
        if(possible) {
            ans += (3*a+b);
        }

    }
    cout << ans << endl;    
    return 0;
}