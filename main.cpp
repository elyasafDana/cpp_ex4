//elidnana@gmail.com

#include <iostream>
#include "MyContainer.h"  
#include <iostream>
#include "AscendingOrder.h"
#include "DescendingOrder.h"
#include "Order.h"
#include "ReverseOrder.h"
#include "MiddleOutOrder.h"
#include "SideCrossOrder.h"
using namespace MyNamespace;
int main() {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    std::cout << "Size of container: " << container.size() << std::endl;

        for (auto it = container.AscendingOrder_begin(); it != container.AscendingOrder_end(); ++it) {    

        std::cout << *it << ' ';   // 1 2 6 7 15
    }
    std::cout << std::endl;

    for (auto it = container.DescendingOrder_begin(); it != container.DescendingOrder_end(); ++it) {
        std::cout << *it << ' ';  // 15 7 6 2 1
    }
    std::cout << std::endl;

    for (auto it = container.SideCrossOrder_begin(); it != container.SideCrossOrder_end(); ++it) {
        std::cout << *it << ' ';  // 1 15 2 7 6
    }
    std::cout << std::endl;

    for (auto it = container.ReverseOrder_begin(); it != container.ReverseOrder_end(); ++it) {
        std::cout << *it << ' ';  // 2 1 6 15 7
    }
    std::cout << std::endl;

    for (auto it = container.Order_begin(); it != container.Order_end(); ++it) {
        std::cout << *it << ' ';  // 7 15 6 1 2
    }
    std::cout << std::endl;

    for (auto it = container.MiddleOutOrder_begin(); it != container.MiddleOutOrder_end(); ++it) {
        std::cout << *it << ' ';  // 6 15 1 7 2
    }
    std::cout << std::endl;

  

    return 0;
}