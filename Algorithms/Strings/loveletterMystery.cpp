#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome (string testString);
int changeToPalindrome (string srcString);

int main()
{
	int lines = 0;
	cin >> lines;
	cin.ignore();
	int result[lines];

	for (int i = 0; i < lines; ++i)
	{
		string inputString;
		getline(cin, inputString);
		bool palindrome = isPalindrome(inputString);
		if (palindrome == true)
		{
			result[i] = 0;
		}
		else
		{
			result[i] = changeToPalindrome(inputString);
		}
	}

	for (int j = 0; j < lines; ++j)
	{
		cout << result[j] << endl;
	}

	return 0;
}

bool isPalindrome (string testString)
{
	bool result;
	int length = testString.length();
	if (length % 2 == 0)
	{
		for (int i = 0; i < length; ++i)
		{
			if (i < length / 2)
			{
				if (testString[i] == testString[length - i - 1])
				{
					result = true;
				}
				else
				{
					result =false;
					break;
				}
			}
		}
	} 
	else 
	{
		int mid = length / 2 + 1;
		for (int j = 0; j < length; ++j)
		{	
			if (j < mid)
			{
				if (testString[j] == testString[length - j - 1])
				{
					result = true;
				}
				else 
				{
					result = false;
					break;
				}
			}		
		}
	}

	return result;
}

int changeToPalindrome (string srcString)
{
	string tmpString = srcString;
	int count = 0;
	int r = 0,l = 0;
	int length = srcString.length();
	if (length % 2 == 0)
	{
		r = length / 2 - 1;
		l = length / 2;
	}
	else
	{
		int mid = length / 2;
		r = mid - 1;
		l = mid + 1;
	}

	do
	{
		char rc = tmpString[r];
		char lc = tmpString[l];
		int rascii = rc;
		int lascii = lc;
		if (rascii > lascii)
		{
			tmpString[r] = lc;
		}
		else
		{
			tmpString[l] = rc;
		}
		count += abs(rascii - lascii);
		r--;
		l++;
	} while (r >= 0 && l < length && !isPalindrome(tmpString));

	return count;
}
