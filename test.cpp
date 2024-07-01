#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Tree.hpp"
#include "TreeNode.hpp"
#include "Complex.hpp"
#include <vector>
//hila.shamir99@gmail.com
//314906983
// Test case for Tree<double>
TEST_CASE("Tree Traversal Tests - Double Type") {
    Tree<double> tree_double;
    auto root_double = new TreeNode<double>(1.2);
    tree_double.add_root(root_double);
    tree_double.add_sub_node(root_double, new TreeNode<double>(2.3));
    tree_double.add_sub_node(root_double, new TreeNode<double>(3.4));

    auto child1 = tree_double.getCurrentRoot()->children[0];
    tree_double.add_sub_node(child1, new TreeNode<double>(5.6));
    tree_double.add_sub_node(child1, new TreeNode<double>(6.7));

    auto child2 = tree_double.getCurrentRoot()->children[1];
    tree_double.add_sub_node(child2, new TreeNode<double>(7.8));


    
        std::vector<double> expected = {1.2, 2.3, 5.6, 6.7, 3.4, 7.8};
        std::vector<double> actual;
        for (auto it = tree_double.begin_pre_order(); it != tree_double.end_pre_order(); ++it) {
            actual.push_back(*it);
        }
        REQUIRE(actual == expected);

        std::vector<double> expected1 = {5.6, 6.7, 2.3, 7.8, 3.4, 1.2};
        std::vector<double> actual1;
        for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it) {
            actual1.push_back(*it);
        }
        REQUIRE(actual1 == expected1);

        std::vector<double> expected2 = {5.6, 2.3, 6.7, 1.2, 7.8, 3.4};
        std::vector<double> actual2;
        for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it) {
            actual2.push_back(*it);
        }
        REQUIRE(actual2 == expected2);

        std::vector<double> expected3 = {1.2, 2.3, 3.4, 5.6, 6.7, 7.8};
        std::vector<double> actual3;
        for (auto it = tree_double.begin_bfs_scan(); it != tree_double.end_bfs_scan(); ++it) {
            actual3.push_back(*it);
        }
        REQUIRE(actual3 == expected3);

        std::vector<double> expected4 = {1.2, 2.3, 5.6, 6.7, 3.4, 7.8};
        std::vector<double> actual4;
        for (auto it = tree_double.begin_dfs_scan(); it != tree_double.end_dfs_scan(); ++it) {
            actual4.push_back(*it);
        }
        REQUIRE(actual4 == expected4);


}

