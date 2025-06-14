//elidnana@gmail.com

#ifndef SideCrossOrder_H
#define SideCrossOrder_H

/**
 * @file SideCrossOrder.h
 * @brief Defines the SideCrossOrder iterator class for MyContainer.
 *
 * @details
 * The SideCrossOrder iterator traverses elements in a "zig-zag" pattern from
 * the sorted container:
 *   - Starts from the smallest element,
 *   - Then jumps to the largest,
 *   - Then the second smallest,
 *   - Then the second largest, etc.
 *
 * For example, for input: [1, 2, 3, 4, 5]
 * Order will be: 1, 5, 2, 4, 3
 */
#include <iostream>
#include"MyContainer.h"
#include<vector>
#include<algorithm>
using namespace std;
namespace  MyNamespace{

    /**
 * @class SideCrossOrder
 * @brief An iterator class for traversing MyContainer elements in a zig-zag fashion from both ends.
 *
 * @tparam T The type of elements stored in the container.
 */


        template<typename T>
    class MyContainer<T>:: SideCrossOrder  {
        protected:
        MyContainer& data;///< Reference to the container
        vector<T> sortedData;///< Elements arranged in side-cross order
        int index;///< Current index for iteration


        public:
        /**
     * @brief Constructor: Initializes the sortedData in side-cross pattern.
     * @param v Reference to the container to iterate over.
     */
        SideCrossOrder  (MyContainer& v): data(v),index(0),sortedData(){
            vector<T> temp=data.getVec();// Copy original data
           
            sort(temp.begin(),temp.end());// Sort ascending
           
           // Interleave elements from both ends
            for(int i=0;i<temp.size()/2;i++){
            
            sortedData.push_back(temp[i]);// From beginning
            sortedData.push_back(temp[data.size()-i-1]);// From end
           }
           if(data.size()%2!=0) sortedData.push_back(temp[data.size()/2]); // Middle element (if odd number of elements)
        }

        ~SideCrossOrder  (){}


        /**
     * @brief Sets the current iterator index.
     * @param x Index to set.
     */
        void changeIndex(int x){
            index=x;
        }


        /**
     * @brief Returns a new iterator pointing to the beginning.
     * @return A copy of the iterator at the beginning.
     */

        SideCrossOrder   begin(){
            SideCrossOrder   copy=*this;
            copy.changeIndex(0);
            return copy;
        }


        /**
     * @brief Returns a new iterator pointing to the end.
     * @return A copy of the iterator at the end.
     */
        SideCrossOrder   end(){
           SideCrossOrder   copy=*this;
            copy.changeIndex(data.size());
            return copy;
        }



        /**
     * @brief Advances the iterator to the next position.
     * @return Reference to the updated iterator.
     */

        SideCrossOrder  & operator++(){
            index++;
            return *this;
        }



        /**
     * @brief Dereferences the iterator to access the current element.
     * @return The element at the current iterator position.
     */
        T operator*(){
            return sortedData[index];
        }

        /**
     * @brief Checks if two iterators point to different positions.
     * @param other Iterator to compare with.
     * @return True if different, false if equal.
     */
        bool operator!=(const SideCrossOrder  & other) const{
            return other.index!=index;
        }

        



    };

}


#endif