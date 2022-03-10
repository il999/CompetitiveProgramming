#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long f[n];
    long long s[n];
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    long long m=abs(s[0]-f[0])+abs(s[n-1]-f[n-1]);
    m=min(m,abs(s[n-1]-f[0])+abs(s[0]-f[n-1]));
    m=min(m,abs(s[0]-f[n-1])+abs(s[n-1]-f[0]));
    long long o=0;
    long long p=0;
    long long c=0;
    long long actual1=0;
    actual1=abs(s[0]-f[0]);
    long long actual2=abs(s[n-1]-f[n-1]);
    long long f1[4];
    for(int i=0;i<4;i++)
        f1[i]=actual1+actual2;

    for(int i=0;i<n;i++)
    {
        f1[0]=min(f1[0],abs(s[0]-f[i]));
        f1[1]=min(f1[1],abs(s[n-1]-f[i]));
        f1[2]=min(f1[2],abs(f[0]-s[i]));
        f1[3]=min(f1[3],abs(f[n-1]-s[i]));
    }
    actual1=min(f1[0]+f1[2],actual1);
    actual2=min(f1[1]+f1[3],actual2);
    m=min(m,f1[0]+f1[3]+abs(s[n-1]-f[0]));
     m=min(m,f1[2]+f1[1]+abs(s[0]-f[n-1]));
        /*
    for(int i=1;i<n-1;i++)
    {
        o=abs(s[i+1]-f[i+1]);
        if(i%2==0&&i!=n-1)
        {
            p=abs(f[i]-s[i+1]);
            c=abs(s[i]-f[i+1]);
        }else if(i!=n-1)
        {
            p=abs(s[i]-f[i+1]);
            c=abs(f[i]-s[i+1]);
        }
        actual+=min(o,p+c);

    }
    */


    cout<<min(m,actual1+actual2)<<"\n";

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