// Test case for Tree<int, 3>
TEST_CASE("Tree Traversal Tests - Int Type") {
    Tree<int,3> tree_int;
    auto root_int = new TreeNode<int>(1);
    tree_int.add_root(root_int);
    tree_int.add_sub_node(root_int, new TreeNode<int>(2));
    tree_int.add_sub_node(root_int, new TreeNode<int>(3));
    tree_int.add_sub_node(root_int, new TreeNode<int>(4));

    auto child1 = tree_int.getCurrentRoot()->children[0];
    tree_int.add_sub_node(child1, new TreeNode<int>(5));
    tree_int.add_sub_node(child1, new TreeNode<int>(6));

    auto child2 = tree_int.getCurrentRoot()->children[1];
    tree_int.add_sub_node(child2, new TreeNode<int>(7));
    std::vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
    std::vector<int> actual;
    for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it) {
        actual.push_back(*it);
    }
    REQUIRE(actual == expected);
    // std::cout <<tree_int;

    std::vector<int> expected1 = {1, 2, 5, 6, 3, 7, 4};
    std::vector<int> actual1;
    for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it) {
        actual1.push_back(*it);
    }
    REQUIRE(actual1 == expected1);

    std::vector<int> expected2 = {1, 2, 5, 6, 3, 7, 4};
    std::vector<int> actual2;
    for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it) {
        actual2.push_back(*it);
    }
    REQUIRE(actual2 == expected2);

    std::vector<int> expected3 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> actual3;
    for (auto it = tree_int.begin_bfs_scan(); it != tree_int.end_bfs_scan(); ++it) {
        actual3.push_back(*it);
    }
    REQUIRE(actual3 == expected3);

}
TEST_CASE("Tree Traversal Tests - Complex Type") {
    Tree<Complex,4> tree_complex;
    auto root_complex = new TreeNode<Complex>(Complex(5.2, 3.1));
    tree_complex.add_root(root_complex);
    tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.2, 0.5)));
    tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.3, 0.7)));
    tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.4, 0.9)));
    tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.5, 1.1)));

    auto child1 = root_complex->children[0];
    tree_complex.add_sub_node(child1, new TreeNode<Complex>(Complex(1.6, 1.3)));
    tree_complex.add_sub_node(child1, new TreeNode<Complex>(Complex(1.7, 1.5)));

    auto child2 = root_complex->children[1];
    tree_complex.add_sub_node(child2, new TreeNode<Complex>(Complex(1.8, 1.7)));
    // std::cout << tree_complex;
    std::vector<Complex> expected = {
        Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
        Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
    };
    std::vector<Complex> actual;
    for (auto it = tree_complex.begin_pre_order(); it != tree_complex.end_pre_order(); ++it) {
        actual.push_back(*it);
    }
    REQUIRE(actual == expected);

   std::vector<Complex> expected1 = {
        Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
        Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
    };
    std::vector<Complex> actual1;
    for (auto it = tree_complex.begin_post_order(); it != tree_complex.end_post_order(); ++it) {
        actual1.push_back(*it);
    }
    REQUIRE(actual1 == expected1);

    std::vector<Complex> expected2 = {
        Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.3, 0.7), Complex(1.4, 0.9),
        Complex(1.5, 1.1), Complex(1.6, 1.3), Complex(1.7, 1.5), Complex(1.8, 1.7)
    };
    std::vector<Complex> actual2;
    for (auto it = tree_complex.begin_bfs_scan(); it != tree_complex.end_bfs_scan(); ++it) {
        actual2.push_back(*it);
    }
    REQUIRE(actual2 == expected2);

    std::vector<Complex> expected3 = {
        Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
        Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
    };
    std::vector<Complex> actual3;
    for (auto it = tree_complex.begin_dfs_scan(); it != tree_complex.end_dfs_scan(); ++it) {
        actual3.push_back(*it);
    }
    REQUIRE(actual3 == expected3);
}

