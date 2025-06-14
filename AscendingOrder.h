//elidnana@gmail.com

/**
 * @file AscendingOrder.h
 * @brief Defines the AscendingOrder iterator class for MyContainer.
 *
 * @details
 * The AscendingOrder iterator allows traversing the elements in ascending order,
 * i.e., from the smallest to the largest element. It internally copies and sorts
 * the container's elements using std::sort.
 */

#ifndef AscendingOrder_H
#define AscendingOrder_H

#include"MyContainer.h"
#include"Order.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{


    /**
 * @class AscendingOrder
 * @brief An iterator class for traversing MyContainer elements in ascending (sorted) order.
 *
 * @tparam T The type of elements stored in the container.
 */

        template<typename T>
    class MyContainer<T>:: AscendingOrder{
        protected:
        MyContainer& data;///< Reference to the original container
        vector<T> sortedData;///< Sorted copy of the data in ascending order
        int index;///< Current index in the traversal


        public:
        /**
     * @brief Constructor: Initializes and sorts the container data in ascending order.
     * @param v Reference to the container to iterate over.
     */
        AscendingOrder(MyContainer& v): data(v),index(0),sortedData(data.getVec()){
           // std::sort(sortedData.begin(), sortedData.end(), greater<int>());
           sort(sortedData.begin(), sortedData.end());
        }

        ~AscendingOrder(){}


        /**
     * @brief Sets the current iterator index.
     * @param x The new index.
     */
        void changeIndex(int x){
            index=x;
        }


        /**
     * @brief Returns a new iterator pointing to the beginning of the sorted sequence.
     * @return A copy of the iterator set to the beginning.
     */
        AscendingOrder begin(){
            AscendingOrder copy=*this;
            copy.changeIndex(0);
            return copy;
        }


        /**
     * @brief Returns a new iterator pointing just past the end of the sequence.
     * @return A copy of the iterator set to the end.
     */
        AscendingOrder end(){
           AscendingOrder copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }

        /**
     * @brief Advances the iterator to the next element.
     * @return Reference to the updated iterator.
     */

        AscendingOrder& operator++(){
            index++;
            return *this;
        }

        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The element at the current position in the sorted order.
     */

        T operator*(){
            return sortedData[index];
        }

        /**
     * @brief Compares two iterators for inequality.
     * @param other The other iterator to compare with.
     * @return True if the iterators point to different positions.
     */
        bool operator!=(const AscendingOrder& other) const{
            return other.index!=index;
        }

        



    };

}


#endif