#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string removeDuplicate(string s)
{
	int check = 0;
	int len = s.length();
	if (len < 2)
	{
		return s;
	}
	string str = "";
	for (int i = 0; i < len; ++i)
	{	
		int v = (int)(s[i] - 'a');
		if ((check & (1 << v)) == 0)
		{
			str += s[i];
			check |= (1 << v);
		}
	}

	return str;
}

int main() {
    int lines = 0;
    int resultCount = 0;
    int totalCount[26];
    for (int k = 0; k < 26; ++k)
    {
    	totalCount[k] = 0;
    }
    cin >> lines;
    cin.ignore();
    if (lines < 1 || lines > 100)
    {
    	return 0;
    }
    for (int i = 0; i < lines; ++i)
    {	
    	string inputString;
    	getline(cin, inputString);
    	inputString = removeDuplicate(inputString);
    	int length = inputString.length();
    	for (int m = 0; m < length; ++m)
    	{
    		char c = inputString[m];
    		int index = (int)c - (int)'a';
    		int count = totalCount[index];
    		totalCount[index] = ++count;
    	}
    }
    
    for (int j = 0; j < 26; ++j)
    {
    	if (totalCount[j] == lines)
    	{
    		resultCount++;
    	}
    }

    cout << resultCount << endl;

    return 0;
}

