// Example program
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    
    {
        cin>>s[i];   
    }
      long long total[12]={0};
       long long l[12][12]={{0}};
     
    for(int i=0;i<n;i++)
    {
        l[s[i][0]-'a'][s[i][1]-'a']++;
        
    }
  
     long long ans=0;
    for (int i=0;i<12;i++)
    
    {
       for(int j=0;j<12;j++)
       {
            total[i]+=l[i][j];   
       }
       for(int j=0;j<12;j++)
       {
           ans+=(l[i][j]) * (total[i]-l[i][j]);
           total[i]-=l[i][j];
       }
    }
    
    for(int i=0;i<12;i++)
    
    {
        total[i]=0;
        for(int j=0;j<12;j++)
        {
            l[i][j]=0;   
        }
    }
    for(int i=0;i<n;i++)
    {
        l[s[i][1]-'a'][s[i][0]-'a']++;
        
    }
    for (int i=0;i<12;i++)
    
    {
       for(int j=0;j<12;j++)
       {
            total[i]+=l[i][j];   
       }
       for(int j=0;j<12;j++)
       {
           ans+=(l[i][j]) * (total[i]-l[i][j]);
           total[i]-=l[i][j];
       }
    }
   cout<<ans<<"\n";
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
