#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdexcept>



// Tree class definition
template<typename T>
class Tree {
private:
    TreeNode<T>* root;
    int k; // Maximum number of children

public:
    Tree(int k = 2) : root(nullptr), k(k) {}
    ~Tree() {
        deleteTree(root);
    }

    void add_root(T value) {
        if (!root) {
            root = new TreeNode<T>(value);
        } else {
            root->value = value;
        }
    }

    void add_sub_node(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent->children.size() < k) {
            parent->children.push_back(child);
        } else {
            throw std::overflow_error("Cannot add more children to this node");
        }
    }

    T get_root() const {
        if (!root) {
            throw std::runtime_error("Tree is empty");
        }
        return root->value;
    }

    TreeNode<T>* getCurrentRoot() const {
        return root;
    }

    int get_k() const {
        return k;
    }

    // Preorder iterator
    class PreorderIterator {
    private:
        TreeNode<T>* current;
        std::stack<TreeNode<T>*> stack;

    public:
        PreorderIterator(TreeNode<T>* root) : current(nullptr) {
            if (root) stack.push(root);
            advance();
        }

        bool operator!=(const PreorderIterator& other) const {
            return current != other.current;
        }

        T& operator*() const {
            return current->value;
        }

        PreorderIterator& operator++() {
            advance();
            return *this;
        }

    private:
        void advance() {
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
                for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                    stack.push(*it);
                }
            } else {
                current = nullptr;
            }
        }
    };

    PreorderIterator begin_pre_order() {
        return PreorderIterator(root);
    }

    PreorderIterator end_pre_order() {
        return PreorderIterator(nullptr);
    }

    // Post-order iterator
   class PostorderIterator {
private:
    TreeNode<T>* current;
    std::stack<TreeNode<T>*> stack;
    std::stack<TreeNode<T>*> visitStack;

public:
    PostorderIterator(TreeNode<T>* root) : current(nullptr) {
        if (root) {
            fillStack(root);
            advance();
        }
    }

    bool operator!=(const PostorderIterator& other) const {
        return current != other.current;
    }

    T& operator*() const {
        return current->value;
    }

    PostorderIterator& operator++() {
        advance();
        return *this;
    }

private:
    void advance() {
        if (!visitStack.empty()) {
            current = visitStack.top();
            visitStack.pop();
        } else {
            current = nullptr;
        }
    }

    void fillStack(TreeNode<T>* node) {
    if (!node) return;
    std::stack<TreeNode<T>*> tempStack;
    tempStack.push(node);
    while (!tempStack.empty()) {
        TreeNode<T>* n = tempStack.top();
        tempStack.pop();
        visitStack.push(n);
        for (auto it = n->children.begin(); it != n->children.end(); ++it) {
            tempStack.push(*it);
        }
    }
}

};


    PostorderIterator begin_post_order() {
        return PostorderIterator(root);
    }

    PostorderIterator end_post_order() {
        return PostorderIterator(nullptr);
    }

    // In-order iterator
    class InorderIterator {
    private:
        TreeNode<T>* current;
        std::stack<TreeNode<T>*> stack;

    public:
    InorderIterator(TreeNode<T>* root) : current(root) {
        while (current) {
            stack.push(current);
            current = current->children.empty() ? nullptr : current->children[0];
        }
        if (!stack.empty()) {
            current = stack.top();
            stack.pop();
        }
    }

        bool operator!=(const InorderIterator& other) const {
            return current != other.current;
        }

        T& operator*() const {
            return current->value;
        }

        InorderIterator& operator++() {
            advance();
            return *this;
        }

    private:
        void advance() {
        if (!current) return;
        
        if (!current->children.empty() && current->children.size() > 1) {
            TreeNode<T>* temp = current->children[1];
            while (temp) {
                stack.push(temp);
                temp = temp->children.empty() ? nullptr : temp->children[0];
            }
        }

        if (!stack.empty()) {
            current = stack.top();
            stack.pop();
        } else {
            current = nullptr;
        }
    }
    };

    InorderIterator begin_in_order() {
        return InorderIterator(root);
    }

    InorderIterator end_in_order() {
        return InorderIterator(nullptr);
    }

    // BFS iterator
    class BFSIterator {
    private:
        TreeNode<T>* current;
        std::queue<TreeNode<T>*> queue;

    public:
        BFSIterator(TreeNode<T>* root) : current(nullptr) {
            if (root) queue.push(root);
            advance();
        }

        bool operator!=(const BFSIterator& other) const {
            return current != other.current;
        }

        T& operator*() const {
            return current->value;
        }

        BFSIterator& operator++() {
            advance();
            return *this;
        }

    private:
        void advance() {
            if (!queue.empty()) {
                current = queue.front();
                queue.pop();
                for (auto child : current->children) {
                    queue.push(child);
                }
            } else {
                current = nullptr;
            }
        }
    };

    BFSIterator begin_bfs_scan() {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() {
        return BFSIterator(nullptr);
    }

    // DFS iterator
    class DFSIterator {
    private:
        TreeNode<T>* current;
        std::stack<TreeNode<T>*> stack;

    public:
        DFSIterator(TreeNode<T>* root) : current(nullptr) {
            if (root) stack.push(root);
            advance();
        }

        bool operator!=(const DFSIterator& other) const {
            return current != other.current;
        }

        T& operator*() const {
            return current->value;
        }

        DFSIterator& operator++() {
            advance();
            return *this;
        }

    private:
        void advance() {
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
                for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                    stack.push(*it);
                }
            } else {
                current = nullptr;
            }
        }
    };

    DFSIterator begin_dfs_scan() {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() {
        return DFSIterator(nullptr);
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

#endif // TREE_HPP
