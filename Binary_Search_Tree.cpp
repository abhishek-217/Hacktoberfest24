#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        this->val = v;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* InsertInBST(Node* root, int data){
    //Base Case

    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->val){
        //Insert at right

        root->right = InsertInBST(root->right, data);
    }else{
        root->left = InsertInBST(root->left, data);

    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = InsertInBST(root,data);
        cin>>data;
    }
}


void levelOTraverse(Node* root){

    if(root == NULL){
        return ;
    }
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }else{
            cout<<temp->val<<" ";

            if(temp->left){// 
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }


    }
}


void InOrder(Node* root){
    //BAse case 
    if(root == NULL){
        return;
    }
    
    InOrder(root->left);
    cout<<"Node is "<<root->val<<" ";
    InOrder(root->right);
      
}



void PreOrder(Node* root){
    //BAse case 
    if(root == NULL){
        return;
    }
    
    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
      
}



void PostOrder(Node* root){
    //BAse Case 
    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}

Node* MinVal(Node* root){

    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node* deleteFromBST(Node* root , int val){

    //Base Case
    if(root == NULL){
        return root;
    }

    if(root->val == val){
        //0 child

        if(root->left == NULL && root->right == NULL){

            delete root;
            return NULL;
        }

        //1 child

            //left child
            if(root->left != NULL && root->right == NULL){

                Node* temp = root->left;
                delete root;
                return temp;
            }

            //right child
            if(root->right != NULL && root->left == NULL){

                Node* temp = root->right;
                delete root;
                return temp;
            }

        //2 child

            if(root->left != NULL && root->right != NULL){
                int mini = MinVal(root->right) ->val;

                root->val = mini;
                root->right = deleteFromBST(root->right, mini);
                return root;
            }


    }else if(root->val < val){

        root->right = deleteFromBST(root->right, val);
        return root;

    }else{

        root->left = deleteFromBST(root->left, val);
        return root;

    }
}


int main(){

    Node* root = NULL;
    // 50 20 70 10 30 90 110 -1

    cout<<"Enter Data to create BST"<<endl;

    takeInput(root);

    cout<<"Printing BST"<<endl;
    levelOTraverse(root);

    cout<<"Deleting node from BST"<<endl;

    deleteFromBST(root, 20);
    cout<<"Printing BST"<<endl;
    levelOTraverse(root);


    return 0;

}