TEST_CASE("Single node tree iterators work correctly"){
    Tree<int> tree;
    auto root = new TreeNode<int>(1);
    tree.add_root(root);
    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();
    REQUIRE(it != end);
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(it == end);
    auto it1 = tree.begin_post_order();
    auto end1 = tree.end_post_order();
    REQUIRE(it1 != end1);
    REQUIRE(*it1 == 1);
    ++it1;
    REQUIRE(it1 == end1);
    auto it2 = tree.begin_in_order();
    auto end2 = tree.end_in_order();
    REQUIRE(it2 != end2);
    REQUIRE(*it2 == 1);
    ++it2;
    REQUIRE(it2 == end2);
    auto it3 = tree.begin_bfs_scan();
    auto end3 = tree.end_bfs_scan();
    REQUIRE(it3 != end3);
    REQUIRE(*it3 == 1);
    ++it3;
    REQUIRE(it3 == end3);
    auto it4 = tree.begin_dfs_scan();
    auto end4 = tree.end_dfs_scan();
    REQUIRE(it4 != end4);
    REQUIRE(*it4 == 1);
    ++it4;
    REQUIRE(it4 == end4);
}


   TEST_CASE("Empty tree iterators work correctly"){
    Tree<int> tree;
    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();
    REQUIRE(it == end);
    auto it1 = tree.begin_post_order();
    auto end1 = tree.end_post_order();
    REQUIRE(it1 == end1);
    auto it2 = tree.begin_in_order();
    auto end2 = tree.end_in_order();
    REQUIRE(it2 == end2);
    auto it3 = tree.begin_bfs_scan();
    auto end3 = tree.end_bfs_scan();
    REQUIRE(it3 == end3);
    auto it4 = tree.begin_dfs_scan();
    auto end4 = tree.end_dfs_scan();
    REQUIRE(it4 == end4);
   }
   TEST_CASE("Tree with one node iterators work correctly"){
    Tree<int> tree;
    auto root = new TreeNode<int>(1);
    tree.add_root(root);
    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();
    REQUIRE(it != end);
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(it == end);
    auto it1 = tree.begin_post_order();
    auto end1 = tree.end_post_order();
    REQUIRE(it1 != end1);
    REQUIRE(*it1 == 1);
    ++it1;
    REQUIRE(it1 == end1);
    auto it2 = tree.begin_in_order();
    auto end2 = tree.end_in_order();
    REQUIRE(it2 != end2);
    REQUIRE(*it2 == 1);
    ++it2;
    REQUIRE(it2 == end2);
    auto it3 = tree.begin_bfs_scan();
    auto end3 = tree.end_bfs_scan();
    REQUIRE(it3 != end3);
    REQUIRE(*it3 == 1);
    ++it3;
    REQUIRE(it3 == end3);
    auto it4 = tree.begin_dfs_scan();
    auto end4 = tree.end_dfs_scan();
    REQUIRE(it4 != end4);
    REQUIRE(*it4 == 1);
    ++it4;
    REQUIRE(it4 == end4);
   }
   TEST_CASE("Tree with duplicate values iterators work correctly"){
    Tree<int,3> tree;
    auto root = new TreeNode<int>(1);
    tree.add_root(root);
    tree.add_sub_node(root, new TreeNode<int>(1));
    tree.add_sub_node(root, new TreeNode<int>(2));
    tree.add_sub_node(root, new TreeNode<int>(1));
    

     std::vector<int> expected_pre_order = {1, 1, 2, 1};
    std::vector<int> actual_pre_order;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        actual_pre_order.push_back(*it);
    }
    REQUIRE(actual_pre_order == expected_pre_order);
   }
   TEST_CASE("Tree with negative values iterators work correctly"){
    Tree<int,37> tree;
    auto root = new TreeNode<int>(-1);
    tree.add_root(root);
    tree.add_sub_node(root, new TreeNode<int>(-2));
    tree.add_sub_node(root, new TreeNode<int>(-3));
    tree.add_sub_node(root, new TreeNode<int>(-4));
    tree.add_sub_node(root, new TreeNode<int>(-5));
    tree.add_sub_node(root, new TreeNode<int>(-6));
    tree.add_sub_node(root, new TreeNode<int>(-7));
    tree.add_sub_node(root, new TreeNode<int>(-8));
    tree.add_sub_node(root, new TreeNode<int>(-9));
    tree.add_sub_node(root, new TreeNode<int>(-10));
    tree.add_sub_node(root, new TreeNode<int>(-11));
    tree.add_sub_node(root, new TreeNode<int>(-12));
    tree.add_sub_node(root, new TreeNode<int>(-13));
    tree.add_sub_node(root, new TreeNode<int>(-14));
    tree.add_sub_node(root, new TreeNode<int>(-15));
    tree.add_sub_node(root, new TreeNode<int>(-16));
    tree.add_sub_node(root, new TreeNode<int>(-17));
    tree.add_sub_node(root, new TreeNode<int>(-18));
    tree.add_sub_node(root, new TreeNode<int>(-19));
    tree.add_sub_node(root, new TreeNode<int>(-20));
    tree.add_sub_node(root, new TreeNode<int>(-21));
    tree.add_sub_node(root, new TreeNode<int>(-22));
    tree.add_sub_node(root, new TreeNode<int>(-23));
    tree.add_sub_node(root, new TreeNode<int>(-24));
    tree.add_sub_node(root, new TreeNode<int>(-25));
    tree.add_sub_node(root, new TreeNode<int>(-26));
    tree.add_sub_node(root, new TreeNode<int>(-27));
    tree.add_sub_node(root, new TreeNode<int>(-28));
    tree.add_sub_node(root, new TreeNode<int>(-29));
    tree.add_sub_node(root, new TreeNode<int>(-30));
    tree.add_sub_node(root, new TreeNode<int>(-31));
    tree.add_sub_node(root, new TreeNode<int>(-32));
    tree.add_sub_node(root, new TreeNode<int>(-33));
    tree.add_sub_node(root, new TreeNode<int>(-34));
    tree.add_sub_node(root, new TreeNode<int>(-35));
    tree.add_sub_node(root, new TreeNode<int>(-36));
     
    std::vector<int> expected_pre_order = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31, -32, -33, -34, -35, -36};
    std::vector<int> actual_dfs;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        actual_dfs.push_back(*it);
    }
    REQUIRE(actual_dfs == expected_pre_order);
   }
   TEST_CASE("Adding sub node to a full node throws error"){
    Tree<int,3> tree;
    auto root = new TreeNode<int>(1);
    tree.add_root(root);
    tree.add_sub_node(root, new TreeNode<int>(2));
    tree.add_sub_node(root, new TreeNode<int>(3));
    tree.add_sub_node(root, new TreeNode<int>(4));
    tree.add_sub_node(root->children[0], new TreeNode<int>(5));
    tree.add_sub_node(root->children[0], new TreeNode<int>(6));
    tree.add_sub_node(root->children[0], new TreeNode<int>(7));
    REQUIRE_THROWS(tree.add_sub_node(root->children[0], new TreeNode<int>(8)));
   }
   TEST_CASE("Tree with strings iterators work correctly"){
    Tree<std::string,15> tree;
    auto root = new TreeNode<std::string>("root");
    tree.add_root(root);
    tree.add_sub_node(root, new TreeNode<std::string>("child1"));
    tree.add_sub_node(root, new TreeNode<std::string>("child2"));
    tree.add_sub_node(root->children[0], new TreeNode<std::string>("child3"));
    tree.add_sub_node(root->children[0], new TreeNode<std::string>("child4"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child5"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child6"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child7"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child8"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child9"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child10"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child11"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child12"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child13"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child14"));
    tree.add_sub_node(root->children[1], new TreeNode<std::string>("child15"));
    
    std::vector<std::string> expected_pre_order = {"root", "child1", "child3", "child4", "child2", "child5", "child6", "child7", "child8", "child9", "child10", "child11", "child12", "child13", "child14", "child15"};
    std::vector<std::string> actual_pre_order;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        actual_pre_order.push_back(*it);
    }
    REQUIRE(actual_pre_order == expected_pre_order);
    // std::cout << tree;
   }
   TEST_CASE("Heap functionality"){
    Tree<int> tree;
    auto root = new TreeNode<int>(1);
    tree.add_root(root);
    tree.add_sub_node(root, new TreeNode<int>(2));
    tree.add_sub_node(root, new TreeNode<int>(3));
    tree.add_sub_node(root->children[0], new TreeNode<int>(4));
    tree.add_sub_node(root->children[0], new TreeNode<int>(5));
    tree.add_sub_node(root->children[1], new TreeNode<int>(6));
    tree.add_sub_node(root->children[1], new TreeNode<int>(7));
    
    
    std::cout << "Calling myHeap()" << std::endl;
    auto heapIterators = tree.myHeap();
    auto heapBegin = heapIterators.first;
    auto heapEnd = heapIterators.second;
    std::vector<int> expected_heap = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> actual_heap;
    for (auto it = heapBegin; it != heapEnd; ++it) {
        actual_heap.push_back(*it);
    }
    REQUIRE(actual_heap == expected_heap);

    SECTION("Tree with duplicate values to heap"){
        Tree<int> tree;
        auto root = new TreeNode<int>(1);
        tree.add_root(root);
        tree.add_sub_node(root, new TreeNode<int>(1));
        tree.add_sub_node(root, new TreeNode<int>(2));
        auto heapIterators = tree.myHeap();
        auto heapBegin = heapIterators.first;
        auto heapEnd = heapIterators.second;
        std::vector<int> expected_heap = {1, 1, 2};
        std::vector<int> actual_heap;
        for (auto it = heapBegin; it != heapEnd; ++it) {
            actual_heap.push_back(*it);
        }
        REQUIRE(actual_heap == expected_heap);
    }

   }
     
    

