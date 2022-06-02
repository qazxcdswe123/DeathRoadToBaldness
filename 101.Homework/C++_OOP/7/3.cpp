// 3、假设某一txt文件中包含一篇英文文章。编一程序统计该文件中有多少行，多少个单词， 有多少字符。假定文章中的标点符号只可能出现逗号或句号。
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input("eng.txt");
    int lines = 1;
    int words = 0;
    int chars = 0;
    char ch;
    while (input.get(ch))
    {
        if (ch == '\n')
        {
            lines++;
        }
        else if (ch == ' ')
        {
            words++;
        }
        chars++;
    }

    std::ofstream output("result.txt");
    output << "lines: " << lines << std::endl;
    output << "words: " << words << std::endl;
    output << "chars: " << chars;
}