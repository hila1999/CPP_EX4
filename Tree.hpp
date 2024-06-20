#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include "TreeIterator.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

// Forward declaration for the general template
template<typename T, int k = 2>
class Tree;

// Specialization for binary tree (k = 2)
template<typename T>
class Tree<T, 2> {
public:
    using TreeNodeType = TreeNode<T>;
    TreeNodeType* root;

    Tree() : root(nullptr) {}
    ~Tree() { deleteTree(root); }

    void add_root(TreeNode<T>* root1) {
        
            root= root1;
        
    }

    void add_sub_node(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent->children.size() < 2) {
            parent->children.push_back(child);
        } else {
            throw std::overflow_error("Node already has maximum number of children");
        }
    }

    TreeNode<T>* getCurrentRoot() const {
        return root;
    }

    PreorderIterator<T, 2> begin_pre_order() {
        return PreorderIterator<T, 2>(root);
    }

    PreorderIterator<T, 2> end_pre_order() {
        return PreorderIterator<T, 2>(nullptr);
    }

    PostorderIterator<T, 2> begin_post_order() {
        return PostorderIterator<T, 2>(root);
    }

    PostorderIterator<T, 2> end_post_order() {
        return PostorderIterator<T, 2>(nullptr);
    }

    InorderIterator<T, 2> begin_in_order() {
        return InorderIterator<T, 2>(root);
    }

    InorderIterator<T, 2> end_in_order() {
        return InorderIterator<T, 2>(nullptr);
    }

    BFSIterator<T, 2> begin_bfs_scan() {
        return BFSIterator<T, 2>(root);
    }

    BFSIterator<T, 2> end_bfs_scan() {
        return BFSIterator<T, 2>(nullptr);
    }

    DFSIterator<T, 2> begin_dfs_scan() {
        return DFSIterator<T, 2>(root);
    }

    DFSIterator<T, 2> end_dfs_scan() {
        return DFSIterator<T, 2>(nullptr);
    }

private:
    void deleteTree(TreeNode<T>* node) {
        if (node) {
            for (auto child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
    }
};

template<typename T, int k>
class Tree {
public:
    TreeNode<T>* root;

    Tree() : root(nullptr) {}
    ~Tree() { deleteTree(root); }

    void add_root(T value) {
        root = new TreeNode<T>(value);
    }

    TreeNode<T>* getCurrentRoot() const {
        return root;
    }

    void add_sub_node(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent->children.size() < k) {
            parent->children.push_back(child);
        } else {
            throw std::runtime_error("Node already has maximum number of children");
        }
    }


    
    DFSIterator<T,k>  begin_pre_order() { return DFSIterator<T,k>(root); }
    DFSIterator<T,k> end_pre_order() { return  DFSIterator<T,k>(nullptr);  }
    DFSIterator<T,k>  begin_post_order() { return DFSIterator<T,k>(root); }
    DFSIterator<T,k> end_post_order() { return  DFSIterator<T,k>(nullptr); }
    DFSIterator<T,k>  begin_in_order() { return DFSIterator<T,k>(root); }
    DFSIterator<T,k> end_in_order() { return  DFSIterator<T,k>(nullptr);  }
    BFSIterator<T,k> begin_bfs_scan() { return BFSIterator<T,k>(root); }
    BFSIterator<T,k> end_bfs_scan() { return BFSIterator<T,k>(nullptr); }
    DFSIterator<T,k> begin_dfs_scan() { return DFSIterator<T,k>(root); }
    DFSIterator<T,k> end_dfs_scan() { return DFSIterator<T,k>(nullptr); }

private:
    void deleteTree(TreeNode<T>* node) {
        if (node) {
            for (auto child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
        }
};

#endif // TREE_HPP