#include <iostream>
using namespace std;
int twoPoint(int a[],int left,int right,int k);
int twoPoint(int a[],int left,int right,int k)
{
    while(left<right)
    {
        if(a[left]+a[right]<k){
            left++;
        }
        if(a[left]+a[right]>k){
            right--;
        }
        if(a[left]+a[right]==k && left!=right)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
int main(){
    int a[100],n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int left=0,right=n-1;
    twoPoint(a,left,right,k);
}