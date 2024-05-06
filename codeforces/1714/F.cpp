#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
const int MOD=998244353;
#define int long long
void giveitago(int d12, int d23, int d13, string s, int n,vector<array<int,2> >& tree){
    if(tree.size()==n-1) return;
    if(d23+d13-d12>=0&&(d23+d13-d12)%2==0){
        if((d23+d13-d12)==0){
        //    cout<<"her\n";
            vector<int> order(n);
            order[0]=s[0]-'0';
            order[d13] = s[2]-'0';
            order[d12] = s[1]-'0';
            int noderightnow =4;
            for(int i=0;i<n;i++){
                if(order[i]==0){
                    order[i]=noderightnow;
                    noderightnow++;
                }
            }
            for(int i=1;i<n;i++){
                tree.push_back({order[i],order[i-1]});
            }
            return;
        }
        int last =s[0]-'0';
        int noderightnow=4;
        while(noderightnow-3<=d12-1){
            tree.push_back({last,noderightnow});
            last = noderightnow;
            noderightnow++;
        }
        tree.push_back({last,s[1]-'0'});
        int x = d13 - (d23+d13-d12)/2;
        last=s[0]-'0';
        if(x<0) {
            tree.clear();
            return;
        }
        if(x!=0){
            last = 3+x;
        }
        if(last>=noderightnow){
            //cout<<" here\n";
            tree.clear();
            return;
        }
        int cur=0;
        while(cur<(d23+d13-d12)/2-1){
            cur++;
            tree.push_back({last,noderightnow});
            last=noderightnow;
            noderightnow++;
        }
        tree.push_back({last,s[2]-'0'});
        while(noderightnow<=n){
            tree.push_back({s[0]-'0',noderightnow});
            noderightnow++;
        }

    }
}
void solve() {
    int n, d12,d13,d23;
    cin>>n>>d12>>d23>>d13;
    vector<array<int,2> > tree;
    giveitago(d12,d23,d13,"123",n,tree);
    giveitago(d23,d12,d13,"321",n,tree);
    giveitago(d13,d23,d12,"132",n,tree);
    if(tree.size()!=n-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(array<int,2> edge: tree){
        cout<<edge[0]<< " "<<edge[1]<<"\n";
    }



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}