#include <iostream>

using namespace std;
void solve()
{
    int n1;
    cin>>n1;
    int n=n1-2;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];

    }
    for(int i=1;i<n;i++)
    {
        if(s[i-1][1]!=s[i][0])
        {

            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    cout<<s[j][0];
                }else
                {
                    cout<<s[j-1][1]<<s[j][0];

                }

            }
            cout<<s[n-1][1];
            cout<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<s[i][0];
    }
    cout<<s[n-1][1];
    cout<<"b";
    cout<<endl;
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
