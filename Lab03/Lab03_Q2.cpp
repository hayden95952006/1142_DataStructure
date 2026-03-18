#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {             
        int count[101] = { 0 };       

        for (int num : arr) {           
            
            count[num]++;               

        }

        for (int i = 100; i >= 1; i--) {
            if (count[i] == i) {   
                return i;           
            }
        }

        return -1;         
    }
};

// Total operations:
// 101 (initialization of count array)
// + n (first loop: counting frequencies)
// + 100 (second loop: searching lucky number)
// + 1 (return)

// = 101 + n + 100 + 1
// = n + 202 operations
// Therefore, O(n) complexity
