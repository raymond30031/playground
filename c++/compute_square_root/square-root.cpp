#include <iostream>
float computeSquareRoot(float input, const float epsilon, const int max_iter) {
  if (input < 0) {
    return -1;
  }
  
  // float epsilon = 1e-6;
  // remove x0 as xk always lag behind one iteration
  float xk=input/2;

  for (int i = 0; i<max_iter; ++i)
  {
    xk = xk - (xk*xk -input)/(2*xk);    
    if ((xk*xk -input) < epsilon) {
      return xk;
    }
  }
 
  return xk;
}

int main() {
  // std::cout<<"here"<<std::endl;
  float input = 2;
  float result = computeSquareRoot(input, 1e-6, 1000);
  std::cout<<"result: "<< result<<std::endl;
  return 0;  
}

// Reference:
// https://en.wikipedia.org/wiki/Newton%27s_method?fbclid=IwAR3Ap5HMdnBfvgCJzUaaIYvHBcnUuDsya_Gi78DaEza3I8gmjeXWmZJ5Gt0
// https://stackoverflow.com/questions/9235456/determining-floating-point-square-root?fbclid=IwAR2wDTrQjfMx8h3jmCspgyH61OwSEu5CvmQ4G0MELtQNyEBQBemzQF2elT4

// J(x) = 2x
// e(x) ~= e(x') + J(x')*delta_x
// e(x) - e(x') =



// epsilon = 1e-6
// x1 = x0+delta_x
// if (e(x1) < epsilon)
         

//          xk = ..(xk-1)

// B
// f(x=result) = x^2 -input = 0
