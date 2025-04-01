#include <iostream>
using namespace std;
int boBaTongBangKhong(int a[],int n);
void SlecSort(int a[],int n);
void swap(int a[],int i,int j);
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void SlecSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int Gtmin=i;
        for (int j=i+1;j<n;j++)
        {
            if(a[j]<a[Gtmin])
            Gtmin=j;
        }
        swap(a,i,Gtmin);
    }
    
}
int boBaTongBangKhong(int a[],int n)
{
    SlecSort(a,n);
    for(int i=0;i<n;i++){
        int left=i+1,right=n-1;
        while(left<right){
            int sum=a[i]+a[left]+a[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }
            else if(sum==0){
               cout<<"["<<a[i]<<" ; "<<a[left]<<" ; "<<a[right]<<"]";
               break;
            }
        }
    }
    return 0;
}
int main(){
    int a[100],n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    boBaTongBangKhong(a,n);
}