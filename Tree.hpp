#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include "TreeIterator.hpp"
#include "Complex.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <SFML/Graphics.hpp>

// Forward declaration for the general template
template<typename T, int k = 2>
class Tree;

template<typename T>
std::string to_string(const T& value) {
    return std::to_string(value);
}

// Forward declare the to_string function for Complex
inline std::string to_string(const Complex& c);

// Specialization for binary tree (k = 2)
template<typename T >
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
    
        void drawNode(sf::RenderWindow& window, sf::Font& font, TreeNode<T>* node, float x, float y, float xOffset, float yOffset) {
        if (!node) return;

        // Draw the node
        sf::CircleShape circle(30);  // Increase the size of the circle
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(x - 30, y - 30);  // Adjust the position to center the circle
        window.draw(circle);

        // Draw the value of the node
        sf::Text text(to_string(node->value), font, 10);  // Adjust font size if needed
        text.setFillColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2, textRect.height / 2);  // Center the text within the circle
        text.setPosition(x, y - 5);  // Adjust the position to center the text
        window.draw(text);

        // Draw lines to children and recursively draw them
        for (int i = 0; i < node->children.size(); ++i) {
            if (node->children[i]) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset))
                };
                window.draw(line, 2, sf::Lines);
                drawNode(window, font, node->children[i], x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset, xOffset / 2, yOffset);
            }
        }
    }

    void drawTree(sf::RenderWindow& window) {
        sf::Font font;
        if (!font.loadFromFile("Inter-Regular.otf")) {  // Ensure the path is correct
            std::cerr << "Failed to load font" << std::endl;
            return;
        }
        if (root) {
            drawNode(window, font, root, window.getSize().x / 2, 50, window.getSize().x / 4, 50);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Tree& tree) {
        // Create an SFML window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
        
        // Main loop to keep the window open and display the tree
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::Black);

            // Draw the tree
            tree.drawTree(window);
            window.display();
        }

        return os;
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

    void add_root(TreeNode<T>* root1) {
        root = root1;
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

    void drawNode(sf::RenderWindow& window, sf::Font& font, TreeNode<T>* node, float x, float y, float xOffset, float yOffset) {
        if (!node) return;

        // Draw the node
        sf::CircleShape circle(30);  // Increase the size of the circle
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(x - 30, y - 30);  // Adjust the position to center the circle
        window.draw(circle);

        // Draw the value of the node
        sf::Text text(to_string(node->value), font, 10);  // Adjust font size if needed
        text.setFillColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2, textRect.height / 2);  // Center the text within the circle
        text.setPosition(x, y - 5);  // Adjust the position to center the text
        window.draw(text);

        // Draw lines to children and recursively draw them
        for (int i = 0; i < node->children.size(); ++i) {
            if (node->children[i]) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset))
                };
                window.draw(line, 2, sf::Lines);
                drawNode(window, font, node->children[i], x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset, xOffset / 2, yOffset);
            }
        }
    }

    void drawTree(sf::RenderWindow& window) {
        sf::Font font;
        if (!font.loadFromFile("Inter-Regular.otf")) {  // Ensure the path is correct
            std::cerr << "Failed to load font" << std::endl;
            return;
        }
        if (root) {
            drawNode(window, font, root, window.getSize().x / 2, 50, window.getSize().x / 4, 50);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Tree& tree) {
        // Create an SFML window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        // Main loop to keep the window open and display the tree
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::Black);

            // Draw the tree
            tree.drawTree(window);
            window.display();
        }

        return os;
    }

    DFSIterator<T, k> begin_pre_order() { return DFSIterator<T, k>(root); }
    DFSIterator<T, k> end_pre_order() { return DFSIterator<T, k>(nullptr); }
    DFSIterator<T, k> begin_post_order() { return DFSIterator<T, k>(root); }
    DFSIterator<T, k> end_post_order() { return DFSIterator<T, k>(nullptr); }
    DFSIterator<T, k> begin_in_order() { return DFSIterator<T, k>(root); }
    DFSIterator<T, k> end_in_order() { return DFSIterator<T, k>(nullptr); }
    BFSIterator<T, k> begin_bfs_scan() { return BFSIterator<T, k>(root); }
    BFSIterator<T, k> end_bfs_scan() { return BFSIterator<T, k>(nullptr); }
    DFSIterator<T, k> begin_dfs_scan() { return DFSIterator<T, k>(root); }
    DFSIterator<T, k> end_dfs_scan() { return DFSIterator<T, k>(nullptr); }

private:
    void deleteTree(TreeNode<T>* node) {
        if (node) {
            for (auto child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
    }
    //   void drawTree(sf::RenderWindow& window) {
    //     sf::Font font;
    //     if (!font.loadFromFile("Inter-Regular.otf")) {  // Ensure the path is correct
    //         std::cerr << "Failed to load font" << std::endl;
    //         return;
    //     }
    //     if (root) {
    //         drawNode(window, font, root, window.getSize().x / 2, 50, window.getSize().x / 4, 50);
    //     }
    // }
    
  
     
    // void drawNode(sf::RenderWindow& window, sf::Font& font, TreeNode<T>* node, float x, float y, float xOffset, float yOffset) {
    //     if (!node) return;

    //     // Draw the node
    //     sf::CircleShape circle(20);
    //     circle.setFillColor(sf::Color::Blue);
    //     circle.setPosition(x - 20, y - 20);
    //     window.draw(circle);

    //     // Draw the value of the node
    //     sf::Text text(std::to_string(node->value), font, 20);
    //     text.setFillColor(sf::Color::White);
    //     text.setPosition(x - 10, y - 10);
    //     window.draw(text);

    //     // Draw lines to children and recursively draw them
    //     for (int i = 0; i < node->children.size(); ++i) {
    //         if (node->children[i]) {
    //             sf::Vertex line[] = {
    //                 sf::Vertex(sf::Vector2f(x, y)),
    //                 sf::Vertex(sf::Vector2f(x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset))
    //             };
    //             window.draw(line, 2, sf::Lines);
    //             drawNode(window, font, node->children[i], x - xOffset + 2 * xOffset * i / (node->children.size() - 1), y + yOffset, xOffset / 2, yOffset);
    //         }
    //     }
    // }
};

#endif // TREE_HPP