#include <iostream> 
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
using ll= long long;
using namespace std;

const int INF=1e9+7;
int n;
//vector<int> a;

 
int main()
{
   // cin.tie(0);
   cin.tie(0); ios_base::sync_with_stdio(0);
    int q;
    cin>>n>>q;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> start(n+1);
    vector<int> end(n+1);
    vector<int> totpre(n+1);
    vector<bool> add(n+1);
    vector<bool> started(n+2);
    vector<bool> ended(n+1);
    for(int i=0;i<n;i++){
        if(i<n-2&&a[i]>=a[i+1]&&a[i+1]>=a[i+2]){
            add[i]=1;
            add[i+1]=1;
            add[i+2]=1;
        }
        if(add[i]&&(i==n-1||a[i]<a[i+1])){
            end[i+1]++;
            ended[i+1]=1;
        }
        if(add[i]&&(i==0||a[i]>a[i-1])){
            start[i+1]++;
            started[i+1]=1;
        }
        if(add[i])totpre[i+1]++;
    }
    for(int i=1;i<=n;i++){
        
        start[i]+=start[i-1];
        end[i]+=end[i-1];
        totpre[i]+=totpre[i-1];
        //cout<<start[i]<<" ";
    }
   // cout<<" aa\n";

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<"1\n";
            continue;
        }
        int reduce=0;
        if(!started[r]&&!ended[r]&&add[r-1]){
            reduce++;
        }
         if(!ended[l]&&!started[l]&&add[l-1]){
            reduce++;
        }
        //cout<<totpre[r]-totpre[l-1]<<" "<<start[r]-start[l-1]<<" "<<end[r]-end[l-1]<<"\n";
        cout<<r-l+1-(totpre[r]-totpre[l-1]-(start[r]-start[l-1])-(end[r]-end[l-1])-reduce)<<"\n";
    }
   
  

    //update(0,1,n,1,1,0);
    
    


}