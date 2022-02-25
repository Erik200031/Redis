#include<iostream>
class Node {
public:

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    
    
    Node* insert(Node *root,int value){ 
    
    if (root == nullptr) {
        return new Node(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
        
    } else {
        root->left = insert(root->left, value);
    }

    return root;
    }

    void inorder(Node *root) {
        if(root == nullptr) {
            return ;
        }
        inorder(root->left);
        std::cout << root->data<<" ";
        inorder(root->right);
    }
    void preorder(Node * root) {
        if(root == nullptr) {
            return ;
        }
        std::cout<< root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node * root) {
        if(root == nullptr) {
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        std::cout<< root->data<<" ";
    }

    Node* deleter(Node *root,int key){ 
    if (root == nullptr) {
        return new Node(key);
    }
    if (key > root->data) {
        
        root->right = deleter(root->right, key);
        if(root->data == key) {
            delete root;
            root = nullptr;
        }

    } else {

        root->left = deleter(root->left, key);
        if(root->data == key) {
            delete root;
            root = nullptr;
        }

    }

    return root;
    }

private:

    int data;
    Node * left;
    Node * right;

};

int main()
{
    Node *root = new Node(10);
    root->insert(root,5);
    root->insert(root,3);
    root->insert(root,7);
    root->insert(root,15);    
    root->insert(root,13);
    root->insert(root,17);
    root->deleter(root,7);
    std::cout << "\nInorder: ";
    root->inorder(root);
    
    std::cout << "\nPostorder: ";
    root->postorder(root);
    
    std::cout << "\nPreorder: ";
    root->preorder(root);
        
    std::cout<<std::endl;
    return 0;
}
