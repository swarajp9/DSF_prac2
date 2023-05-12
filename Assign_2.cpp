#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertbst(Node* root,int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    
    if (d>root->data)
    {
        root->right = insertbst(root->right,d);
    }
    else{
        root->left = insertbst(root->left,d);
    }
    return root;
}
void input(Node *&root){
    int data;
    cin>>data;
    while (data!=-1)
    {
        root = insertbst(root,data);
        cin>>data;
    }
    
}
void preorder(Node* &root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void LevelOrderTransversal(Node* &root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp ==NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }            
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }   
        }
    }
}

bool Search(Node* root,int d){
    if(root == NULL){
        return false;
    }
    if (root->data == d){
        return true;
    }
    if (root->data > d){
        return Search(root->left,d);
    }
    else{
        return Search(root->right,d);
    }
}

Node* deletebst(Node* root,int del){
    //  base
    if (root == NULL){
        return root;
    }
    
    if(root->data == del){

        // 0
        if(root->left == NULL && root->right == NULL){
            delete root;
            return root;
        }
        // 1 child 
        //left
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        
        
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data into bst : " << endl;
    input(root);

    cout<<"Printing"<<endl;
    LevelOrderTransversal(root);
    
    cout<<"Printing preorder"<<endl;
    preorder(root);

    cout<<"Search"<<endl;
    if(Search(root,10))
        cout<<"Yes";
    else
        cout<<"No";

}