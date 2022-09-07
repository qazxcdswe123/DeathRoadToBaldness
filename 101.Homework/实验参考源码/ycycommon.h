#pragma once

//只编译1次头文件
//-----------------------------------01【程序说明】----------------------------------------------
//  描述：常用的
//常用头文件
//
//
//
//

//------------------------------------------------------------------------------------------------

//条件编译
#ifndef _YCYCOMMON_H //方法1,如果没有定义__YCYCOMMON_H__
#define _YCYCOMMON_H // 那么定义__YCYCOMMON_H__
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址
//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
//方法一：无需在程序最前面加那行代码，只需在新建项目时取消勾选“SDL检查”即可。
//方法二：若项目已建立好，在项目属性里关闭SDL；项目 > 属性 > C / C++ > 常规 > SDL检查（改成否）。

// ---------------------------------- - 02【头文件包含部分】-------------------------------------- -
//  描述：包含程序所依赖的头文件
//------------------------------------------------------------------------------------------------
//考虑VC各个版本的兼容性
#ifdef _MSC_VER		 // 表示是VC
#if _MSC_VER == 1200 // 表示VC6.0
// 标准库头文件
#include <string.h>	  // 标准串和操作
#include <iostream.h> // 标准流操作
#include <limits.h>	  // 极限
#include <math.h>	  // 数学函数
#include <fstream.h>  // 文件输入输出
#include <ctype.h>	  // 字符处理
#include <time.h>	  // 日期和时间函数
#include <stdlib.h>	  // 标准库
#include <stdio.h>	  // 标准输入输出
#include <iomanip.h>  // 输入输出流格式设置
#include <stdarg.h>	  // 支持变长函数参数
#include <assert.h>	  // 支持断言

#else				// 其它版本的VC++
// MSVC++ 10.0 _MSC_VER = 1600 (Visual Studio 2010)
//#include<Windows.h>///移动光标以及SetConsoleTextAttribute,使用Windows中API
#include <iostream> //标准流操作
#include <cstdio>
#include <iomanip> //输入输出流格式控制,如setw等
#include <ctime>   //C++日期时间函数
//#include<time.h>//C日期时间函数
#include <cstdlib> //C++标准库system("pause"),EXIT_SUCCESS;操作“exit”存放在此，rand,RAND_MAX
//#include<stdlib.h>//C标准库  system("pause")
#include <fstream> //文件输入输出
#include <string>
#include <conio.h>
#include <sstream>	 //c++字符串流
#include <cassert>	 //C++断言工具
//#include<assert.h>//C断言工具
#include <stdexcept> //C++标准异常处理库
#include <typeinfo>
#include <cmath>	 //数据函数
//#include<cstdio>//标准输入输出
#include <cctype>	 //字符处理,toupper
//#include<cstdarg>//支持变长函数参数
#include <algorithm> //使用swap函数
#include <random>	 //c++11
#include <direct.h>
#include <tchar.h> //_T

//为避免函数冲突，不使用标准命名空间(standard namespace,std)
// using namespace std;//使用标准命名空间(standard namespace,std)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#endif // _MSC_VER == 1200

#else				// 非VC
// ANSI C++标准库头文件
#include <string>	// 标准串操作
#include <iostream> // 标准流操作
#include <limits>	// 极限
#include <cmath>	// 数据函数
#include <fstream>	// 文件输入输出
#include <cctype>	// 字符处理
#include <ctime>	// 日期和时间函数
#include <cstdlib>	// 标准库
#include <cstdio>	// 标准输入输出
#include <iomanip>	// 输入输出流格式设置
#include <cstdarg>	// 支持变长函数参数
#include <cassert>	// 支持断言
// using namespace std; // 标准库包含在命名空间std中
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#endif // _MSC_VER

//补充各个章节的头文件定义在这里的话会出现什么问题？why？//
//#include"ch2/ch2.h"
// ---------------------------------- - 03【库文件包含部分】-------------------------------------- -
//  描述：包含程序所依赖的库文件
//------------------------------------------------------------------------------------------------
//#pragma comment(linker,"/subsystem:Console")//修改子系统选项为控制台

//-----------------------------------04【宏定义部分】--------------------------------------------
//  描述：定义一些辅助宏
//------------------------------------------------------------------------------------------------
#define r() std::cout << std::endl //换行
#define DEFAULT_SIZE 1000		   //默认元素个数
#define DEFAULT_INFINITY 1000000   //默认 无穷大
#define MaxInt 0x7fffffff
#define MaxSize 100
//#define  DEFAULT_INFINITY MAX_PATH //默认 无穷大
#define NR(x) (sizeof(x) / sizeof(x[0] + 0))
#define YCYTITLE "数据结构实验课程实验范例"
#define YCYAUTHOR "作者:***华南师范大学计算机学院***"
#define YCYDATE "日期:2021年9月17日"

// ---------------------------------- - 05【全局变量声明部分】------------------------------------ -
//  描述：全局变量的声明
//------------------------------------------------------------------------------------------------
//声明全局变量
extern int ycycount; //计算程序步

//定义公共使用函数
char *s_gets(char *st, int n);
//读取整行输入并用空字符代替换行符，或者读取一部分（n-1）并丢弃剩余部分（以免留在缓冲区成为下一次读取语句的输入）。

char *s_gets(char *st, int n)
{
	//读取整行输入并用空字符代替换行符，或者读取一部分（n-1）并丢弃剩余部分（以免留在缓冲区成为下一次读取语句的输入）。
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin); // n指明读入字符的最大变量为n-1，或者遇到第一个换行符为止，并将换行符存储在字符串中
	if (ret_val)
	{
		find = strchr(st, '\n'); //查找换行符
		if (find)				 //如果地址不为NULL
			*find = '\0';		 //出现换行符放置一个空字符替换
		else					 //字符串中出现空字符则丢弃输入行的其它字符。
			while (getchar() != '\n')
			{ //处理剩余输入行，
				puts("丢弃超出长度剩余部分");
				continue;
			}
	}
	//如果fgets返回NULL，说明读到文件结尾或出现读取错误，跳过这个过程
	return ret_val;
}

//补充各个章节的头文件
//
#include "ch2/ch2.h"

#endif