// /**
//  * Demo app for Ex4
//  */
// #include <iostream>
// #include <string>
// #include "node.hpp"
// #include "tree.hpp"

#include "TreeNode.hpp"
#include "Tree.hpp"
#include <iostream>
using namespace std;

int main(){

   try {
        Tree<double> tree; 
        cout << "k: " << tree.get_k() << endl;
        tree.add_root(5.2);
        cout << "Root: " << tree.get_root() << endl;
        
        auto root = tree.getCurrentRoot();
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

        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();

        std::cout << "Preorder Traversal: ";
        for (; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        
        auto post_it = tree.begin_post_order();
        auto post_end = tree.end_post_order();

        std::cout << "Postorder Traversal: ";
        for (; post_it != post_end; ++post_it) {
            std::cout << *post_it << " ";
        }
        std::cout << std::endl;

        auto in_it = tree.begin_in_order();
        auto in_end = tree.end_in_order();

        std::cout << "Inorder Traversal: "<< endl;
        for (; in_it != in_end; ++in_it) {
            std::cout << *in_it << " ";
        }
        std::cout << std::endl;

        auto bfs_it = tree.begin_bfs_scan();
        auto bfs_end = tree.end_bfs_scan();

        std::cout << "BFS Traversal: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

        auto dfs_it = tree.begin_dfs_scan();
        auto dfs_end = tree.end_dfs_scan();

        std::cout << "DFS Traversal: " <<endl;
        for (; dfs_it != dfs_end; ++dfs_it) {
            std::cout << *dfs_it << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


//     Node<double> root_node = Node(1.1);
//     Tree<double> tree; // Binary tree that contains doubles.
//     tree.add_root(root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(root_node, n1);
//     tree.add_sub_node(root_node, n2);
//     tree.add_sub_node(n1, n3);
//     tree.add_sub_node(n1, n4);
//     tree.add_sub_node(n2, n5);
   
//     // The tree should look like:
//     /**
//      *       root = 1.1
//      *     /       \
//      *    1.2      1.3
//      *   /  \      /
//      *  1.4  1.5  1.6
//      */

//     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

//     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

//     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

//     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     for (auto node : tree)
//     {
//         cout << node.get_value() << endl;
//     } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     cout << tree; // Should print the graph using GUI.

//     Tree<double,3> three_ary_tree; // 3-ary tree.
//     three_ary_tree.add_root(root_node);
//     three_ary_tree.add_sub_node(root_node, n1);
//     three_ary_tree.add_sub_node(root_node, n2);
//     three_ary_tree.add_sub_node(root_node, n3);
//     three_ary_tree.add_sub_node(n1, n4);
//     three_ary_tree.add_sub_node(n2, n5);

//      // The tree should look like:
//     /**
//      *       root = 1.1
//      *     /      |     \
//      *    1.2    1.3    1.4
//      *   /        |
//      *  1.5      1.6
//      */
    
// }

