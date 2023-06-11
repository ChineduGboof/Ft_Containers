/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:00:36 by gboof             #+#    #+#             */
/*   Updated: 2023/06/11 05:31:43 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

// template <typename Key, typename T>
// void printMapComparison(const std::map<Key, T>& stdMap, const ft::map<Key, T>& ftMap) {
//     typename std::map<Key, T>::const_iterator stdIt = stdMap.begin();
//     typename ft::map<Key, T>::const_iterator ftIt = ftMap.begin();

//     std::cout << GREEN << "std::map: ";
//     for (; stdIt != stdMap.end(); ++stdIt)
//         std::cout << "(" << stdIt->first << "," << stdIt->second << ") " << DEFAULT;

//     std::cout << YELLOW << "\nft::map:  ";
//     for (; ftIt != ftMap.end(); ++ftIt)
//         std::cout << "(" << ftIt->first << "," << ftIt->second << ") " << DEFAULT;

//     std::cout << std::endl << std::endl;
// }

void mapTests(){
     {
        std::cout << "TEST THE BEGIN FUNCTION" <<std::endl;
        std::cout << "Calling the Begin Function" <<std::endl;
        std::map<char, int> stdMap;
        std::map<char, int> ftMap;
        stdMap['c'] = 3;
        stdMap['d'] = 5;
        stdMap['e'] = 6;
        ftMap['c'] = 3;
        ftMap['d'] = 5;
        ftMap['e'] = 6;
        std::map<char, int>::iterator stdIt = stdMap.begin();
        std::map<char, int>::iterator ftIt = ftMap.begin();

        std::cout << YELLOW << "stdMap.begin() => " << stdIt->second << DEFAULT << std::endl;
        std::cout << GREEN << "ftMap.begin() => " << ftIt->second << DEFAULT << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "TEST THE END FUNCTION" <<std::endl;
        std::cout << "Calling the end function with three elements in the map" <<std::endl;
        std::map<char, int> stdMap;
        std::map<char, int> ftMap;
        stdMap['c'] = 4;
        stdMap['d'] = 5;
        stdMap['e'] = 7;
        ftMap['c'] = 4;
        ftMap['d'] = 5;
        ftMap['e'] = 7;
        std::map<char, int>::iterator stdIt = --stdMap.end();
        std::map<char, int>::iterator ftIt = --ftMap.end();

        std::cout << YELLOW << "stdMap.end() => " << stdIt->second << DEFAULT << std::endl;
        std::cout << GREEN << "ftMap.end() => " << ftIt->second << DEFAULT << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "TEST THE CLEAR FUNCTION" <<std::endl;
        std::map<char, int> stdMap;
        std::map<char, int> ftMap;
        stdMap['x']=100;
        stdMap['y']=200;
        stdMap['z']=300;
        ftMap['x']=100;
        ftMap['y']=200;
        ftMap['z']=300;

        std::cout << "stdMap contains:\n";
        for (std::map<char,int>::iterator it=stdMap.begin(); it!=stdMap.end(); ++it)
            std::cout << YELLOW << it->first << " => " << it->second << DEFAULT <<'\n';
        std::cout << "ftMap contains:\n";
        for (std::map<char,int>::iterator it=ftMap.begin(); it!=ftMap.end(); ++it)
            std::cout << GREEN << it->first << " => " << it->second << DEFAULT << '\n';

        stdMap.clear();
        ftMap.clear();
        stdMap['a']=1101;
        stdMap['b']=2202;
        ftMap['a']=1101;
        ftMap['b']=2202;

        std::cout << "stdMap contains:\n";
        for (std::map<char,int>::iterator it=stdMap.begin(); it!=stdMap.end(); ++it)
            std::cout << YELLOW << it->first << " => " << it->second << DEFAULT <<'\n';
        std::cout << "ftMap contains:\n";
        for (std::map<char,int>::iterator it=ftMap.begin(); it!=ftMap.end(); ++it)
            std::cout << GREEN << it->first << " => " << it->second << DEFAULT << '\n';
        std::cout << std::endl;
    }
    {
        std::cout << "TEST THE BOUNDS FUNCTION" <<std::endl;
        std::map<char, int> stdMap;
        ft::map<char, int> ftMap;

        stdMap['a']=100;
        stdMap['b']=200;
        stdMap['c']=300;
        ftMap['a']=100;
        ftMap['b']=200;
        ftMap['c']=300;

        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> stdRet;
        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ftRet;
        {
            std::cout << "Passing Key 'b: " << std::endl;
            stdRet = stdMap.equal_range('b');
            ftRet = ftMap.equal_range('b');

            std::cout << "lower bound points to: " << std::endl;
            std::cout << YELLOW << "std: "<< stdRet.first->first << " => " << stdRet.first->second << DEFAULT << '\n';
            std::cout << GREEN << "ft: "<< ftRet.first->first << " => " << ftRet.first->second << DEFAULT <<'\n';

            std::cout << "upper bound points to: " << std::endl;
            std::cout << YELLOW << "std: "<< stdRet.second->first << " => " << stdRet.second->second << DEFAULT << '\n';
            std::cout << GREEN << "ft: "<< ftRet.second->first << " => " << ftRet.second->second << DEFAULT <<'\n';
            std::cout << std::endl;
        }

        {
            stdRet = stdMap.equal_range('a');
            ftRet = ftMap.equal_range('a');

            std::cout << "lower bound points to: " << std::endl;
            std::cout << YELLOW << "std: "<< stdRet.first->first << " => " << stdRet.first->second << DEFAULT << '\n';
            std::cout << GREEN << "ft: "<< ftRet.first->first << " => " << ftRet.first->second << DEFAULT <<'\n';

            std::cout << "upper bound points to: " << std::endl;
            std::cout << YELLOW << "std: "<< stdRet.second->first << " => " << stdRet.second->second << DEFAULT << '\n';
            std::cout << GREEN << "ft: "<< ftRet.second->first << " => " << ftRet.second->second << DEFAULT <<'\n';
            std::cout << std::endl;
        }

        {
            std::cout << "TEST THE ERASE FUNCTION" <<std::endl;
            std::map<char,int>::iterator stdIt;
            ft::map<char,int>::iterator ftIt;

            stdIt=stdMap.find('b');
            ftIt=ftMap.find('b');
            stdMap.erase (stdIt);       // erasing by iterator
            ftMap.erase (ftIt); 

            stdMap.erase ('c');                  // erasing by key
            ftMap.erase ('c');

            std::cout << "std: " << std::endl;
            for (stdIt=stdMap.begin(); stdIt!=stdMap.end(); ++stdIt)
                std::cout << YELLOW << stdIt->first << " => " << stdIt->second << DEFAULT <<'\n';
            std::cout << "ft: " << std::endl;
            for (stdIt=stdMap.begin(); stdIt!=stdMap.end(); ++stdIt)
                std::cout << GREEN << stdIt->first << " => " << stdIt->second << DEFAULT <<'\n';
            std::cout << std::endl;
        }
    }
    {
        std::cout << "TEST THE FIND FUNCTION" <<std::endl;
        std::map<char,int> stdMap;
        ft::map<char,int> ftMap;
        std::map<char,int>::iterator stdIt;
        ft::map<char,int>::iterator ftIt;

        stdMap['a']=50;
        stdMap['b']=100;
        stdMap['c']=150;
        stdMap['d']=200;
        ftMap['a']=50;
        ftMap['b']=100;
        ftMap['c']=150;
        ftMap['d']=200;

        // print content:
        std::cout << "elements in stdMap:" << '\n';
        std::cout << YELLOW << "a => " << stdMap.find('a')->second << DEFAULT << '\n';
        std::cout << YELLOW << "d => " << stdMap.find('d')->second << DEFAULT << '\n';
        std::cout << "elements in ftMap:" << '\n';
        std::cout << YELLOW << "a => " << ftMap.find('a')->second << DEFAULT << '\n';
        std::cout << YELLOW << "d => " << ftMap.find('d')->second << DEFAULT << '\n';
        std::cout << std::endl;
    }
    {
        std::cout << "TEST THE INSERT FUNCTION" <<std::endl;

        std::map<char, int>stdMap;
        ft::map<char, int>ftMap;
        {
            std::cout << "Single Element Insertion: " << std::endl;
            stdMap.insert(std::pair<char, int>('a', 100));
            stdMap.insert(std::pair<char, int>('z', 200));
            ftMap.insert(ft::pair<char, int>('a', 100));
            ftMap.insert(ft::pair<char, int>('z', 200));

            std::map<char, int>::iterator stdIt;
            for (stdIt = stdMap.begin(); stdIt != stdMap.end(); ++stdIt){
                std::cout << YELLOW << stdIt->second << " " << DEFAULT;
            }
            std::cout << std::endl;
            ft::map<char, int>::iterator ftIt;
            for (ftIt = ftMap.begin(); ftIt != ftMap.end(); ++ftIt){
                std::cout << GREEN << ftIt->second << " " << DEFAULT;
            }
            std::cout << std::endl;
            std::cout << "Insertion with already used key: " << std::endl;
            std::pair<std::map<char, int>::iterator, bool> stdRes;
            stdRes = stdMap.insert(std::pair<char, int>('a', 70));
            if (stdRes.second == false){
                std::cout << YELLOW  << "Element '" << stdRes.first->first << "' already exists with value " << stdRes.first->second << std::endl;
            }
            ft::pair<ft::map<char, int>::iterator, bool> ftRes;
            ftRes = ftMap.insert(ft::pair<char, int>('a', 70));
            if (ftRes.second == false){
                std::cout << GREEN << "Element '" << ftRes.first->first << "' already exists with value " << ftRes.first->second << std::endl;
            }
            std::cout << std::endl;
        }
            std::cout << "Insertion with Hint: " << std::endl;
            std::map<char,int>::iterator stdIt = stdMap.begin();
            ft::map<char,int>::iterator ftIt = ftMap.begin();
        {
            stdMap.insert (stdIt, std::pair<char,int>('b',300));
            stdMap.insert (stdIt, std::pair<char,int>('c',400));
            for (stdIt = stdMap.begin(); stdIt != stdMap.end(); ++stdIt){
                std::cout << YELLOW << stdIt->second << " " << DEFAULT;
            }
            std::cout << std::endl;

            ftMap.insert (ftIt, ft::pair<char,int>('b',300));
            ftMap.insert (ftIt, ft::pair<char,int>('c',400)); 
            for (ftIt = ftMap.begin(); ftIt != ftMap.end(); ++ftIt){
                std::cout << GREEN << ftIt->second  << " " << DEFAULT;
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }

        {
            std::map<char, int> stdMap;
            ft::map<char, int> ftMap;

            stdMap['x'] = 1001;
            stdMap['y'] = 2002;
            stdMap['z'] = 3003;
            ftMap['x'] = 1001;
            ftMap['y'] = 2002;
            ftMap['z'] = 3003;

            std::map<char, int>::iterator stdIt1 = stdMap.begin();        // Iterator to the first element
            std::map<char, int>::reverse_iterator stdIt2 = stdMap.rbegin(); // Reverse iterator to the last element
            ft::map<char, int>::iterator ftIt1 = ftMap.begin(); 
            ft::map<char, int>::reverse_iterator ftIt2 = ftMap.rbegin(); 
            bool isStdFirstKeyLess = stdMap.key_comp()(stdIt1->first, stdIt2->first);
            bool isFtFirstKeyLess = stdMap.key_comp()(ftIt1->first, ftIt2->first);

            std::cout << "The key of the STD first element ('" << stdIt1->first << "') is ";

            if (isStdFirstKeyLess) {
                std::cout << YELLOW << "less than the key of the last element ('" << stdIt2->first << "')." << DEFAULT << std::endl;
            } else {
                std::cout << YELLOW << "not less than the key of the last element ('" << stdIt2->first << "')." << DEFAULT <<std::endl;
            }
            std::cout << "The key of the FT first element ('" << ftIt1->first << "') is ";

            if (isFtFirstKeyLess) {
                std::cout << GREEN << "less than the key of the last element ('" << ftIt2->first << "')." << DEFAULT <<std::endl;
            } else {
                std::cout << GREEN << "not less than the key of the last element ('" << ftIt2->first << "')." << DEFAULT << std::endl;
            }
            std::cout << std::endl;
        }
        {
            std::cout << "TEST THE MAKE_PAIR FUNCTION" <<std::endl;

            std::pair<std::string, int>stdMap;
            ft::pair<std::string, int>ftMap;
            stdMap = std::make_pair("Bugsy", 400);
            ftMap = ft::make_pair("Bugsy", 400);
            std::cout << YELLOW << "stdMap of " << stdMap.first << " " << stdMap.second << DEFAULT << std::endl;
            std::cout << GREEN << "ftMap of " << ftMap.first << " " << ftMap.second << DEFAULT << std::endl;
            std::cout << std::endl;
        }
        {
            std::cout << "TEST THE SWAP FUNCTION" <<std::endl;
            std::map<char,int> foo,bar;
            ft::map<char,int> hoo, ber;

            foo['x']=100;
            foo['y']=200;

            bar['a']=11;
            bar['b']=22;
            bar['c']=33;

            hoo['x']=100;
            hoo['y']=200;

            ber['a']=11;
            ber['b']=22;
            ber['c']=33;

            foo.swap(bar);
            hoo.swap(ber);

            std::cout << "std foo contains:\n";
            for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
                std::cout << YELLOW << it->first << " => " << it->second << DEFAULT << '\n';

            std::cout << "std bar contains:\n";
            for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
                std::cout << YELLOW << it->first << " => " << it->second << DEFAULT << '\n';
            
            std::cout << "ft hoo contains:\n";
            for (ft::map<char,int>::iterator it=hoo.begin(); it!=hoo.end(); ++it)
                std::cout << GREEN << it->first << " => " << it->second << DEFAULT << '\n';

            std::cout << "ft ber contains:\n";
            for (ft::map<char,int>::iterator it=ber.begin(); it!=ber.end(); ++it)
                std::cout << GREEN << it->first << " => " << it->second << DEFAULT << '\n';
            std::cout << std::endl;
        }
    }
    {
        std::cout << "TEST THE VALUE_COMPARE FUNCTION" <<std::endl;
        std::map<char, int> stdMap;
        ft::map<char, int> ftMap;

        stdMap['x'] = 1001;
        stdMap['y'] = 2002;
        stdMap['z'] = 3003;
        ftMap['x'] = 1001;
        ftMap['y'] = 2002;
        ftMap['z'] = 3003;
        
        std::pair<char, int> stdIt1 = *stdMap.begin();           // First element
        std::pair<char, int> stdIt2 = *stdMap.rbegin();           // Last element
        ft::pair<char, int> ftIt1 = *ftMap.begin();           // First element
        ft::pair<char, int> ftIt2 = *ftMap.rbegin();           // Last element

        bool isStdFirstElementLess = stdMap.value_comp()(stdIt1, stdIt2);
        bool isFtFirstElementLess = ftMap.value_comp()(ftIt1, ftIt2);

        std::cout << YELLOW << "The value of the first element (" << stdIt1.second << ") is ";

        if (isStdFirstElementLess) {
            std::cout << "less than the value of the last element (" << stdIt2.second << ")." << DEFAULT << std::endl;
        } else {
            std::cout << "not less than the value of the last element (" << stdIt2.second << ")." << DEFAULT << std::endl;
        }
        
        std::cout << GREEN << "The value of the first element (" << ftIt1.second << ") is ";
        if (isFtFirstElementLess) {
            std::cout << "less than the value of the last element (" << ftIt2.second << ")." << DEFAULT << std::endl;
        } else {
            std::cout << "not less than the value of the last element (" << ftIt2.second << ")." << DEFAULT << std::endl;
        }
        std::cout << std::endl;
    }
}