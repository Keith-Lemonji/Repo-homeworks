#include <iostream>
using namespace std;

int maxcap(int weight[],int n);
int mincap(int weight[],int n);
bool can(int weight[],int n,int days,int cap);
int mindaysrequired(int weight[],int n,int days);


//trong luong toi da
int maxcap(int weight[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=weight[i];
    }
    return sum;
}
//trong luong lon nhat cua cac mon hang
int mincap(int weight[],int n)
{
    int max=weight[0];
    for(int i=1;i<n;i++)
    {
        if(weight[i]>max)
        max=weight[i];
    }
    return max;
}
bool can(int weight[],int n,int days,int cap)
{
    int currentWeight = 0, requiredDays = 1;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] > cap) {
            requiredDays++;
            currentWeight = 0;
        }
        currentWeight += weight[i];
    }

    return requiredDays <= days;
}
int mindaysrequired(int weight[],int n,int days)
{
    int left=mincap(weight,n);//trong luong min
    int right=maxcap(weight,n);//trong luong max
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (can(weight, n, days, mid)) {
            result = mid;
            right = mid ;
        } else {
            left = mid + 1;
        }
    }

    return result;
}
int main()
{
    int weight[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int days;
    cin>>days;
    cout<<mindaysrequired(weight,n,days)<<endl;
}