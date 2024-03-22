#include <stdio.h>

struct Node {
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree {

    public:

        Node* root = nullptr;

        BinarySearchTree( ): root(nullptr) { }

        BinarySearchTree( int key ): root(new Node{ key, nullptr, nullptr }) { }

        Node* insert( int key, Node* from_node = nullptr ) {

            Node* newNode = new Node { key };

            if ( this->root == nullptr ) {
                this->root = newNode;
                return this->root;
            }

            if ( from_node == nullptr ) {
                return newNode;
            }

            if ( key < from_node->key ) {
                from_node->left = this->insert(key, from_node->left);
            }

            if ( key > from_node->key ) {
                from_node->right = this->insert(key, from_node->right);
            }

            return from_node;

        }

};

int main() {

    BinarySearchTree* bst = new BinarySearchTree();
    
    bst->insert(2);
    bst->insert(1, bst->root);
    bst->insert(3, bst->root);
    bst->insert(4, bst->root);

    return 0;
}