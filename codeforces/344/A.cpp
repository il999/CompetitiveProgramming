#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string list1[n];
    for(int i=0;i<n;i++)
    {
        cin>>list1[i];
    }
    int count1=0;
    for(int i=0;i<n-1;i++)
    {
        if(list1[i]!=list1[i+1]){
            count1+=1;
        }
    }
    count1+=1;
    cout<<count1;

    return 0;
}
