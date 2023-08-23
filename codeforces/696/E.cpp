#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll> > v(200001,vector<ll>());
vector<vector<array<ll,2> > > girls(200001,vector<array<ll,2> >());
int n;
vector<array<ll,4> > seg (2000001,array<ll,4>());
vector<ll> flag(2000001,0);
vector<array<ll,3> > li;
ll inf=1e16;
void build(int v, int tl, int tr){
    if(tl==tr){
        seg[v][0]=li[tl][0];
      //  cout<<seg[v][0]<<"\n";
        seg[v][1]=li[tl][1];
        seg[v][2]=li[tl][2];
        seg[v][3]=tl;
        return;
    }
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    seg[v]=min(seg[v*2],seg[v*2+1]);
}
void push_flag(int v, int tl,int tr){
    //cout<<"We here for sure\n";
    if(flag[v]==0) return;
    int tm=(tl+tr)/2;
    ll x=flag[v];
    seg[v*2][0]=min(seg[v*2][0]+x,inf);
    flag[v*2]+=x;
    seg[v*2+1][0]=min(seg[v*2+1][0]+x,inf);
    flag[v*2+1]+=x;
    flag[v]=0;
    
}
array<ll,4> query(int v, int tl, int tr, int l ,int r){
    if(l>r) return {inf,inf,inf,inf};
    if(tl==l&&tr==r){
        return seg[v];
    }
    int tm=(tl+tr)/2;
    push_flag(v,tl,tr);
    return min(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}
void update(int v, int tl, int tr,int l, int r,ll x){
    if(l>r) return;
    if(tl==l&&tr==r){
        push_flag(v,tl,tr);
       // if(x!=inf)cout<<"increased\n";
        seg[v][0]=min(inf,seg[v][0]+x);
        flag[v]=x;
        return;
    }
 //   cout<<seg[v][0]<<" "<<v<<" "<<l<<" "<<r<<"\n";
    push_flag(v,tl,tr);
    int tm=(tl+tr)/2;
    update(v*2,tl,tm,l,min(r,tm),x);
    update(v*2+1,tm+1,tr,max(l,tm+1),r,x);
    seg[v]=min(seg[v*2],seg[v*2+1]);
}
vector<ll> heavy(200001);
vector<ll> subc(200001,1);
vector<ll> depth(200001,0);
vector<ll> parent(200001,-1);
void dfsinit(int u,int last){

    for(int x: v[u]){
        if(x!=last){
            depth[x]=depth[u]+1;
            parent[x]=u;
            dfsinit(x,u);
            subc[u]+=subc[x];
        }
    }

}
ll heavycount=1;
//keeps track of where in seg tree it is
vector<array<ll,2> > position(200001,array<ll,2> ());
vector<ll> headcomponent(200001);
void append( int u){
   // cout<<"here"<<u<<"\n";
    position[u][0]=li.size();
    for(int i=0;i<girls[u].size();i++){
        li.push_back({girls[u][i][0],u,girls[u][i][1]});
    }
    position[u][1]=li.size()-1;
}
void heavydfs(int u,int last){

    ll ma=-1;
    ll in=-1;
    for(int x: v[u]){
        if(x!=last){
            if(subc[x]>ma){
                ma=subc[x];
                in=x;
            }
        }
    }
    if(in==-1) {
        if(heavy[u]==0){
            heavy[u]=heavycount;
            headcomponent[heavy[u]]=u;
            append(u);
            heavycount++;
            return;
        }
        return;
    }
    swap(ma,in);
    if(heavy[u]==0){
        heavy[u]=heavycount;
        heavy[ma]=heavycount;
        headcomponent[heavycount]=u;
        append(u);
        append(ma);
        //position[ma] and such should be the last of each;
        //where has heavycomponenet should be vertex the top of such
        heavycount++;
        heavydfs(ma,u);

    }else{
        heavy[ma]=heavy[u];
        append(ma);
        heavydfs(ma,u);
    }
    for(int x: v[u]){
        if(x!=ma&&x!=last){
            //append(x);
            heavydfs(x,u);
        }
    }
}
void solve(){
     ios_base::sync_with_stdio(0); cin.tie(0);
    cin>> n;
    ll m,q;
    cin>>m>>q;
    ll a,b;
    for(int i=1; i<n ;i++){
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>a;
        a--;
        girls[a].push_back({i+1,i+1});
    }
    for(int i=0;i<n;i++){
        subc[i]=girls[i].size();
    }
    dfsinit(0,-1);
    
    heavydfs(0,-1);
    //cout<<"here\n";
    for(int i=0;i<n;i++){
      //  cout<<heavy[i]<<"\n";
    }
   // cout<<tp[0]<<" "<<tp[1]<<"\n";
    build(1,0,li.size()-1);
    while(q--){
        int t;
        cin>>t;
        ll k;
        if(t==1){
            cin>>a>>b>>k;
            a--;b--;
            vector<array<ll,2> > queries;
            while(heavy[a]!=heavy[b]){
                if(depth[headcomponent[heavy[a]]]<depth[headcomponent[heavy[b]]]){
                    swap(a,b);
                }
                queries.push_back({position[headcomponent[heavy[a]]][0],position[a][1]});
             //   cout<<position[headcomponent[heavy[a]]][0]<<" " <<position[a][1]<<" thing\n";
                a=parent[headcomponent[heavy[a]]];
                
               // cout<<heavy[a]<<" "<<a<<"\n";
            }
        
            if(depth[a]>depth[b])swap(a,b);
           // cout<<a+1<<" "<<b+1<<" "<<position[a][0]<<" "<<position[b][1]<<" this thing\n";
            queries.push_back({position[a][0],position[b][1]});
            vector<ll> toprint;
            while(k--){
                array<ll,4> qans={inf,inf,inf,inf};
                for(int j=0;j<queries.size();j++){
                    if(queries[j][0]<=queries[j][1]){
                      //  cout<<queries[j][0]<<" "<<queries[j][1]<<" these be the queries\n";
                        qans=min(qans,query(1,0,li.size()-1,queries[j][0],queries[j][1]));
                    }

                }
                //cout<<"we be her no cap";
                
                if(qans[0]!=inf){
                    toprint.push_back(qans[2]);
                   // toprint.push_back(qans[0]);
                  //  cout<<qans[2]<<" literal ans ";
                    update(1,0,li.size()-1,qans[3],qans[3],inf);
                }else break;
            }
            cout<<toprint.size()<<" ";
            for(int i=0;i<toprint.size();i++){
                cout<<toprint[i]<<" ";
            }
            cout<<"\n";
        }else{
            cin>>a>>k;
            a--;
          // cout<<position[a][0]<<" "<<position[a][0]+subc[a]-1<<" "<<li.size()<<"\n";
            if(position[a][0]>position[a][0]+subc[a]-1){
                continue;
            }
           // cout<<"beingdone\n";
            update(1,0,li.size()-1,position[a][0],position[a][0]+subc[a]-1,k);
        }
    }
    
}
int main(){
    solve();
}