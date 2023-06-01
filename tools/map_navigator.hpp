/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_navigator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:45:55 by gboof             #+#    #+#             */
/*   Updated: 2023/06/01 19:59:40 by gboof            ###   ########.fr       */
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

    node_pointer get_successor_node(node_pointer root, node_pointer node) {
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

    node_pointer get_predecessor_node(node_pointer root, node_pointer node) {
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

    node_pointer get_minimum_node(node_pointer node) {
        node_pointer min_node = node;
        while (min_node->left) {
            min_node = min_node->left;
        }
        return min_node;
    }

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
