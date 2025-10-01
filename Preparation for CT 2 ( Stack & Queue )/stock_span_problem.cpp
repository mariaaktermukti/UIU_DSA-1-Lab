// Given an array arr[] of daily stock prices, the stock span for the i-th day is the count of 
// consecutive days up to and including day i, such that each of those days had a stock price 
// less than or equal to the price on day i.

// Examples:

// Input: arr[] = [100, 80, 60, 120]
// Output: [1, 1, 1, 4]
// Explanation: For 100, there are no previous higher prices, 
// so span = 1. For 80 and 60, each is smaller than the previous, 
// so their spans remain 1. For 120, it is greater than all earlier prices (100, 80, 60), 
// so the span extends back across all four days, giving span = 4.

// Input: arr[] = [10, 4, 5, 90, 120, 80]
// Output: [1, 1, 2, 4, 5, 1]
// Explanation: For 10 and 4, no earlier prices are smaller, 
// so span = 1 each. For 5, it is greater than 4, so span = 2. For 90, 
// it is greater than 10, 5, and 4, so span = 4. For 120, it is greater than all previous prices, 
// giving span = 5. Finally, 80 is smaller than 120, so span = 1.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];      // input prices
    int span[1000];     // result
    int stack[1000];    // stack for indices
    int top = -1;       // top of stack

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        // pop while stack is not empty and price at top <= current price
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--;
        }

        if (top == -1) {
            span[i] = i + 1; // no previous higher price
        } else {
            span[i] = i - stack[top]; // distance to previous higher price
        }

        stack[++top] = i; // push current index
    }

    // output
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << "\n";

    return 0;
}
