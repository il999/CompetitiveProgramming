#include <iostream>

using namespace std;
#include <vector>
int binary(int n)
{
  int count=-1;
  vector <int> l;
  while(n>0)
  {
    l.push_back(n%2);
    n/=2;

    count+=1;
  }
  int s=0;
  int ones=0;
  for(int i=count;i>=0;i--)
  {

    int temp=l[i];
    if(temp==1)
    {
      ones++;
    for(int j=0;j<i;j++)
    {
      temp=temp*10;
    }
  }

    s+=temp;
  }
  cout<<ones<<endl;
  return ones;

}


int main()
{
  int n;
  cin>>n;
  binary(n);
  return 0;
}
