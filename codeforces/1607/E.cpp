#include <iostream>

using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    string s;
    cin>>s;
    int x1=0;
    int y1=0;
    int maxx=0;
    int maxy=0;
    int minx=0;
    int miny=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='D'){

            y1++;
            maxy=max(maxy,y1);
            if(maxy+abs(miny)>=x)
            {
                cout<<max(abs(miny)+1,1)<<" "<<abs(minx)+1<<endl;
                return;
            }

        }else if(s[i]=='U')
        {
            y1--;
            miny=min(miny,y1);
             if(maxy+abs(miny)>=x)
            {
                cout<<max(abs(miny),1)<<" "<<abs(minx)+1<<endl;
                return;
            }
        }else if(s[i]=='R')
        {
            x1++;
            maxx=max(maxx,x1);
             if(maxx+abs(minx)>=y)
            {
                cout<<abs(miny)+1<<" "<<max(abs(minx)+1,1)<<endl;
                return;
            }
        }else
        {
            x1--;
            minx=min(minx,x1);
             if(maxx+abs(minx)>=y)
            {
                cout<<abs(miny)+1<<" "<<max(abs(minx),1)<<endl;
                return;
            }
        }

    }

    cout<<abs(miny)+1<<" "<<abs(minx)+1<<endl;

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
