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
