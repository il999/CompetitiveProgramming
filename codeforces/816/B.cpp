//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k,q;
    cin>>k>>q;
    long long pre[200002];
    pre[0]=0;
    int l,r;

    for(int i=0;i<n;i++)
    {
         cin>>l>>r;
        pre[l]++;
        pre[r+1]--;
    }
    for(int i=1;i<200002;i++)
    {
        pre[i]+=pre[i-1];

    }
    long long pre2[200002];
    pre2[0]=0;
    for(int i=1;i<200002;i++)
    {
        pre2[i]=pre2[i-1];
        if(pre[i]>=k)
        {
            pre2[i]++;
        }
    }
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<pre2[b]-pre2[a-1]<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
