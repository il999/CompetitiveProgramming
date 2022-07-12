//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a,b;
    int total[n];
    for(int i=0;i<n;i++) total[i]=0;
    int l[n][3];
    bool pont=1;
    bool pos[n];
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        pos[i]=false;
        if(a==b)
        {
            pont=0;
        }
        l[a][total[a]]=b;
        l[b][total[b]]=a;
        if(total[a]==2||total[b]==2)
        {
            pont=0;
        }
        if(pont)
        {
            total[a]++;
        total[b]++;
        }



    }

    for(int i=0;i<n;i++)
    {
        if(total[i]!=2)
        {
            pont=0;
        }
    }

    if(!pont)
    {
        cout<<"NO\n";
        return;
    }

    for(int i=0;i<n;i++)
    {
        //cout<<"GDS";
        if(l[i][0]==l[i][1])
        {

        }
        else if(!pos[i])
        {
            int s=i;
            int f=l[i][1];
            int c=1;
           // cout<<"SD";
           bool run=1;
            while(run)
            {
               // cout<<"GDS";
                pos[s]=true;
                for(int j=0;j<2;j++)
                {
                    if(l[f][j]!=s)
                    {
                        s=f;
                        f=l[s][j];
                        break;
                    }
                }
                c++;
              //  cout<<s<<" "<<f<<"\n";
                if((s==i&&f==l[i][1])||(s==l[i][1]&&f==i))
                {

                    run=0;
                    c--;
                }
            }
            //cout<<"GDS";
            if(c%2==1)
            {
                cout<<"NO\n";
                return;
            }
        }



    }
    cout<<"YES\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
