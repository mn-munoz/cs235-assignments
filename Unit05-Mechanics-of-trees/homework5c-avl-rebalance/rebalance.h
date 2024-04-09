#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int getHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

int getBalance(Node* root) {
    return (getHeight(root->right) - getHeight(root->left));
}

void updateHeight(Node* &root) {
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void promote_left(Node*& root) {
    // implement promote_left here
    Node* new_root = root->left;
    root->left = root->left->right;
    new_root->right = root;
    root = new_root;
    updateHeight(root->right);
    updateHeight(root);
}

void promote_right(Node*& root) {
    // implement promote_right here
    Node* new_root = root->right;
    root->right = root->right->left;
    new_root->left = root;
    root = new_root;
    updateHeight(root->left);
    updateHeight(root);
}

void rebalance(Node*& root) {
    // implement rebalance here

    //determine if node is left-heavy or right-heavy
    int balanceRoot = getBalance(root);

    //Left heavy
    if (balanceRoot <= -2) {
        int leftBalance = getBalance(root->left);
        if (leftBalance <= -1) { //LL imbalance
            promote_left(root);
        } else { // LR imbalance 
            promote_right(root->left);
            promote_left(root);
        }
    }

    //Right Heavy
    if(balanceRoot >= 2) {
        int rightBalance = getBalance(root->right);
        if (rightBalance >= 1) { //RR tree
            promote_right(root);
        } else { //RL tree
            promote_left(root->right);
            promote_right(root);
        }

    }
}
