/*
    Selection Sort Algorithm with ascending order
    Note:
    Selection sort is an in-place and stable sorting algorithm
    Reference:
    https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=2
*/

#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &A, int num) {

    /* 
    | sorted | unsorted |
    iterate through the list and move the smallest item to the left
    */
    for (int i = 0; i<num; ++i) {
        int iMin = i;
        for (int j = i+1; j<num; ++j) {
            if (A[j] < A[iMin]) {
                iMin = j;
            }
            int temp = A[i];
            A[i] = A[iMin];
            A[iMin] = temp;
        }
    }
}

void print_array(const std::vector<int> &array) {
    for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
        std::cout<< *it <<" ";
}

int main() {

    std::vector<int> A = {2, 7, 4, 1, 5, 3};

    std::cout << "Before sorting:" << std::endl;
    print_array(A);
    std::cout << std::endl;
    
    std::cout << "After sorting:" << std::endl;
    selection_sort(A, A.size());
    print_array(A);
    std::cout << std::endl;

    return 0;
}