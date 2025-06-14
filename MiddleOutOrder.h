//elidnana@gmail.com

/**
 * @file MiddleOutOrder.h
 * @brief Defines the MiddleOutOrder iterator class for MyContainer.
 *
 * @details
 * The MiddleOutOrder iterator traverses the elements starting from the middle
 * of the container and alternates outwards to the left and right.
 *
 * For example, given a vector [1, 2, 3, 4, 5], the traversal order would be:
 *     3, 2, 4, 1, 5
 * For an even-sized vector [1, 2, 3, 4, 5, 6], the traversal order would be:
 *     4, 3, 5, 2, 6, 1
 */


#ifndef MiddleOutOrder_H
#define MiddleOutOrder_H
#include <iostream>
#include"MyContainer.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{
    
/**
 * @class MiddleOutOrder
 * @brief An iterator class for traversing MyContainer elements from the middle outward.
 *
 * @tparam T The type of the elements stored in the container.
 */

        template<typename T>
    class MyContainer<T>:: MiddleOutOrder {
        protected:
        MyContainer& data;///< Reference to the container
        vector<T> sortedData;///< The reordered data in middle-out traversal order
        int index; ///< Current index in the traversal


        public: 
        /**
     * @brief Constructor: Initializes the iterator and builds the middle-out order.
     * @param v The container to iterate over.
     */
        MiddleOutOrder (MyContainer& v): data(v),index(0),sortedData(){
            vector<T> temp=data.getVec();
            // For odd-sized containers
            if(data.size()%2!=0){
                sortedData.push_back(temp[data.size()/2]);
                for(int i=1;i<=temp.size()/2;i++){
                 sortedData.push_back(temp[ (data.size()/2)-i ] );
                 sortedData.push_back(temp[ (data.size()/2)+i ] );
           }
        }
        // For even-sized containers
           else{
            sortedData.push_back(temp[data.size()/2]);
            for(int i=1;i<temp.size()/2;i++){
            sortedData.push_back(temp[ (data.size()/2)-i ] );
            sortedData.push_back(temp[ (data.size()/2)+i ] );
           }
           sortedData.push_back(data[0]);// Last element to fill remaining spot

           }

        }

        ~MiddleOutOrder (){}
        /**
     * @brief Sets the current index.
     * @param x The new index value.
     */
        void changeIndex(int x){
            index=x;
        }

        /**
     * @brief Returns an iterator to the beginning of the sequence.
     * @return A copy of the iterator pointing to the start.
     */

        MiddleOutOrder  begin(){
            MiddleOutOrder  copy=*this;
            copy.changeIndex(0);
            return copy;
        }


         /**
     * @brief Returns an iterator to the end of the sequence.
     * @return A copy of the iterator pointing just past the end.
     */

        MiddleOutOrder  end(){
           MiddleOutOrder  copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }


         /**
     * @brief Advances the iterator to the next position.
     * @return Reference to the updated iterator.
     */

        MiddleOutOrder & operator++(){
            index++;
            return *this;
        }


        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The element at the current position in the traversal.
     */
        T operator*(){
            return sortedData[index];
        }

        /**
     * @brief Checks inequality between two iterators (based on index).
     * @param other The other iterator to compare with.
     * @return True if iterators are at different positions.
     */


        bool operator!=(const MiddleOutOrder & other) const{
            return other.index!=index;
        }

        



    };

}


#endif