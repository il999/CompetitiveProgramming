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
    int n;
    cin>>n;
    vector<array<int,4>> v;
    int x,y,z;
    bool snapped[n];

    for(int i=0;i<n;i++)
    {
        snapped[i]=0;
        cin>>x>>y>>z;
        v.push_back({x,y,z,i+1});
    }
    sort(v.begin(),v.end());
    int lookback=0;;
    for(int i=0;i<n;i++)
    {
        if(i>0&&v[i][0]!=v[i-1][0])
        {
            lookback=i;
        }
        if(!snapped[i])
        {
           // cout<<"FDS";
             int in2=i+1;
            for(int j=in2;j<n;j++)
            {
                if(!snapped[j])
                {
                    in2=j;
                    break;
                }
            }
            int temp=in2;
            x=v[in2][0];
            int last=-1;;
            //int last=0;


           // vector<int> possible v;
            while(in2<n&&v[in2][0]==x)
            {

                if(!snapped[in2])
                {

                    if(last!=-1&&abs(v[i][1]-v[in2][1])>last)
                    {
                        break;

                    }
                    last=abs(v[i][1]-v[in2][1]);

                }
                in2++;

            }
            int mi=1e9+7;;
            int indexoutput=temp;
            for(int j=temp;j<in2;j++)
            {
                if(!snapped[j]&&abs(v[i][1]-v[j][1])==last)
                {
                    if(abs(v[i][2]-v[j][2])<mi)
                    {
                        mi=abs(v[i][2]-v[j][2]);
                        indexoutput=j;

                    }
                }
            }
            snapped[indexoutput]=1;
            snapped[i]=1;
            cout<<v[i][3]<<" "<<v[indexoutput][3]<<"\n";
        }


    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
