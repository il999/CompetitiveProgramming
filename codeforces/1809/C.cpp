// Example program
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t ;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
       
        int neg=((n+1)*n)/2-k;
        int index[n];
        for(int i=n;i>=1;i--){
            if(neg>=i){
                neg-=i;
                index[i-1]=1;}
            else index[i-1]=0;
        }
      
        int pre[n+1];
        int a[n];
        a[0]=1;
        pre[0]=0;

        for(int i=0;i<n;i++){
            
            if(index[i]==1){
                int ma=0;
                int tot=0;
                for(int j=i-1;j>=0;j--){
                    tot+=a[j];
                    if(tot>ma){
                        ma=tot;
                    }
                }
                a[i]=-ma-1;
                //pre[i+1]=pre[i]+a[i];
            }else{
                int ma=0;
                int tot=0;
                for(int j=i-1;j>=0;j--){
                    tot+=a[j];
                    if(tot<ma){
                        ma=tot;
                    }
                }
                a[i]=-ma+1;
                //pre[i+1]=pre[i]+a[i];
            }
        }
        
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}
