//elidnana@gmail.com


/**
 * @file DescendingOrder.h
 * @brief Defines the DescendingOrder iterator class for MyContainer.
 *
 * @details
 * The DescendingOrder iterator traverses the elements of the container in descending order,
 * i.e., from the largest to the smallest element. The iterator uses a copy of the container's
 * data, sorted in descending order.
 */

#ifndef DescendingOrder_H
#define DescendingOrder_H

#include"MyContainer.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{

    /**
 * @class DescendingOrder
 * @brief An iterator class for traversing MyContainer elements in descending order.
 *
 * @tparam T The type of elements stored in the container.
 */

        template<typename T>
    class MyContainer<T>:: DescendingOrder{
        protected:
        MyContainer& data;///< Reference to the original container
        vector<T> sortedData;///< Sorted copy of the data in descending order
        int index;///< Current index in the traversal


        public:
        /**
     * @brief Constructor: Initializes and sorts the container data in descending order.
     * @param v Reference to the container to iterate.
     */
        DescendingOrder(MyContainer& v): data(v),index(0),sortedData(data.getVec()){
            //sort(sortedData.begin(),sortedData.end());
            std::sort(sortedData.begin(), sortedData.end(), greater<int>());
        }

        ~DescendingOrder(){}


        /**
     * @brief Sets the current iterator index.
     * @param x The new index.
     */
        void changeIndex(int x){
            index=x;
        }

        /**
     * @brief Returns a new iterator pointing to the beginning of the sequence.
     * @return A copy of the iterator set to the start.
     */

        DescendingOrder begin(){
            DescendingOrder copy=*this;
            copy.changeIndex(0);
            return copy;
        }


        /**
     * @brief Returns a new iterator pointing to the end of the sequence.
     * @return A copy of the iterator set to the end.
     */
        DescendingOrder end(){
           DescendingOrder copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }



        /**
     * @brief Advances the iterator to the next element.
     * @return Reference to the updated iterator.
     */
        DescendingOrder& operator++(){
            index++;
            return *this;
        }


        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The current element in the sorted sequence.
     */
        T operator*(){
            return sortedData[index];
        }



        /**
     * @brief Compares two iterators for inequality.
     * @param other The other iterator to compare with.
     * @return True if iterators point to different positions.
     */

        bool operator!=(const DescendingOrder& other) const{
            return other.index!=index;
        }

        



  };

}


#endif