//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int max1=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    if(n%2==1)
    {
        cout<<"NO\n";
        return;
    }
    int c=1;
    int m=0;
    int p=-1;
    for(int i=0;i<n-1;i++)
    {
        if(l[i]==l[i+1])
        {
            c++;
            if(c==n/2)
                p=l[i];
            m=max(c,m);
        }else

        {
            c=1;
        }
    }

    if(m>n/2)
    {
        cout<<"NO"<<"\n";
    }else
    {
        vector<int> v;



        for(int i=0;i<n/2;i++)
        {
            v.push_back(l[i]);
            v.push_back(l[i+n/2]);

        }
        if(v[0]>=v[n-1])
        {
            cout<<"NO\n";
            return;
        }
        for(int i=1;i<n-1;i++)
        {
            if(i%2)
            {
                if(v[i]<=v[i-1]||v[i]<=v[i+1])
                {
                    cout<<"NO\n";
                    return;
                }
            }else
            {
                if(v[i]>=v[i-1]||v[i]>=v[i+1])
                {
                    cout<<"NO\n";
                    return;
                }
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";


    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
