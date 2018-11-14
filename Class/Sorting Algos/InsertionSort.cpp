#include <iostream>

using namespace std;
void insertion_sort ( int arr[ ] , int n)
{
     for( int i = 0 ;i < n ; i++ ) {

      int temp = arr[ i ];
      int j = i;

          while(  j > 0  && temp < arr[ j -1]) {
                arr[ j ] = arr[ j-1];
                j= j - 1;

           }
           arr[ j ] = temp;
     }
}

int main()
{
    int arr[10],n;
    cout<<"Enter the number of elements to enter\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
