#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    int sellers[m+1];
    sellers[m]=n;
    for(int i=0;i<m;i++){
        cin>>sellers[i];
    }
    int totalcookies=0;
    if(sellers[0]!=1) totalcookies++;
   // d--;
    for(int i=0;i<m;i++){
        if(i==0){
            totalcookies+=(sellers[0]-1-1)/d;
            totalcookies++;
        }else{
            totalcookies+=(sellers[i]-sellers[i-1]-1)/d;
            totalcookies++;
        }
    }
    totalcookies+=(n-sellers[m-1])/d;
    vector<array<int,2> > lost;
    array<int,2> tp;
    for(int i=0;i<m;i++){
        tp[0]=0;
        tp[1]=i;
        lost.push_back(tp);
    }
   // d--;
 //  cout<<totalcookies<<"\n";
    for(int i=0;i<m-1;i++){
        if(i==0){
            
            //lost[i][0]=(sellers[i+1]-1-1)/d-(sellers[i+1]-1-sellers[i])/d-(sellers[i]-1-1)/d-1;
            
            if(sellers[0]==1){
               lost[i][0]=0;
            }else{
                if((sellers[i+1]-1-1)/d==(sellers[i+1]-sellers[i]-1)/d+(sellers[i]-1-1)/d){
                 //   cout<<i<<"hehe\n";
                    lost[i][0]=-1;
                }
            }
        }else{
            if(((sellers[i+1]-sellers[i]-1)/d+(sellers[i]-sellers[i-1]-1)/d)==(sellers[i+1]-1-sellers[i-1])/d){

             lost[i][0]=-1;
           //  cout<<i<<"heheh\n";
            }
           // lost[i][0]=(sellers[i+1]-1-sellers[i-1])/d-(sellers[i+1]-1-sellers[i])/d-(sellers[i]-1-sellers[i-1])/d-1;
           // cout<<lost[i][0]<<"\n";
        }
    }
    //lost[m-1][0]=((sellers[m]-sellers[m-2])/d)-((sellers[m-1]-sellers[m-2]-1)/d+1-(sellers[m]-sellers[m-1])/d);
    if((n-sellers[m-2])/d==((n-sellers[m-1])/d+(sellers[m-1]-sellers[m-2]-1)/d)){
        lost[m-1][0]=-1;
       // cout<<"heeheh";
    }
    sort(lost.begin(),lost.end());
    for(int i=0;i<m-1;i++){
        //cout<<lost[i][1]<<" ooga ";
        if(lost[i][0]!=lost[i+1][0]){
            cout<<totalcookies-abs(lost[i][0])<<" "<<i+1<<"\n";
            return;
        }
    }
    cout<<totalcookies-abs(lost[0][0])<<" "<<m<<"\n";
}
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int t;
      cin>>t;
      while(t--)
        solve();
}