#include<iostream>
using namespace std;
void Merging(int arr[],int first,int mid,int last)//function that take array,first ,middle and last index as firstarameters
{
    int sizeOfLeft,sizeOfRight,x;
    sizeOfLeft = mid -first+1;
    sizeOfRight = last-mid;
    x = first;
    int *left = new int[sizeOfLeft] ,*right=new int[sizeOfRight];
    for(int i=0;i<sizeOfLeft;i++)
    {
        left[i]=arr[x];
        x++;
    }
    for(int j=0;j<sizeOfRight;j++)
    {
        right[j]=arr[mid+1];
        mid++;
    }
    int i,j,k=first;
    i=j=0;
    while(i<sizeOfLeft && j <sizeOfRight)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            k++;
        }
    }
        if(j==sizeOfRight)
        {

            while(i<sizeOfLeft)
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        }

        else if(i==sizeOfLeft)
          {

          while(j<sizeOfRight)
        {
            arr[k]=right[j];
            k++;
            j++;
        }
          }

}
void ms(int arr[],int first,int last)//sort function that take arr, first and last index of array as firstarameters
{
    if(first<last)
    {
     int mid=(first+last)/2;
     ms(arr,first,mid);
     ms(arr,mid+1,last);
     Merging(arr,first,mid,last);
    }
}

int main()
{
    int arr[6]={7,4,6,1,2,5};//array to be sorted
    ms(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i];
    }
}
