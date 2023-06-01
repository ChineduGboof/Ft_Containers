#include <iostream>
#include <map>

namespace ft {
    template<class T1, class T2>
    std::pair<T1, T2> make_pair(T1 t, T2 u) {
        return std::pair<T1, T2>(t, u);
    }
}

class MyMap : public std::map<int, std::string> {
public:
    std::map<int, std::string>::mapped_type& operator[](const key_type& k) {
        return (*((this->insert(ft::make_pair(k, std::map<int, std::string>::mapped_type()))).first)).second;
    }
};

// class MyMap : public std::map<int, std::string> {
// public:
//     std::map<int, std::string>::mapped_type& operator[](const key_type& k) {
//         this->insert(ft::make_pair(k, std::map<int, std::string>::mapped_type()));
// 			return this->find(k)->second;
//     }
// };
	// mapped_type &operator[](const key_type &k) {
	// 		this->insert(ft::make_pair(k, mapped_type()));
	// 		return this->find(k)->second;
	// 	}

int main() {
    MyMap myMap;

    // Testing the custom operator[]
    myMap[1] = "Hello";
    myMap[2] = "World";

    std::cout << "Custom operator[]:" << std::endl;
    std::cout << "myMap[1]: " << myMap[1] << std::endl;
    std::cout << "myMap[2]: " << myMap[2] << std::endl;

    return 0;
}
