/*
    Insertion Sort Algorithm with ascending order
    Note:
    Insertion sort is an in-place, stable and online sorting algorithm
    Reference:
    https://en.wikipedia.org/wiki/Insertion_sort
    https://www.youtube.com/watch?v=i-SKeOcBwko&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=4
*/

#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &A, int num) {

    /* 
    | sorted | hole | unsorted |
    Remove an element from the list and creates a hole
    Move all the elements in the sorted list to the right if greater than the selected element
    insert the selected element into sorted list
    */
    
    // no need to sort if less than 2;
    if (num < 2)
        return;

    for (int i = 1; i < num; ++i) {
        int value = A[i];
        int hole = i;
        while (hole > 0 && A[hole-1] > value) {
            A[hole] = A[hole-1];
            hole--; 
        }
        A[hole] = value;
    }
}

void print_array(const std::vector<int> &array) {
    for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
        std::cout<< *it <<" ";
}

int main() {

    std::vector<int> A = {2, 2, 7, 4, 1, 5, 3};

    std::cout << "Before sorting:" << std::endl;
    print_array(A);
    std::cout << std::endl;
    
    std::cout << "After sorting:" << std::endl;
    insertion_sort(A, A.size());
    print_array(A);
    std::cout << std::endl;

    return 0;
}