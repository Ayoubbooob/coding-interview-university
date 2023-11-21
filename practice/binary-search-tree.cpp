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

// This function is for determine if the three is Binary search(root >= left sub-tree && root < right sub-tree)
//there is a more better way is to see if the root include in a range - see video for more info


//TODO -- You have to correct this one : it returns every time true
bool isBinarySearchTree(BSTNode* root){
    if(root == NULL) return true;
    if(root->data >= findMax(root->left)
        && root->data < findMin(root->right)
    ) return true;

    return false;
}

//Delete a node 

BSTNode* deleteNode(BSTNode* root, int data){
    if(root == NULL) return root;
    //we need to search the node with date
    else if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else{
        //case 1: No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL){
            BSTNode* temp = root;
            root = root->left;
            delete temp;
        }

        else{
            int temp = findMin(root->right);
            root->data = temp;
            root->right = deleteNode(root->left, temp); //TODO-  need to be fixed, returns duplicate 
        }



    }
    return root;

}

int main(){
    
    // root = insertNode(root, 50);
    // root= insertNode(root, 10);
    // root= insertNode(root, 5);
    // root= insertNode(root, 80);
    // root= insertNode(root, 35);
    // root= insertNode(root, 2);
    // root= insertNode(root, 100);
    // root= insertNode(root, 589);
    // root= insertNode(root, 450);
    // root= insertNode(root, 226);
    // root= insertNode(root, -5);
    // root= insertNode(root, -120);
    // root= insertNode(root, -555);
    // root= insertNode(root, -24);
    // root= insertNode(root, -1);

    root = insertNode(root, 7);
    root= insertNode(root, 5);
    root= insertNode(root, 4);
    root= insertNode(root, 6);
    root= insertNode(root, 9);
    root= insertNode(root, 8);
    root= insertNode(root, 10);


    root=deleteNode(root, 4);
    root=deleteNode(root, 5);
    root=deleteNode(root, 9);



    showBST(root);

    cout << endl;

    cout << "Min : " << findMin(root) << endl;
    cout << "Max : " << findMax(root) << endl;


    cout << "The Tree Height is: " << findTreeHeight(root) << endl;


    cout << "Is this is tree a binary search tree : " << isBinarySearchTree(root) << endl ; 
    return 0;
}