#include <iostream>
using namespace std;

int SentineLinearSearch(int a[],int n, int k);
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
    SentineLinearSearch(a,n,k);
}
int SentineLinearSearch (int a[],int n, int k){
    int fake=a[n-1];
    a[n-1]=k;
    int i=0;
    while(a[i]!=k)
    {
        i++;
    }
    if (i<= n-1||a[n-1]==k)
    {
        cout<<i;
        return i;
    }
    return -1;

}