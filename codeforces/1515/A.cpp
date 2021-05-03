#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,x;
      cin>>n>>x;
      int l[n];
      int max1=0;
      int max2=0;
      int count2=0;
      for(int i=0;i<n;i++)
      {
        cin>>l[i];
        if(l[i]>max1)
        {
          max1=l[i];
          max2=i;
        }
        count2+=l[i];
      }
      if(max1>x)
      {
        cout<<"YES"<<endl;
        cout<<max1<<" ";
        for(int i=0;i<n;i++)
        {
          if(max2!=i)
          {


            cout<<l[i]<<" ";
        }
        }
        cout<<endl;
      }else
      {
        if(count2==x)
        {
          cout<<"NO"<<endl;
        }else if(count2<x)
        {
          cout<<"YES"<<endl;
          for(int i=0;i<n;i++)
          {



              cout<<l[i]<<" ";

          }
          cout<<endl;
        }else
        {
          int count=0;
          for(int i=0;i<n-1;i++)
          {
            count+=l[i];
            if(count==x)
            {
               int thing=l[i];
               int thing2=l[i+1];
               l[i]=thing2;
               l[i+1]=thing;
            }
          }
          cout<<"YES"<<endl;
          for(int i=0;i<n;i++)
          {



              cout<<l[i]<<" ";

          }
          cout<<endl;
        }
      }
}
}
