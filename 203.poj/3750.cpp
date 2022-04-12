#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int a ,b;
	cin >> a;
	cin.ignore();
	cin >> b;
	int index = a + b - 2;
	while (v.size() != 0)
	{
		while (index >= v.size())
		{
			index = index - v.size();
		}
		cout << v[index] << endl;
		v.erase(v.begin() + index);
		index +=  b - 1;
	}
}
