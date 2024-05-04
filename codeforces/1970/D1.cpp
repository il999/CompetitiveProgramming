#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    cout<<"XOX\n";
    if(n>=2)
        cout<<"XOOO\n";
    if(n==3)
        cout<<"XXOOOOX\n";
    cout.flush();
    int q;
    cin>>q;
    while(q--){
        int p;
        cin>>p;
        if(p==14) cout<<"1 1\n";
        if(p==23) cout<<"2 2\n";
        if(p==68) cout<<"3 3\n";
        if(p==21) cout<<"1 2\n";
        if(p==20) cout<<"2 1\n";
        if(p==41) cout<<"1 3\n";
        if(p==40) cout<<"3 1\n";
        if(p==45) cout<<"2 3\n";
        if(p==44) cout<<"3 2\n";
        cout.flush();
    }
}
int main() {
    solve();
}
