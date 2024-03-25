#include <stdio.h>
#include <cmath>

class Node {

    public:

        int key;
        int height = 1;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int _key) { this->key = _key; }

};

class AVLTree {

    Node* right_rotate(Node* node) {

        //             y                                  x     
        //            / \       Right Rotation          /  \   
        //           x   T3     - - - - - - - >        T1   y  
        //          / \                                    / \   
        //         T1  T2                                T2  T3

        Node* y = node;
        Node* x = y->left;  
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = fmax( this->get_node_height(y->left), this->get_node_height(y->right) ) + 1;
        x->height = fmax( this->get_node_height(x->left), this->get_node_height(x->right) ) + 1;

        return x; // new root

    }

    Node* left_rotate(Node* node) {

        //       x            y
        //        \          / 
        //         y   ->   x
        //        /          \ 
        //      T2            T2

        Node* x = node;
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = fmax(this->get_node_height(x->left), this->get_node_height(x->right)) + 1;
        y->height = fmax(this->get_node_height(y->left), this->get_node_height(y->right)) + 1;

        return y;

    }

    int get_node_height(Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    int get_node_balance(Node* node) {
        return this->get_node_height(node->left) - this->get_node_height(node->right);
    }

    public:

        Node* root;

        Node* insert( int key, Node* from_node ) {
        
            if ( this->root == nullptr ) {
                this->root = new Node(key);
                return this->root;
            }

            if ( from_node == nullptr ) return new Node(key);

            if ( key < from_node->key ) {
                from_node->left = this->insert(key, from_node->left );
            }
            if ( key > from_node->key ) {
                from_node->right = this->insert(key, from_node->right );
            }
            if ( key == from_node->key ) return nullptr;

            from_node->height = 1 + fmax( this->get_node_height(from_node->right), this->get_node_height(from_node->left) );

            int balance = get_node_balance(from_node);

            // Left Left Case
            if ( balance > 1 && key < from_node->left->key ) {
                Node* result = this->right_rotate(from_node);
                if ( from_node == this->root ) this->root = result;
                return result;
            }
            // Right Right Case
            if ( balance < -1 && key > from_node->right->key ) {
                Node* result = this->left_rotate(from_node);
                if (from_node == this->root) this->root = result;
                return result;
            }
            // Left Right Case
            if ( balance > 1 && key > from_node->left->key ) {
                Node* result = this->left_rotate(from_node->left);
                from_node->left = this->right_rotate(from_node);
                if( from_node == this->root ) this->root = result;
                return result;
            }
            // Right Left Case
            if ( balance < -1 && key < from_node->right->key ) {
                Node* result = this->right_rotate(from_node->right);
                from_node->right = this->left_rotate(from_node);
                if( from_node == this->root ) this->root = result;
                return result;
            }

            return from_node;

        }

};

AVLTree* tree = new AVLTree();

int main() {
    
    // Test Cases For Left Rotation
    // tree->insert(20, tree->root );
    // tree->insert(16, tree->root );
    // tree->insert(12, tree->root );
    // tree->insert(8, tree->root );
    // tree->insert(4, tree->root );
    // tree->insert(2, tree->root );
    
    //Test Cases For Right Rotation
    tree->insert( 4, tree->root );
    tree->insert( 8, tree->root );
    tree->insert( 12, tree->root );


    return 0;

}