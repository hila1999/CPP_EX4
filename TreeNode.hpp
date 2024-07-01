#ifndef TREENODE_HPP
#define TREENODE_HPP
//hila.shamir99@gmail.com
//314906983
#include <vector>
#include <iostream>
template<typename T>
class TreeNode {
public:
    T value;
    std::vector<TreeNode*> children;

    TreeNode(T val) : value(val) {}
    
    T get_value() const {
        return value;
    }
    
    void remove_children() {
        children.clear();
    }
};

#endif // TREENODE_HPP
