#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// 從文件中讀取數據並存入向量
vector<int> readFromFile(const string& filename) {
    vector<int> arr;
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return arr;
    }

    string line;
    while (getline(file, line)) { // 持續讀取整行內容
        stringstream ss(line);    // 創建字符串流
        string value;
        while (getline(ss, value, ',')) { // 用逗號分隔值
            try {
                arr.push_back(stoi(value)); // 將字符串轉換為整數並存入向量
            }
            catch (exception& e) {
                cerr << "Invalid number format in file: " << value << endl;
            }
        }
    }

    file.close();
    return arr;
}

class MinHeap {
public:
    vector<int> heap; // 儲存Min Heap的元素

    // 建立Min Heap
    void buildMinHeap(vector<int>& arr) {
        heap = arr;

        // 從最後一個非葉子節點開始堆化
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // 堆化函式
    void heapify(int i) {
        int smallest = i;       // 假設目前節點最小
        int left = 2 * i + 1;   // 左子節點
        int right = 2 * i + 2;  // 右子節點

        // 如果左子節點比較小
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // 如果右子節點比較小
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // 如果最小值不是父節點
        if (smallest != i) {
            swap(heap[i], heap[smallest]);

            // 繼續堆化
            heapify(smallest);
        }
    }

    // 印出Min Heap
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // 從文件讀取輸入元素
    string filename = "input1.txt";//請貼上input檔案的正確路徑
    vector<int> arr = readFromFile(filename);//讀取數據

    if (arr.empty()) {// 如果數據為空
        cerr << "No valid data found in file." << endl;//輸出錯誤信息
        return -1;
    }
    cout << "Input Array: ";//輸出讀取的數據
    for (int val : arr) {
        cout << val << " ";//輸出每個元素
    }
    cout << endl;

    MinHeap maxHeap;// 創建Max Heap對象
    maxHeap.buildMinHeap(arr); // 建立Max Heap

    // 輸出Max Heap的內容
    cout << "Max Heap: ";
    maxHeap.printHeap();
    cout << endl;

    system("pause");
    return 0;
}
