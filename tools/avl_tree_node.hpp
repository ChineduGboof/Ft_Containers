/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree_node.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:24:40 by gboof             #+#    #+#             */
/*   Updated: 2023/06/04 21:11:27 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>

namespace ft {

/**
 ** @brief Represents a node in an AVL tree.
 ** The avlTreeNode struct stores the value, parent, left child, right child, and height
 ** information for a node in the AVL tree.
 ** @tparam T The type of the value stored in the node.
 */
template <class T>
struct avlTreeNode {
    typedef T               value_type;
    typedef avlTreeNode*    pointer;
    typedef std::size_t     size_type;

    value_type  value;     /**< The value stored in the node. */
    pointer     parent;       /**< Pointer to the parent node. */
    pointer     left;         /**< Pointer to the left child node. */
    pointer     right;        /**< Pointer to the right child node. */
    size_type   height;     /**< The height of the node in the tree. */

    /**
     ** @brief Default constructor.
     ** Initializes an empty node with default values.
     */
    avlTreeNode()
        : value(),
          parent(NULL),
          left(NULL),
          right(NULL),
          height(0) {}

    /**
     ** @brief Value constructor.
     ** Initializes a node with the given value and default pointers and height.
     ** @param val The value to be stored in the node.
     */
    explicit avlTreeNode(value_type val)
        : value(val),
          parent(NULL),
          left(NULL),
          right(NULL),
          height(1) {}

    ~avlTreeNode() {}
};

}    // namespace ft

#endif    // TREE_NODE_HPP
