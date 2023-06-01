/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:37:31 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/01 19:58:32 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "avl_tree_node.hpp"
#include "map_navigator.hpp"

namespace ft {

    template<class T, class Compare>
    class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
        public:
            typedef Compare                                                     key_compare;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>    traits;
            typedef typename traits::value_type                                 value_type;
            typedef typename traits::difference_type                            difference_type;
            typedef typename traits::pointer                                    pointer;
            typedef typename traits::reference                                  reference;
            typedef typename traits::iterator_category                          iterator_category;
            typedef avlTreeNode<value_type>                                     node_type;
            typedef node_type*                                                  node_pointer;
            typedef map_navigator<value_type, key_compare>                      node_finder;

        private:
            node_pointer _node;
            node_pointer _root;
            node_pointer _sentinel;
            key_compare _comp;
            node_finder _find; 
        
        public:
            map_iterator() : _node(), _root(), _sentinel(), _comp(), _find() {}

    };  //map_iterator


}   // namespace ft
#endif