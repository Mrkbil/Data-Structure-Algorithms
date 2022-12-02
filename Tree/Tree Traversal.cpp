#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
    Node(int data)
    {
        this->data=data;
        left = right = NULL;
    }
};
typedef struct Node Node;

void InOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}
void PreOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}
//Tree
/*               25
               /    \
             /        \
            /          \
           /            \
          15             50
         /   \          /   \
        /     \        /     \
       10     22      35      70
      /  \   /  \    /  \    /  \
     4  12  18  24  31  44  66  90

In-Order Traversal: 4 10 12 15 18 22 24 25 31 35 44 50 66 70 90
Pre-Order Traversal: 25 15 10 4 12 22 18 24 50 35 31 44 70 66 90
Post-Order Traversal: 4 12 10 18 24 22 15 31 44 35 66 90 70 50 25
*/
int main()
{
    Node *root=new Node(25);
    root->left=new Node(15);
    root->right=new Node(50);
    root->left->left=new Node(10);
    root->left->right=new Node(22);
    root->right->left=new Node(35);
    root->right->right=new Node(70);
    root->left->left->left=new Node(4);
    root->left->left->right=new Node(12);
    root->left->right->left=new Node(18);
    root->left->right->right=new Node(24);
    root->right->left->left=new Node(31);
    root->right->left->right=new Node(44);
    root->right->right->left=new Node(66);
    root->right->right->right=new Node(90);
    cout<<"In-Order Traversal: ";
    InOrder(root);
    cout<<"\nPre-Order Traversal: ";
    PreOrder(root);
    cout<<"\nPost-Order Traversal: ";
    PostOrder(root);
}
