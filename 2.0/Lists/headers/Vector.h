/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a List that are based on the vector and realise different sort algorithms
 *
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#ifndef FIRST_LAB_VECTOR_H
#define FIRST_LAB_VECTOR_H
#include "Interface.h"
#include "vector"

/**
 * Template interface structure for the List structure that is based on the vector
 */
template <typename T>
class Vector : public Interface<T>
{
private:
    std::vector<T> arr;
public:
    /**
     * The default constructor
     */
    Vector();
    /**
     * returns size of the List
     *
     */
    int GetSize();
    /**
     * delete all elements
     */
    void remove();
    /**
     * Adds the input value to the list
     *
     * @param data The value that would be added to the List
     */
    void add(T data);
    /**
     * Function that prints all the data from the list on the screen
     */
    void print();
    /**
     * Deletes the last element of the list
     */
    T popTail();
    /**
     * Deletes the first element of the list
     */
    T popHead();
    /**
     * Function that adds entered the element to the List
     *
     */
    void Enter_element();
    /**
     * Function thad return elements from position
     *
     * @param position
     * @return elements
     */
    T element(int position);
    /**
    * Function that performs the quicksort algorithm
     *
     *@param a The start sorting
     *@param b The end sorting
    */
    void quicksort(int a=1,int b=-2);
    /**
     * Function that performs the insertion sort algorithm
     */
    void insertionsort();
    /**
    * Function that basically calls the merge function
    *
     * @param left The start sorting
     * @param right The end sorting
     *
     */
    void mergesort(int left=1,int right=-2);
    /**
     +* task
     *
     *Function that basically calls the heap function
     */
    void heapsort();
    /**
     +* task
     *
    * Function that performs the selection sort algorithm
    */
    void selectionsort();
    /**
     * Function that randomly generates the List of spec. data
     */
    void random();

private:
    /**
     *The function that divides the array in two subarrays and then merges them into one in ascending order
     *
     * @param left The start of the first array
     * @param m The end of the first array and the start of the second array
     * @param right The end of the second array
     */
    void merge(int left,int m,int right);
    /**
     +* task
     *
     * Function that performs the heapsort algorithm
     *
     * @param n count of elements
     * @param i position of largest element
     */
    void heap(int n,int i);
};


#endif //FIRST_LAB_VECTOR_H
