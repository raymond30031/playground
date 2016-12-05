/*
    Quick Sort Algorithm with ascending order
    Note:
    Quick sort is an in-place, non-stable and recursive sorting algorithm
    Reference:
    https://en.wikipedia.org/wiki/Quicksort
    https://www.youtube.com/watch?v=COk73cpQbFQ&index=7&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
    For random function:
    http://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library

*/

#include <iostream>
#include <vector>
#include <random> 

void print_array(const std::vector<int> &array) {
    for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
        std::cout<< *it <<" ";
}

int partition(std::vector<int> &A, int start, int end) {
    // default pivot at the end
    int pIndex = start; // position of the pivot
    for (int i = start; i<end; ++i) {
        if(A[i] < A[end]) {
            int temp = A[pIndex];
            A[pIndex] = A[i];
            A[i] = temp;
            pIndex++;
        }
    }
    int temp = A[pIndex];
    A[pIndex] = A[end];
    A[end] = temp;
    return pIndex;
}

int randomized_partition(std::vector<int> &A, int start, int end) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(start, end);
    int pIndex = dist(gen); //generate a num for the range of [start, end]
    // swap end with random pivot to avoid worst case performance
    int temp = A[end];
    A[end] = A[pIndex];
    A[pIndex] = temp;

    return partition(A,start,end);

}

void quick_sort(std::vector<int> &A, int start, int end) {

    /* 
    Randomize a pivot point in the array
    swap the pivot value with the end of the array to avoid worst case
    Divide the list such that all values left of the pivot are smaller than pivot
    and the ones to the right are greater
    quick sort the left and the right list
    */

    if (start < end) {
        int pIndex = randomized_partition(A, start, end);
        quick_sort(A, start, pIndex-1);
        quick_sort(A, pIndex+1, end);
    }

}

int main() {

    std::vector<int> A = {2, 2, 7, 4, 1, 5, 3};

    std::cout << "Before sorting:" << std::endl;
    print_array(A);
    std::cout << std::endl;
    
    std::cout << "After sorting:" << std::endl;
    quick_sort(A, 0, A.size()-1);
    print_array(A);
    std::cout << std::endl;

    return 0;
}