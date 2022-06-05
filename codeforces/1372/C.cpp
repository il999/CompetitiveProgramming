//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        l2[i]=l[i];
    }
    sort(l2,l2+n);
    int in=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(l[i]!=l2[i])
        {
            in =i;
            break;
        }
    }
    if(in==-1)
    {
        cout<<0<<"\n";
        return;
    }
    bool wrong=false;
    for(int i=0;i<in;i++)
    {
        //cout<<i<<"\n";
        if(wrong&&l[i]==l2[i])
        {
            cout<<2<<"\n";
            return;
        }
        if(l[i]!=l2[i]&&!wrong)
        {
            wrong=true;
        }

    }
    cout<<"1\n";


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
