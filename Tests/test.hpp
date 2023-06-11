/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:05:54 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 02:24:43 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP
#define NAMESPACE ft
#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

void vector_tests();
void vector_allocation();
void nested_vectors();
void mapTests();

#endif