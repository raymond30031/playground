#include <iostream>
#include <vector>

/*  The code is supposed to rotate the array A by B positions
    A : [1 2 3 4 5 6]
    B : 1
    output: [2 3 4 5 6 1]
*/

std::vector<int> rotateArray(std::vector<int> A, int B) {
    std::vector<int> ret;

    // My solution
    int rem = B%A.size();
    for (int i = 0; i < A.size()-rem; ++i) {
        ret.push_back(A[rem+i]);
    }
    for (int i = 0; i < rem; ++i) {
        ret.push_back(A[i]);
    }


    // Official Solution    
    // for (int i = 0; i<A.size(); ++i) {
    //     ret.push_back(A[(i+B)% A.size()]);
    // }    

    return ret;
}

void printArray(const std::vector<int> &array) {
    for (std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
        std::cout<< *it <<" ";
}

int main() {

    std::vector<int> A {1, 2, 3, 4, 5, 6};
    int B = 10;

    auto C = rotateArray(A,B);
    printArray(C);

    return 0;
}