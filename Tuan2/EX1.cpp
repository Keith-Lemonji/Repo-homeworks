#include <iostream>
using namespace std;
int LinearSearch(int a[],int n, int k);

int main() {
   int n,a[100];
   cout<<"nhap n phan tu trong mang: ";
   cin>>n;
    for(int i=0;i<n;i++){
         cout<<"nhap phan tu thu "<<i+1<<": ";
         cin>>a[i];
    }
    cout<<"nhap phan tu k can tim: ";
     int k;  cin>>k;
     LinearSearch(a,n,k);
}

int LinearSearch(int a[],int n, int k){
    for(int i=0;i<n;i++){
        if(a[i]==k){
          cout<<"phan tu "<<k<<" o vi tri thu "<<i;
          return i;
        }
    }
    return -1;
}
