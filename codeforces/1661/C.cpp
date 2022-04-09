
//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    long long o=0;
    int e=0;
    int needed=l[n-1];
    long long h=0;
    for(int i=0;i<n;i++)
    {
        h+=needed-l[i];
        if((needed-l[i])%2==1)
        {
            o++;
        }
        e++;
    }
  //  cout<<h<<"\n";
    //cout<<h<<"\n";
    long long m=0;
    if(h%3==2)
    {
        m=(h/3+1)*2;
    }else if(h%3==0)
    {
         m=(h/3)*2;
    }else
    {
        m=(h/3)*2+1;
    }
    h=0;
    m=max((o*2)-1,m);
    needed++;
    o=0;
    for(int i=0;i<n;i++)
    {
        h+=needed-l[i];
        if((needed-l[i])%2==1)
        {
            o++;
        }
    }
    long long mn=h;
    if(h%3==2)
    {
        mn=min(mn,(h/3+1)*2);
    }else if(h%3==0)
    {
         mn=min(mn,(h/3)*2);
    }
    else
    {
        mn=min((h/3)*2+1,mn);
    }
    mn=max((o*2)-1,mn);
    cout<<min(mn,m)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
