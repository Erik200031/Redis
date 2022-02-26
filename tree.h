#ifndef TREE_H
#define TREE_H

#include <iostream>

namespace myl
{
    template <typename T>
    class AVLtree
    {
    private:
        template <typename E>
        struct Node {
            T key;
            int height;
            Node<T> *left;
            Node<T> *right;
        };
    private:

        static int max(int a, int b) 
        {
            return (a > b) ? a : b;
        }

        static int height(Node<T>* root)
        {
            if (root == nullptr)
                return 0;
            return root->height;
        }

        static Node<T> *newNode(const T& key)
        {
            Node<T> *node = new Node<T>();
            node->key = key;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;
            return node;
        }

        static Node<T> *rightRotate(Node<T> *y)
        {
            Node<T> *x = y->left;
            Node<T> *T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;
            return x;
        }

        static Node<T> *leftRotate(Node<T> *x)
        {
            Node<T> *y = x->right;
            Node<T> *T2 = y->left;
            y->left = x;
            x->right = T2;
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;
            return y;
        }

        static int getBalanceFactor(Node<T> * root)
        {
            if (root == nullptr)
                return 0;
            return height(root->left) - height(root->right);
        }


        static Node<T> *insert(Node<T>* node,const T& key)
        {
            if (node == nullptr) {
                return newNode(key);
            }
            if (key < node->key) {
                node->left = insert(node->left, key);
            } else if (key > node->key) {
                node->right = insert(node->right, key);
            } else {
                return node;
            }

            node->height = 1 + max(height(node->left), height(node->right));
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1) {
                if (key < node->left->key) {
                    return rightRotate(node);
                } else if (key > node->left->key) {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (balanceFactor < -1) {
                if (key > node->right->key) {
                    return leftRotate(node);
                } else if (key < node->right->key) {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }
            return node;
        }
        static Node<T> *nodeWithMimumValue(Node<T> * node)
        {
            Node<T> *current = node;
            while (current->left != nullptr)
                current = current->left;
            return current;
        }
        static Node<T> *erase(Node<T>* node,const T& key)
        {
            if (node == nullptr) {
                return node;
            }
            if (key < node->key) {
                node->left = erase(node->left, key);
            } else if (key > node->key) {
                node->right = erase(node->right, key);
            } else {
                if ((node->left == nullptr) || (node->right == nullptr)) 
                {
                    Node<T> *temp = node->left ? node->left : node->right;
                    if (temp == nullptr) {
                        temp = node;
                        node = nullptr;
                    } else {
                        *node = *temp;
                    }
                    free(temp);
                } else {
                    Node<T> *temp = nodeWithMimumValue(node->right);
                    node->key = temp->key;
                    node->right = erase(node->right, temp->key);
                }
            }

            if (node == nullptr)
            {
                return node;
            }

            node->height = 1 + max(height(node->left), height(node->right));
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1) {
                if (getBalanceFactor(node->left) >= 0) {
                    return rightRotate(node);
                } else {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (balanceFactor < -1) {
                if (getBalanceFactor(node->right) <= 0) {
                    return leftRotate(node);
                } else {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }
            return node;
        }

        static void inorder(Node<T> * node)
        {
            if(node == nullptr) {
                return ;
            }
            inorder(node->left);
            std::cout << node->key <<" ";
            inorder(node->right);
        }

        static void preorder(Node<T> * node)
        {
            if(node == nullptr) {
                return ;
            }
            std::cout<< node->key <<" ";
            preorder(node->left);
            preorder(node->right);
        }

        static void postorder(Node<T> * node)
        {
            if(node == nullptr) {
                return ;
            }
            postorder(node->left);
            postorder(node->right);
            std::cout<< node->key << " ";
        }
    public:
        void insert(const T& val)
        {
            root = insert(root,val);
        }
        void erase(const T& val)
        {
            root = erase(root,val);
        }
        void inorder()
        {
            inorder(root);
        }
        void preorder()
        {
            preorder(root);
        }
        void postorder()
        {
            postorder(root);
        }
    private:
        Node<T> * root {nullptr};
    };
}


#endif