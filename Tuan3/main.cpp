#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime> 
#include <cstdlib>
#include <time.h>
using namespace std;

void SelectionSort(int a[], int n);
void insertionSort(int a[], int n);
void swap(int a[], int i, int j);
void Swap(int &i,int &j);
void HeapSort(int a[], int n);
void Heapify(int a[], int n, int i);
void bubbleSort(int arr[], int n) ;
void quickSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int getMax(int arr[], int n);
void countingSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);


void GenerateSortedData(int arr[], int size);
void GenerateNearlySortedData(int arr[], int size);
void GenerateReverseData(int arr[], int size);
void GenerateRandomData(int arr[], int size);
double measureRuntime(void dataGenFunc(int[], int), int a[], int n,char algorithm[]);

int main(int argc, char* argv[]) {
    char algorithm[50] = "";
    char inputFile[100] = "";
    char outputFile[10000] = "";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0 && i + 1 < argc) {
            strcpy(algorithm, argv[++i]);
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            strcpy(inputFile, argv[++i]);
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            strcpy(outputFile, argv[++i]);
        }
    }

    fstream in(inputFile);
    int temp[100000];  
    int n;
    
    in >> n; 
    for (int i = 0; i < n; ++i) {
        in >> temp[i];
    }
    in.close();
    

    if (strcmp(algorithm, "insertion-sort") == 0) 
        insertionSort(temp, n);
    else if (strcmp(algorithm, "selection-sort") == 0) 
        SelectionSort(temp, n);
    else if (strcmp(algorithm, "heap-sort") == 0) 
        HeapSort(temp,n);
    else if (strcmp(algorithm, "bubble-sort") == 0) 
        bubbleSort(temp, n);
    else if (strcmp(algorithm, "quick-sort") == 0) 
        quickSort(temp, 0, n - 1);
    else if (strcmp(algorithm, "merge-sort") == 0)
        mergeSort(temp, 0, n - 1);
    else if (strcmp(algorithm, "radix-sort") == 0) 
        radixSort(temp, n);
    else {
        return 1;
    }

    ofstream out(outputFile);
      srand(time(0));
    int sizes[] = {1000, 2000, 10000, 20000, 50000, 100000};

    for (int s = 0; s < 6; ++s) {
        int size = sizes[s];
        int a[100000];  

        cout <<"size: "<< size <<endl<<endl;

        cout <<"Sorted: "<< measureRuntime(GenerateSortedData, a, size,algorithm) <<endl;
        cout <<"NearlySorted: "<< measureRuntime(GenerateNearlySortedData, a, size,algorithm) <<endl;
        cout <<"ReverseSorted: "<< measureRuntime(GenerateReverseData, a, size,algorithm) <<endl;
        cout <<"Random: "<< measureRuntime(GenerateRandomData, a, size,algorithm) <<endl<<endl;
    }
    out << n << endl;
    for (int i = 0; i < n; i++) {
    out << temp[i] << " ";
    }
    out.close();
  
    return 0;
}

// algorithm
//1
void insertionSort(int a[], int n)
{
    for (int i =1; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
//2
void SelectionSort(int a[],int n)
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
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
//3
void HeapSort(int a[],int n){
    for (int i= n/2 - 1 ;i>=0;i--)
    {
       Heapify (a,n,i);
    }
    for (int i= n-1;i>0;i--)
    {
       Swap(a[0],a[i]);
       Heapify (a,i,0);
    }
   }
   
void Swap(int &i,int &j)
   {
       int temp=i;
   
       i=j;
       j=temp;
   }
void Heapify(int a[],int n,int i)
   {
   
       int largest=i;
       int left=2*i+1;
       int right=2*i+2; 
   
       if (left<n && a[left]>a[largest])
       largest = left;
       if (right < n && a[right] > a[largest])
       largest = right;
   
       if (largest != i)
       {
       Swap(a[i], a[largest]);
       Heapify(a, n, largest); 
       }
   
 }
 //4
 void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
      }
}
}
//5
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;  

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}
//6
void merge(int arr[], int left, int mid, int right) {
    const int MAX = 100000;
    int temp[MAX];
    int i = left;  
    int j = mid + 1;   
    int k = 0;      

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

   
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
   
    for (int x = 0; x < k; x++){
        arr[left + x] = temp[x];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//7
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}
void countingSort(int arr[], int n, int exp) {
    int output[100000]; // Mảng kết quả tạm
    int count[10] = {0};

    for (int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
    }
}



//time 
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}
double measureRuntime(void dataGenFunc(int[], int), int a[], int n,char algorithm[]) {
    dataGenFunc(a, n);
    clock_t start = clock();
       if (strcmp(algorithm, "insertion-sort") == 0)
        insertionSort(a, n);
    else if (strcmp(algorithm, "selection-sort") == 0)
        SelectionSort(a, n);
    else if (strcmp(algorithm, "heap-sort") == 0)
        HeapSort(a,n);
    else if (strcmp(algorithm, "bubble-sort") == 0)
        bubbleSort(a, n);
    else if (strcmp(algorithm, "quick-sort") == 0)
        quickSort(a, 0, n - 1);
    else if (strcmp(algorithm, "merge-sort") == 0)
        mergeSort(a, 0, n - 1);
    else if (strcmp(algorithm, "radix-sort") == 0)
        radixSort(a, n);
    else {
        return 1;
    }
    clock_t end = clock();
    return double(end - start)/ CLOCKS_PER_SEC;// trả giá trị theo giây
}