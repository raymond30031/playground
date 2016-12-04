/*
    Bubble Sort Algorithm with ascending order
    Reference:
    https://www.youtube.com/watch?v=Jdtq5uKz-w4&index=3&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
*/

#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &A, int num) {

    /* num - i to avoid sorted region as after each sort
       the greatest element of the list should be at the end
       The -1 to not go over bound of A
    */
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num-i-1; ++j) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }

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
    bubble_sort(A, A.size());
    print_array(A);
    std::cout << std::endl;

    return 0;
}