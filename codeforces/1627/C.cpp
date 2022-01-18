#include <iostream>
#include <bits/stdc++.h>


using namespace std;

    vector<pair<int,int>> ans;
    vector<vector<int>> v;
    vector<int> v4;
void dfs(int a,int b,int j,int last)
{

    for(int i=0;i<v4[j];i++)
    {

        if(v[j][i]!=last)
        {


            ans[j].first=v[j][i];
            ans[j].second=b;
           // cout<<j<<" GDGD"<<endl;

            //cout<<ans[j].second<<"j"<<j<<"i"<<v[j][i]<<endl;
            //cout<<"j"<<j<<endl;
            //cout<<v[j][i].first<<endl;
            //cout<<v[i][j].second<<endl;
            dfs(b,a,v[j][i],j);
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    ans.clear();
    v.clear();
    v4.clear();

    vector<int> palce;
    bool seen[n]={};
    int cost[n];

    int u,v2;
    vector<pair<int,int>> edges;
    for(int i=0;i<n;i++)
    {
        v.push_back(palce);
        v4.push_back(0);
        ans.push_back(make_pair(-1,-1));

    }
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v2;
        u--;
        v2--;
        seen[i]=false;
        cost[i]=0;

        v[u].push_back(v2);
        v[v2].push_back(u);
        edges.push_back(make_pair(u,v2));
        v4[u]++;
        v4[v2]++;


    }
    for(int i=0;i<n;i++)
    {
        if(v4[i]>=3)
        {
            cout<<-1<<endl;
            return;
        }
    }
     for(int i=0;i<n;i++)
    {
        if(v4[i]==1)
        {

            dfs(3,2,i,-1);
            //cout<<"Answers"<<endl;
            //for(int i=0;i<n;i++)
            //{

                //cout<<ans[i].first<<endl;
            //}
            //cout<<"Answers done"<<endl;
            for(int i=0;i<n-1;i++)
            {

                //cout<<ans[i].first<<endl;


                if(ans[edges[i].first].first==edges[i].second)
                {
                    cout<<ans[edges[i].first].second<<" ";
                }else if(ans[edges[i].second].first==edges[i].first)
                {
                    cout<<ans[edges[i].second].second<<" ";
                }else
                {
                    //cout<<edges[i].first<<" dfjhdsaghadslkgh "<<edges[i].second<<endl;
                    //cout<<ans[edges[i].first].first<<endl;
                    //cout<<ans[edges[i].second].first<<endl;
                }
            }
            cout<<endl;
            return;

        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
