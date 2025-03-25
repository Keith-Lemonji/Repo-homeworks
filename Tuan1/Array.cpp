#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // Get array size

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output: 10 20 30 40 50
    }
    return 0;
}