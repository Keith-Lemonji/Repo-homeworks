#include <iostream>
using namespace std;
int minimalsuplen(int a[],int n,int target);

int minimalsuplen(int a[],int n,int target)
{
    int left=0,min=n+1,sum=0;
    for(int right=0;right<n;right++)
    {
        sum+=a[right];
        while (sum>= target){
            int length =right-left+1;
        if (length<min){
            min=length;
        }
        sum -=a[left];
        left++;
    }
}
if(min==n+1){
    return 0;
}
else{
    cout<<min;
    return 0;
}
    
}
// t=7 a[1,2,3,4,5]
int main(){
    int target, n, a[100];
    cin>>n;
    for(int i=0;i<n;i++){
       
        cin>>a[i];
    }
    cin>>target;
    minimalsuplen(a,n,target);
}
