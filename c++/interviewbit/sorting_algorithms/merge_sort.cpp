/*
    Merge Sort Algorithm with ascending order
    Note:
    Merge sort is an Non in-place, stable and recursive sorting algorithm
    Reference:
    https://en.wikipedia.org/wiki/Merge_sort
    https://www.youtube.com/watch?v=TzeBrDU-JaY&index=5&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
    for range copy: http://www.cplusplus.com/reference/vector/vector/vector/
*/

#include <iostream>
#include <vector>

void print_array(const std::vector<int> &array) {
    for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
        std::cout<< *it <<" ";
}

void merge(std::vector<int> &L, std::vector<int> &R, std::vector<int> &a_new) {
    int i = 0; // index for L
    int j = 0; // index for R

    /*  Compare the elements from the front as the list are sorting 
        in ascending order already until one of the list is exhausted
    */
    while (i<L.size() && j<R.size()) {
        if (L[i] <= R[j]) {
            a_new.push_back(L[i]);
            ++i;
        } else {
            a_new.push_back(R[j]);
            ++j;
        }
    }

    // push the rest of the sorted list to the end
    while (i<L.size()) {
        a_new.push_back(L[i]);
        ++i;    
    }

    while (j<R.size()) {
        a_new.push_back(R[j]);
        ++j;
    }    
    

    // std::cout<<"Size of a_new: " <<a_new.size()<<std::endl;
}

void merge_sort(std::vector<int> &A) {

    /* 
    | sorted | hole | unsorted |
    Remove an element from the list and creates a hole
    Move all the elements in the sorted list to the right if greater than the selected element
    insert the selected element into sorted list
    */
    
    int num = A.size();

    // no need to sort if less than 2;
    if (num < 2)
        return;

    int mid_num = A.size()/2;
    std::vector<int>::const_iterator first = A.begin();
    std::vector<int>::const_iterator mid = A.begin()+ mid_num;
    std::vector<int>::const_iterator last = A.end();

    std::vector<int> a_left(first, mid);
    std::vector<int> a_right(mid, last);
    merge_sort(a_left);
    merge_sort(a_right);
    std::vector<int> a_new;
    merge(a_left, a_right, a_new);
    A = a_new;
}

int main() {

    std::vector<int> A = {2, 2, 7, 4, 1, 5, 3};

    std::cout << "Before sorting:" << std::endl;
    print_array(A);
    std::cout << std::endl;
    
    std::cout << "After sorting:" << std::endl;
    merge_sort(A);
    print_array(A);
    std::cout << std::endl;

    return 0;
}