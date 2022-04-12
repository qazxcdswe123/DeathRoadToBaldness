#include <iostream>

using namespace std;

class String
{
public:
     String(const char *str = NULL); // 普通构造函数
     String(const String &other); // 复制构造函数
     ~String(void); // 析构函数
private:
     char *m_data; // 用于保存字符串
};


