/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_navigator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:45:55 by gboof             #+#    #+#             */
/*   Updated: 2023/06/03 20:15:30 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NAVIGATOR_HPP
#define MAP_NAVIGATOR_HPP
#include "avl_tree_node.hpp"
#include "pair.hpp"

namespace ft {

template <class T, class Compare>
class map_navigator {
public:
    typedef T                           mapped_type;
    typedef Compare                     key_compare;
    typedef avlTreeNode<mapped_type>    node_type;
    typedef node_type*                  node_pointer;

private:
    node_pointer _current_node;
    node_pointer _root_node;
    node_pointer _end_node;
    key_compare _key_comp;

public:
    map_navigator() : _current_node(),
                      _root_node(),
                      _end_node(),
                      _key_comp() {}

    map_navigator(node_pointer current, node_pointer root, node_pointer end_node,
                  const key_compare& comp = key_compare())
        : _current_node(current),
          _root_node(root),
          _end_node(end_node),
          _key_comp(comp) {}

    ~map_navigator() {}

    /**
        Retrieves the successor node of the given node in the binary search tree.
        The successor node is the node with the smallest key greater than the given node's key.
        If the given node is the last node or is null, returns the sentinel node.
        If the given node has a right child, returns the minimum node in the right subtree.
        Otherwise, traverses the tree from the root to find the successor node.
        @param root The root node of the binary search tree.
        @param node The node for which to find the successor.
        @return Pointer to the successor node.
    */
    node_pointer getSuccessor(node_pointer root, node_pointer node) {
        if (node == _end_node || !node) {
            return _end_node;
        } else if (node->right) {
            return get_minimum_node(node->right);
        }

        node_pointer successor = _end_node;
        while (root) {
            if (_key_comp(node->value.first, root->value.first)) {
                successor = root;
                root = root->left;
            } else if (_key_comp(root->value.first, node->value.first)) {
                root = root->right;
            } else {
                break;
            }
        }
        return successor;
    }

    /**
        Retrieves the predecessor node of the given node in the binary search tree.
        The predecessor node is the node with the largest key smaller than the given node's key.
        If the given node is null, returns the sentinel node.
        If the given node is the sentinel node, returns the maximum node in the tree.
        If the given node has a left child, returns the maximum node in the left subtree.
        Otherwise, traverses the tree from the root to find the predecessor node.
        @param root The root node of the binary search tree.
        @param node The node for which to find the predecessor.
        @return Pointer to the predecessor node.
    */
    node_pointer getPredecessor(node_pointer root, node_pointer node) {
        if (!node) {
            return _end_node;
        } else if (node == _end_node) {
            return get_maximum_node(root);
        } else if (node->left) {
            return get_maximum_node(node->left);
        }

        node_pointer predecessor = _end_node;
        while (root) {
            if (_key_comp(root->value.first, node->value.first)) {
                predecessor = root;
                root = root->right;
            } else if (_key_comp(node->value.first, root->value.first)) {
                root = root->left;
            } else {
                break;
            }
        }
        return predecessor;
    }

    /**
        Retrieves the node with the minimum key in the given subtree.
        Traverses the left child of each node until a node with no left child is found.
        @param node The root node of the subtree.
        @return Pointer to the node with the minimum key.
    */
    node_pointer get_minimum_node(node_pointer node) {
        node_pointer min_node = node;
        while (min_node->left) {
            min_node = min_node->left;
        }
        return min_node;
    }

    /**
        Retrieves the node with the maximum key in the given subtree.
        Traverses the right child of each node until a node with no right child is found.
        @param node The root node of the subtree.
        @return Pointer to the node with the maximum key.
    */
    node_pointer get_maximum_node(node_pointer node) {
        node_pointer max_node = node;
        while (max_node->right) {
            max_node = max_node->right;
        }
        return max_node;
    }
};

}  // namespace ft

#endif // !map_navigator_HPP
