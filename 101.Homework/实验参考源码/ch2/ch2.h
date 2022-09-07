#pragma once

#ifndef __YCYCH2_H__ // 如果没有定义__YCYCOMMON_H__
#define __YCYCH2_H__ // 那么定义__YCYCOMMON_H__

#include "../ycycommon.h"
//#include"./ch2/LinearList.h"
//#include"./ch2/seqList.h"

void chaptermenu2(void);	 //章节2功能菜单
void ChapterMainMenu2(void); // 2功能菜单

void ycyseqListTest1(void); //顺序表测试函数

void chaptermenu2(void)
{ //章节2功能菜单
	cout << "============================第二章菜单================================" << endl;
	cout << "1：顺序表\t";
	cout << "2：单链表\t";
	cout << "3：循环链表\t";
	cout << "4：双向循环链表\t";
	cout << "5：\t";
	cout << "6：\t";
	cout << "7：\t";
	cout << "8：\t";
	cout << "9：\t";
	cout << "10：\t";
	cout << "0:退出.\n\r";
	cout << "============================第二章菜单===============================" << endl;
}
void ChapterMainMenu2(void)
{ //功能菜单
	int ycyselect;
	chaptermenu2();

	do
	{
		// cout << "请输入对应的数(0-10)按回车结束：";
		while (cin.get() == '\n') //如果只是回车没有输入数据
			cout << "没有输入数据！请输入对应的数(0-10)按回车结束：";
		cin.unget();

		cin >> ycyselect;
		while (cin.fail())
		{ // cin会智能判断输入类型,如果不是会
			cin.clear();
			cin.ignore();
			cout << "输入类型有误，请重新输入数字(0-10)：";
			//输入非数字提示错误，数字错误不提示
			cin >> ycyselect;
		}

	} while ((ycyselect < 0) || (ycyselect > 10));

	while (1)
	{
		switch (ycyselect)
		{
		case 1:
			ycyseqListTest1();

			break;
		case 2:
			// ycylinklisttest();

			break;
		case 3:
			// ycyCircListTest();//循环链表测试

			break;
		case 4:
			// ycyDbListTest(); //双向循环链表测试

			break;

		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		default:

			break;
		}
		if (ycyselect == 0)
		{
			cin.clear();
			cin.ignore();
			break;
		}
		else
		{
			chaptermenu2();
			cout << "请选择：";
			cin >> ycyselect;
		}
	}
}

//顺序表测试函数
void ycyseqListTest1(void)
{
	int ycyselectList = 1;
	// SeqList<int> temp(10);//测试整数
	// SeqList<int> temp(defaultSize);//测试整数，如果有不带形参的构造函数
	// SeqList<int> temp;//测试整数,使用默认参数
	int reSize = 20;
	while (ycyselectList)
	{

		cout << "*************顺序表***************" << endl;

		cout << "**0退出测试      **" << endl;
		cout << "**1建立顺序表      **" << endl;
		cout << "**2输出顺序表  3顺序表插入(前插法） **" << endl;
		cout << "**4顺序表删除  5顺序表搜索    **" << endl;
		cout << "**6顺序表扩容  7顺序表搜索    **" << endl;
		cout << "***********顺序表****************" << endl;
		cout << "请选取需测试的内容：";
		cin >> ycyselectList;
		switch (ycyselectList)
		{
		case 0:
			return;
		case 1:
			// while (cin >> Item, Item != -1)
			// ycyconsequentiallist();
			// temp.input();
			break;
		case 2:
			// ycyconsequentiallist2();
			// temp.output();
			break;
		case 3:
			// ycyconsequentiallist3();
#if 0

			cout << "请输入你要插入的位置(0-" << temp.Length() - 1 << ")和数据:";
			int i;
			//char dat;
			int dat;
			cin >> i >> dat;
			if (temp.Insert(i, dat))
				cout << "数据插入成功!" << endl;
			else
				cout << "插入位置非法或超出最大个数,请输入(0-" << temp.Length() - 1 << ")之间的整数或扩容！" << endl;
#endif
			break;
		case 4:
#if 0
			cout << "请输入你要删除的位置(0-" << temp.Length() - 1 << "):";
			cin >> i;
			if (temp.Remove(i, dat)) {
				temp.output();
				cout << "删除数据:" << dat << "成功!" << endl;
			}
			else cout << "数据不存在!" << endl;
#endif

			break;
		case 5:
#if 0
			cout << "请输入你要搜索的数据:";
			cin >> dat;
			i = temp.Search(dat);
			if (i)cout << "搜索成功!数据位于下标:" << i - 1 << endl;
			else cout << "数据不存在!" << endl;
#endif
			break;
		case 6:
#if 0
			cout << "请输入你要扩容的数组大小:";
			cin >> reSize;
			temp.llist(reSize);
			cout << "扩容成功！" << endl;
#endif
			break;
		default:
			break;
		}
	}
}

#endif //__YCYCHi_H__
