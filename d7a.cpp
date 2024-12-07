#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;




int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 850;
    // int n_line = 9;
    lli sum = 0;
    for(int i = 0; i < n_line; i++) {
        string s; getline(cin, s);
        stringstream ss(s);
        string temp;
        vector<lli> numbers;
        lli firstInt;
        getline(ss, temp, ':');
        firstInt = stoll(temp);
        while (getline(ss, temp, ' ')) {
            if (!temp.empty()) {
            numbers.push_back(stoll(temp));
            }
        }
        bool found = false;
        int size = numbers.size()-1;
        
        for (int j = 0; j < (1 << size); ++j) {
            lli ans = numbers[0];
            for(int i = 0; i < size; i++) {
                if(j & (1 << i)) {
                    ans += numbers[i+1];
                } else {
                    ans*=numbers[i+1];
                }
                if(ans>firstInt) {
                    break;
                }
            }
            if(ans == firstInt) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "firstInt: " << firstInt << endl;
            sum += firstInt;
        }
    }
    cout << sum << endl;
    return 0;
}