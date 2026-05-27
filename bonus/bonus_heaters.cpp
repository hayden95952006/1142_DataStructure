class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int R = 0;      // 定義半徑
        for (int house : houses) {      // 遍歷 houses vector
            int minD = INT_MAX;     // 將最小距離 minD 賦予 int 的最大值，方便找最小
            for (int heater : heaters) {    // 遍歷 heaters
                minD = min(minD, abs(house - heater));  // 找最小距離並更新
            }
            R = max(R, minD);   // 更新最大值
        }
        return R;
    }
};
