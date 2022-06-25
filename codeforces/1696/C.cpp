#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    vector<pair<long long,long long>> a2;
    vector<pair<long long,long long>> b2;
    int in=-1;

    for(int i=0;i<n;i++)
    {
        if(a[i]%k==0)
        {
            long long am=1;
            while(a[i]%k==0&&a[i]>0)
            {
                am*=k;
                a[i]/=k;
            }
            if(a2.size()>0&&a2[a2.size()-1].first==a[i])
            {
                a2[a2.size()-1].second+=am;
            }else
            {
                 a2.push_back(make_pair((a[i]),am));

            }





        }else

        {
            if(a2.size()>0&&a2[a2.size()-1].first==a[i])
            {
                a2[a2.size()-1].second++;
            }else
            {
                 a2.push_back(make_pair((a[i]),1));

            }

        }
    }

    for(int i=0;i<m;i++)
    {
        if(b[i]%k==0)
        {
            long long am=1;
            while(b[i]%k==0&&b[i]>0)
            {
                am*=k;
                b[i]/=k;
            }
            //cout<<am<<" "<<b[i]<<"\n";
            if(b2.size()>0&&b2[b2.size()-1].first==b[i])
            {
                b2[b2.size()-1].second+=am;
            }else
            {
                b2.push_back(make_pair((b[i]),am));
            }


        }else

        {
            if(b2.size()>0&&b2[b2.size()-1].first==b[i])
            {
                b2[b2.size()-1].second++;
            }else
            {
                b2.push_back(make_pair((b[i]),1));
            }
        }
    }
   // cout<<a2.size()<<" gg "<<b2.size()<<"\n";

   if(a2.size()!=b2.size())
   {
       cout<<"NO\n";
       return;
   }
    for(int i=0;i<max(a2.size(),b2.size());i++)
    {
        //cout<<a2[i].first<<" "<<a2[i].second<<" others "<<b2[i].first<<" "<<b2[i].second<<"\n";
        if(a2[i].first!=b2[i].first||a2[i].second!=b2[i].second)
        {


            cout<<"NO\n";
            return;
        }
    }



    cout<<"YES\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
