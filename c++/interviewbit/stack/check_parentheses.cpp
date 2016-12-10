#include <iostream>
#include <stack>
#include <string>
/*
    Check is parentheses match () [] {}
    Example:
    [()]  (O)
    {(})  (X)

    Approach:
    1. read the expression from left to right
    2. if open parenthese, push into the stack
    3. if close parenthese, pop the latest element and compare
    4. If all parenthese matched, then the stack should be empty
    5. If there is a mismatch, return false; else return true

    Reference:
    https://www.youtube.com/watch?v=QZOLb0xHB_Q&index=18&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P
*/

bool check_parentheses(std::string exp) {
    std::stack<char> s;

    for (int i = 0; i<exp.size(); ++i) {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            s.push(exp[i]);
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
            if ((exp[i] == '}' && s.top() == '{') || 
                (exp[i] == ']' && s.top() == '[') ||
                (exp[i] == ')' && s.top() == '('))
                s.pop();
    }

    return s.empty();

}

int main() {

    std::string expression;
    std::cout << "Enter an expression: " << std::endl;
    std::cin >> expression;

    if (check_parentheses(expression))
        std::cout<<"Threre is no mismatch"<<std::endl;
    else
        std::cout<<"There is parentheses mismatch"<<std::endl;

}