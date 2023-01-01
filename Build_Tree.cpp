#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void print(Node*root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}

Node* BuildTree(Node* root)
{
  cout<<"Enter the data: " << endl;
  int data;
  cin>>data;
  root = new Node(data);
  if(data == -1)
  {
    return NULL;
  }

  cout <<"Enter data for inserting in left of " << data << endl;
  root->left = BuildTree(root->left);
  cout <<"Enter data for inserting in right of " << data << endl;
  root->right = BuildTree(root->right);
  return root;

}

void LevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);//separator if u want it to be in tree structure than use separator

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {//puarana wala level complete ho gya hai isliye hum next line m ja rahe h
            cout << endl;// apne ko wapas chk karna honga ki kahi apni queue bhari hui nhi h na agar ha toh apn eko null dalna honga as a separator
            if(! q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }  
}

void inorderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data <<" ";
    inorderTraversal(root->right);
}

void postorderTraversal (Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data <<" ";
}

void preorderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data <<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    // print(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Printing the LevelOrder Traversal of the Tree: "<< endl;
    LevelOrderTraversal(root);
    cout <<"Inorder Traversal is :";
    inorderTraversal(root);
    cout << endl <<"Postorder Traversal is :";
    postorderTraversal(root);
    cout << endl <<"Preorder Traversal is :";
    preorderTraversal(root);
    return 0;
}