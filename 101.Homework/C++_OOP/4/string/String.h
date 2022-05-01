#include <iostream>

class String
{
    friend String operator+(const String &s1, const String &s2);

    friend std::ostream &operator<<(std::ostream &os, const String &obj);

    friend std::istream &operator>>(std::istream &is, String &obj);

    friend bool operator>(const String &s1, const String &s2);

    friend bool operator>=(const String &s1, const String &s2);

    friend bool operator==(const String &s1, const String &s2);

    friend bool operator!=(const String &s1, const String &s2);

    friend bool operator<(const String &s1, const String &s2);

    friend bool operator<=(const String &s1, const String &s2);

private:
    int len;
    char *data;

public:
    String(const char *s = "");

    String(const String &other);

    String &operator+=(const String &other);

    String &operator=(const String &other);

    String operator()(int start, int end);

    char &operator[](int index);

    ~String();
};