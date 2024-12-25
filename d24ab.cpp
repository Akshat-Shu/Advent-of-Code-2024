#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

class command {
    public:
    int method;
    string first, second, res;
};

string intToString(int x) {
    if(x<10) return "0"+to_string(x);
    return to_string(x);
}

int stringToInt(string s) {
    if(s == "OR") return 0;
    if(s == "AND") return 1;
    if(s=="XOR") return 2;
}

int getVal(string s, map<string, int> &vars, map<string, command> &wayToGet) {
    if(vars.find(s) != vars.end()) return vars[s];
    command c = wayToGet[s];
    int value = -1;
    if(c.method == 0) value = getVal(c.first, vars, wayToGet) | getVal(c.second, vars, wayToGet);
    if(c.method == 1) value = getVal(c.first, vars, wayToGet) & getVal(c.second, vars, wayToGet);
    if(c.method == 2) value = getVal(c.first, vars, wayToGet) ^ getVal(c.second, vars, wayToGet);
    vars[s] = value;
    return value;
}

bool test(map<string, command> &wayToGet, int bit) {
    for(int i = 0; i <= 10; i++) {
        if(!genXYTest(wayToGet, bit)) return false;
    }
    return true;
}

bool genXYTest(map<string, command> &waysToGet, int bit) {
    map<string, int> vars;
    lli x = 0, y = 0;
    for(int i = 0; i < 45; i++) {
        lli xi = rand()%(1LL<<bit), yi = rand()%(1LL<<bit);
        vars["x"+intToString(i)] = xi;
        x += (xi<<i);
        vars["y"+intToString(i)] = yi;
        y += (yi<<i);  
    }
    lli res = x+y;
    for(int i = 0; i <= bit; i++) {
        if(getVal("z"+intToString(i), vars, waysToGet) != ((res>>i)&1)) return false;
    }
    return true;
}

pair<string, string> swap(map<string, command> &waysToGet, int bit) {
    vector<string> keys;
    for(auto p: waysToGet) keys.push_back(p.first);
    for(int i = 0; i < waysToGet.size(); i++) {
        for(int j = i+1; j < waysToGet.size(); j++) {
            swap(waysToGet[keys[i]], waysToGet[keys[j]]);
            if(test(waysToGet, bit)) return {keys[i], keys[j]};
            swap(waysToGet[keys[i]], waysToGet[keys[j]]);
        }
    }
    return {"", ""};
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_var = 90, n_cmd = 222, n_z=45;
    // int n_var = 10, n_cmd = 36, n_z = 12;
    map<string, int> vars;
    for(int i = 0; i < n_var; i++) {
        string s; int x; cin >> s >> x;
        vars[s.substr(0, 3)] = x;
    }
    string s; getline(cin, s);
    srand(time(NULL));
    vector<command> cmds;
    vector<string> z;
    map<string, command> wayToGet;
    for(int i = 0; i < n_cmd; i++) {
        cout << "i: " << i << endl;
        string first, method, second, _, res;
        cin >> first >> method >> second >> _ >> res;
        command c;
        cout << first << " " << method << " " << second << " " << res << endl;
        c.method = stringToInt(method);
        c.first = first;
        c.second = second;
        c.res = res;
        if(res[0] == 'z') z.push_back(res);
        wayToGet[res] = c;
        cmds.push_back(c);
    }
    

    cout << "ok\n";
    string sing = "";
    vector<string> swaps;
    sort(z.begin(), z.end());
    for(string zi: z) {
        int bit = stoi(zi.substr(1));
        if(test(wayToGet, bit)) continue;
        pair<string, string> swapp = swap(wayToGet, bit+1);
        if(!swapp.first.empty()) {
            swaps.push_back(swapp.first); swaps.push_back(swapp.second);
        }
        if(swaps.size() >= 8) break;
    }
    sort(swaps.begin(), swaps.end());
    for(string s: swaps) cout << s << ",";
    cout << endl;
    
    return 0;
}