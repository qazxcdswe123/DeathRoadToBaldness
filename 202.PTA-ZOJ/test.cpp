#include <iostream>
#include <cstring>
using namespace std;

int card[1001], n, m, sum_value, ways;

void DFS(int start) // start 为开始节点
{
	if (sum_value == n)
		ways++; //等于目标价值了，计数+1，回溯
	else
	{
		for (int i = start; i <= n; i++)
		{
			if (card[i] && sum_value + i <= n) // 剪枝：加上这张后不超，递归下一张
			{
				sum_value += i;
				card[i]--;
				DFS(i);
				card[i]++;
				sum_value -= i;
			}
		}
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);
	int value, pieces, flag = 0;
	while (cin >> n >> m)
	{
		if (flag)
			cout << endl;
		flag = 1;
		sum_value = ways = 0;
		memset(card, 0, sizeof(card));
		while (m--)
		{
			cin >> value >> pieces;
			card[value] = pieces;
		}
		DFS(1);
		cout << ways << endl;
	}
	return 0;
}