//     SUBCASE("Postorder Traversal") {
//         std::vector<double> expected = {5.6, 6.7, 2.3, 7.8, , 3.4, 1.2};
//         std::vector<double> actual;
//         for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("Inorder Traversal") {
//         std::vector<double> expected = {5.6, 2.3, 6.7, 1.2, 7.8, 3.4};
//         std::vector<double> actual;
//         for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("BFS Traversal") {
//         std::vector<double> expected = {1.2, 2.3, 3.4, 5.6, 6.7, 7.8};
//         std::vector<double> actual;
//         for (auto it = tree_double.begin_bfs_scan(); it != tree_double.end_bfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("DFS Traversal") {
//         std::vector<double> expected = {1.2, 2.3, 5.6, 6.7, 3.4, 7.8};
//         std::vector<double> actual;
//         for (auto it = tree_double.begin_dfs_scan(); it != tree_double.end_dfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     delete tree_double.getCurrentRoot();
// }

// // Test case for Tree<int, 3>
// TEST_CASE("Tree Iterators - Int Type (k=3)") {
//     Tree<int, 3> tree_int;
//     auto root_int = new TreeNode<int>(1);
//     tree_int.add_root(root_int);
//     tree_int.add_sub_node(root_int, new TreeNode<int>(2));
//     tree_int.add_sub_node(root_int, new TreeNode<int>(3));
//     tree_int.add_sub_node(root_int, new TreeNode<int>(4));

