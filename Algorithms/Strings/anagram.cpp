#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int changeTimes(string inputString);

int main() {
    int lines = 0;
    cin >> lines;
    cin.ignore();
    int result[lines];

    for (int i = 0; i < lines; ++i)
    {
    	string inputString;
    	getline(cin, inputString);
    	result[i] = changeTimes(inputString);
    }

    for (int j = 0; j < lines; ++j)
    {
    	cout << result[j] << endl;
    }

    return 0;
}

int changeTimes(string inputString)
{
	int changeCount = 0;
	int standardCharacter[26];
	int changeCharacter[26];
	for (int h = 0; h < 26; ++h)
	{
		standardCharacter[h] = 0;
		changeCharacter[h] = 0;
	}
	int length = inputString.length();
	if (length % 2 != 0)
	{
		return -1;
	}
	int mid = length / 2;
	string changeString;
	string standardString;
	for (int i = 0; i < length; ++i)
	{
		if (i < mid)
		{
			changeString += inputString[i];
		}
		else
		{
			standardString += inputString[i];
		}
	}

	int changeLength = changeString.length();
	int standardLength = standardString.length();
	for (int j = 0; j < standardLength; ++j)
	{
		int v = (int)(standardString[j] - 'a');
		int count = standardCharacter[v];
		standardCharacter[v] = ++count;
	}
	for (int k = 0; k < changeLength; ++k)
	{
		int v = (int)(changeString[k] - 'a');
		int count = changeCharacter[v];
		changeCharacter[v] = ++count;
	}

	for (int m = 0; m < 26; ++m)
	{
		changeCount += abs(standardCharacter[m] - changeCharacter[m]);
	}

	return changeCount / 2;
}