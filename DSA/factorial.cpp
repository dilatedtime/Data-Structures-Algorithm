#include <iostream>
#include <vector>
#include <algorithm>

void multiply(int x, std::vector<int>& result) {
    int carry = 0; // Initialize carry
    
    // One by one multiply n with individual digits of result
    for (int i = 0; i < result.size(); i++) {
        int prod = result[i] * x + carry;
        result[i] = prod % 10; // Store last digit of 'prod' in result
        carry = prod / 10; // Put rest in carry
    }

    // Put carry in result and increase result size
    while (carry) {
        result.push_back(carry % 10);
        carry = carry / 10;
    }
}

void factorial(int n) {
    std::vector<int> result;
    result.push_back(1); // Initialize result with 1
    
    for (int x = 2; x <= n; x++) {
        multiply(x, result);
    }
    
    // Result is stored in reverse order, so reverse it
    std::reverse(result.begin(), result.end());

    // // Print the result
    // for (int i = 0; i < result.size(); i++) {
    //     std::cout << result[i];
    // }
    // std::cout << std::endl;
}

int main() {
    int n = 100000;
    std::cout << n << "! = ";
    factorial(n);       
    return 0;
}
