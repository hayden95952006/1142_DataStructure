#include <iostream>
#include <vector>

using namespace std;
int stepCount = 0;

void printPairs(const vector<int>& arr) {
	
	stepCount++;	// assignment (i = 0)
	for (int i = 0; i < arr.size(); i++) {
		stepCount++;	// comparison (i < arr.size())
		

		stepCount += 2;	// assignment (j = i + 1) + addition (j = i + 1)
		for (int j = i + 1; j < arr.size(); j++) {
			stepCount++;	// comparison (j < arr.size())
			
			stepCount += 2;	// aray access (arr[i])(arr[j])
			cout << arr[i] << "," << arr[j] << endl;

			stepCount++;	// increment (j++)
		}
		stepCount++;	//Loop exit comparison
		stepCount++;	//increment (i++)
	}
	stepCount++;	//Loop exit comparison
}


// Total operations:
// 1 (initialization) 
// + n (outer loop comparisons)
// + 2n (inner loop initialization)
// + 2n(n - 1) (inner loop operations)
// + n (inner loop exit comparisons)
// + n (outer loop increments)
// + 1 (outer loop exit)

// = 2n(n - 1) + 5n + 2
// = 2n² - 2n + 5n + 2
// = 2n² + 3n + 2 operations

// Therefore, O(n^2) complexity

