#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int r[n];
      int p=0;
      for(int i=0;i<n;i++)
      {
        cin>>r[i];
        if(r[i]==3||r[i]==1)
        {
          p++;
        }
      }
      cout<<p<<endl;


    }
}
