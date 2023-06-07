/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_vectors_main.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:19:35 by gboof             #+#    #+#             */
/*   Updated: 2023/06/07 20:21:24 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

class MyVector {
public:
    MyVector() {
        std::cout << "Constructing MyVector..." << std::endl;
    }

    ~MyVector() {
        std::cout << "Destroying MyVector..." << std::endl;
    }
};

int main() {
    ft::vector<ft::vector<ft::vector<MyVector> > > nestedVectors;

    std::cout << "Creating nested vectors..." << std::endl;
    nestedVectors.resize(3);

    for (int i = 0; i < 3; i++) {
        nestedVectors[i].resize(3);
        for (int j = 0; j < 3; j++) {
            // Trying to push an element into the innermost vector without constructing it
            // This will result in a segmentation fault (segfault)
            nestedVectors[i][j].push_back(MyVector());
        }
    }

    return 0;
}