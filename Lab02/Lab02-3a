#include <iostream>
#include <vector>

using namespace std;
int stepCount = 0;


void copyArray(const vector<int>& source, vector<int>& dest) {
	
	stepCount++;	// assignment (i = 0)
	for (int i = 0; i < source.size(); i++) {
		stepCount++;	// comparison (i < source.size())
		
		dest[i] = source[i];

		stepCount++;	// increment (i++)
	}
	stepCount++;	// Loop exit comparison
}

// Total operations:
// 1 (initialization) + 5n (loop operations) + 1 (loop exit)

// = 5n + 2 operations

// Therefore, O(n) complexity

