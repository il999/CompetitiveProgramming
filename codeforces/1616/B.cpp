#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    n=s.size();
    string new1="";
    int last=198433324;
    bool different=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]<=last)
        {

            if(s[i]!=last&&last!=198433324)
            {
                different=true;
            }
            if(!different&&s[i]==last)
            {
                break;
            }
            last=s[i];
            new1+=s[i];

        }else
        {
            break;
        }
    }
    string new2="";
    string acc=new1;
    for(int i=new1.size()-1;i>=0;i--)
    {
        acc+=new1[i];
    }
    if(different)
    {
         cout<<acc<<endl;
    }else
    {
        cout<<s[0]<<s[0]<<endl;
    }

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
