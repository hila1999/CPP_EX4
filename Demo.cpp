#include <SFML/Graphics.hpp>
#include "TreeNode.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
//hila.shamir99@gmail.com
//314906983
 
int main() {

   
    // Create a Tree<double> and perform operations
    Tree<double> tree; 
        
    auto root =new TreeNode<double>(1.2);
    tree.add_root(root);
    
    // // auto root = tree.getCurrentRoot();
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


    auto it1 = tree.begin_pre_order();
    auto end1 = tree.end_pre_order();

    std::cout << "Preorder Traversal: ";
    for (; it1 != end1; ++it1) {
        std::cout << *it1 << " ";
    }
    std::cout << std::endl;

    auto post_it1 = tree.begin_post_order();
    auto post_end1 = tree.end_post_order();

    std::cout << "Postorder Traversal: ";
    for (; post_it1 != post_end1; ++post_it1) {
        std::cout << *post_it1 << " ";
    }
    std::cout << std::endl;

    auto in_it1 = tree.begin_in_order();
    auto in_end1 = tree.end_in_order();

    std::cout << "Inorder Traversal: "<< std::endl;
    for (; in_it1 != in_end1; ++in_it1) {
        std::cout << *in_it1 << " ";
    }
    std::cout << std::endl;

    auto bfs_it1 = tree.begin_bfs_scan();
    auto bfs_end1 = tree.end_bfs_scan();

    std::cout << "BFS Traversal: "<< std::endl;
    for (; bfs_it1 != bfs_end1; ++bfs_it1) {
        std::cout << *bfs_it1 << " ";
    }
    std::cout << std::endl;

    auto dfs_it1 = tree.begin_dfs_scan();
    auto dfs_end1 = tree.end_dfs_scan();

    std::cout << "DFS Traversal: " << std::endl;
    for (; dfs_it1 != dfs_end1; ++dfs_it1) {
        std::cout << *dfs_it1 << " ";
    }
    std::cout << std::endl;
    // std::cout << tree;
    

      // Transform the binary tree to a minimum heap and get iterators
    auto heapIterators = tree.myHeap();
    auto heapBegin = heapIterators.first;
    auto heapEnd = heapIterators.second;

    // Print the elements of the heap
    std::cout << "Heap elements in order: ";
    for (auto it = heapBegin; it != heapEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

  // Create a Tree<int, 3> and perform operations
    std::cout << "Tree with 3 children" << std::endl;
    Tree<int, 3> tree1;
    auto root1= new TreeNode<int>(1);
    tree1.add_root(root1);
//     // auto root1 = tree1.getCurrentRoot();
//     std::cout << "Root: " << root1->value << std::endl;

    auto child1_int = new TreeNode<int>(2); 
    std::cout << "Child1: " << child1_int->value << std::endl;
    auto child2_int = new TreeNode<int>(3);
    auto child3_int = new TreeNode<int>(4);

    tree1.add_sub_node(root1, child1_int);
    tree1.add_sub_node(root1, child2_int);
    tree1.add_sub_node(root1, child3_int);

    auto grandchild1_int = new TreeNode<int>(5);
    auto grandchild2_int = new TreeNode<int>(6);

    tree1.add_sub_node(child1_int, grandchild1_int);
    tree1.add_sub_node(child1_int, grandchild2_int);

    auto grandchild3_int = new TreeNode<int>(7);
    auto grandchild4_int = new TreeNode<int>(8);

    tree1.add_sub_node(child2_int, grandchild3_int);
    tree1.add_sub_node(child2_int, grandchild4_int);

    auto grandchild5_int = new TreeNode<int>(9);
    auto grandchild6_int = new TreeNode<int>(10);

    tree1.add_sub_node(child3_int, grandchild5_int);
    tree1.add_sub_node(child3_int, grandchild6_int);

    std::cout << "Tree: "  << std::endl;

    auto it2 = tree1.begin_pre_order();
    auto end2 = tree1.end_pre_order();

    std::cout << "Preorder Traversal: ";
    for (; it2 != end2; ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;

    auto post_it2 = tree1.begin_post_order();
    auto post_end2 = tree1.end_post_order();

    std::cout << "Postorder Traversal: ";
    for (; post_it2 != post_end2; ++post_it2) {
        std::cout << *post_it2 << " ";
    }
    std::cout << std::endl;

    auto in_it2 = tree1.begin_in_order();
    auto in_end2 = tree1.end_in_order();

    std::cout << "Inorder Traversal: "<< std::endl;
    for (; in_it2 != in_end2; ++in_it2) {
        std::cout << *in_it2 << " ";
    }
    std::cout << std::endl;

    auto bfs_it2 = tree1.begin_bfs_scan();
    auto bfs_end2 = tree1.end_bfs_scan();

    std::cout << "BFS Traversal: "<< std::endl;
    for (; bfs_it2 != bfs_end2; ++bfs_it2) {
        std::cout << *bfs_it2 << " ";
    }
    std::cout << std::endl;

    auto dfs_it2 = tree1.begin_dfs_scan();
    auto dfs_end2 = tree1.end_dfs_scan();

    std::cout << "DFS Traversal: " << std::endl;
    for (; dfs_it2 != dfs_end2; ++dfs_it2) {
        std::cout << *dfs_it2 << " ";
    }
    std::cout << std::endl;

    // std::cout << tree1;








Tree<Complex,3> tree3; // יצירת עץ עם מספר ילדים מרבי של 3

auto root3 = new TreeNode<Complex>(Complex(5.2, 3.1));
tree3.add_root(root3);

tree3.add_sub_node(root3, new TreeNode<Complex>(Complex(1.2, 0.5)));
tree3.add_sub_node(root3, new TreeNode<Complex>(Complex(1.3, 0.7)));
tree3.add_sub_node(root3, new TreeNode<Complex>(Complex(1.4, 0.9)));
tree3.add_sub_node(root3->children[0], new TreeNode<Complex>(Complex(1.4, 0.9)));
tree3.add_sub_node(root3->children[0], new TreeNode<Complex>(Complex(1.5, 1.1)));
tree3.add_sub_node(root3->children[0], new TreeNode<Complex>(Complex(1.5, 1.1)));
// tree3.add_sub_node(root3->children[1], new TreeNode<Complex>(Complex(1.6, 1.3)));
tree3.add_sub_node(root3->children[1], new TreeNode<Complex>(Complex(1.7, 1.5)));
tree3.add_sub_node(root3->children[1], new TreeNode<Complex>(Complex(1.8, 1.7)));

std::cout << "Preorder Traversal: ";
auto pre_it3 = tree3.begin_pre_order();
auto pre_end3 = tree3.end_pre_order();
for (; pre_it3 != pre_end3; ++pre_it3) {
    std::cout << *pre_it3 << " ";
}
std::cout << std::endl;

  auto post_it3 = tree3.begin_post_order();
    auto post_end3 = tree3.end_post_order();

    std::cout << "Postorder Traversal: ";
    for (; post_it3 != post_end3; ++post_it3) {
        std::cout << *post_it3 << " ";
    }
    std::cout << std::endl;


     auto bfs_it3 = tree3.begin_bfs_scan();
    auto bfs_end3 = tree3.end_bfs_scan();

    std::cout << "BFS Traversal: "<< std::endl;
    for (; bfs_it3 != bfs_end3; ++bfs_it3) {
        std::cout << *bfs_it3 << " ";
    }
    std::cout << std::endl;

    auto dfs_it3 = tree3.begin_dfs_scan();
    auto dfs_end3 = tree3.end_dfs_scan();

    std::cout << "DFS Traversal: " << std::endl;
    for (; dfs_it3 != dfs_end3; ++dfs_it3) {
        std::cout << *dfs_it3 << " ";
    }
    std::cout << std::endl;
    
//  std::cout << tree3;



    return 0;
}