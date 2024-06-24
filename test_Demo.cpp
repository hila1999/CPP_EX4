
#include "TreeNode.hpp"
#include "TreeIterator.hpp"
#include "Tree.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>



void test_tree_traversals() {
    try {
        // Create a tree
        Tree<double> tree;
        
        auto root =new TreeNode<double>(5.2);
        tree.add_root(root);
        auto child1 = new TreeNode<double>(1.2);
        auto child2 = new TreeNode<double>(1.3);
        auto grandchild1 = new TreeNode<double>(1.4);
        auto grandchild2 = new TreeNode<double>(1.5);
        auto grandchild3 = new TreeNode<double>(1.6);

        tree.add_sub_node(root, child1);
        tree.add_sub_node(root, child2);
        tree.add_sub_node(child1, grandchild1);
        tree.add_sub_node(child1, grandchild2);
        tree.add_sub_node(child2, grandchild3);
        
        std::cout << tree;
        // Perform preorder traversal
        auto it = tree.begin_pre_order();
        std::cout << "a";
        auto end = tree.end_pre_order();
        std::vector<double> preorder_result;
                std::cout << "b";

        for (; it != end; ++it) {
            preorder_result.push_back(*it);
        }
        std::vector<double> expected_preorder = { 5.2, 1.2, 1.4, 1.5, 1.3, 1.6 };
        assert(preorder_result == expected_preorder);

        // Perform postorder traversal
        auto post_it = tree.begin_post_order();
        auto post_end = tree.end_post_order();
        std::vector<double> postorder_result;
        for (; post_it != post_end; ++post_it) {
            postorder_result.push_back(*post_it);
        }
        std::vector<double> expected_postorder = { 1.4, 1.5, 1.2, 1.6, 1.3, 5.2 };
        assert(postorder_result == expected_postorder);

        // Perform inorder traversal
        auto in_it = tree.begin_in_order();
        auto in_end = tree.end_in_order();
        std::vector<double> inorder_result;
        for (; in_it != in_end; ++in_it) {
            inorder_result.push_back(*in_it);
        }
        std::vector<double> expected_inorder = { 1.4, 1.2, 1.5, 5.2, 1.6, 1.3 };
        assert(inorder_result == expected_inorder);

        // Perform BFS traversal
        auto bfs_it = tree.begin_bfs_scan();
        auto bfs_end = tree.end_bfs_scan();
        std::vector<double> bfs_result;
        for (; bfs_it != bfs_end; ++bfs_it) {
            bfs_result.push_back(*bfs_it);
        }
        std::vector<double> expected_bfs = { 5.2, 1.2, 1.3, 1.4, 1.5, 1.6 };
        assert(bfs_result == expected_bfs);

        // Perform DFS traversal
        auto dfs_it = tree.begin_dfs_scan();
        auto dfs_end = tree.end_dfs_scan();
        std::vector<double> dfs_result;
        for (; dfs_it != dfs_end; ++dfs_it) {
            dfs_result.push_back(*dfs_it);
        }
        std::vector<double> expected_dfs = { 5.2, 1.2, 1.4, 1.5, 1.3, 1.6 };
        assert(dfs_result == expected_dfs);

        std::cout << "All tree traversal tests passed!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error in test: " << e.what() << std::endl;
    }
}


void test_3k_tree_traversals() {
    try {
          // Create a 3-K tree
            Tree<double, 3> tree;

            auto root = new TreeNode<double>(5.2); // Create root node as a pointer
            // Add root and some nodes
            tree.add_root(root);
        auto child1 = new TreeNode<double>(1.2);
        auto child2 = new TreeNode<double>(1.3);
        auto child3 = new TreeNode<double>(1.4);
        auto grandchild1 = new TreeNode<double>(1.5);
        auto grandchild2 = new TreeNode<double>(1.6);
        auto grandchild3 = new TreeNode<double>(1.7);
        auto grandchild4 = new TreeNode<double>(1.8);

        tree.add_sub_node(root, child1);
        tree.add_sub_node(root, child2);
        tree.add_sub_node(root, child3);
        tree.add_sub_node(child1, grandchild1);
        tree.add_sub_node(child1, grandchild2);
        tree.add_sub_node(child2, grandchild3);
        tree.add_sub_node(child3, grandchild4);
        std::cout << "Tree: "  << std::endl;
        
        // Perform preorder traversal
        std::cout << "Preorder : ";
                std::cout << tree;

        auto it = tree.begin_pre_order();
        std:: cout <<"a";
        auto end = tree.end_pre_order();
        std::cout << "b";
        std::cout << "Preorder Traversal: ";
        std::vector<double> preorder_result;
        for (; it != end; ++it) {
            preorder_result.push_back(*it);
           std::cout << *it << " ";
        }
        std::vector<double> expected_preorder = { 5.2, 1.2, 1.5, 1.6, 1.3, 1.7, 1.4,1.8};
        assert(preorder_result == expected_preorder);

        // Perform postorder traversal
        auto post_it = tree.begin_post_order();
        auto post_end = tree.end_post_order();
        std::vector<double> postorder_result;
        for (; post_it != post_end; ++post_it) {
            postorder_result.push_back(*post_it);
        }
        std::vector<double> expected_postorder = { 1.5, 1.6, 1.2, 1.7, 1.8, 1.3, 1.4, 5.2 };
        assert(postorder_result == expected_postorder);

        // Perform inorder traversal
        auto in_it = tree.begin_in_order();
        auto in_end = tree.end_in_order();
        std::vector<double> inorder_result;
        for (; in_it != in_end; ++in_it) {
            inorder_result.push_back(*in_it);
        }
        std::vector<double> expected_inorder = { 1.5, 1.2, 1.6, 5.2, 1.7, 1.3, 1.8, 1.4 };
        assert(inorder_result == expected_inorder);

        // Perform BFS traversal
        auto bfs_it = tree.begin_bfs_scan();
        auto bfs_end = tree.end_bfs_scan();
        std::vector<double> bfs_result;
        for (; bfs_it != bfs_end; ++bfs_it) {
            bfs_result.push_back(*bfs_it);
        }
        std::vector<double> expected_bfs = { 5.2, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8 };
        assert(bfs_result == expected_bfs);

        // Perform DFS traversal
        auto dfs_it = tree.begin_dfs_scan();
        auto dfs_end = tree.end_dfs_scan();
        std::vector<double> dfs_result;
        for (; dfs_it != dfs_end; ++dfs_it) {
            dfs_result.push_back(*dfs_it);
        }
        std::vector<double> expected_dfs = { 5.2, 1.2, 1.5, 1.6, 1.3, 1.7, 1.8, 1.4 };
        assert(dfs_result == expected_dfs);

        std::cout << "All 3-K tree traversal tests passed!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error in test: " << e.what() << std::endl;
    }
}

int main() {
     test_3k_tree_traversals();
    test_tree_traversals();
   
    return 0;
}