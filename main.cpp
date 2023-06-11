/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:04:47 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 21:20:23 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests/test.hpp"
# define TEST 2     // 0 for Vector , 1 for Map, 2 for Stack

int main() {
    if (TEST == 0){
        vector_tests();
        vector_allocation();
        nested_vectors();
    }
    else if (TEST == 1){
        mapTests();
    }
    else if (TEST == 2)
        stackTests();
    return 0;
}
