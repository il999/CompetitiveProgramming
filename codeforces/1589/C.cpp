#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{

    int n;
    cin>>n;
    int l[n];
    int l1[n];
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        cin>>l1[i];
    }
    bool found=false;

    sort(l1,l1+n);
    sort(l,l+n);
    for(int i=0;i<n;i++)
    {


        found=false;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false&&l[j]+1==l1[i])
            {
                visited[j]=true;

                found=true;
                break;

            }
        }
        if(!found)
        {


            for(int j=0;j<n;j++)
            {
                if(visited[j]==false&&l[j]==l1[i])
                {
                    visited[j]=true;

                    found=true;
                    break;

                }

            }
        }

        if(!found)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
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
