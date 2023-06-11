/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:04:47 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 02:25:51 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests/test.hpp"
# define TEST 1     // 0 for Vector , 1 for Map

int main() {
    if (TEST == 0){
        vector_tests();
        vector_allocation();
        nested_vectors();
    }
    else if (TEST == 1){
        mapTests();
    }
    return 0;
}
