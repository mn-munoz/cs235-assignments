#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<class T>
struct Node {
    T value;
    vector<Node*> children;
    
    Node(T value) : value(value), children() {}
    
    Node<T>* add(T item) {
        auto node = new Node<T>(item);
        children.push_back(node);
        return node;
    }
};

template<class T>
void print(Node<T>* const& node, string const& prefix) {
    
    cout << prefix << node->value << endl;
    
    for (auto child : node->children) {
        print(child, prefix + "  ");
    }
}

int main(){
    // make a tree
    Node<string>* home = new Node<string>("Home/");
    auto docs = home->add("Documents/");
    docs->add("cs235/");
    docs->add("personal/");
    auto down = home->add("Downloads/");
    down->add("cat videos/");
    down->add("tree-info.pdf");
    //print it
    print(home, "");


    return 0;
}