#include <iostream>
#include <string>
#include <any>
using namespace std;
using var = any;

//output
template<typename T>
void output(T t) {cout << t << endl;}
template<>
void output(bool flag) {cout << (flag? "true" : "false") << endl;}
template<>
void output(var v)
{
    if (v.type() == typeid(int)) {output(any_cast<int>(v));}
    else if (v.type() == typeid(double)) {output(any_cast<double>(v));}
    else if (v.type() == typeid(std::string)) {output(any_cast<std::string>(v));}
    else if (v.type() == typeid(bool)) {output(any_cast<bool>(v));}
    else if (v.type() == typeid(char)) {cout << any_cast<char>(v) << endl;}
    else if (v.type() == typeid(const char*)) {cout << any_cast<const char*>(v) << endl;}
    else {cout << "[错误] 未知类型：" << v.type().name() << endl;}
}
//input
template<typename T>
T input() {T t;cin >> t;return t;}
template<>
bool input() {string s;cin >> s;return s == "true";}

//operator +
std::any operator+(const std::any& a, const std::any& b) {
    // 检查两个 std::any 是否存储相同类型
    if (a.type() != b.type()) {
        throw std::invalid_argument("The types of the two std::any objects do not match.");
    }

    // 检查类型并执行相应操作
    if (a.type() == typeid(int)) {
        // 如果是 int 类型，进行加法运算
        return std::any_cast<int>(a) + std::any_cast<int>(b);
    } else if (a.type() == typeid(std::string)) {
        // 如果是 std::string 类型，进行字符串拼接
        return std::any_cast<std::string>(a) + std::any_cast<std::string>(b);
    } else {
        // 如果不支持的类型，抛出异常
        throw std::invalid_argument("Unsupported type for operator +.");
    }
}