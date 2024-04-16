#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() : m_root(nullptr), m_size(0) {
        // implement the contructor here
    }

    ~BST() {
        // implement the destructor here
        clear();
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
        return remove(m_root, item);
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return find(m_root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree

        clearTree(m_root);
        m_size = 0;
        m_root = nullptr;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return m_size;
    }

    private:

    bool find(Node* root, T item) const {
    // implement find here
    // return true if item is in the subtree, false otherwise
    if (root == nullptr) {
        return false;
    }
    if (root->value == item) {
        return true;
    } else {
        
    }
    if (item < root->value) {
        return find(root->left, item);
    } else {
        return find(root->right, item);
    }
}  

    bool add(Node*& root, const T item) {
        if (root == nullptr) {
            root = new Node(item);
            m_size++;
            return true;
        }
        if (root->value == item) {
            return false;
        }

        if (item < root->value) {
            return add(root->left, item);
        } else {
            return add(root->right, item);
        }
    }

    bool remove(Node*& root, const T item) {
        
        if (root == nullptr) {
            return false;
        }

        if (root->value == item) {
            if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
            } else {
                Node* iop = get_inorder_predecessor(root);
                root->value = iop->value;
                remove(root->left, iop->value);
            }
            m_size--;
            return true;
        } else if (item < root->value) {
            return remove(root->left, item);
        } else {
            return remove (root->right, item);
        }
    }

    void clearTree(Node*& root) {
        if (root == nullptr) {
            return;
        }

        clearTree(root->left);
        clearTree(root->right);

        delete root;
    }

    Node* get_inorder_predecessor (Node* node ) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* m_root;
    size_t m_size;
};
