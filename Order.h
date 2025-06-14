//elidnana@gmail.com

/**
 * @file Order.h
 * @brief Defines the default Order iterator class for MyContainer.
 *
 * @details
 * The Order iterator provides a straightforward traversal of elements in the same
 * order they were inserted into the MyContainer instance (insertion order).
 */


#ifndef Order_H
#define Order_H

#include"MyContainer.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{
/**
 * @class Order
 * @brief A basic iterator class for traversing MyContainer elements in insertion order.
 *
 * @tparam T The type of elements stored in the container.
 */

        template<typename T>
    class MyContainer<T>:: Order{
        protected:
        MyContainer& data;///< Reference to the container
        vector<T> sortedData;///< Copy of the container data (in insertion order).
        int index;///< Current position in the iteration.


        public:
        /**
     * @brief Constructor: Initializes the iterator with container data in original order.
     * @param v Reference to the container.
     */


        Order(MyContainer& v): data(v),index(0),sortedData(data.getVec()){
        }

        ~Order(){}


        /**
     * @brief Sets the current index in the iteration.
     * @param x New index to assign.
     */
        void changeIndex(int x){
            index=x;
        }


        /**
     * @brief Returns an iterator to the beginning of the sequence.
     * @return A copy of the iterator at the beginning.
     */
        Order begin(){
            Order copy=*this;
            copy.changeIndex(0);
            return copy;
        }



        /**
     * @brief Returns an iterator to the end of the sequence.
     * @return A copy of the iterator at the end (one past the last element).
     */

        Order end(){
           Order copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }

        /**
     * @brief Moves the iterator to the next element.
     * @return Reference to the updated iterator.
     */
        Order& operator++(){
            index++;
            return *this;
        }


        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The current element.
     */
        T operator*(){
            return sortedData[index];
        }



         /**
     * @brief Checks if two iterators are not at the same position.
     * @param other The iterator to compare with.
     * @return True if iterators are at different positions.
     */
        bool operator!=(const Order& other) const{
            return other.index!=index;
        }

    };

}


#endif