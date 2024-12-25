#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_robot = 500, n_step = 100;
    int n_line = 103, n_col = 101;
    vector<pair<lli, lli>> pos(n_robot, {0, 0});    
    vector<pair<lli, lli>> vel(n_robot, {0, 0});
    for(int i = 0; i < n_robot; i++) {
        string s;
        getline(cin, s);
        string input = s.substr(2);
        int comma_pos = input.find(',');
        lli px = stoll(input.substr(0, comma_pos));
        int space_pos = input.find(' ');
        lli py = stoll(input.substr(comma_pos+1, space_pos));
        int equal_pos = input.find('=');
        input = input.substr(equal_pos+1);
        comma_pos = input.find(',');
        lli vx = stoll(input.substr(0, comma_pos));
        lli vy = stoll(input.substr(comma_pos+1));
        pos[i] = {px, py};
        vel[i] = {vx, vy};
        cout << px << " " << py << " " << vx << " " << vy << endl;
    }
    vector<vector<lli>> grid(n_line, vector<lli>(n_col, 0));

    for(int i = 0; i < n_robot; i++) {
        lli newx = (pos[i].first + n_step*vel[i].first + 10000*n_col)%n_col;
        lli newy = (pos[i].second + n_step*vel[i].second + 10000*n_line)%n_line;
        grid[newy][newx]++;
    }

    vector<lli> ans(4, 0);
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_col; j++) {
            if(j<n_col/2 && i < n_line/2) ans[0] += grid[i][j];
            else if(j>n_col/2 && i<n_line/2) ans[1] += grid[i][j];
            else if(j<n_col/2 && i>n_line/2) ans[2] += grid[i][j];
            else if(j>n_col/2 && i>n_line/2) ans[3] += grid[i][j];
        }
    }

    lli fin = 1;
    for(int x: ans) {
        fin *= x;
    }
    cout << fin << endl;

    return 0;
}