class Solution {        // 定義一個名為 Solution 的類別
public:
    int findLucky(vector<int>& arr) {
        int count[101] = { 0 }; // 建立一個大小 101的陣列，並將全部數值設為0，用來計數字出現的次數

        for (int num : arr) {   // 依序將arr中的資料取出命名為 num
            count[num]++;   // 將與取出數字相對應位置的數字 +1，紀錄為出現過一次
        }

        for (int i = 100; i >= 1; i--) { // 從一百倒著數到一，一一尋找最大的lucky number
            if (count[i] == i){     // 數字出現的次數是否與本身相等
                return i;           // 如果是則回傳此lucky number
            }
        }

        return -1;              // 如果找不到lucky number則回傳 -1
    }
};
