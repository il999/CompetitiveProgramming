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
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<bool> off (34);
    int st=-1;
    vector<int> num;
    vector<pair<int,string> > bin;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1){
            if(st==-1)
                st=i;
            num.push_back(i);
            string str="";

            int tp = a[i];
            while(tp>0){
                if(tp%2==1) str+='1';
                else str+='0';
                tp/=2;
            }
            reverse(str.begin(),str.end());
           // cout<<str<<"\n";
            bin.push_back({i,str});
        }
    }
    if(st==-1){
        for(int i=0;i<n;i++){
            if(i%2==0) cout<<1<<" ";
            else cout<<2<<" ";

        }
        cout<<"\n";
        return;
    }
    vector<int> dis;
    vector<array<int,2> > diff;
    for(int i=0;i<bin.size()-1;i++){
        int stp=min(bin[i+1].second.size(),bin[i].second.size());
        for(int j=0;j<min(bin[i].second.size(),bin[i+1].second.size());j++){
            if(bin[i].second[j]!=bin[i+1].second[j]){
                stp=j;
                break;
            }
        }
      //  cout<<bin[i].second.size()-stp+bin[i+1].second.size()-stp<<"here \n";
        dis.push_back(bin[i].second.size()-stp+bin[i+1].second.size()-stp);
        diff.push_back({static_cast<long long>(1ll*bin[i].second.size()-stp),static_cast<long long>(bin[i+1].second.size()-stp)});
    }
    vector<int> ans(n);
    ans[st]=a[st];
    for(int i=st-1;i>=0;i--){
        if((i%2)==(st%2)){
            ans[i]=ans[i+1]/2;
        }else {
            ans[i] = ans[i + 1] * 2;
        }
    }
    int in=1;
    for(int in=1;in<num.size();in++){
        if(num[in]-num[in-1]<dis[in-1]||((num[in]-num[in-1])%2!=(dis[in-1]%2))){
          //  cout<<"here\n";
            cout<<-1<<"\n";
            return;
        }
        int posofnumber = bin[in-1].second.size();
      //  cout<<diff[in-1][0]<<" "<<diff[in-1][1]<<"\n";
        for(int i=num[in-1]+1;i<=num[in];i++){
            //cout<<i<<" h";
            if(diff[in-1][0]>0){
                diff[in-1][0]--;
                posofnumber--;
                ans[i]=ans[i-1]/2;
            }else if(diff[in-1][1]>0){
                posofnumber++;
                diff[in-1][1]--;
                ans[i]=ans[i-1]*2;
                if(bin[in].second[posofnumber-1]=='1'){
                    ans[i]++;
                }
            }else{
                //cout<<"bagga\n";
                if((i%2)!=(num[in]%2)){
                    posofnumber++;
                    ans[i]=ans[i-1]*2;
                }else{
                    ans[i]=ans[i-1]/2;
                    posofnumber--;
                }
            }
        }


    }
    for(int i=num[num.size()-1]+1;i<n;i++){
        if((i%2)==(num[num.size()-1]%2)){
            ans[i]=ans[i-1]/2;
        } else ans[i]=ans[i-1]*2;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}