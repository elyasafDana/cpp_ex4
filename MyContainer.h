//elidnana@gmail.com


/**
 * @file MyContainer.h
 * @brief Defines the MyContainer template class for storing and iterating over elements
 *        in various custom traversal orders.
 *
 * @details
 * MyContainer<T> is a generic container class that manages a collection of elements of type T.
 * It provides methods to add, remove, and access elements, as well as several custom iterator-like
 * nested classes for different traversal strategies:
 *  - AscendingOrder
 *  - DescendingOrder
 *  - ReverseOrder
 *  - MiddleOutOrder
 *  - SideCrossOrder
 *  - Order (default order)
 *
 * Each iterator class is expected to implement begin() and end() functions to support iteration.
 */
#ifndef MYCONTAINER_H
#define MYCONTAINER_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace MyNamespace {
     /**
     * @class MyContainer
     * @brief A generic container class that stores elements and supports multiple custom iteration orders.
     *
     * @tparam T The type of elements stored in the container.
     */

    template<typename T>
    class MyContainer {
    private:
        std::vector<T> data;

    public:
        class AscendingOrder;
        class DescendingOrder;
        class Order;
        class ReverseOrder;
        class MiddleOutOrder;
        class SideCrossOrder;

        MyContainer() {}

        ~MyContainer() {}


        /**
     * @brief Adds a new element to the container.
     * @param x The element to add.
     */
        void add(T x) {
            data.push_back(x);
        }


        /**
     * @brief Removes an element from the container.
     * @param x The element to remove.
     * @note If the element is not found, a message is printed to stdout.
     */
        void remove(T x) {
            auto it = std::find(data.begin(), data.end(), x);
            if (it != data.end()) {
                data.erase(it);
            } else {
                std::cout << "not found\n";
            }
        }


        /**
     * @brief Returns the number of elements in the container.
     * @return The size of the container.
     */
        int size() {
            return data.size();
        }


        /**
     * @brief Provides indexed access to elements.
     * @param x The index of the element.
     * @return The element at the specified index.
     */

        T operator[](int x) {
            return data[x];
        }


            // ---------- Iteration Methods (begin/end pairs for each order type) ----------


        /// Default Order (Order class)
        Order Order_begin() {
            Order it(*this);
            return it.begin();
        }

        Order Order_end() {
            Order it(*this);
            return it.end();
        }


        DescendingOrder DescendingOrder_begin(){
            DescendingOrder it(*this);
            return it.begin();
        }

        DescendingOrder DescendingOrder_end(){
            DescendingOrder it(*this);
            return it.end();
        }


        /// Reverse Order (reverse of insertion order)

        ReverseOrder ReverseOrder_begin(){
            ReverseOrder it(*this);
            return it.begin();
        }

        ReverseOrder ReverseOrder_end(){
            ReverseOrder it(*this);
            return it.end();
        }


        


        AscendingOrder AscendingOrder_begin(){
            AscendingOrder it(*this);
            return it.begin();
        }

        AscendingOrder AscendingOrder_end(){
            AscendingOrder it(*this);
            return it.end();
        }

        MiddleOutOrder MiddleOutOrder_begin(){
            MiddleOutOrder it(*this);
            return it.begin();
        }

        MiddleOutOrder MiddleOutOrder_end(){
            MiddleOutOrder it(*this);
            return it.end();
        }


        SideCrossOrder SideCrossOrder_begin(){
            SideCrossOrder it(*this);
            return it.begin();
        }

        SideCrossOrder SideCrossOrder_end(){
            SideCrossOrder it(*this);
            return it.end();
        }
        
       
        

      
    
        /**
     * @brief Returns a reference to the underlying vector.
     * @return A reference to the internal vector of elements.
     */
        vector<T>& getVec() {
            return data;
        }

        // operator<<
        friend std::ostream& operator<< (std::ostream& os, const MyContainer<T>& container) {
            os << "[";
            for (size_t i = 0; i < container.data.size(); ++i) {
                os << container.data[i];
                if (i != container.data.size() - 1)
                    os << ", ";
            }
            os << "]";
            return os;
        }
    };

} // namespace MyNamespace

#endif // MYCONTAINER_H
