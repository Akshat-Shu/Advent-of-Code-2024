#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    lli A = 51342988, B = 0, C=0;
    function<lli(lli)> combo = [&](lli x) {
        if(x<=3) return x;
        if(x==4) return A;
        if(x==5) return B;
        if(x==6) return C;
        cout << "bro" << endl;
        return -1LL;
        
    };
    vector<lli> p = {2,4,1,3,7,5,4,0,1,3,0,3,5,5,3,0};
    for(int i = 0; i < p.size(); i+=2) {
        lli val = p[i+1], op = p[i];
        if(op == 0) {
            A=A/(1LL<<combo(val));
        } else if(op==1) {
            B=B^val;
        } else if(op==2) {
            B=combo(val)%8;
        } else if(op==3) {
            if(A!=0) {
                i=val-2;
            }
        } else if(op==4) {
            B=B^C;
        } else if(op==5) {
            cout << combo(val)%8 << ",";
        } else if(op==6) {
            B=A/(1LL<<combo(val));
        } else if(op==7) {
            C=A/(1LL<<combo(val));
        }
    }
    
    return 0;
}