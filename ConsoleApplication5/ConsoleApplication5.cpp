
#include "pch.h"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	std::vector<int> prefix(1 + n, 0);//[len]->len
	int len = 0;
	for (int i = 1; i < n; i++)
	{
		//pos
		while (true)
		{
			if (a[len] == a[i])
			{
				len++;
				break;
			}
			if (len == 0)
			{
				break;
			}
			len = prefix[len];
		}
		prefix[i + 1] = len;
	}
	while (true)
	{
		int period = n - len;
		if ((n - 1) % period == 0)
		{
			printf("%d\n", period);
			return 0;
		}
		assert(len > 1);
		len = prefix[len];
	}
}
