#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *ptr = &x; // Pointer storing the address of x

    cout << "Value of x: " << x << endl;             // Output: 10
    cout << "Address of x: " << &x << endl;          // Memory address
    cout << "Pointer value: " << ptr << endl;        // Address stored in ptr
    cout << "Value using pointer: " << *ptr << endl; // Dereferencing: 10
    return 0;
}