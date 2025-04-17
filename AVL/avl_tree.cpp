#include <iostream>
#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // No duplicates

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        // Perform AVL rotations
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left) current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);

        // Rebalance
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            std::cout << root->key << " ";
            inOrder(root->right);
        }
    }

    int getSubTreeHeight(Node* node, int key) {
        if (!node) return -1;
        if (key < node->key)
            return getSubTreeHeight(node->left, key);
        else if (key > node->key)
            return getSubTreeHeight(node->right, key);
        else
            return node->height;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void printInOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    int getHeight(int key) {
        int h = getSubTreeHeight(root, key);
        if (h == -1)
            std::cout << "Key not found in tree." << std::endl;
        return h;
    }
};

int main() {
    AVLTree tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(15);
    tree.insert(70);
    tree.insert(50);
    tree.insert(100);
    tree.insert(80);

    std::cout << "In-order traversal: ";
    tree.printInOrder();

    std::cout << "Height of subtree rooted at 70: " << tree.getHeight(70) << std::endl;

    tree.remove(70);
    std::cout << "After deleting 70: ";
    tree.printInOrder();

    return 0;
}
