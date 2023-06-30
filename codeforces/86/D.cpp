#include <bits/stdc++.h>
using namespace std;
const int b=450;
using ll=long long;
int main(){
    int n,t;
    cin>>n>>t;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i+1];
    
    int l,r;

    vector<vector<array<int,3> > > blocks((n+b-1)/b,vector<array<int,3> >());
    
    for(int i=0;i<t;i++){
        cin>>l>>r;
        blocks[l/b].push_back({r,l,i});

    }
    vector<ll> queryans(t);
    for(int i=0;i<blocks.size();i++){
        if(blocks[i].size()==0) continue;
        sort(blocks[i].begin(),blocks[i].end());
        ll total=0;

        vector<int> m(1000001);
        //ll total=0;
        for(int j=blocks[i][0][1];j<=blocks[i][0][0];j++){
            if(m[a[j]]==0){
                m[a[j]]=1;
                total+=a[j];
            }else{
                total-=(1ll*m[a[j]]*m[a[j]])*a[j];
                m[a[j]]++;
                total+=(1ll*m[a[j]]*m[a[j]])*a[j];
            }
            
        }
        queryans[blocks[i][0][2]]=total;
        for(int j=1;j<blocks[i].size();j++){
            if(blocks[i][j][1]>blocks[i][j-1][1]){
                for(int k=blocks[i][j-1][1];k<blocks[i][j][1];k++){
                    
                    
                    total-=(1ll*m[a[k]]*m[a[k]])*a[k];
                    m[a[k]]--;
                    total+=(1ll*m[a[k]]*m[a[k]])*a[k];
                    
                }
            }else{
                for(int k=blocks[i][j][1];k<blocks[i][j-1][1];k++){
                    if(m[a[k]]==0){
                        m[a[k]]=1;
                        total+=a[k];
                    }else{
                        total-=(1ll*m[a[k]]*m[a[k]])*a[k];
                        m[a[k]]++;
                        total+=(1ll*m[a[k]]*m[a[k]])*a[k];
                    }
                }
            }
            for(int k=blocks[i][j-1][0]+1;k<=blocks[i][j][0];k++){
                if(m[a[k]]==0){
                        m[a[k]]=1;
                        total+=a[k];
                    }else{
                        total-=(1ll*m[a[k]]*m[a[k]])*a[k];
                        m[a[k]]++;
                        total+=(1ll*m[a[k]]*m[a[k]])*a[k];
                    }
            
            }
            queryans[blocks[i][j][2]]=total;
            
        }
    }
    for(int i=0;i<queryans.size();i++){
        cout<<queryans[i]<<"\n";

    }
}
