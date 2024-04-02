#include <stdio.h>

struct Node {

    int key;
    char color = 'R';
    Node* left = nullptr;
    Node* right = nullptr;

    Node (int data): key(data) {} 

};

class RedBlackTree {

    private:
        
        char get_node_color(Node* node) {
            return node == nullptr ? 'B' : node->color;
        }

        void invert_node_color(Node* node) {
            if( !node  ) return;
            node->color = node->color == 'B' ? 'R' : 'B';
        }

        void invert_node_and_children_color(Node* node) {
            this->invert_node_color(node);
            if ( node->left ) this->invert_node_color(node->left);
            if ( node->right ) this->invert_node_color(node->right);
        }

        Node* rotate_left(Node* root) {

            Node* x = root;
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;
            
            y->color = x->color;
            x->color = 'R';

            if ( root == this->root ) this->root = y;

            return y;

        }

        Node* rotate_right(Node* root) {

            Node* y = root;
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            x->color = y->color;
            y->color = 'R';

            if ( root == this->root ) this->root = x;

            return x;

        }

    public:

        Node* root;

        Node* find(int key, Node* node) {

            if ( this->root == nullptr ) return nullptr;

            if ( node->key == key ) return node;

            if ( node->left && key <= node->left->key ) {
                return this->find( key, node->left );
            }

            if ( node->right && key >= node->right->key ) {
                return this->find(key, node->right );
            }

            return nullptr;

        }

        Node* insert( int key, Node* root ) {

            if ( this->root == nullptr ) {
                 this->root = new Node(key);
                 this->root->color = 'B';
                 return this->root;
            }
            
            if ( root == nullptr ) {
                root = new Node(key);
                return root;
            }

            if ( key == root->key ) return nullptr;

            if ( key < root->key ) {
                root->left = insert(key, root->left);
            }
            if ( key > root->key ) {
                root->right = insert(key, root->right); 
            }
            
            // Fix Violations
            if ( get_node_color(root->right) == 'R' && get_node_color(root->left) == 'B' ) {
                root = rotate_left(root);
            }
            if ( get_node_color(root->left) == 'R' && get_node_color(root->left->left) == 'R' ) {
                root = rotate_right(root);
            }
            if ( get_node_color(root->left) == 'R' && get_node_color(root->right) == 'R' ) {
                invert_node_color(root);
                invert_node_color(root->left);
                invert_node_color(root->right);
            }

            this->root->color = 'B';

            return root;

        }

};

RedBlackTree* tree = new RedBlackTree();

int main() {

    tree->insert(50, tree->root);
    tree->insert(20, tree->root);
    tree->insert(85, tree->root);
    tree->insert(70, tree->root);
    tree->insert(30, tree->root);
    tree->insert(15, tree->root);
    tree->insert(21, tree->root);

    return 0;

}