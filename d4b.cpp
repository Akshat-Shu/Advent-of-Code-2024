#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 10, n_char = 10;
    vector<vector<char>> s(n_line, vector<char>(n_char, '.'));
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_char; j++) {
            cin >> s[i][j];
        }
    }
    int count = 0;
    vector<vector<int>> found(n_line, vector<int>(n_char, 0));
    for(int i = 0; i < n_line; i++) {
        for(int j = 0; j < n_char; j++) {
            if(s[i][j] == '.') break;
            bool possible = false;
            // if(s[i][j] == 'X') {
            //     count += ((j+3<n_char && s[i][j+1] == 'M' && s[i][j+2] == 'A' && s[i][j+3] == 'S')
            //     + (j-3>=0 && s[i][j-1] == 'M' && s[i][j-2] == 'A' && s[i][j-3] == 'S')
            //     + (i+3<n_line && s[i+1][j] == 'M' && s[i+2][j] == 'A' && s[i+3][j] == 'S')
            //     + (i-3>=0 && s[i-1][j] == 'M' && s[i-2][j] == 'A' && s[i-3][j] == 'S')
            //     + (i-3>=0 && j-3>=0 && s[i-1][j-1] == 'M' && s[i-2][j-2] == 'A' && s[i-3][j-3] == 'S')
            //     + (i-3>=0 && j+3<n_char && s[i-1][j+1] == 'M' && s[i-2][j+2] == 'A' && s[i-3][j+3] == 'S')
            //     + (i+3<n_line && j-3>=0 && s[i+1][j-1] == 'M' && s[i+2][j-2] == 'A' && s[i+3][j-3] == 'S')
            //     + (i+3<n_line && j+3<n_char && s[i+1][j+1] == 'M' && s[i+2][j+2] == 'A' && s[i+3][j+3] == 'S'));
            // }

            if(s[i][j] == 'A') {
                if(
                    ((i-1>=0&&j+1<n_char&&s[i-1][j+1]=='M') && (i+1<n_line&&j-1>=0&&s[i+1][j-1]=='S') ||
                    (i-1>=0&&j+1<n_char&&s[i-1][j+1] == 'S') && (i+1<n_line&&j-1>=0&&s[i+1][j-1] == 'M')) && 
                    ((i-1>=0&&j-1>=0&&s[i-1][j-1]=='M') && (i+1<n_line&&j+1<n_char&&s[i+1][j+1]=='S') ||
                    (i-1>=0&&j-1>=0&&s[i-1][j-1] == 'S') && (i+1<n_line&&j+1<n_char&&s[i+1][j+1] == 'M'))
                ) {
                    count++;
                }
            }
        }
    }
    // for(int i = 0; i < n_line; i++) {
    //     for(int j = 0; j < n_char; j++) {
    //         if(found[i][j]) cout << '*';
    //         else cout << '.';
    //     }
    //     cout << endl;
    // }
    cout << count << endl;
    return 0;
}