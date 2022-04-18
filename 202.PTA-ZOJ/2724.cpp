#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node
{
	string msg;
	string msg1;
	int val;
	bool operator<(const node& other) const
	{
		return val > other.val;
	}
};

int main()
{
	freopen("input.in", "r", stdin);
	priority_queue<node> pq;
	string first_input;
	while (cin >> first_input)
	{
		if (first_input == "GET")
		{
			if (pq.empty())
			{
				cout << "EMPTY QUEUE!" << '\n';
			}
			else
			{
				cout << pq.top().msg << ' ' << pq.top().msg1 << '\n';
				pq.pop();
			}
		}
		else
		{
			node a;
			cin >> a.msg >> a.msg1 >> a.val;
			pq.push(a);
		}
	}
}
