//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
int n;
 string s[101];
bool inside(int i,int j)
{
 if(i>=0&&i<n&&j>=0&&i<n)
 {
     return true;
 }else
 {
     return false;
 }
}
int c=0;
void check(int i,int j)
{
   // cout<<i<<" "<<j<<" "<<"value: "<<s[i][j]<<" ";
    if(s[i][j]=='0')
    {
        c++;

    }else
    {
       // cout<<"its a one\n ";
    }

}
void check2(int i,int j)
{
    check(i,j);

    check(n-i-1,n-j-1);
    check(n-j-1,i);
    check(j,n-i-1);
    s[i][j]='0';
    s[n-i-1][n-j-1]='0';
    s[n-j-1][i]='0';
    s[j][n-i-1]='0';
}
void solve()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int n2=n/2;
    if(n&1)
    {
        n2++;
    }
    int ans=0;
    //cout<<n2<<"\n";
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n2;j++)
        {
           // cout<<"<GDS";
            c=0;
            check2(i,j);
           // cout<<" c:"<<c<<"\n";
            ans+=min(c,4-c);

        }
    }
    cout<<ans<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
