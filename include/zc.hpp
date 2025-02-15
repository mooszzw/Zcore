#include <iostream>
#include <string>
#include <any>
using namespace std;
#define var  any

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
T input()
{
    T t;
    cin >> t;
    return t;
}

template<>
bool input()
{
    string s;
    cin >> s;
    return s == "true" || s == "1";
}

// 为std::any类型提供输入处理，自动推断类型
template<>
var input()
{
    string value;
    cout << "请输入值: ";
    cin >> value;

    // 尝试转换为int
    try {return stoi(value);}
    catch (...) {}

    // 尝试转换为double
    try {return stod(value);}
    catch (...) {}

    // 尝试转换为bool
    if (value == "true" || value == "1") return true;
    else if (value == "false" || value == "0") return false;

    // 尝试转换为char，如果value长度为1
    if (value.size() == 1) return value[0];

    // 默认情况下，作为string处理
    return value;
}
