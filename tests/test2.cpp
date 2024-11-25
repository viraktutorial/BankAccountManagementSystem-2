#include <iostream>

// Function to test
int multiply(int a, int b) {
    return a * b;
}

// Test function
void testMultiply() {
    // Test cases
    if (multiply(2, 3) != 6) std::cerr << "Test case 1 failed!" << std::endl;
    if (multiply(-2, 3) != -6) std::cerr << "Test case 2 failed!" << std::endl;
    if (multiply(0, 5) != 0) std::cerr << "Test case 3 failed!" << std::endl;

    std::cout << "All test cases passed (if no errors)!" << std::endl;
}

int main() {
    testMultiply();
    return 0;
}
