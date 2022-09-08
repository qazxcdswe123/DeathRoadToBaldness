#include <vector>

int main()
{
    std::vector<bool> v(10);
    for (auto &&e : v)
        e = true;
}