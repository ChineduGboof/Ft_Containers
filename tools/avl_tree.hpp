/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:37:38 by gboof             #+#    #+#             */
/*   Updated: 2023/06/04 21:24:47 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "pair.hpp"
#include "map_iterator.hpp"
#include "map_navigator.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class avl_tree {
    public:
		typedef Key                                                           key_type;
		typedef T                                                             mapped_type;
		typedef ft::pair<const key_type, mapped_type>                         value_type;
		typedef Compare                                                       key_compare;
		typedef Allocator                                                     allocator_base;
		typedef avlTreeNode<value_type>                                       node_type;
		typedef node_type*                                                    pointer;
		typedef const pointer                                                 const_pointer;
		typedef typename allocator_base::template rebind<node_type>::other    allocator_type;
		typedef std::size_t                                                   size_type;

	private:
		key_compare _comp;
		allocator_type _alloc;
		allocator_base _base;
		pointer _root;
		pointer _end_node;

    public:
    
        /*
        **  Constructor for the avl_tree class.
        **  Initializes the avl_tree object with the provided key compare function and allocator.
        **  Sets the root pointer to null and creates an end-node for end-of-tree representation.
        */
		avl_tree(const key_compare &comp = key_compare(),
		         const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc), _root(0) {                                               
			_end_node = _alloc.allocate(1 * sizeof(node_type));
			_alloc.construct(_end_node, node_type());
		}

		~avl_tree() {}

        /*
        **  Returns a constant pointer to the root node of the AVL tree.
        */
        pointer getRoot() const {
			return _root;
		}

        /*
        **  Returns a constant pointer to the end node of the AVL tree.
        */
        pointer getEndNode() const {
			return _end_node;
		}

        /*
        **  Returns the maximum possible size of the AVL tree.
        */
		size_type max_size() const {
			return _alloc.max_size();
		}

        /*
        ** Updates the root pointer of the AVL tree with the provided new root pointer.
        */
		void updateRoot(pointer new_root) {
			_root = new_root;
		}


        /**
            Inserts a new node with the given value into the AVL tree.
            If the node is null, a new node is created and returned.
            If the value is less than the node's value, the node is inserted in the left subtree.
            If the value is greater than the node's value, the node is inserted in the right subtree.
            After insertion, the heights of the nodes are updated, and rotations are performed if necessary
            to maintain the balance of the tree.
            @param node The current node in the recursion.
            @param value The value to be inserted.
            @return The root of the updated subtree.
        */
        pointer insertNode(pointer node, value_type value) {
            if (node == NULL) {
                return createNode(value);
            }
            else if (_comp(value.first, node->value.first)) {
                node->left = insertNode(node->left, value);
            }
            else if (_comp(node->value.first, value.first)) {
                node->right = insertNode(node->right, value);
            }

            updateHeight(node);
            int balance = getBalanceFactor(node);
            return (balance > 1 && _comp(value.first, node->left->value.first)) ? rightRotate(node) :
                (balance > 1 && _comp(node->left->value.first, value.first)) ? leftThenRightRotate(node) :
                (balance < -1 && _comp(node->right->value.first, value.first)) ? leftRotate(node) :
                (balance < -1 && _comp(value.first, node->right->value.first)) ? rightThenLeftRotate(node) : node;
        }

        /**
            Deletes a node with the given value from the AVL tree.
            If the node is null, the tree remains unchanged.
            If the value is less than the node's value, the node is deleted from the left subtree.
            If the value is greater than the node's value, the node is deleted from the right subtree.
            If the value is equal to the node's value, different cases are considered:
            If the node has no children, it is freed and set to NULL.
            If the node has only one child, the child becomes the new node.
            If the node has two children, the successor node (smallest node in the right subtree)
            is copied to the current node, and the successor node is deleted recursively from the right subtree.
            After deletion, the heights of the nodes are updated, and rotations are performed if necessary
            to maintain the balance of the tree.
            @param node The current node in the recursion.
            @param value The value to be deleted.
            @return The root of the updated subtree.
        */
		pointer deleteNode(pointer node, value_type value) {
			if (node == NULL) {
				return node;
			} else if (_comp(value.first, node->value.first)) {
				node->left = deleteNode(node->left, value);
			} else if (_comp(node->value.first, value.first)) {
				node->right = deleteNode(node->right, value);
			} else {
				if (!node->left && !node->right) {
					return freeNode(node);
				} else if (!node->left && node->right) {
					pointer new_node = node->right;
					freeNode(node);
					return new_node;
				} else if (node->left && !node->right) {
					pointer new_node = node->left;
					freeNode(node);
					return new_node;
				} else {
					pointer temp = getMinimum(node->right);
					_base.destroy(&node->value);
					_base.construct(&node->value, temp->value);
					node->right = deleteNode(node->right, temp->value);
				}
			}

			if (!node) {
				return node;
			}
			updateHeight(node);
			int balance = getBalanceFactor(node);
			return (balance > 1 && getBalanceFactor(node->left) >= 0) ? rightRotate(node) :
			       (balance > 1 && getBalanceFactor(node->left) < 0) ? leftThenRightRotate(node) :
			       (balance < -1 && getBalanceFactor(node->right) <= 0) ? leftRotate(node) :
			       (balance < -1 && getBalanceFactor(node->right) > 0) ? rightThenLeftRotate(node) : node;
		}

        /**
            Searches for a node with the given value in the AVL tree.
            If the node is found, it is returned.
            If the value is less than the node's value, the search continues in the left subtree.
            If the value is greater than the node's value, the search continues in the right subtree.
            If the value is equal to the node's value, the node is returned.
            @param node The current node in the recursion.
            @param value The value to search for.
            @return The node with the given value, or the end_node node if not found.
        */
		pointer search(pointer node, key_type value) const {
            if (node == NULL) {
                return _end_node;
            }
            else if (_comp(value, node->value.first)) {
                return search(node->left, value);
            }
            else if (_comp(node->value.first, value)) {
                return search(node->right, value);
            }
            else {
                return node;
            }
        }


        /**
            Returns the successor node of the node with the given key in the AVL tree.
            The successor is the node with the smallest key greater than the given key.
            If the right subtree of the node is non-empty, the successor is the minimum node
            in the right subtree. Otherwise, the successor is the ancestor node that is
            the first node on the right side of the given key.
            @param root The root of the AVL tree.
            @param key The key to find the successor for.
            @return The successor node.
        */
		pointer getKeySuccessor(pointer root, const key_type &key) const {
			pointer node = this->search(_root, key);
			if (node->right) {
				return getMinimum(node->right);
			}
			pointer successor = _end_node;
			while (root) {
				if (_comp(key, root->value.first)) {
					successor = root;
					root = root->left;
				} else if (_comp(root->value.first, key)) {
					root = root->right;
				} else {
					break;
				}
			}
			return successor;
		}

        /**
            Prints the nodes of the AVL tree in pre-order traversal.
            Each node's key and value are printed on a separate line.
            The traversal starts from the given node.
            @param node The starting node for the traversal.
        */
		void printPreOrder(pointer node) {
			if (node) {
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second << std::endl;
				printPreOrder(node->left);
				printPreOrder(node->right);
			}
		}

        /**
            Prints the nodes of the AVL tree in in-order traversal.
            Each node's key and value are printed on a separate line.
            The traversal starts from the given node.
            @param node The starting node for the traversal.
            Essentially, pre-order traversal visits the current node before its children, 
            while in-order traversal visits the left subtree, 
            then the current node, and finally the right subtree.
        */
		void printInOrder(pointer node) {
			if (node) {
				printInOrder(node->left);
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second;
				std::cout << std::endl;
				printInOrder(node->right);
			}
		}

        /**
            Returns the node with the minimum key in the AVL tree.
            The minimum node is the leftmost node in the tree.
            @param node The root of the AVL tree.
            @return The node with the minimum key.
        */
		pointer getMinimum(pointer node) const {
			pointer min = node;
			while (min && min->left) {
				min = min->left;
			}
			return min;
		}

        /**
            Frees the memory allocated for the end_node node.
            The end_node node is set to NULL.
        */
		void freeend_nodeNode() {
			if (_end_node) {
				_alloc.destroy(_end_node);
				_alloc.deallocate(_end_node, sizeof(node_type));
				_end_node = NULL;
			}
		}

        /**
            Clears the AVL tree by deallocating all nodes.
            If free_end_node is true, the end_node node is also freed.
            After clearing, the root node and end_node node are set to NULL.
            @param node The current node in the recursion.
            @param free_end_node Flag indicating whether to free the end_node node.
        */
		void clear(pointer node, bool free_end_node) {
			if (free_end_node == true) {
				freeend_nodeNode();
			}

			if (node) {
				clear(node->left, false);
				clear(node->right, false);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1 * sizeof(node_type));
				_root = node = NULL;
			}
		}

    private:
        /**
            Creates a new AVL tree node with the given value.
            @param value The value to be stored in the new node.
            @return Pointer to the newly created node.
        */

		pointer createNode(value_type value) {
			pointer node = _alloc.allocate(sizeof(node_type));
			_alloc.construct(node, node_type(value));
			return node;
		}

        /**
            Returns the height of the given node.
            If the node is null, returns 0.
            @param node The node to get the height of.
            @return The height of the node.
        */
        size_type getHeight(pointer node){
            return (node == NULL) ? 0 : node->height;
        }

        /**
            Calculates and returns the balance factor of the given node.
            If the node is null, returns 0.
            The balance factor is calculated as the difference between
            the heights of the left and right subtrees.
            @param node The node to calculate the balance factor of.
            @return The balance factor of the node.
        */
		int getBalanceFactor(pointer node) {
			return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
		}

        /**
            Updates the height of the given node based on the heights of its children.
            The height is calculated as the maximum height between the left and right subtrees,
            plus 1 for the current node.
            @param node The node to update the height of.
        */
		void updateHeight(pointer node) {
			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
		}

        /**
            Performs a left rotation on the given node.
            Adjusts the pointers of the nodes involved in the rotation
            and updates their heights.
            @param node The node to perform the left rotation on.
            @return The new root of the rotated subtree.
        */

		pointer leftRotate(pointer node) {
			pointer x = node->right;
			pointer y = x->left;

			x->left = node;
			node->right = y;

			updateHeight(node);
			updateHeight(x);
			return x;
		}

        /**
            Performs a right rotation on the given node.
            Adjusts the pointers of the nodes involved in the rotation
            and updates their heights.
            @param node The node to perform the right rotation on.
            @return The new root of the rotated subtree.
        */
		pointer rightRotate(pointer node) {
			pointer x = node->left,
			        y = x->right;

			x->right = node;
			node->left = y;

			updateHeight(node);
			updateHeight(x);
			return x;
		}

        /**
            Performs a left-then-right rotation on the given node.
            First performs a left rotation on the left child of the node,
            then performs a right rotation on the node itself.
            @param node The node to perform the left-then-right rotation on.
            @return The new root of the rotated subtree.
        */
		pointer leftThenRightRotate(pointer node) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

        /**
            Performs a right-then-left rotation on the given node.
            First performs a right rotation on the right child of the node,
            then performs a left rotation on the node itself.
            @param node The node to perform the right-then-left rotation on.
            @return The new root of the rotated subtree.
        */
		pointer rightThenLeftRotate(pointer node) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

        /**
            Frees the memory of the given node and destroys its value.
            Deallocates the memory occupied by the node using the allocator.
            @param node The node to be freed.
            @return The freed node (set to NULL).
        */
		pointer freeNode(pointer node) {
			_alloc.destroy(node);
			_alloc.deallocate(node, sizeof(node_type));
			return node = NULL;
		}
};

}   // namespace ft

#endif // !AVL_TREE_HPP