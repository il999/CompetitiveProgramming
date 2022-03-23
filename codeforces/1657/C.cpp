// Example program
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int b=0;
    int last=-1;
    int c=0;
    string cur="";
    string cur2="";
    int val=0;
    int s1=0;
    bool initial=false;
    int needed=0;

    for(int i=0;i<n;i++)
    {

        if(s[i]=='('&&i<n-1&&!initial)
        {
            c++;
            last=i+1;
            i++;
        }else if(s[i]==')'&&i<n-1&&s[i+1]==')'&&val==0&&!initial)
        {
            c++;
            last=i+1;
            i++;


        }else
        {
                if(initial&&s[i]==')')
                {
                    c++;
                    last=i;
                    initial=false;

                }else
                {
                    initial=true;
                }



        }



    }
    cout<<c<<" "<<n-last-1<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)
    solve();
}
