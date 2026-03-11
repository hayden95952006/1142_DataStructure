#include <iostream>
#include <vector>

using namespace std;
int stepCount = 0;

int findMax(const vector<int>& arr) {

    stepCount = stepCount + 2;      // array access (arr[0]) + assignment (max = arr[0])
    int max = arr[0];

    stepCount++;    // assignment (i = 1)
    for (int i = 1; i < arr.size(); i++) {
        stepCount++;    // comparison (i < arr.size())
        stepCount++;    // array access (arr[i]) 

        stepCount = stepCount + 2;  // array access (arr[i]) + comparision (arr[i] > max)
        if (arr[i] > max) {

            stepCount = stepCount + 2; // array access (arr[i]) + assignment (max = arr[i])
            max = arr[i];
        }
        stepCount++;    // Increment (i++)
    }
    stepCount++;    // loop exit comparison
    
    stepCount++;    // return max
    cout << "Step count: " << stepCount << endl;
    return max;
}

// Total operations:
// 3 (initialization) + 7(n - 1) (loop operations) + 1 (loop exit) + 1 (return)
// = 3 + 7n - 7 + 2
// = 7n - 2 operations
// Therefore, O(n) complexity
