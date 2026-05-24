#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
template <typename T>//為了讓堆疊能放入小數點和整數 
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* topNode;//單向鏈結串列

public:
    Stack() : topNode(nullptr) {}

    bool isEmpty() const {//這裡問AI說要加上CONST 代表該函式只會讀取不會寫入  因為在string infixToPostfix有用到isempty const Stack<char>&
        //編譯器在執行 s.isEmpty() 時，內部的 this 指標型態是 const Stack<char>* 那麼一來便會更動到指標
        return (topNode == nullptr);
    }
    void push(T val) {
        Node* newNode = new Node(val); //當push的時候 新建立一個節點 該點的位置就是newnode
        newNode->next = topNode;//top由原本的(可能是null)的新節點的next
        topNode = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        Node* temp = topNode;//temp指標指向當前的top
        T poppedData = temp->data;//變數popdata為堆疊表面的data
        topNode = topNode->next;//表層被pop了, top變成原本top的next
        delete temp;
        return poppedData;
    }

    T get() const {//這裡是取得堆疊top資料但是不pop
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return topNode->data;
    }
};
// ==========================================
int precedence(char op) {//在infix to postfix的時候 要先pop 優先權>=token的運算元
    if (op == '!') return 5;    // 反向優先權最高 
    if (op == '^') return 4;    // 次方優先於其他四則運算子
    if (op == '*' || op == '/' || op == '%') return 3;  // 先乘除後加減所以優先權大於加減
    if (op == '+' || op == '-') return 2;
    if (op == '&'|| op == '~'|| op == '|') return 1;    // 邏輯運算最後才做
        
    return 0;
}
// ==========================================
// 3. 中綴表達式 轉換為 後綴表達式 (Infix to Postfix)
// ==========================================
string infixToPostfix(const string& infix) {
    Stack<char> s;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); i++) {//infix有多長postfix就有多長
        char token = infix[i];

        if (isspace(token)) continue;//isspace 為c++函式 如果空白就跳過

        if (isdigit(token) || token == '.' || (token == '-' && (i == 0 || infix[i - 1] == '(') && (isdigit(infix[i + 1]) || infix[i + 1] == '.'))) {//token讀到'.' 和數字時，負號則要位於開頭或是(後面
            if (infix[i] == '-') {
                postfix += infix[i++];
            }

            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {

                postfix += infix[i++];
            }
            postfix += " ";//輸出完一組數值後 輸出空白
            i--; //此時因為while break i會多加一次 要-掉1
        }
        else if (token == '(') {//這裡開始就是一般的將( push 然後
            s.push(token);
        }
        else if (token == ')') {
            while (!s.isEmpty() && s.get() != '(') {//pop直到出現) 就是pop 到出現)為止 因為誇號不輸出postfix 所以用get
                postfix += s.pop();
                postfix += " ";//這裡的空白是關鍵 用以區分數字和數字
            }
            if (!s.isEmpty()) s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.get()) >= precedence(token)) {//這裡是當token是運算元時 pop優先權的>=token的運算元
                postfix += s.pop();
                postfix += " ";//這裡的空白是關鍵 用以區分數字和數字
            }
            s.push(token);
        }
    }

    while (!s.isEmpty()) { //還有東西就全部pop
        postfix += s.pop();
        postfix += " "; // 這裡的空白是關鍵 用來區分數字和數字
    }

    if (!postfix.empty()) postfix.pop_back();

    return postfix;
}

bool logical(bool a, bool b, char op) { // 負責邏輯運算
    switch (op) {
    case '&':
        return a && b;
    case '|':
        return a || b;
    case '~':   
        return a != b;
    default:
        throw runtime_error("Invalid logical operator");
    }
}

bool logical_NOT(bool a) {  // 只做反向
    return !a;
}
double evaluatePostfix(const string& postfix) { //將post fix 算出
    Stack<double> s;
    for (size_t i = 0; i < postfix.length(); i++) {
        if (isspace(postfix[i])) continue;  // isspace 為c++函式 如果空白就跳過

        if (isdigit(postfix[i]) || postfix[i] == '.' || (postfix[i] == '-' && i + 1 < postfix.length() && (isdigit(postfix[i + 1]) || postfix[i + 1] == '.'))) {//postfix[i]讀到'.' 和數字時，負號則要位於開頭或是(後面
            string numStr = "";
            if (postfix[i] == '-') {
                numStr += postfix[i++];
            }
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.')) {
                numStr += postfix[i++];
            }
                        
            s.push(stod(numStr));

            i--;
        }
        else {
            if (postfix[i] == '!') {   // 優先做反向
                double val = s.pop();
                bool result = logical_NOT(val != 0);
                cout << "!" << val << " = " << result << endl;
                s.push(result);
                continue;
            }

            double val2 = s.pop();
            
            double val1 = s.pop();
            
            cout << val1 << " " << postfix[i] << " " << val2 << " = ";
            switch (postfix[i]) {   //計算與結果輸出
            case '+':
                s.push(val1 + val2);
                cout << val1 + val2 << endl;
                
                break;
            case '-': 
                s.push(val1 - val2);
                cout << val1 - val2 << endl;
                
                break;
            case '*':
                s.push(val1 * val2);
                cout << val1 * val2 << endl;
                
                break;
            case '/':
                if (val2 == 0) {    // 除以0會使商不存在，所以視為錯誤輸出
                    throw runtime_error("Division by zero");
                }
                s.push(val1 / val2);
                cout << val1 / val2 << endl;
                
                break;
            case '^':
                s.push(pow(val1, val2));
                cout << pow(val1, val2) << endl;
                
                break;
            case '%':
                if (val2 == 0) {    // 除以0會使商不存在，找不到餘數，所以視為錯誤輸出
                    throw runtime_error("Modulo by zero");
                }
                s.push(fmod(val1, val2));
                cout << fmod(val1, val2) << endl;
                
                break;
            case '&':
            case '|':
            case '~':
            {
                bool result = logical(val1 != 0, val2 != 0, postfix[i]);    // 丟進 logical運算
                s.push(result);
                cout << result << endl;
                break;
            }
            default:
                throw runtime_error("Invalid operator");
            }
        }
    }
    return s.pop();//跑完for最後pop答案
}

bool comparison();
bool logical_AND_comparison();

//=======================================================================================================
int main() {
    string infix;
    cout << "===============================================" << endl;
    cout << "  中綴式轉後綴式並求值計算機 (輸入 'exit' 離開)  " << endl;
    cout << "===============================================" << endl;
    while (true) {
        cout << "\n請輸入算式 (例如 -2*(-9.5 + 2 ^ 3)/0.5 * 4 % 7):\n> ";
        getline(cin, infix);// ai說使用 getline 可以抓取包含空格的整行字串 cin 看到空格會斷
        // 跳過空白輸入
        // 輸入 exit 結束
        if (infix == "exit") {
            break;
        }

        if (infix.empty()) {
            continue;
        }

        try {
            // 轉換為後綴式
            string postfix = infixToPostfix(infix);
            cout << "後綴式 (Postfix) : " << postfix << endl;
            // 計算後綴式結果
            double result = evaluatePostfix(postfix);
            cout << "計算結果 (Result) : " << result << endl;
        }
        catch (exception& e) {

            cout << "Error: "
                << e.what() << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
    return 0;
}
