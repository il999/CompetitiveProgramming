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
int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;   
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);    
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<ll,2> > > v(n+1,vector<array<ll,2> >() );
    ll a;
    ll b;
    ll c;
    array<ll,2> tp;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        tp[1]=b;
        tp[0]=c;
        v[a].push_back(tp);
        tp[1]=a;
        v[b].push_back(tp);

    }
    string s="";
    for(int i=0;i<n-1;i++)s+='1';
    s+='0';
    priority_queue<array<ll,2>, vector<array<ll,2> >, greater<array<ll,2> > > pq;
    ll t=0;
    vector<ll> constraint(n+1,1e18+1);
    vector<bool> ingame(n+1,1);
    ingame[n]=0;
    for(int i=0;i<v[n].size();i++){
        //if(s[0]=='0') break;
        //constraint[v[n][i][1]]=v[n][i][0];
        if(v[n][i][0]==0){
            int u=v[n][i][1];
            for(int j=0;j<v[u].size();j++){
                if(v[u][j][0]<constraint[v[u][j][1]]){
                    if(constraint[v[u][j][1]]==1e18+1||v[u][j][0]==0){
                        v[n].push_back(v[u][j]);
                    }
                    constraint[v[u][j][1]]=v[u][j][0];
                    pq.push(v[u][j]);
                }
            }
            ingame[u]=0;
            s[u-1]='0';
        }else{
            pq.push(v[n][i]);
        }
        constraint[v[n][i][1]]=min(v[n][i][0],constraint[v[n][i][1]]);
        

    }
    vector<string> ans1;
    vector<ll> ans2;
    
    while(!pq.empty()){
        if(s[0]=='0') break;
      //  cout<<"ingam\n";
        vector<ll > get_ridof;
        ll cur=0;
        bool found=0;
        while(!pq.empty()&&(cur==pq.top()[0]||!found)){
            if(ingame[pq.top()[1]]){
                ingame[pq.top()[1]]=0;
                get_ridof.push_back(pq.top()[1]);
                found=1;
                cur=pq.top()[0];
               
            }
            
            pq.pop();
        }
        
    
        //tp[0]=s;
        //tp[1]=cur-t;
        if(cur!=0){
            ans1.push_back(s);
            ans2.push_back(cur-t);
        }
        //cout<<s<<" "<<cur-t<<"\n";
        t+=(cur-t);
        for(int i=0;i<get_ridof.size();i++){
            int u=get_ridof[i];
            for(int j=0;j<v[u].size();j++){
                
                if(ingame[v[u][j][1]]&&constraint[v[u][j][1]]>t+v[u][j][0]){
                    constraint[v[u][j][1]]=t+v[u][j][0];
                    if(v[u][j][0]==0){
                        get_ridof.push_back(v[u][j][1]);
                        ingame[v[u][j][1]]=0;
                    }else{
                        v[u][j][0]+=t;
                        pq.push(v[u][j]);
                    }
                    
                }
            }
            s[u-1]='0';
        }
        if(s[0]=='0') break;
    }
    int tem=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            tem++;
        }
    }
    if(s[0]=='0'||tem==0){
        //cout<<ans1.size()<<" ";
        ll tot=0;
        for(int i=0;i<ans2.size();i++){
            tot+=ans2[i];

        }
        cout<<tot<<" "<<ans1.size()<<"\n";
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i]<<" "<<ans2[i]<<"\n";
        }

    }else{
        cout<<"inf\n";
    }

   // cout<<t<<"\n";
  //  priority_queue<array<ll,2>,
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    
        solve();
}