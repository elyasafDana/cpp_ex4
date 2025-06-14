//elidnana@gmail.com

#ifndef ReverseOrder_H
#define ReverseOrder_H

/**
 * @file ReverseOrder.h
 * @brief Defines the ReverseOrder iterator class for MyContainer.
 *
 * @details
 * The ReverseOrder iterator traverses the elements of the container
 * in reverse insertion order — from the last added element to the first.
 */
#include <iostream>
#include"MyContainer.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{
    /**
 * @class ReverseOrder
 * @brief An iterator class for traversing MyContainer elements in reverse insertion order.
 *
 * @tparam T The type of elements stored in the container.
 */

        template<typename T>
    class MyContainer<T>:: ReverseOrder {
        protected:
        MyContainer& data;///< Reference to the container.
        vector<T> sortedData;///< Copy of data in reverse order.
        int index;///< Current index in the traversal.


        public:

        /**
     * @brief Constructor: Copies and reverses the container's data.
     * @param v Reference to the container.
     */
        ReverseOrder (MyContainer& v): data(v),index(0),sortedData(data.getVec()){
    

            std::reverse(sortedData.begin(), sortedData.end());


        }

        ~ReverseOrder (){}


        /**
     * @brief Updates the current iterator index.
     * @param x The new index to assign.
     */
        void changeIndex(int x){
            index=x;
        }


        /**
     * @brief Returns a new iterator pointing to the beginning (last element of container).
     * @return A copy of the iterator at the start.
     */
        ReverseOrder  begin(){
            ReverseOrder  copy=*this;
            copy.changeIndex(0);
            return copy;
        }


        /**
     * @brief Returns a new iterator pointing past the end (before first element).
     * @return A copy of the iterator at the end.
     */
        ReverseOrder  end(){
           ReverseOrder  copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }


        /**
     * @brief Advances the iterator to the next position.
     * @return Reference to the updated iterator.
     */

        ReverseOrder & operator++(){
            index++;
            return *this;
        }


        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The current element in the reversed sequence.
     */
        T operator*(){
            return sortedData[index];
        }


        /**
     * @brief Compares this iterator with another for inequality.
     * @param other The other iterator to compare with.
     * @return True if iterators are at different positions.
     */
        bool operator!=(const ReverseOrder & other) const{
            return other.index!=index;
        }

        



    };

}


#endif