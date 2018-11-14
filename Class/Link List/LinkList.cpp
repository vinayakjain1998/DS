#include<iostream>
using namespace std;

class LinkList
{
    struct node
    {
        int value;
        struct node* next;
    };
    struct node* start;
    struct node* ptr;
    struct node* save;
    struct node* new_node;
public:
    LinkList()
    {
        start=NULL;
    }
    void create_begin()
    {
        int num;
        cin>>num;
        while(num!=-1)
        {
            new_node= new node;
            new_node->value=num;
            new_node->next=start;
            start=new_node;
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
            {   new_node= new node;
                if(new_node==NULL)
                {
                    cout<<"Error";
                }
                else{
                new_node->value=num;
                new_node->next=start;
                start=new_node;
                save=new_node;
                }
            }
            else
            {
                new_node= new node;
                if(new_node==NULL)
                {
                    cout<<"Error";
                }
                else
                {
                new_node->value=num;
                new_node->next=save->next;
                save->next=new_node;
                save=new_node;
                }
            }
            cin>>num;
        }
    }
    void show()
    {
        cout<<endl;
        ptr=start;

        while(ptr!=NULL){
            cout<<ptr->value<<endl;
            ptr=ptr->next;
        }
    }
   void ins_begin()
    {
        struct node* new_node;
        int num;
        cin>>num;
        new_node=new node;
        new_node->value=num;
        new_node->next=start;
        start=new_node;
    }
    void ins_end()
    {
        struct node* new_node;
        int num;
        cin>>num;
        ptr=start;
          while(ptr!=NULL){
                save=ptr;
            ptr=ptr->next;
        }
         new_node=new node;
        new_node->value=num;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;
    }
        void ins_after()
    {
        int num,n;
        cin>>num>>n;
        ptr=start;
        while(ptr->value!=num)
        {  ptr=ptr->next;
            save=ptr;
        }
        new_node=new node;
        new_node->value=n;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;
    }
    void ins_before()
    {
        int num,n;
        cin>>num>>n;
        ptr=start;
        while(ptr->value!=num)
        {   save=ptr;
            ptr=ptr->next;

        }
        new_node=new node;
        new_node->value=n;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;

    }
    void ins_ss()
    {
        int num;
        cin>>num;
        ptr=start;
        while(ptr->value<num)
        {   save=ptr;
            ptr=ptr->next;

        }
          new_node=new node;
        new_node->value=num;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;

    }
    void del_begin()
    { struct node *temp;
        temp=start;
        start=temp -> next;
        temp -> next=NULL;
        delete temp;
    }
    void del_given()
    {
        int num;
        cout<<"Enter the number to delete"<<endl;
        struct node *previous;
        previous=NULL;
        ptr=start;
        while(ptr != NULL)
        {
            if (ptr -> value==num)
                break;
            previous=ptr;
            ptr=ptr -> next;
        }
        previous -> next=ptr -> next;
        ptr -> next= NULL;
        delete ptr;
    }
    void del_end()
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            save=ptr;
            ptr=ptr->next;
        }
        save->next=NULL;
        delete ptr;

    }
};

int main()
{
    LinkList obj;
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
        cout<<"3 to show the LinkList"<<endl;
        cin>>n;
    do
    {
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
                obj.ins_begin();
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
            case(3):
                obj.show();
                break;
        }
        cout<<"Please select one of the following options:"<<endl;
        cout<<"1 to Insert an element"<<endl;
        cout<<"2 to Delete an element"<<endl;
        cout<<"3 to show the LinkList"<<endl;
        cin>>n;
    }while(n);
}
