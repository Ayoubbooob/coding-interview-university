#include <bits/stdc++.h>

using namespace std;



typedef struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
}BSTNode;

BSTNode* root = NULL;


BSTNode* createNode(int data){
    BSTNode* newNode = new BSTNode();
    newNode->data = data;

    return newNode;
}


BSTNode* insertNode(BSTNode* root, int data){
    
    if(root == NULL){
        root = createNode(data);

    }else{
        if(data <= root->data) root->left = insertNode(root->left, data);
        else  root->right = insertNode(root->right, data);
    }

    return root;
}

//preOrder Traversal
void showBST(BSTNode* root){
    if(root == NULL){
        return;
    }else{
        cout << root->data << " ";
        showBST(root->left);
        showBST(root->right);
    }


}



//preOrder Traversal
int findMin(BSTNode* root){
    
    if(root == NULL) {
        
        cout << "Error : Empty Tree";
        return -1;

     }else if(root->left == NULL){
        return root->data;
     
     }

     return findMin(root->left);


}

int findMax(BSTNode* root){
     if(root == NULL) {
        
        cout << "Error : Empty Tree";
        return -1;

     } else if(root->right == NULL) return root->data;

   return findMax(root->right);

    }

int findTreeHeight(BSTNode* root){
    if(root == NULL){
        return -1;
    }

    return max(findTreeHeight(root->left), findTreeHeight(root->right)) + 1;
}

int main(){
    
    root = insertNode(root, 50);
    root= insertNode(root, 10);
    root= insertNode(root, 5);
    root= insertNode(root, 80);
    root= insertNode(root, 35);
    root= insertNode(root, 2);
    root= insertNode(root, 100);
    root= insertNode(root, 589);
    root= insertNode(root, 450);
    root= insertNode(root, 226);
    root= insertNode(root, -5);
    root= insertNode(root, -120);
    root= insertNode(root, -555);
    root= insertNode(root, -24);
    root= insertNode(root, -1);


    showBST(root);

    cout << endl;

    cout << "Min : " << findMin(root) << endl;
    cout << "Max : " << findMax(root) << endl;


    cout << "The Tree Height is: " << findTreeHeight(root) << endl;
    return 0;
}