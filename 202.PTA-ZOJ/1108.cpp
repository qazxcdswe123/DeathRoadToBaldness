#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;
int i = 1;
struct ip
{
	int w;
	int s;
	int num;
} input[1001];

bool cmp(ip &a, ip &b) { return (a.w > b.w); }

struct dp
{
	int pre = -1;
	int preIndex;
	int max = 0;
} dpt[1001];

int main()
{
	freopen("input.in", "r", stdin);
	while (cin >> input[i].s >> input[i].w)
	{
		input[i].num = i;
		i++;
	}
	sort(input + 1, input + 1001, &cmp);
	dpt[1].pre = 0;
	int j, k;
	for (j = 1; j < i; j++) // start with 1
	{
		dpt[j].max = 1;
		for (k = 1; k < j; k++)
		{
			if (input[j].s > input[k].s)
			{
				if (dpt[j].max < dpt[k].max + 1)
				{
					dpt[j].max = dpt[k].max + 1;
					dpt[j].pre = input[k].num;
					dpt[j].preIndex = k;
				}
			}
		}
	}
	int max = 1;
	int index = 1;
	for (int l = 1; l < i; l++)
	{
		if (dpt[l].max > max)
		{
			max = dpt[l].max;
			index = l;
		}
	}
	cout << max << '\n';
	stack<int> st;
	st.push(index);
	while (index != 1)
	{
		st.push(dpt[index].pre);
		// cout << dpt[index].pre << '\n';
		index = dpt[index].preIndex;
	}
	while (!st.empty())
	{
		cout << st.top() << '\n';
		st.pop();
	}
}

// #include <bits/stdc++.h>

// using namespace std;

// struct mouse
// {
// 	int weight, speed, id;
// };

// struct mouse mice[1005];

// bool cmp(mouse a, mouse b)
// {
// 	if (a.weight == b.weight)
// 		return a.speed > b.speed;

// 	return a.weight < b.weight;
// }

// int cont[1005] = {0};
// int path[1005] = {0};

// void output(int path[], int pos)
// {
// 	if (pos == 0)
// 		return;

// 	output(path, path[pos]);
// 	printf("%d\n", mice[pos].id);
// }

// int main()
// {
// 	int i = 1;

// 	freopen("input.in", "r", stdin);
// 	while (cin >> mice[i].speed >> mice[i].weight)
// 	{
// 		mice[i].id = i;
// 		i++;
// 	}

// 	sort(mice + 1, mice + i + 1, cmp);
// 	cont[1] = 1;
// 	for (int n = 1; n < i; n++)
// 	{
// 		for (int j = 1; j < n; j++)
// 		{
// 			if (mice[n].weight > mice[j].weight && mice[n].speed < mice[j].speed)
// 				if (cont[n] < cont[j])
// 				{
// 					cont[n] = cont[j];
// 					path[n] = j;
// 				}
// 		}
// 		cont[n]++;
// 	}

// 	int max = 0;
// 	int pos;

// 	for (int n = 0; n < i; n++)
// 	{
// 		if (cont[n] > max)
// 		{
// 			max = cont[n];
// 			pos = n;
// 		}
// 	}

// 	cout << max << '\n';
// 	output(path, pos);

// 	return 0;
// }
