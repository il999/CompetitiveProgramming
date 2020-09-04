#include <iostream>

using namespace std;

int main()
{
    long int n=0;
    cin>>n;
    long int l[n];
    long int r[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        cin>>r[i];
    }

    int count1;
    for(int i=0;i<n;i++)
    {

        count1=0;
        if(r[i]==l[i]){
            cout<<count1<<endl;
        }else if(r[i]>l[i]){
            if(r[i]-l[i]<=10)
            {
                cout<<1<<endl;
            }else{
                count1=(r[i]-l[i]);

                if(count1%10>0){
                    cout<<count1/10+1<<endl;
                }else{
                    cout<<count1/10<<endl;
                }
            }

        }else{
            if(l[i]-r[i]<=10)
            {
                cout<<1<<endl;
            }else{
                count1=(l[i]-r[i]);

                if(count1%10>0){
                    cout<<count1/10+1<<endl;
                }else{
                    cout<<count1/10<<endl;
                }
            }
        }

    }
}

