#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool valid1(int a[4], int limit)
{
	for (int i = 0; i < 4; ++i)
	{
		if (a[i] > limit)
		{
			return false;
		}
	}
	return true;
}

int checkIndex(char c)
{
	if (c == 'A')
	{
		return 0;
	}
	if (c == 'C')
	{
		return 1;
	}
	if (c == 'G')
	{
		return 2;
	}
	if (c == 'T')
	{
		return 3;
	}
	return -1;
}

int main() {
	int times = 0;
	string inputString;
	cin >> times;
	cin >> inputString;
	int range = inputString.length();
	int count[4] = {0,0,0,0};

	for (int i = 0; i < times; ++i)
	{
		int index = checkIndex(inputString[i]);
		count[index]++;
	}

	if (valid1(count, times / 4))
	{
		cout << "0" << endl;
	}
	else
	{
		int rebackIndex = 0;
		for (int j = 0; j < inputString.length(); ++j)
		{
			int index = checkIndex(inputString[j]);
			count[index]--;
			while(valid1(count, times / 4) && rebackIndex <= j)
			{
				range = min(range, j - rebackIndex + 1);
				int index = checkIndex(inputString[rebackIndex]);
				count[index]++;
				rebackIndex++;
			}
		}
		cout << range << endl;
	}

    return 0;
}
