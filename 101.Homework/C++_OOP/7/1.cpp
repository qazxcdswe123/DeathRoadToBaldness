/*
1、写一个程序，将文件in.txt 里面的整数排序后，输出到out.txt

例如，若in.txt 的内容为:

1 234 9 45 6 879

则执行本程序后，生成的out.txt的内容为:

1 6 9 45 234 879
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream input;
    input.open("in.txt");
    std::ofstream output;
    output.open("out.txt");

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "open file error" << std::endl;
        return -1;
    }
    else
    {
        std::vector<int> vec;
        int num;
        while (input >> num)
        {
            vec.push_back(num);
        }
        std::sort(vec.begin(), vec.end());
        for (auto i : vec)
        {
            output << i << " ";
        }
    }
}