// 2、文件a和文件b都是二进制文件，其中包含的都是一组按递增次序排列的整型数。编一个程序将文件a、b的内容归并到文件c。在文件c中，数据仍按递增次序排列。

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

int main(void)
{
    // generate file
    std::ofstream a, b;
    a.open("a.txt", std::ios::binary);
    b.open("b.txt", std::ios::binary);
    // add 10 random to a and b
    for (int i = 0; i < 10; i++)
    {
        a << std::rand() % 500 << std::endl;
        b << std::rand() % 100 << std::endl;
    }
    a.close();
    b.close();

    std::ifstream input1, input2;
    input1.open("a.txt", std::ios::binary);
    input2.open("b.txt", std::ios::binary);
    std::ofstream output;
    output.open("c.txt");

    if (!input1.is_open() || !input2.is_open() || !output.is_open())
    {
        std::cout << "open file error" << std::endl;
        return -1;
    }
    else
    {
        int num;
        std::vector<int> vec1;
        std::vector<int> vec2;
        while (input1 >> num)
        {
            vec1.push_back(num);
        }
        while (input2 >> num)
        {
            vec2.push_back(num);
        }
        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());
        while (!vec1.empty() && !vec2.empty())
        {
            if (vec1.front() < vec2.front())
            {
                output << vec1.front() << " ";
                vec1.erase(vec1.begin());
            }
            else
            {
                output << vec2.front() << " ";
                vec2.erase(vec2.begin());
            }
        }

        while (!vec1.empty())
        {
            output << vec1.front() << " ";
            vec1.erase(vec1.begin());
        }
        while (!vec2.empty())
        {
            output << vec2.front() << " ";
            vec2.erase(vec2.begin());
        }
    }
    return 0;
}