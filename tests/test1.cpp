#include <iostream>
#include <cassert> // For assertions

// Function to test
int add(int a, int b) {
    return a + b;
}

int main() {
    // Basic test cases
    assert(add(2, 3) == 5);  // Test case 1
    assert(add(-1, 1) == 0); // Test case 2
    assert(add(0, 0) == 0);  // Test case 3
    
    // If assertions pass
    std::cout << "All test cases passed!" << std::endl;

    return 0;
}
