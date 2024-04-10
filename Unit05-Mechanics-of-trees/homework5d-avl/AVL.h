#pragma once

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL(): m_root(nullptr), m_size(0) {
        // implement the contructor here

    }

    ~AVL() {
        // implement the destructor here
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return m_root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        return add(m_root, item);
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return findItem(m_root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return m_size;
    }

    private:

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

    // bsr add, remove, 
    bool add(Node* & node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            m_size++;
            return true;
        }
        if(node->value == item) {
            return false;
        }
        bool changed;
        if (item < node->value) {
            changed = add(node->left, item);
        } else {
            changed = add(node->right, item);
        }
        if (changed) {
            rebalance(node);
            updateHeight(node);
        }
        return changed;
    }
    // bool remove(Node*)

    bool findItem(const Node* root, const T item) const {
        if (root->value == item) {
            return true;
        } else if (root == nullptr){
            return false;
        } else if (root->value < item) {
            findItem(root->left, item);
        } else {
            findItem(root->right, item);
        }
    }

    Node* get_inorder_predecessor (Node* node ) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    size_t m_size;
    Node * m_root;

};
