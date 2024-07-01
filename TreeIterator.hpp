#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP
//hila.shamir99@gmail.com
//314906983
#include "TreeNode.hpp"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
// Preorder iterator
template<typename T, int k>
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

    bool operator==(const PreorderIterator& other) const {
        return current == other.current;
    }

    PreorderIterator& operator++() {
        advance();
        return *this;
    }

    PreorderIterator &operator++(int) {
        PreorderIterator temp = *this;
        advance();
        return temp;
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

// Postorder iterator
template<typename T, int k>
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
    bool operator==(const PostorderIterator& other) const {
        return current == other.current;
    }

    T& operator*() const {
        return current->value;
    }

    PostorderIterator& operator++() {
        advance();
        return *this;
    }

    PostorderIterator &operator++(int) {
        PostorderIterator temp = *this;
        advance();
        return temp;
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

// Inorder iterator
template<typename T, int k>
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
    bool operator==(const InorderIterator& other) const {
        return current == other.current;
    }

    T& operator*() const {
        return current->value;
    }

    InorderIterator& operator++() {
        advance();
        return *this;
    }

    InorderIterator &operator++(int) {
        InorderIterator temp = *this;
        advance();
        return temp;
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

// BFS iterator
template<typename T, int k>
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
    bool operator==(const BFSIterator& other) const {
        return current == other.current;
    }
    T& operator*() const {
        return current->value;
    }

    BFSIterator& operator++() {
        advance();
        return *this;
    }

    TreeNode<T>* operator->() { return queue.front(); }

    BFSIterator &operator++(int) {
        BFSIterator temp = *this;
        advance();
        return temp;
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

// DFS iterator
template<typename T, int k>
class DFSIterator {
private:
    TreeNode<T>* current;
    std::stack<TreeNode<T>*> stack;

public:
    DFSIterator(TreeNode<T>* root) {
        if (root) stack.push(root);
        advance();
    }

    bool operator!=(const DFSIterator& other) const {
        return current != other.current;
    }
    bool operator==(const DFSIterator& other) const {
        return current == other.current;
    }
    T& operator*() const {
        return current->value;
    }
    
 
    DFSIterator& operator++() {
        advance();
        return *this;
    }

    DFSIterator &operator++(int) {
        DFSIterator temp = *this;
        advance();
        return temp;
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

// Iterator for the heap
template<typename T>
class HeapIterator : public std::iterator<std::input_iterator_tag, T> {
    const std::vector<T>* heap;
    size_t index;
public:
    HeapIterator(const std::vector<T>* heap, size_t index) : heap(heap), index(index) {}

    bool operator!=(const HeapIterator& other) const {
        return index != other.index;
    }

    const T& operator*() const {
        return (*heap)[index];
    }

    HeapIterator& operator++() {
        ++index;
        return *this;
    }
};

#endif // TREEITERATOR_HPP