//     auto child1 = tree_int.getCurrentRoot()->children[0];
//     tree_int.add_sub_node(child1, new TreeNode<int>(5));
//     tree_int.add_sub_node(child1, new TreeNode<int>(6));

//     auto child2 = tree_int.getCurrentRoot()->children[1];
//     tree_int.add_sub_node(child2, new TreeNode<int>(7));
//     std::cout << tree_int;
//     SUBCASE("Preorder Traversal") {
//         std::vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
//         std::vector<int> actual;
//         for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SECTION("Postorder Traversal") {
//         std::vector<int> expected = {5, 6, 2, 7, 3, 4, 1};
//         std::vector<int> actual;
//         for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it) {
//             actual.push_back(*it);
//         }
//         REQUIRE(actual == expected);
//     }

//     SUBCASE("Inorder Traversal") {
//         std::vector<int> expected = {5, 2, 6, 1, 7, 3, 4};
//         std::vector<int> actual;
//         for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("BFS Traversal") {
//         std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
//         std::vector<int> actual;
//         for (auto it = tree_int.begin_bfs_scan(); it != tree_int.end_bfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("DFS Traversal") {
//         std::vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
//         std::vector<int> actual;
//         for (auto it = tree_int.begin_dfs_scan(); it != tree_int.end_dfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     delete tree_int.getCurrentRoot();
// }

// // Test case for Tree<Complex, 3>
// TEST_CASE("Tree Iterators - Complex Type (k=3)") {
//     Tree<Complex, 3> tree_complex;
//     auto root_complex = new TreeNode<Complex>(Complex(5.2, 3.1));
//     tree_complex.add_root(root_complex);
//     tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.2, 0.5)));
//     tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.3, 0.7)));
//     tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.4, 0.9)));
//     tree_complex.add_sub_node(root_complex, new TreeNode<Complex>(Complex(1.5, 1.1)));

//     auto child1 = root_complex->children[0];
//     tree_complex.add_sub_node(child1, new TreeNode<Complex>(Complex(1.6, 1.3)));
//     tree_complex.add_sub_node(child1, new TreeNode<Complex>(Complex(1.7, 1.5)));

//     auto child2 = root_complex->children[1];
//     tree_complex.add_sub_node(child2, new TreeNode<Complex>(Complex(1.8, 1.7)));

//     SUBCASE("Preorder Traversal") {
//         std::vector<Complex> expected = {
//             Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
//             Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
//         };
//         std::vector<Complex> actual;
//         for (auto it = tree_complex.begin_pre_order(); it != tree_complex.end_pre_order(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     // SUBCASE("Postorder Traversal") {
//     //     std::vector<Complex> expected = {
//     //         Complex(1.6, 1.3), Complex(1.7, 1.5), Complex(1.2, 0.5), Complex(1.8, 1.7),
//     //         Complex(1.3, 0.7), Complex(1.4, 0.9), Complex(1.5, 1.1), Complex(5.2,3.1)};
//     //         DOCTEST_CHECK(actual == expected);
//     // }

//     SUBCASE("BFS Traversal") {
//         std::vector<Complex> expected = {
//             Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.3, 0.7), Complex(1.4, 0.9),
//             Complex(1.5, 1.1), Complex(1.6, 1.3), Complex(1.7, 1.5), Complex(1.8, 1.7)
//         };
//         std::vector<Complex> actual;
//         for (auto it = tree_complex.begin_bfs_scan(); it != tree_complex.end_bfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

//     SUBCASE("DFS Traversal") {
//         std::vector<Complex> expected = {
//             Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
//             Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
//         };
//         std::vector<Complex> actual;
//         for (auto it = tree_complex.begin_dfs_scan(); it != tree_complex.end_dfs_scan(); ++it) {
//             actual.push_back(*it);
//         }
//         DOCTEST_CHECK(actual == expected);
//     }

    // delete tree_complex.getCurrentRoot();


