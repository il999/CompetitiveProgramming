//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int a1[n];
    int b1[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a1[i]=a[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
        b1[j]=b[j];
    }
    sort(a1,a1+n);
    sort(b1,b1+n);
    vector<pair<int,int>> v;
    bool used[n]={0};
    bool done=false;
    for(int i=0;i<n;i++)
    {
        done=false;
        for(int j=i;j<n;j++)
        {
            if(a1[i]==a[j]&&b1[i]==b[j])
            {
                if(i!=j)
                    v.push_back(make_pair(i+1,j+1));
                done=true;
                used[j]=true;
                a[j]=a[i];
                b[j]=b[i];
                break;
            }
        }
        if(!done)
        {
            cout<<-1<<"\n";
            return;
        }
    }

    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    cout<<"\n";


}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
