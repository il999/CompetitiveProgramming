#include <bits/stdc++.h>

using namespace std;

struct p{
    int b;
    int pos;
    char c;

    bool operator<(p other) const{
        if (other.b != b) return b < other.b;
        else return pos > other.pos;
    }
};

int main() {
    string str; cin >> str;
    vector<p> v;
    int cpos = 1;
    int b = 0;
    for (auto c : str){
        v.push_back({b, cpos, c});
        if (c == '(') b++;
        else b--;
        cpos++;
    }
    sort(v.begin(), v.end());
    string ans;
    for (auto x : v) ans += x.c;
    cout << ans << "\n";



    return 0;
}
