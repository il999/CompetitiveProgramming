//coding template
/*
⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉
*/
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;

    cin>>s;
    k++;
    int l=n;
    int r=1;
    int c=0;
    int pre[n+1];
   // cout<<"GDS";
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            c++;
            l=min(i,l);
        }
        if(c==k)
        {
            r=i;
            break;
        }
    }
    int in=0;
    int mn=n;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='0'&&max(r-i,i-l)<mn)
        {
            in=i;
           // cout<<mn<<"\n";
            mn=max(r-i,i-l);
        }
    }
   // cout<<"DGF";
    while(true)
    {
        bool too_big=0;
        for(int i=r+1;i<n;i++)
        {
            if(s[i]=='0')
            {
                r=i;
                too_big=1;
                break;

            }
        }
       // cout<<"GDS";
        if(!too_big)
        {
            cout<<mn<<"\n";
            return;
        }
        for(int i=l+1;i<n;i++)
        {
            if(s[i]=='0')
            {
                l=i;

                break;
            }
        }
        bool smaller=0;
        int last=-1;
        for(int i=in;i<=r;i++)
        {
            //cout<<"DGFS";
            //cout<<"DGFS";
            if(s[i]=='0'&&last!=-1&&last<max(r-i,i-l))
            {

                smaller=1;
                break;
            }
            if(s[i]=='0'&&max(r-i,i-l)<mn)
            {

                mn=max(r-i,i-l);
                //cout<<mn<<" "<<i<<"\n";
            }
             if(s[i]=='0')
             {
                 in=i;
                 last=max(r-i,i-l);
                 //cout<<last<<"\n";
             }
        }
    }
    cout<<mn<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
