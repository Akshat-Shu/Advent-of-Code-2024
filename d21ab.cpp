#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct Visit {
    int x, y;
    string moves;
};

map<pair<pair<pair<int, int>, pair<int, int>>, int>, lli> memo;

lli smallestKeypad2(const string& moves, int n_robots);

lli keypad2BFS(int x, int y, int newX, int newY, int n_robots) {
    auto it = memo.find({{{x, y}, {newX, newY}}, n_robots});
    if (it != memo.end())
        return it->second;

    lli answer = INT64_MAX;
    queue<Visit> q;
    q.push({x, y, ""});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v.x == newX && v.y == newY) {
            lli rec = smallestKeypad2(v.moves + "A", n_robots-1);
            answer = min(answer, rec);
            continue;
        }
        if (v.x == 0 && v.y == 0)
            continue;
        else {
            if (v.x < newX) {
                q.push({ v.x + 1,v.y,v.moves + "v" });
            }
            else if (v.x > newX) {
                q.push({ v.x - 1, v.y, v.moves + "^" });
            }
            if (v.y < newY) {
                q.push({ v.x, v.y + 1, v.moves + ">" });
            }
            else if (v.y > newY) {
                q.push({ v.x, v.y - 1, v.moves + "<" });
            }
        }
    }
    memo[{{{x, y}, {newX, newY}}, n_robots}] = answer;
    return answer;
}

lli smallestKeypad2(const string& moves, int n_robots) {
    if (n_robots == 1)
        return moves.length();

    lli result = 0;
    map<char, pair<int, int>> second = {
        {'A', {0, 2}},
        {'<', {1, 0}},
        {'^', {0, 1}},
        {'>', {1, 2}},
        {'v', {1, 1}},
    };

    int x = 0;
    int y = 2;

    for (int i = 0; i < moves.length(); i++) {
        result += keypad2BFS(x, y, second[moves[i]].first, second[moves[i]].second, n_robots);
        x = second[moves[i]].first;
        y = second[moves[i]].second;
    }
    return result;
}

lli keypad1BFS(int x, int y, int newX, int newY, int n_robots) {
    lli answer = INT64_MAX;

    queue<Visit> q;
    q.push({x, y, ""});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v.x == newX && v.y == newY) {
            lli rec = smallestKeypad2(v.moves + "A", n_robots);
            answer = min(answer, rec);
            continue;
        }
        if (v.x == 3 && v.y == 0)
            continue;
        else {
            if (v.x < newX) {
                q.push({v.x + 1,v.y,v.moves + "v"});
            }
            else if (v.x > newX) {                
                q.push({v.x - 1, v.y, v.moves + "^"});
            }
            if (v.y < newY) {
                q.push({v.x, v.y + 1, v.moves + ">"});
            }
            else if (v.y > newY) {
                q.push({v.x, v.y - 1, v.moves + "<"});
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int n_line = 5, n_robots = 26;
    lli sum = 0;
    for(int i = 0; i < n_line; i++) {
        string s;
        cin >> s;

        lli result = 0;
        map<char, pair<int, int>> first = {
            {'7', {0, 0}},
            {'8', {0, 1}},
            {'9', {0, 2}},
            {'4', {1, 0}},
            {'5', {1, 1}},
            {'6', {1, 2}},
            {'1', {2, 0}},
            {'2', {2, 1}},
            {'3', {2, 2}},
            {'0', {3, 1}},
            {'A', {3, 0}},
        };

        int x = 3;
        int y = 2;

        for (int i = 0; i < s.length(); i++) {
            result += keypad1BFS(x, y, first[s[i]].first, first[s[i]].second, n_robots);
            x = first[s[i]].first;
            y = first[s[i]].second;
        }
        lli num = stoll(s.substr(0, 3));
        sum += result * num;
    }
    cout << sum << endl;
}