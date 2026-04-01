#include<iostream>
#include<string>
using namespace std;

//建立一個名為Student的結構型態,裡面包含int、string等不同類型的資料型態
struct Student{
	int id;// 學生ID
	string name;// 學生姓名
	int chinese;// 國文分數
	int english;// 英文分數
	int math;// 數學分數
	int social;// 社會分數
	int science;// 自然分數
};
// 使用call by address的方式回傳值
void updateMath(Student* s) {
	s->math = 100;//透過->改變結構成員的數值
}
// 使用call by value的方式回傳值
void printStudent(Student s) {
	cout << "學生編號: " << s.id << endl;
	cout << "姓名: " << s.name << endl;
	cout << "數學成績: " << s.math << endl;
}
int main() {
	Student one;
	// 利用前面所建立的名為Studunt的結構來宣告一個名為 one 的結構變數
	// 對新宣告的結構變數 one 中的元素賦值
	one.id = 1;// 設定學生ID
	one.name = "張小美";// 設定姓名
	one.chinese = 77;// 設定國文分數
	one.english = 83;// 設定英文分數
	one.math = 86;// 設定數學分數
	one.social = 68;// 設定社會分數
	one.science = 91;// 設定自然分數
	updateMath(&one);// 利用指標 s 指向 one 的位址，才能使函式直接修改原本數值結構中的資料。
	printStudent(one);// 把one的資料複製一份給函式s做輸出
	return 0;
}
ㄋ
