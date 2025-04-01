#include <iostream>
using namespace std;

int BinarySearch(int a[],int left , int right);
int main() {
    int n,a[100];
    cout<<"nhap n phan tu trong mang: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"nhap phan tu thu "<<i+1<<": ";
        cin>>a[i];
    }
    int  left=0 ,right=n-1;
    int ans = BinarySearch(a, left, right);
    cout<<a[ans];
}
int BinarySearch (int a[],int left ,int right){
    while (left<right){

        int mid=(right+left)/2;
        if(a[mid]>a[right])
        {
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return left; 
}