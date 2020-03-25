/**
 * 2nd Course K-28
 * Lab 1. Variant 2-9
 * Task: make a interface to the lists
 *
 * Purpose: contains declarations of the list interface
 *
 *@author Stanislav Dombrovskyi
 *@version 13/11/19
 */

#ifndef FIRST_LAB_INTERFACE_H
#define FIRST_LAB_INTERFACE_H

/**
 * Template Node structure that is used in the List structure
 */
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

/**
 * Template interface structure for the List interface structure
 */
template <typename T>
class Interface
{
public:
    /**
     * Pure virtual function that returns size of the List
     *
     */
    int virtual GetSize()=0;
    /**
     * Pure virtual function thad return elements from position
     *
     * @param position
     * @return elements
     */
    T virtual element(int position)=0;
    /**
     * Pure virtual function that delete all elements from the List
     *
     */
    void virtual remove()=0;
    /**
     * Pure virtual function that adds the element to the List
     *
     * @param data The value that would be added to the List
     */
    void virtual add(T data)=0;
    /**
     * Pure virtual function that prints all the data from the list on the screen
     */
    void virtual print()=0;
    /**
     * Deletes the last element of the list
     */
    T virtual popTail()=0;
    /**
     * Deletes the first element of the list
     */
    T virtual popHead()=0;
    /**
     * Pure virtual function that adds entered the element to the List
     *
     */
    void virtual Enter_element()=0;
    //T virtual element(int)=0;
    /**
    * Pure virtual function that performs the quicksort algorithm
     *
     *@param a The start sorting
     *@param b The end sorting
    */
    void virtual quicksort(int a=1,int b=-2)=0;
    /**
     * Pure virtual function that performs the insertion sort algorithm
     */
    void virtual insertionsort()=0;
    /**
    * Pure virtual function that performs the mergesort algorithm
    *
     * @param left The start sorting
     * @param right The end sorting
     *
     */
    void virtual mergesort(int left=1,int right=-2)=0;
    /**
     +* task
     *
     * Pure virtual function that performs the heapsort algorithm
     */
    void virtual heapsort()=0;
    /**
     +* task
     *
    * Pure virtual function that performs the selection sort algorithm
    */
    void virtual selectionsort()=0;
    /**
     * Pure virtual function that randomly generates the List of spec. data
     */
    void virtual random()=0;
};


#endif //FIRST_LAB_INTERFACE_H
