// factorial of a number
#include <iostream>
using namespace std;

// Class definition
class Example {
public:
    int fact(int n);  // Function prototype
};

// Recursive function definition
int Example::fact(int n) {
    if (n <= 1)       // Base case: factorial of 0 or 1 is 1
        return 1;
    else
        return n * fact(n - 1);  // Recursive case
}

int main() {
    Example f;        // Object of class Example
    int n, result;
    
    cout << "Enter a number: ";
    cin >> n;

    result = f.fact(n);  // Call the recursive factorial function
    cout << "The factorial of " << n << " is = " << result << endl;

    return 0;
}
