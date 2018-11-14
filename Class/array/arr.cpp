#include<iostream>
using namespace std;
class array1
{
    int *arr,n;
public:
    array1 (int size_)
    {
        n=size_;
        arr=new int[n];
    }
    void input()
    {
        for (int i=0;i<n;i++)
        {
        cin>>arr[i];
        }
    }
    void display()
    {
        for (int i=0;i<n;i++)
        {
        cout<<arr[i]<<endl;
        }
    }
    void lsearch()
    {
        int flag=0,value;
        cout<<"enter item to be searched"<<endl;
        cin>>value;
        for (int i=0;i<n;i++)
        {
            if (arr[i]==value)
            {
            flag=1;
            cout<<"FOUND at"<<i<<endl;
            break;
            }
        }
        if (flag==0)
        {
            cout<<"NOT FOUND"<<endl;
        }
    }
    void bsearch()
    {
        int value,mid,beg,end_,flag=0;
        cout<<"enter item to be searched";
        cin>>value;
        beg=0;
        end_=n-1;
        mid= (beg+end_)/2;
        while (beg<=end_)
        {
        if (arr[mid]==value)
        {
            cout<<"item found at"<<mid<<endl;
            flag=1;
            break;
        }
        else
        {
            if (arr[mid]>value)
                end_=mid-1;
            else
                beg=mid+1;

        }
        mid= (beg+end_)/2;
    }
    if (flag==0)
        cout<<"item not found"<<endl;
    }
    void bsort();
};
void array1::bsort()
{ int temp,flag;
    for (int p=1;p<n;p++)
    {
        flag=0;
        for (int c=0;c<n-p;c++)
        {
            if (arr[c]>arr[c+1])
            { flag=1;
                temp=arr[c];
                arr[c]=arr[c+1];
                arr[c+1]=temp;
            }
        }
        if (flag==0)
            break;
    }
}

int main()
{
int size_,ch;
cout<<"enter size of array"<<endl;
cin>>size_;
array1 ob(size_);
cout<<"Enter 1 to enter values\n2 To display \n3 for linear search\n4 for binary search\n5 for sorting\n0 to exit"<<endl;
cin>>ch;
while (ch!=0)
    {
        switch(ch)
            {
            case 1:
                cout<<"Enter values\n";
            ob.input();
            break;
            case 2:
            ob.display();
            break;
            case 3:
                ob.lsearch();
            break;
            case 4:
                ob.bsearch();
                break;
            case 5:
                ob.bsort();
                cout<<"After sorting"<<endl;
                ob.display() ;
            }

    cout<<"enter choice"<<endl;
    cin>>ch;
    }
}
