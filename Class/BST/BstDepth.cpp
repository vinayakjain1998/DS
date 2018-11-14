#include <iostream>

using namespace std;

struct BST
{
    int info;
    BST *left;
    BST *right;
};
BST *root;
class binary
{
    BST *check,*ptr;
    int num;
public:
    binary()
    {
        root = NULL;
    }
    void add()
    {
        cout<<"\nEnter the number until -1 is entered\n";
        cin>>num;
        while(num != -1)
        {
            BST *new_node = new BST;
            new_node->info = num;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root == NULL)
            {
                root = new_node;
            }
            else
            {
                check = root;
                while(1)
                {
                    if(check->info<num)
                    {
                        if(check->right == NULL)
                        {
                            check->right=new_node;
                            cout<<"Parent is = "<<check->info<<endl;
                            break;
                        }
                        else
                        {
                            check=check->right;
                        }
                    }
                    else
                    {
                        if(check->left == NULL)
                        {
                            check->left = new_node;
                            cout<<"Parent is = "<<check->info<<endl;
                            break;
                        }
                        else
                        {
                            check=check->left;
                        }
                    }
                }
            }
            cout<<"\nEnter the number\n";
            cin>>num;
        }

    }

    void inorder(BST *node)
    {

        if(node == NULL)
        	return;
		inorder(node->left);
		cout<<node->info<<" ";
		inorder(node->right);
    }

    int maxdepth(BST *node)
    {
        if(node == NULL)
            return 0;
        else
        {
            int ldepth = maxdepth(node->left);
            int rdepth = maxdepth(node->right);

            if(ldepth>rdepth)
                return ldepth+1;
            else
                return rdepth+1;
        }
    }
};

int main()
{
    binary b1;
    int exit = 1;
    int number,num;
    b1.add();
    cout<<"\nThe inorder of tree is : ";
    b1.inorder(root);
    cout<<"\n";
    cout<<"Maximum depth of binary search tree : "<<b1.maxdepth(root);
}