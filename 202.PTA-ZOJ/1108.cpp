#include <algorithm>
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

// bool cmp(ip a, ip b) {
//   if (a.w == b.w)
//     return a.s > b.s;

//   return a.w < b.w;
// }

struct dp
{
	int pre;
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
	dpt[1].pre = 1;
	int j, k;
	for (j = 1; j < i; j++)
	{
		dpt[j].max = 1;
		for (k = 1; k <= j; k++)
		{
			if (input[k].s < input[j].s)
			{
				if (dpt[j].max < dpt[k].max + 1)
				{
					dpt[j].max = dpt[k].max + 1;
					dpt[j].pre = input[k].num;
				}
			}
		}
	}
	// for (j = 0; j < i; j++) {
	//   dpt[j].max = 1;
	//   for (k = 0; k < j; k++) {
	//     if (input[k].s <= input[j].s) {
	//       dpt[j].max = max(dpt[k].max + 1, dpt[j].max);
	//     }
	//   }
	//   if (dpt[k].max > dpt[j].max) {
	//     dpt[k].pre = j;
	//   }
	// }
}
