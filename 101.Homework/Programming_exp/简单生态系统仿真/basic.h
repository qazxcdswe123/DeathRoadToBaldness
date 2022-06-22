#ifndef _BASIC_H_
#define _BASIC_H_

//和程序实现相关的一些基础的常量、函数声明

enum State
{
    EMPTY,
    GRASS,
    RABBIT,
    FOX,
    HUMAN,
    STATES
}; //添加了人类

const int DRAB = 3;   //兔子的寿命
const int DFOX = 4;   //狐狸的寿命
const int TMFOX = 2;  //太多的狐狸数
const int DHUM = 5;   //人类的寿命
const int TMHUM = 2;  //太多的人类数
const int CYCLES = 5; //仿真总步数
const int N = 40;     //世界的大小

struct Position //位置
{
    int row;   //行
    int colum; //列
};

#include <iostream>
using namespace std;

//用于在控制台窗口显示彩色的字体
// #include <windows.h>
// struct color
// {
//     color(WORD attribute) : m_color(attribute){};
//     WORD m_color; //颜色值
// };

//使用模板函数
// template <class _Elem, class _Traits>
// std::basic_ostream<_Elem, _Traits> &
// operator<<(std::basic_ostream<_Elem, _Traits> &i, color &c)
// {
//     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
//     SetConsoleTextAttribute(hStdout, c.m_color);      //设置文本颜色
//     return i;
// }

#endif