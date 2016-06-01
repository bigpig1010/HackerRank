#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool funnyString(string srcString);

int main() {
    int lines = 0;
    cin >> lines;
    cin.ignore();
    int result[lines];

    for (int i = 0; i < lines; ++i)
    {
    	string inputString;
    	getline(cin, inputString);
    	bool funny = funnyString(inputString);
    	result[i] = funny;
    }

    for (int j = 0; j < lines; ++j)
    {
    	if (result[j] == 0)
    	{
    		cout << "Not Funny" << endl;
    	}
    	else
    	{
    		cout << "Funny" << endl;
    	}
    }

    return 0;
}

bool funnyString(string srcString)
{
	bool funny;
	int length = srcString.length();
	if (length < 2 || length > 10000)
	{
		return false;
	}
	for (int i = 1; i < length; ++i)
	{
		int positive = abs((int)(srcString[i] - srcString[i - 1]));
		int reverse = abs((int)(srcString[length - i - 1] - srcString[length - i]));
		if (positive == reverse)
		{
			funny = true;
		}
		else
		{
			funny = false;
			break;
		}
	}
	return funny;
}