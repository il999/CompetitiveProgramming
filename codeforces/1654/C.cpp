#include <bits/stdc++.h>
using namespace std;
bool possible=true;
 
void recur(int l[],int i,bool b[],long long sum)
{
    if(sum<l[0])
    {
 
        possible=false;
        return;
    }
    while(b[i]==true)
    {
        i--;
    }

 if(i<0)
        {
               possible=false;
               return;
         }

    if(sum==l[i])
    {
        b[i]=true;
        i--;
        return;
    }else if(sum<l[i])
    {
        while(sum<l[i])
        {
            i--;
        }
        while(b[i]==true)
        {
            i--;
        }
        if(i<0)
        {
               possible=false;
               return;
         }
        if(sum==l[i])
        {
            b[i]=true;
            i--;
            return;
        }
    }
    if(possible)
    {
        if(sum%2==0)
        {
            sum/=2;
             recur(l,i,b,sum);
             recur(l,i,b,sum);
        }else
        {
            sum/=2;
            recur(l,i,b,sum);
            recur(l,i,b,sum+1);
        }
    }
 
 
 
 
}
void solve()
{
    int n;
    cin>>n;
    int l[n];
    possible=true;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        sum+=l[i];
 
    }
    bool b[n]={0};
    sort(l,l+n);
 
    recur(l,n-1,b,sum);
 
    for(int i=0;i<n;i++)
    {
        if(b[i]==0)
        {
            cout<<"NO"<<"\n";
            return;
        }
    }
 
    //cout<<"YES"<<"\n";
    cout<<"YES"<<endl;
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