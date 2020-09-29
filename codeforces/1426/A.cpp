#include <iostream>

using namespace std;

int main()
{
    int t=0;
    cin>>t;
    int x[t];
    int n[t];
    for (int i=0;i<t;i++)
    {
        cin>>n[i];
        cin>>x[i];
    }
    for (int i=0;i<t;i++)
    {

        if (n[i]>2)
        {


            n[i]-=2;

            int ans=(n[i]/x[i])+2;
            if (n[i]%x[i]==0)
            {
                ans=n[i]/x[i]+1;
            }
            cout<<ans<<endl;

        }else{
            cout<<1<<endl;
        }


    }
}
