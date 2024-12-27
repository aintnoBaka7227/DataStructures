#include <iostream>
#include <vector> 

class Node {
    private: 
    friend class BinaryTree; 
    int data; 
    Node *left, *right; 
    public: 
    Node(int data) : data(data), left(nullptr), right(nullptr) {}; 
}; 

class BinaryTree {
    private: 
    Node *root; 
    public:

    BinaryTree() : root(nullptr) {

    } 
    
    Node* insert(Node* root, int data) {
        if (!root) {
            root = new Node(data);
        }
        else {
            if (data > root->data) {
                root->right = insert(root->right, data);
            }
            else if (data < root->data) {
                root->left = insert(root->left, data);
            }
        }
        return root;
    }

    Node* max(Node* node) {
        Node* temp = node; 
        while (temp->right) {
            temp = temp->right; 
        }
        return temp; 
    }

    Node* remove(Node* root, int data) {
        if (!root) {
            return root; 
        }
        else {
            if (data > root->data) {
                root->right = remove(root->right, data); 
            }
            else if (data < root->data) {
                root->left = remove(root->left, data);
            }
            else {
                // one child or no child
                if (!root->left || !root->right) {
                    Node* temp = root->left ? root->left : root->right; 
                    if (!temp) {
                        root = nullptr; 
                    }
                    else {
                        *root = *temp; 
                    }
                    delete temp;
                }
                else {
                    Node* temp = max(root->left); 
                    root->data = temp->data; 
                    root->left = remove(root->left, temp->data);
                }
            }
        }
        return root; 
    }

    void pre_order(Node* root) {
        if (root) {
            std::cout << root->data << " "; 
            pre_order(root->left); 
            pre_order(root->right);
        }
    }

    void post_order(Node* root) {
        if (root) {
            post_order(root->left);
            post_order(root->right);
            std::cout << root->data << " ";
        }
    }

    void in_order(Node* root) {
        if (root) {
            in_order(root->left);
            std::cout << root->data << " ";
            in_order(root->right);
        }
    }

    void insert_data (int data) {
        root = insert(root, data);
    }

    void remove_data (int data) {
        root = remove(root, data);
    }

    void pre_order_traversal() {
        pre_order(root);
    }

    void post_order_traversal() {
        post_order(root);
    }

    void in_order_traversal() {
        in_order(root);
    }
};

int main() {

    BinaryTree test; 
    test.insert_data(5); 
    test.insert_data(1); 
    test.insert_data(3); 
    test.insert_data(4); 
    test.insert_data(6);
    test.insert_data(2);  
    test.pre_order_traversal();
    std::cout << std::endl; 
    test.post_order_traversal();

    return 0;
}