#include <iostream>

using namespace std;
void  solve()

{
    int n,l;
    cin>>n>>l;
    int l1[n];
    string s;

    int ones[l];
    for(int i=0;i<l;i++)
    {
        s+='0';
        ones[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        cin>>l1[i];

    }

    for(int i=0;i<n;i++)
    {
        int prop=l-1;
        while(l1[i]>0)
        {
            if(l1[i]%2==1)
            {
                s[prop]='1';
                ones[prop]++;
            }
            l1[i]/=2;
            prop--;
        }
    }
    int wanted=0;
    if(n%2==0)
    {
        wanted=n/2;
    }else
    {
        wanted=n/2;
        wanted++;
    }
    for(int i=0;i<l;i++)
    {
        //cout<<"ones"<<ones[i]<<endl;
        if(ones[i]>=wanted)
        {
            s[i]='1';
        }else
        {
            s[i]='0';
        }
    }
    long long temp=1;
    long long ans=0;
    for(int i=l-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            ans+=temp;
        }
        temp*=2;

    }
    cout<<ans<<endl;
    //cout<<s<<endl;
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
