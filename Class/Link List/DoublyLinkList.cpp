#include<iostream>
using namespace std;

class DoublyLinkList
{
    struct node
    {
        int value;
        struct node* prev;
        struct node* next;
    };
    struct node* start;
    struct node* ptr;
    struct node* ptr1;
    struct node* new_node;
    int c;
    public:
        DoublyLinkList()
        {
            start=ptr=ptr1=NULL;
            c=0;
        }
        void create_begin()
        {
            int num;
            cin>>num;
            while(num!=-1)
            {
                new_node=new node;
                new_node->value=num;
                new_node->prev=start;
                new_node->next=ptr1;
                start=new_node;
                ptr1=new_node;
                c++;

                cin>>num;
            }
        }
        void create_end()
        {
            int num;
            cin>>num;
            while(num!=-1)
            {
                if(start==NULL)
                {
                new_node=new node;
                new_node->value=num;
                new_node->prev=start;
                new_node->next=start;
                start=new_node;
                ptr1=new_node;
                c++;
                }
                else
                {
                new_node=new node;
                new_node->value=num;
                new_node->prev=ptr1;
                new_node->next=ptr1->next;
                ptr1->next=new_node;
                ptr1=new_node;
                c++;
                }
                cin>>num;
            }
        }
        void show()
        {
            cout<<endl;
            ptr=start;
            while(ptr!=NULL)
            {
                cout<<ptr->value<<endl;
                ptr=ptr->next;
            }
        }
        void del_begin()
        {
            ptr=start;
            if(ptr->next==NULL)
            {
                start=NULL;
            }
            else{
            start=ptr->next;
            ptr->next->prev=NULL;
            ptr->next=NULL;
            delete ptr;
            }
        }
        void del_end()
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            if(ptr->prev==NULL)
            {
                start=NULL;
            }
            else{
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete ptr;
            }

        }
        void del_given()
        {
            int num;
            cin>>num;
            ptr=start;
            while(ptr->value!=num)
            {
                ptr=ptr->next;
            }
            if(ptr->prev==NULL)
            {
                start=NULL;
            }
            else if(ptr->next==NULL)
            {
                del_end();
            }
            else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            ptr->next=NULL;
            delete ptr;
            }
        }
        void ins_end()
    {
        struct node* new_node;
        int num;
        cin>>num;
        ptr=start;
          while(ptr!=NULL){
                ptr1=ptr;
            ptr=ptr->next;
        }
         new_node=new node;
        new_node->value=num;
        new_node->prev=ptr1;
        new_node->next=ptr1->next;
        ptr1->next=new_node;
        ptr1=new_node;
    }
    void ins_beg()
    {
         struct node* new_node;
         int num;
        cin>>num;
        new_node=new node;
        new_node->value=num;
        new_node->next=start;
        new_node->prev=NULL;
        start=new_node;
    }
       void ins_before()
    {
        int num,n;
        cin>>num>>n;
        ptr=start;
        while(ptr->value!=num)
        {   ptr1=ptr;
            ptr=ptr->next;

        }
        new_node=new node;
        new_node->value=n;
        new_node->prev=ptr1;
        new_node->next=ptr1->next;
        ptr1->next->prev=new_node;
        ptr1->next=new_node;
        ptr1=new_node;

    }
    void ins_after()
    {
        int num,n;
        cin>>num>>n;
        ptr=start;
        while(ptr->value!=num)
        {   ptr=ptr->next;
            ptr1=ptr;

        }
        new_node=new node;
        new_node->value=n;
        new_node->next=ptr1->next;
        new_node->prev=ptr1;
        ptr1->next=new_node;
        new_node->next->prev=new_node;
        ptr1=new_node;
    }
    void ins_ss()
    {
        int num;
        cin>>num;
        ptr=start;
        while(ptr->value<num)
        {   ptr1=ptr;
            ptr=ptr->next;

        }
        new_node=new node;
        new_node->value=num;
        new_node->prev=ptr1;
        new_node->next=ptr1->next;
        ptr1->next=new_node;
        new_node->next->prev=new_node;
        ptr1=new_node;

    }
    void sortt()
    {
       for (int i=1;i<c;i++)
       {
           ptr=start;
           for(int j=0;j<c-i;j++)
           {
               ptr1=ptr;
               ptr=ptr->next;
               if(ptr1->value>ptr->value)
               {
                   int temp;
                   temp=ptr1->value;
                   ptr1->value=ptr->value;
                   ptr->value=temp;
               }
           }
       }
    }

};
int main()
{
    DoublyLinkList obj;
    int n;
cout<<"Please select one of the following options:"<<endl;
cout<<"1 to create list by insertion in beginging"<<endl;
cout<<"2 to create list by inerstion at the end"<<endl;
cin>>n;
switch(n)
{
   case 1:
       cout<<"Enter numbers and press -1 to stop"<<endl;
        obj.create_begin();
        break;
    case 2:
        cout<<"Enter numbers and press -1 to stop"<<endl;
        obj.create_end();
        break;
}
cout<<"Please select one of the following options:"<<endl;
cout<<"1 to Insert an element"<<endl;
cout<<"2 to Delete an element"<<endl;
cout<<"3 to Print the LinkList"<<endl;
cin>>n;
switch(n)
{
   case 1:
cout<<"Please select one of the following options:"<<endl;
cout<<"1 to Insert an element at the begining"<<endl;
cout<<"2 to Insert an element at the end"<<endl;
cout<<"3 to Insert an element before the given"<<endl;
cout<<"4 to Insert an element after the given"<<endl;
cout<<"5 to Insert an element in a sorted list"<<endl;
switch(n)
{
   case 1:
        obj.ins_beg();
        obj.show();
        break;
    case 2:
        obj.ins_end();
        obj.show();
        break;
    case 3:
        obj.ins_before();
        obj.show();
        break;
    case 4:
        obj.ins_after();
        obj.show();
        break;
    case 5:
        obj.ins_ss();
        obj.show();
        break;

}
    case 2:
cout<<"Please select one of the following options:"<<endl;
cout<<"1 to Delete an element from the begining"<<endl;
cout<<"2 to Delete an element from the end"<<endl;
cout<<"3 to Delete a given element"<<endl;
cin>>n;
switch(n)
{
   case 1:
        obj.del_begin();
        obj.show();
        break;
    case 2:
        obj.del_end();
        obj.show();
        break;
    case 3:
        obj.del_given();
        obj.show();
        break;
}
    case 3:
        obj.show();
        break;
}
}
