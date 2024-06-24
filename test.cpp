// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
// #include <catch2/catch.hpp>
#include "Tree.hpp"
#include "TreeNode.hpp"
#include "Complex.hpp"
#include <vector>

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

    SUBCASE("Preorder Traversal") {
        std::vector<double> expected = {1.2, 2.3, 5.6, 6.7, 3.4, 7.8};
        std::vector<double> actual;
        for (auto it = tree_double.begin_pre_order(); it != tree_double.end_pre_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("Postorder Traversal") {
        std::vector<double> expected = {5.6, 6.7, 2.3, 7.8, , 3.4, 1.2};
        std::vector<double> actual;
        for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("Inorder Traversal") {
        std::vector<double> expected = {5.6, 2.3, 6.7, 1.2, 7.8, 3.4};
        std::vector<double> actual;
        for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<double> expected = {1.2, 2.3, 3.4, 5.6, 6.7, 7.8};
        std::vector<double> actual;
        for (auto it = tree_double.begin_bfs_scan(); it != tree_double.end_bfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<double> expected = {1.2, 2.3, 5.6, 6.7, 3.4, 7.8};
        std::vector<double> actual;
        for (auto it = tree_double.begin_dfs_scan(); it != tree_double.end_dfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    delete tree_double.getCurrentRoot();
}

// Test case for Tree<int, 3>
TEST_CASE("Tree Iterators - Int Type (k=3)") {
    Tree<int, 3> tree_int;
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
    std::cout << tree_int;
    SUBCASE("Preorder Traversal") {
        std::vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        std::vector<int> actual;
        for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SECTION("Postorder Traversal") {
        std::vector<int> expected = {5, 6, 2, 7, 3, 4, 1};
        std::vector<int> actual;
        for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it) {
            actual.push_back(*it);
        }
        REQUIRE(actual == expected);
    }

    SUBCASE("Inorder Traversal") {
        std::vector<int> expected = {5, 2, 6, 1, 7, 3, 4};
        std::vector<int> actual;
        for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
        std::vector<int> actual;
        for (auto it = tree_int.begin_bfs_scan(); it != tree_int.end_bfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<int> expected = {1, 2, 5, 6, 3, 7, 4};
        std::vector<int> actual;
        for (auto it = tree_int.begin_dfs_scan(); it != tree_int.end_dfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    delete tree_int.getCurrentRoot();
}

// Test case for Tree<Complex, 3>
TEST_CASE("Tree Iterators - Complex Type (k=3)") {
    Tree<Complex, 3> tree_complex;
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

    SUBCASE("Preorder Traversal") {
        std::vector<Complex> expected = {
            Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
            Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
        };
        std::vector<Complex> actual;
        for (auto it = tree_complex.begin_pre_order(); it != tree_complex.end_pre_order(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    // SUBCASE("Postorder Traversal") {
    //     std::vector<Complex> expected = {
    //         Complex(1.6, 1.3), Complex(1.7, 1.5), Complex(1.2, 0.5), Complex(1.8, 1.7),
    //         Complex(1.3, 0.7), Complex(1.4, 0.9), Complex(1.5, 1.1), Complex(5.2,3.1)};
    //         DOCTEST_CHECK(actual == expected);
    // }

    SUBCASE("BFS Traversal") {
        std::vector<Complex> expected = {
            Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.3, 0.7), Complex(1.4, 0.9),
            Complex(1.5, 1.1), Complex(1.6, 1.3), Complex(1.7, 1.5), Complex(1.8, 1.7)
        };
        std::vector<Complex> actual;
        for (auto it = tree_complex.begin_bfs_scan(); it != tree_complex.end_bfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<Complex> expected = {
            Complex(5.2, 3.1), Complex(1.2, 0.5), Complex(1.6, 1.3), Complex(1.7, 1.5),
            Complex(1.3, 0.7), Complex(1.8, 1.7), Complex(1.4, 0.9), Complex(1.5, 1.1)
        };
        std::vector<Complex> actual;
        for (auto it = tree_complex.begin_dfs_scan(); it != tree_complex.end_dfs_scan(); ++it) {
            actual.push_back(*it);
        }
        DOCTEST_CHECK(actual == expected);
    }

    delete tree_complex.getCurrentRoot();
}

