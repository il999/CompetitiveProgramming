#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,k;
      cin>>n>>k;
      int count=0;
      vector <int> a;
      for(int i=n;i>0;i--)
      {
        if((i>k||i>k/2)&&i!=k)
        {
          a.push_back(i);

          count++;
        }else if(k%i==0&&i>=k/2&&k!=i&&(i>1||k==2))
        {

          a.push_back(i);
          count++;
        }
      }
      cout<<count<<endl;
      for(int i=0;i<count;i++)
      {
        cout<<a[i]<<" ";
      }
      cout<<endl;
    }
}
