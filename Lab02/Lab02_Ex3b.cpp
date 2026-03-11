#include <iostream>
#include <vector>

using namespace std;
int stepCount = 0;

int countElement(const vector<int>& arr, int target) {

	stepCount++;	// assignment (count = 0)
	int count = 0;

	stepCount++;	// assignment (i = 0)
	for (int i = 0; i < arr.size(); i++) {
		stepCount++;	// comparison (i < arr.size())

		stepCount += 2;	// array access (arr[i]) + comparison (arr[i] == target)
		if (arr[i] == target) {

			stepCount++;	// increment (count++)
			count++;
		}
		stepCount++;	// increment (i++)
	}
	stepCount++;	// loop exit comparison

	stepCount++;	//return count
	return count;
}

// Total operations:
// 2 (initialization) + 5n (loop operations) + 1 (loop exit) + 1 (return)

// = 5n + 4 operations

// Therefore, O(n) complexity

