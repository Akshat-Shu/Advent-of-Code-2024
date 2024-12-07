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
        lli pow3 = 1;
        for(int i = 0; i < size; i++) {
            pow3 *= 3;
        }
        for (lli jj = 0; jj < pow3; ++jj) {
            lli ans = numbers[0];
            lli j = jj;
            for(int i = 0; i < size; i++) {
                int state = j%3;
                j/=3;
                if(state==0) {
                    ans += numbers[i+1];
                } else if(state==1) {
                    ans*=numbers[i+1];
                } else {
                    ans = stoll(to_string(ans) + to_string(numbers[i+1]));
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
            sum += firstInt;
        }
    }
    cout << sum << endl;
    return 0;
}