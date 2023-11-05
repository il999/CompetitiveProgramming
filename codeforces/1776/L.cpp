#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <map>
#include <cassert>
#include <numeric>

using namespace std;

#define MOD 1000000007

int N, Q, a, b;
string str;

int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    cin >> str;
    
    pair<int,int> cnt(0, 0);
    for (char ch : str) {
        if (ch == '+')
            cnt.first++;
        else
            cnt.second++;
    }
    
    if (cnt.first > cnt.second)
        swap(cnt.first, cnt.second);
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a > b)
            swap(a, b);
        int ab = gcd(a, b);
        a /= ab;
        b /= ab;
        
        bool flag = false;
        if (cnt.first == cnt.second || a == b)
            flag = cnt.first == cnt.second;
        else if ((cnt.second - cnt.first) % (b - a) == 0 && (cnt.second - cnt.first) / (b - a) <= min(cnt.first/a, cnt.second/b))
            flag = true;
        
        cout << (flag ? "YES" : "NO") << endl;
        
    }
}
