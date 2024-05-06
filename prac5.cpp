#include<iostream>
using namespace std;
        
class thread
{   
    private:
        struct node
            {
                int data;
                node *left,*right;
                int lth,rth;
            };
    
    public:
        node *New,*root,*temp,*dummy;
        thread();
        void create();
        void insert(node*,node*);
        void inorder(node *,node *);
};

thread::thread()
{
    root=NULL;

}

void thread::create()
{
    New=new node;
    New->left=NULL;
    New->right=NULL;
    New->lth=0;
    New->rth=0;
    cout<<"Enter the element "<<endl;
    cin>>New->data;

    if(root==NULL)
    {
        root=New;
        dummy=new node;
        dummy->data=-999;
        dummy->left=root;
        root->left=dummy;
        root->right=dummy;
    }
    else
    {
        insert(root,New);
    }
}

void thread::insert(node *root,node *New)
{
    if(New->data < root->data)
    {
        if(root->lth==0)
        {
            New->left=root->left;
            New->right=root;
            root->left=New;
            root->lth=1;
        }

        else
        {
            insert(root->left,New);
        }
    }

    if(New->data > root->data)
    {
        if(root->rth==0)
        {
            New->right=root->right;
            New->left=root;
            root->rth=1;
            root->right=New;
        }
        else
        {
            insert(root->right,New);
        }
    }
}

void thread::inorder(node *temp,node *dummy)
{
    if(root==NULL)
    {
        cout<<"Tree is not created "<<endl;
        return;
    }
        
  do{
      while(temp->lth!=0){
          temp=temp->left;
      }
      cout<<temp->data;
      while(temp->rth==0){
          temp=temp->right;
          if(temp==dummy){
              return;
          }
          cout<<temp->data;
      }
      temp=temp->right;
  }while(temp!=dummy);
}







int main()
{
    thread t;
    int i;
    int flag=1;
    char ans;

    while(flag)
    {
        cout<<"Enter the operation to be performed on tree "<<endl;
        cout<<"1.Create 2.Display 3.Exit "<<endl;
        cin>>i;

        switch(i)
        {
            case 1:
            {
                do
                {
                    t.create();
                    cout<<"Want to enter more nodes(y/n) "<<endl;
                    cin>>ans;
                } while (ans=='y');
                break;

            }

            case 2:
            {
                cout<<"The tree is "<<endl;
                t.temp=t.root;
                t.inorder(t.temp,t.dummy);
                break;
            }

            case 3:
            {
                flag=0;
            }
            break;

            default:
            {
                cout<<"Enter the correct choice "<<endl;
            }

        }
    }

    return 0;
    
}