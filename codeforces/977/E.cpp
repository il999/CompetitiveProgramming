#include <bits/stdc++.h>
#include<iostream>

using namespace std;
bool seen[200001]={0};
bool cycle=true;
vector<vector<int>> v;
void dfs(int u,int first,int last)
{
    seen[u]=true;
    //cout<<"POO"<<"\n";
    if(v[u].size()!=2)
    {
        cycle=false;
        for(int i=0;i<v[u].size();i++)
        {
            if(seen[v[u][i]]==false)
                dfs(v[u][i],first,last);
        }

    }else
    {

        if(seen[v[u][0]]==false)
        {
            dfs(v[u][0],first,last);
        }else if(seen[v[u][1]]==false)
        {
            dfs(v[u][1],first,last);
        }else if((v[u][0]!=first&&v[u][1]!=first)||u!=last)
        {
            cycle=false;
        }
    }



}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> p;
    for(int i=0;i<=n;i++)
    {
        v.push_back(p);
    }
    int u,v1;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v1;
        v[u].push_back(v1);
        v[v1].push_back(u);
    }
    int o=0;
    for(int i=1;i<=n;i++)
    {
        cycle=true;
        //cout<<"P"<<endl;
        if(seen[i]==false)
        {
            int t;
            t=-1;
            if(v[i].size()>=2)
                t=v[i][1];
            dfs(i,i,t);
            if(cycle)
            {
                o++;
            }
        }
       //cout<<i<<endl;


    }
    cout<<o<<endl;
}
