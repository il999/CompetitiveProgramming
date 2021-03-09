#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
void funct(int n)
{
  int count1=0;

    for(int i=3;(i*i)<=(2*n-1);i+=2)
    {
      count1++;
    }

  cout<<count1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

      int n;
      cin>>n;
      funct(n);
    }
}
