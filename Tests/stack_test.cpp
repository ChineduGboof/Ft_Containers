/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:17:18 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/11 21:25:00 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename Stack>
void printStack(const Stack& stack) {
    // Create a copy of the stack to avoid modifying the original stack
    Stack tempStack = stack;

    // Print the elements in reverse order
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    std::cout << std::endl;
}

void printTestResult(bool result) {
    std::cout << (result ? "Test passed." : "Test failed.") << std::endl;
}

void stackTests(){

    // Test the empty() function
    {
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        printTestResult(stdStack.empty() == ftStack.empty());
    }

    // Test the size() function
    {
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        stdStack.push(10);
        stdStack.push(20);
        stdStack.push(30);
        ftStack.push(10);
        ftStack.push(20);
        ftStack.push(30);

        printTestResult(stdStack.size() == ftStack.size());
    }

    // Test the top() function
    {
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        stdStack.push(42);
        ftStack.push(42);

        printTestResult(stdStack.top() == ftStack.top());
    }

    // Test the push() function
    {
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        stdStack.push(100);
        ftStack.push(100);

        printTestResult(stdStack.top() == ftStack.top());
    }

    // Test the pop() function
    {
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        stdStack.push(1);
        stdStack.push(2);
        stdStack.push(3);
        ftStack.push(1);
        ftStack.push(2);
        ftStack.push(3);

        stdStack.pop();
        ftStack.pop();

        printTestResult(stdStack.top() == ftStack.top());
    }

    // Test the comparison operators
    {
        std::stack<int> stdStack1;
        std::stack<int> stdStack2;
        ft::stack<int> ftStack1;
        ft::stack<int> ftStack2;

        stdStack1.push(10);
        stdStack1.push(20);
        stdStack1.push(30);
        stdStack2.push(10);
        stdStack2.push(20);
        stdStack2.push(30);
        ftStack1.push(10);
        ftStack1.push(20);
        ftStack1.push(30);
        ftStack2.push(10);
        ftStack2.push(20);
        ftStack2.push(30);

        printTestResult(stdStack1 == stdStack2 && ftStack1 == ftStack2);
    }
    {
        // Print the elements in the stack
        std::stack<int> stdStack;
        ft::stack<int> ftStack;

        stdStack.push(1);
        stdStack.push(2);
        stdStack.push(3);
        ftStack.push(1);
        ftStack.push(2);
        ftStack.push(3);

        std::cout << "Elements in stdStack: ";
        printStack(stdStack);

        std::cout << "Elements in ftStack: ";
        printStack(ftStack);
    }
}